#include <iostream>
#include <string>
#include <exception>
using namespace std;

class FileException : public exception {
protected:
    string info;
public:
    FileException(const string& info) : info(info) {}

    virtual const char* what() const noexcept override {
        return info.c_str();
    }
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException() : FileException("FileNotFoundException - File not found!") {}
};

class PermissionDeniedException : public FileException {
public:
    PermissionDeniedException() : FileException("PermissionDeniedException - Access denied!") {}
};

void readFile(const string& file1) {
    if (file1 == "missing.txt") {
        throw FileNotFoundException();
    } else if (file1 == "secret.txt") {
        throw PermissionDeniedException();
    } else {
        cout << "Reading '" << file1 << "' successfully.\n";
    }
}

int main() {
    string file1 = "secret.txt"; 

    try {
        readFile(file1);
    } catch (const FileNotFoundException& e) {
        cout << "Reading '" << file1 << "': " << e.what() << endl;
    } catch (const PermissionDeniedException& e) {
        cout << "Reading '" << file1 << "': " << e.what() << endl;
    } catch (const FileException& e) {
        cout << "File error: " << e.what() << endl;
    }

    string file2 = "missing.txt"; 

    try {
        readFile(file2);
    } catch (const FileNotFoundException& e) {
        cout << "Reading '" << file2 << "': " << e.what() << endl;
    } catch (const PermissionDeniedException& e) {
        cout << "Reading '" << file2 << "': " << e.what() << endl;
    } catch (const FileException& e) {
        cout << "File error: " << e.what() << endl;
    }

    return 0;
}