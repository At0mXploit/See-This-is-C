#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"

/* Initialize library data */
void initLibrary();

void addBook();

void deleteBook();

/* Print all books */
void printAllBooks();

/* Free library resources */
void freeLibrary();

Book* findBookById(int id);

#endif /* LIBRARY_H */


