#include <iostream>
using namespace std;

class Square {
private:
    float sideLength;  
    float area;        

public:
    static float allareas;  

    Square() : sideLength(0), area(0) {}

    Square(float side) : sideLength(side), area(0) {}

    void calculateArea() {
        area = sideLength * sideLength;
        allareas += area;  
    }

    float getSideLength() {
        return sideLength;
    }

    float getArea() {
        return area;
    }

    static float getAllAreas() {
        return allareas;
    }

    void setSideLength(float side) {
        sideLength = side;
    }
    
    void setArea(float a) {
        area = a;
        allareas += area;  
    }
};

float Square::allareas = 0.0;

int main() {
    
    Square square1(4);
    Square square2(8);
    Square square3(11);

    
    square1.calculateArea();

    cout << "Square 1: Side Length = " << square1.getSideLength() << ", Area = " << square1.getArea() << endl;
    cout << "Total area: " << Square::getAllAreas() << endl;
    
    square2.calculateArea();

    cout << "Square 2: Side Length = " << square2.getSideLength() << ", Area = " << square2.getArea() << endl;
    cout << "Total area: " << Square::getAllAreas() << endl;
    
    square3.calculateArea();

    cout << "Square 3: Side Length = " << square3.getSideLength() << ", Area = " << square3.getArea() << endl;
    cout << "Total area: " << Square::getAllAreas() << endl;

    return 0;
}

