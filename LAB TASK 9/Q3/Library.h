#ifndef LIBRARY
#define LIBRARY

#include "book.h"

const int max_books = 20;
class Library{
    Book* books[max_books];
    int count;

    public:
    Library(){}
    void addBook(Book* book);
    void removeBook(string ISBN);
    void searchBook(string title);
    void displayAllBooks();
};

#endif