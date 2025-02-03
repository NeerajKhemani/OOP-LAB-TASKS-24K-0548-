#include <iostream>
#include <conio.h>
using namespace std;

class SerialNumberedObject {
private:
    static int count;
    int serialNumber;

public:
    SerialNumberedObject() {
        serialNumber = ++count;
    }

    int getSerialNumber() {
        return serialNumber;
    }

    void call() {
        cout << "I am object number " << serialNumber << endl;
    }
};

int SerialNumberedObject::count = 0;

int main() {
    SerialNumberedObject obj1, obj2, obj3;
    int choice = 0;

    while (choice != 27) {  
        cout << "Enter:" << endl
             << "A to call object 1." << endl
             << "B to call object 2." << endl
             << "C to call object 3." << endl
             << "Esc to exit." << endl;

        choice = _getch(); 

        switch (choice) {
            case 'A': 
            case 'a':
                obj1.call();
                break;
            case 'B':
            case 'b':
                obj2.call();
                break;
            case 'C':
            case 'c':
                obj3.call();
                break;
            case 27:  
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Input, Try again." << endl;
        }
    }
    return 0;
}

