// This is a simple malloc implementation written in C.
// What this allocator does:
// 1. Keep every block in one doubly linked list
// 2. Look for the first free block that is big enough
// 3. Split that block if it is much larger than requested
// 4. Ask the OS for more heap space with sbrk() if needed

// This is the layout of one block in memory:
/*
   +-----------------------------+
   | block header                |
   +-----------------------------+
   | user memory returned to you |
   +-----------------------------+
*/

// Free blocks and used blocks use the same header.
// The only real difference is the "free" flag.

#define _DEFAULT_SOURCE
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define ALIGNMENT 16

typedef struct block_header {
    size_t size;                 // how many bytes the user can use
    int free;                    // 1 means free, 0 means allocated
    struct block_header *next;   // next block in the heap list
    struct block_header *prev;   // previous block in the heap list
} block_header_t;

// The header itself should also stay aligned, so we round it up.
#define HEADER_SIZE ((size_t)(((sizeof(block_header_t) + (ALIGNMENT - 1)) / ALIGNMENT) * ALIGNMENT))
// If the leftover space is too tiny, splitting is not worth it.
#define MIN_SPLIT_SIZE 32

// Start and end of our internal block list.
static block_header_t *heap_head = NULL;
static block_header_t *heap_tail = NULL;

// Round size up to the next multiple of 16.
static size_t align_up(size_t size) {
    return (size + (ALIGNMENT - 1)) & ~(size_t)(ALIGNMENT - 1);
}

// Walk through the heap and return the first free block that fits.
static block_header_t *find_free_block(size_t size) {
    block_header_t *cur = heap_head;

    while (cur != NULL) {
        if (cur->free && cur->size >= size) {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

// If a block is much bigger than what we need, cut it into:
// [used block][new free block]
static void split_block(block_header_t *block, size_t size) {
    size_t remaining;
    block_header_t *new_block;

    // If the remainder would be too small to be useful, keep the block as-is.
    if (block->size < size + HEADER_SIZE + MIN_SPLIT_SIZE) {
        return;
    }

    remaining = block->size - size - HEADER_SIZE;
    new_block = (block_header_t *)((char *)block + HEADER_SIZE + size);
    new_block->size = remaining;
    new_block->free = 1;
    new_block->next = block->next;
    new_block->prev = block;

    if (new_block->next != NULL) {
        new_block->next->prev = new_block;
    } else {
        heap_tail = new_block;
    }

    block->size = size;
    block->next = new_block;
}

// Ask the OS for more heap space and append it to our list.
static block_header_t *request_space(size_t size) {
    void *mem;
    block_header_t *block;

    mem = sbrk(HEADER_SIZE + size);
    if (mem == (void *)-1) {
        return NULL;
    }

    block = (block_header_t *)mem;
    block->size = size;
    block->free = 0;
    block->next = NULL;
    block->prev = heap_tail;

    if (heap_tail != NULL) {
        heap_tail->next = block;
    } else {
        heap_head = block;
    }

    heap_tail = block;
    return block;
}

// Merge neighboring free blocks so the heap does not get fragmented too fast.
static void coalesce(block_header_t *block) {
    // Merge with the next block first.
    if (block->next != NULL && block->next->free) {
        block_header_t *next = block->next;

        block->size += HEADER_SIZE + next->size;
        block->next = next->next;

        if (block->next != NULL) {
            block->next->prev = block;
        } else {
            heap_tail = block;
        }
    }

    // Then try merging with the previous block.
    if (block->prev != NULL && block->prev->free) {
        block_header_t *prev = block->prev;

        prev->size += HEADER_SIZE + block->size;
        prev->next = block->next;

        if (block->next != NULL) {
            block->next->prev = prev;
        } else {
            heap_tail = prev;
        }
    }
}

// Main malloc:
// align the size, search free list, otherwise grow heap.
void *malloc(size_t size) {
    block_header_t *block;

    if (size == 0) {
        return NULL;
    }

    size = align_up(size);
    block = find_free_block(size);

    if (block != NULL) {
        // Reuse an old free block if we can.
        split_block(block, size);
        block->free = 0;
        return (char *)block + HEADER_SIZE;
    }

    block = request_space(size);
    if (block == NULL) {
        return NULL;
    }

    return (char *)block + HEADER_SIZE;
}

// free() only marks the block as free, then tries to join nearby free blocks.
void free(void *ptr) {
    block_header_t *block;

    if (ptr == NULL) {
        return;
    }

    block = (block_header_t *)((char *)ptr - HEADER_SIZE);
    block->free = 1;
    coalesce(block);
}

// calloc() is malloc() + zeroing the memory.
void *calloc(size_t nmemb, size_t size) {
    size_t total;
    void *ptr;

    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    if (nmemb > ((size_t)-1) / size) {
        return NULL;
    }

    total = nmemb * size;
    ptr = malloc(total);
    if (ptr == NULL) {
        return NULL;
    }

    memset(ptr, 0, total);
    return ptr;
}

// realloc() tries to reuse the same block when possible.
// If that fails, it allocates a new block, copies data, and frees the old one.
void *realloc(void *ptr, size_t size) {
    block_header_t *block;
    void *new_ptr;
    size_t copy_size;

    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    size = align_up(size);
    block = (block_header_t *)((char *)ptr - HEADER_SIZE);

    if (block->size >= size) {
        // Current block is already big enough.
        split_block(block, size);
        return ptr;
    }

    if (block->next != NULL && block->next->free &&
        block->size + HEADER_SIZE + block->next->size >= size) {
        block_header_t *next = block->next;

        // Grow into the next block if it is free.
        block->size += HEADER_SIZE + next->size;
        block->next = next->next;

        if (block->next != NULL) {
            block->next->prev = block;
        } else {
            heap_tail = block;
        }

        split_block(block, size);
        return ptr;
    }

    // Fallback: allocate somewhere else and copy the old bytes.
    new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }

    copy_size = block->size < size ? block->size : size;
    memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}
