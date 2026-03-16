#include <stdio.h>
#include <stdlib.h>
#include "library.h"

#define BOOK_FILE "data/books.dat"

static Book *books = NULL;
static int bookCount = 0;

void initLibrary() {
    FILE *fp = fopen(BOOK_FILE, "rb");

    if (!fp) {
        // First run → create default books
        bookCount = 3;
        books = malloc(sizeof(Book) * bookCount);

        books[0] = (Book){1, "C Programming", "Dennis Ritchie", BOOK_AVAILABLE};
        books[1] = (Book){2, "Data Structures", "Mark Weiss", BOOK_AVAILABLE};
        books[2] = (Book){3, "Algorithms", "CLRS", BOOK_AVAILABLE};

        fp = fopen(BOOK_FILE, "wb");
        fwrite(&bookCount, sizeof(int), 1, fp);
        fwrite(books, sizeof(Book), bookCount, fp);
        fclose(fp);
        return;
    }

    fread(&bookCount, sizeof(int), 1, fp);
    books = malloc(sizeof(Book) * bookCount);
    fread(books, sizeof(Book), bookCount, fp);
    fclose(fp);
}

void printAllBooks() {
    printf("\nID    Title                     Author              Status\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++)
        printBook(&books[i]);
}

Book* findBookById(int id) {
    for (int i = 0; i < bookCount; i++)
        if (books[i].id == id)
            return &books[i];
    return NULL;
}

void freeLibrary() {
    FILE *fp = fopen(BOOK_FILE, "wb");
    fwrite(&bookCount, sizeof(int), 1, fp);
    fwrite(books, sizeof(Book), bookCount, fp);
    fclose(fp);

    free(books);
}

void addBook() {
    Book newBook;

    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);

    // Check duplicate ID
    if (findBookById(newBook.id)) {
        printf("Book ID already exists!\n");
        return;
    }

    printf("Enter Title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Enter Author: ");
    scanf(" %[^\n]", newBook.author);

    newBook.status = BOOK_AVAILABLE;

    Book *temp = realloc(books, sizeof(Book) * (bookCount + 1));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }

    books = temp;
    books[bookCount++] = newBook;

    printf("Book added successfully.\n");
}

void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    if (books[index].status == BOOK_ISSUED) {
        printf("Cannot delete an issued book!\n");
        return;
    }

    // Shift books left
    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }

    Book *temp = realloc(books, sizeof(Book) * (bookCount - 1));
    if (temp || bookCount - 1 == 0) {
        books = temp;
        bookCount--;
        printf("Book deleted successfully.\n");
    } else {
        printf("Memory error. Delete aborted.\n");
    }
}

