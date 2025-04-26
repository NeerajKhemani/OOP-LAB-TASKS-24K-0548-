#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream File("info.txt", ios::out);
    if (!File) {
        cerr << "Failed to open File." << endl;
        return 1;
    }
    File << "C++ is a powerful programming language.";
    File.close();

    fstream file("info.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    cout << "Initial get pointer: " << file.tellg() << endl;
    cout << "Initial put pointer: " << file.tellp() << endl;

    file.seekg(9);   // at seek(6) the pointer is at 'a' 
    string word;
    file >> word;
    cout << "Word at position 9: " << word << endl;

    file.seekp(9);
    file << "dynamicc";   // added an extra letter at end to match length with powerful

    cout << "New get pointer: " << file.tellg() << endl;
    cout << "New put pointer: " << file.tellp() << endl;

    file.seekg(0);
    string line;
    getline(file, line);
    cout << "Updated content: " << line << endl;

    file.close();
    return 0;
}
