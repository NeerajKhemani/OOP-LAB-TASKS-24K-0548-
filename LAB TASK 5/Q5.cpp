#include <iostream>
using namespace std;

class Engine {
    int horsepower;

public:
    Engine(int power) : horsepower(power) {}
    void start() { cout << "Engine with " << horsepower << " HP started.\n"; }    
};

class Wheel {
    int frontLeft, frontRight, backLeft, backRight;
public:
    Wheel(int fLeft, int fRight, int bLeft, int bRight)
        : frontLeft(fLeft), frontRight(fRight), backLeft(bLeft), backRight(bRight) {}

    void rotateFront() { cout << "Front wheels of size " << frontLeft << " and " << frontRight << " inches are rotating.\n"; }
    void rotateBack() { cout << "Back wheels of size " << backLeft << " and " << backRight << " inches are rotating.\n"; }
};

class Headlight {
public:
    void turnOn() { cout << "Headlights turned on.\n"; }
};

class Steering {
public:
    void turn(string direction) { cout << "Steering turned " << direction << ".\n"; }
};

class Car {
    Engine engine;       
    Headlight headlights; 
    Steering steering;    
    Wheel* wheels; 
public:
    Car(int enginePower,Wheel* wheelSet) : engine(enginePower), wheels(wheelSet) {}

    void startCar() {
        cout << "Starting the car...\n";
        engine.start();
        wheels->rotateFront();
        wheels->rotateBack();
        headlights.turnOn();
    }

    void steer(string direction) {
        steering.turn(direction);
    } 
};

int main() {
    Wheel wheelSet(17, 18, 17, 17);

    Car myCar(200, &wheelSet);

    myCar.startCar();
    myCar.steer("left");

    return 0;
}
