#include <stdio.h>
#include "transaction.h"
#include "library.h"

void issueBook(int bookId) {
    Book *book = findBookById(bookId);
    if (!book) {
        printf("Book not found!\n");
        return;
    }
    if (book->status == BOOK_ISSUED) {
        printf("Book already issued!\n");
        return;
    }
    book->status = BOOK_ISSUED;
    printf("Book issued successfully.\n");
}

void returnBook(int bookId) {
    Book *book = findBookById(bookId);
    if (!book) {
        printf("Book not found!\n");
        return;
    }
    book->status = BOOK_AVAILABLE;
    printf("Book returned successfully.\n");
}

