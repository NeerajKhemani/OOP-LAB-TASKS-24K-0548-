#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream chapter1("chapter1.txt");
    ifstream chapter2("chapter2.txt");
    ofstream book("book.txt", ios::app); 

    if (!chapter1 || !chapter2 || !book) {
        cerr << "Error opening one or more files." << endl;
        return 1;
    }

    auto appendContent = [](ifstream& source, ofstream& dest) {
        string line;
        while (getline(source, line)) {
            dest << line << endl;
        }
        dest << endl; 
    };

    appendContent(chapter1, book);
    appendContent(chapter2, book);

    chapter1.close();
    chapter2.close();
    book.close();

    ifstream finalBook("book.txt");
    if (!finalBook) {
        cerr << "Error opening book.txt for reading." << endl;
        return 1;
    }

    cout << "\nBook Contents" << endl;
    string line;
    while (getline(finalBook, line)) {
        cout << line << endl;
    }

    finalBook.close();
    return 0;
}
