#include <iostream>
#include <string>
using namespace std;

class Employee{
     int employeeID;
     string name;
     string department;
     double salary;
    public:
    Employee(){
        salary = 0.0;
    }
    Employee(int employeeID , string name ,string department ,double salary){
        this->employeeID = employeeID;
        this->name = name;
        this->department = department;
        this->salary = salary;
    }

    void giveBonus(double amount){
           salary += amount;
    }
    bool isManager(){
        if(department == "Management"){
            return true;
        }
        else{
            return false;
        }
    }
    void displayDetails() {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: Rs." << salary << endl;
    }
};

int main() {
    Employee emp1(101, "Neeraj", "Management", 75000.0);
    Employee emp2(102, "Ali", "Engineering", 65000.0);
    Employee emp3(103, "Faiz", "HR", 55000.0);

    emp1.displayDetails();
    cout << "Is Manager? " << (emp1.isManager() ? "Yes" : "No") << endl;
    emp1.giveBonus(5000);
    emp1.displayDetails();

    emp2.displayDetails();
    cout << "Is Manager? " << (emp2.isManager() ? "Yes" : "No") << endl;
    emp2.giveBonus(3000);
    emp2.displayDetails();

    emp3.displayDetails();
    cout << "Is Manager? " << (emp3.isManager() ? "Yes" : "No") << endl;
    emp3.giveBonus(2000);
    emp3.displayDetails();

    return 0;
}