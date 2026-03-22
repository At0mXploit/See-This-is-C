#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int test_malloc_and_free(void) {
    char *p = malloc(32);

    if (p == NULL) {
        printf("test_malloc_and_free: malloc failed\n");
        return 0;
    }

    strcpy(p, "hello malloc");
    if (strcmp(p, "hello malloc") != 0) {
        printf("test_malloc_and_free: stored string mismatch\n");
        free(p);
        return 0;
    }

    free(p);
    printf("test_malloc_and_free: ok\n");
    return 1;
}

static int test_calloc_zero(void) {
    int *arr = calloc(5, sizeof(int));

    if (arr == NULL) {
        printf("test_calloc_zero: calloc failed\n");
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        if (arr[i] != 0) {
            printf("test_calloc_zero: arr[%d] is not zero\n", i);
            free(arr);
            return 0;
        }
    }

    free(arr);
    printf("test_calloc_zero: ok\n");
    return 1;
}

static int test_realloc_grow(void) {
    char *p = malloc(8);

    if (p == NULL) {
        printf("test_realloc_grow: malloc failed\n");
        return 0;
    }

    strcpy(p, "abc");
    p = realloc(p, 64);
    if (p == NULL) {
        printf("test_realloc_grow: realloc failed\n");
        return 0;
    }

    if (strcmp(p, "abc") != 0) {
        printf("test_realloc_grow: old data was not preserved\n");
        free(p);
        return 0;
    }

    strcat(p, "def");
    if (strcmp(p, "abcdef") != 0) {
        printf("test_realloc_grow: append after realloc failed\n");
        free(p);
        return 0;
    }

    free(p);
    printf("test_realloc_grow: ok\n");
    return 1;
}

static int test_reuse_freed_block(void) {
    char *a = malloc(32);
    char *b;

    if (a == NULL) {
        printf("test_reuse_freed_block: first malloc failed\n");
        return 0;
    }

    strcpy(a, "reuse");
    free(a);

    b = malloc(24);
    if (b == NULL) {
        printf("test_reuse_freed_block: second malloc failed\n");
        return 0;
    }

    strcpy(b, "worked");
    if (strcmp(b, "worked") != 0) {
        printf("test_reuse_freed_block: reused block write failed\n");
        free(b);
        return 0;
    }

    free(b);
    printf("test_reuse_freed_block: ok\n");
    return 1;
}

int main(void) {
    int passed = 1;

    passed &= test_malloc_and_free();
    passed &= test_calloc_zero();
    passed &= test_realloc_grow();
    passed &= test_reuse_freed_block();

    if (!passed) {
        printf("some tests failed\n");
        return 1;
    }

    printf("all tests passed\n");
    return 0;
}
