#include <iostream>
using namespace std;

class InvalidValueException : public exception{
public:
   const char* what() const noexcept override {
       return "InvalidValueException - Age cannot be negative or exceed 120." ;
   }
   
};
void validateAge(int age){
       if(age<0 || age>120){ throw InvalidValueException(); }
       cout << "Age entered : " << age << endl;
}

int main(){
    int age;
    cout << "Enter age : " << endl;
    cin >> age;

    try{
        validateAge(age);  
    }catch(InvalidValueException& e){
        cerr << "Error: " << e.what() << endl;
    }
}
