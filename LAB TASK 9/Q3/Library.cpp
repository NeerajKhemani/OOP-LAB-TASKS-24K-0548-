#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() : count(0) {
    for (int i = 0; i < MAX_BOOKS; ++i) {
        books[i] = nullptr;
    }
}

void Library::addBook(Book* book) {
    if (count < MAX_BOOKS) {
        books[count++] = book;
    }
}

void Library::removeBook(const string& isbn) {
    for (int i = 0; i < count; ++i) {
        if (books[i]->getISBN() == isbn) {
            delete books[i];
            for (int j = i; j < count - 1; ++j) {
                books[j] = books[j + 1];
            }
            books[--count] = nullptr;
            cout << " Book removed successfully. " << endl;
        }
    }
    cout << " Book not found. " << endl;
}

Book* Library::searchBook(const string& title) {
    for (int i = 0; i < count; ++i) {
        if (books[i]->getTitle() == title) {
            return books[i];
        }
    }
    return nullptr;
}

void Library::displayAllBooks() {
    for (int i = 0; i < count; ++i) {
        cout << "Title: " << books[i]->getTitle()
             << ", Author: " << books[i]->getAuthor()
             << ", ISBN: " << books[i]->getISBN() << endl;
    }
}