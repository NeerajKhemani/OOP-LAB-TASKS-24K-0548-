#include <iostream>
using namespace std;

class Vehicle{
    protected:
    string model;
    double rate;
    public:
    Vehicle (string m,double r) : model(m),rate(r) {}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle{
 public:
   Car(string m,double r) : Vehicle(m,r) {}
   double getDailyRate(){
    return rate;
   }
   void displayDetails(){
    cout << "Car Model: " << model << endl;
    cout << "Rate: " << rate << endl;
   }

};

class Bike  : public Vehicle{
 public:
   Bike(string m,double r) : Vehicle(m,r) {}
   double getDailyRate(){
    return rate;
   }
   void displayDetails(){
    cout << "Bike Model:" << model << endl;
    cout << "Rate:" << rate << endl;
   }

};

int main(){
    Bike bike1("Kawasaki Ninja",40000.00);
    Bike bike2("Kawasaki Z900",30000.00);
    Car car1("Toyota Corolla",60000.00);
    Car car2("Honda Civic",70000.00);
    Vehicle *v1 = &bike1;
    Vehicle *v2 = &bike2;
    Vehicle *v3 = &car1;
    Vehicle *v4 = &car2;
    
    v1->getDailyRate();
    v2->getDailyRate();
    v3->getDailyRate();
    v4->getDailyRate();
    

    v1->displayDetails();
    v2->displayDetails();
    v3->displayDetails();
    v4->displayDetails();

}