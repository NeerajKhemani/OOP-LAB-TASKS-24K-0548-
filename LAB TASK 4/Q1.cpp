#include <iostream>

using namespace std;

class Student{
    public:
    int studentID ;
    string name  ;
    int age;
    char grade;

    Student(){
        grade = 'N' ;
    }
    Student (int studentID , string name , int age , char grade){
        this->studentID = studentID ;
        this->name = name;
        this->age = age;
        this->grade = grade;

    }
    void promoteStudent() {
        if (grade == 'B') {
            grade = 'A';
        } else if (grade == 'C') {
            grade = 'B';
        } else if (grade == 'D') {
            grade = 'C';
        } else if (grade == 'F') {
            grade = 'D';
        } else {
            cout << "The student is already at the highest grade." << endl;
        }
    }

    bool isEligibleForScholarship(){
    if (grade == 'A'){
        return true;
    }
    else {
        return false;
    }
    }  
    void displayDetails(){
        cout << "Student ID : " << studentID << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Grade : " << grade << endl;
    }

};

int main() {
    Student student1(101, "Ali", 20, 'B');
    Student student2(102, "Neeraj", 22, 'A');
    Student student3;

    
    cout << "Student 1 Details: " << endl;
    student1.displayDetails();
    cout << "Eligible for Scholarship: " << (student1.isEligibleForScholarship() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "Student 2 Details: " << endl;
    student2.displayDetails();
    cout << "Eligible for Scholarship: " << (student2.isEligibleForScholarship() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "Student 3 Details: " << endl;
    student3.displayDetails();
    cout << "Eligible for Scholarship: " << (student3.isEligibleForScholarship() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "Promoting Student 1..." << endl;
    student1.promoteStudent();
    cout << "Student 1 Details After Promotion: " << endl;
    student1.displayDetails();
    cout << "Eligible for Scholarship: " << (student1.isEligibleForScholarship() ? "Yes" : "No") << endl;

    return 0;
}
