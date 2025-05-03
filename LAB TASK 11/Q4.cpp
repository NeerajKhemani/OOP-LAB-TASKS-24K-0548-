#include <iostream>
#include <typeinfo>
#include <exception>
using namespace std;


class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - Input must be non-negative!";
    }
};


class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

template<typename T>
T mySqrt(T num) {
    if (!(typeid(num) == typeid(int) ||
          typeid(num) == typeid(float) ||
          typeid(num) == typeid(double))) {
        throw InvalidTypeException();
    }
    else if (num < 0) {
        throw NegativeNumberException();
    }

    return (num * num);
}

int main() {
    try {
        cout << "sqrt(49) = " << mySqrt(49) << endl;
        cout << "sqrt(-9) = " << mySqrt(-9) << endl;  
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        string s = "hello";
        mySqrt(s); 
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
