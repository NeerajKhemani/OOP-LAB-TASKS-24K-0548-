#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;

    Book* b1 = new Book("1984", "George Orwell", "9780451524935");
    Book* b2 = new Book("Brave New World", "Aldous Huxley", "9780060850524");

    lib.addBook(b1);
    lib.addBook(b2);

    cout << "All Books:\n";
    lib.displayAllBooks();

    cout << "\nSearching for '1984':\n";
    Book* found = lib.searchBook("1984");
    if (found)
        cout << "Found: " << found->getTitle() << " by " << found->getAuthor() << endl;

    cout << "\nRemoving '1984'\n";
    lib.removeBook("9780451524935");

    cout << "\nBooks after removal:\n";
    lib.displayAllBooks();

    return 0;
}