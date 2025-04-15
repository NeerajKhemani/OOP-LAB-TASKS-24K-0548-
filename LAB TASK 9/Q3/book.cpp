#include "book.h"
#include <iostream>
using namespace std;

Book::Book(string title,string author,string ISBN) : title(title) , author(author) , ISBN(ISBN) {}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getISBN() {
    return ISBN;
}