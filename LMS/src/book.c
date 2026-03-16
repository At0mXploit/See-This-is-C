#include <stdio.h>
#include "book.h"

const char* bookStatusToString(BookStatus status) {
    return status == BOOK_AVAILABLE ? "Available" : "Issued";
}

void printBook(const Book *book) {
    printf("%-5d %-25s %-20s %-10s\n",
           book->id,
           book->title,
           book->author,
           bookStatusToString(book->status));
}

