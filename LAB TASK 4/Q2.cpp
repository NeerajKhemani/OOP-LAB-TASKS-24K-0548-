#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;

    Book() {
           id = 0;
        title = "Unknown";
        author = "Unknown";
        available = true;
    }

    Book(int id, const string& title, const string& author, bool isAvailable = true) {
        this->id = id;
        this->title = title;
        this->author = author;
        available = isAvailable;
    }

    void displayBook() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", Availability: " << (available ? "Available" : "Not Available") << endl;
    }
};

class Library {
private:
    Book* books[100];
    int bookCount;

public:
    Library(){
	bookCount = 0;
	}

    ~Library() {
        for (int i = 0; i < bookCount; ++i) {
            delete books[i];
        }
    }

    void addBook(int id, const string& title, const string& author, bool availability = true) {
        books[bookCount++] = new Book(id, title, author, availability);
        cout << "Book added: " << title << endl;
    }

    bool borrowBook(int id) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->id == id && books[i]->available) {
                books[i]->available = false;
                cout << "You have borrowed: " << books[i]->title << endl;
                return true;
            }
        }
        cout << "Book not available or invalid ID." << endl;
        return false;
    }

    bool returnBook(int id) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->id == id && !books[i]->available) {
                books[i]->available = true;
                cout << "You have returned: " << books[i]->title << endl;
                return true;
            }
        }
        cout << "Invalid book ID or the book wasn't borrowed." << endl;
        return false;
    }

    void displayAvailableBooks() const {
        bool found = false;
        cout << "Available Books: " << endl;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->available) {
                books[i]->displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "No available books." << endl;
        }
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author;
    bool availability;

    while (true) {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Available Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book ID: ";
                cin >> id;
                cin.ignore();  
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Is the book available (1 for Yes, 0 for No): ";
                cin >> availability;
                lib.addBook(id, title, author, availability);
                break;

            case 2:
                cout << "Enter book ID to borrow: ";
                cin >> id;
                lib.borrowBook(id);
                break;

            case 3:
                cout << "Enter book ID to return: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 4:
                lib.displayAvailableBooks();
                break;

            case 5:
                cout << "Exiting the system.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

