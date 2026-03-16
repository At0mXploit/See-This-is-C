#ifndef BOOK_H
#define BOOK_H

typedef enum {
    BOOK_AVAILABLE,
    BOOK_ISSUED
} BookStatus;

typedef struct {
    int id;
    char title[100];
    char author[100];
    BookStatus status;
} Book;

void printBook(const Book *book);
const char* bookStatusToString(BookStatus status);

#endif

