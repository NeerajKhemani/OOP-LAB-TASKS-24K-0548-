#include <iostream>
#include <iomanip>
#include <conio.h>  
using namespace std;

class angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    angle(int deg, float min, char dir) {
        degrees = deg;
        minutes = min;
        direction = dir;
    }

    void getAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
    }

    void displayAngle() const {
        cout << degrees << "\xF8" << fixed << setprecision(1) 
             << minutes << "' " << direction << endl;
    }
};

int main() {
    angle a1(149, 34.8, 'W');
    
    cout << "Initialized Angle: ";
    a1.displayAngle();

    while (true) {
        cout << "\nPress 'Esc' to exit or any other key to continue...\n";
        if (_getch() == 27)  
            break;

        angle userAngle(0, 0.0, 'N'); 
        cout << "Enter a new angle value:\n";
        userAngle.getAngle();
        cout << "You entered: ";
        userAngle.displayAngle();
    }

    cout << "\nProgram exited successfully.\n";
    return 0;
}
