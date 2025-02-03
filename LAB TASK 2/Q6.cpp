#include <iostream>
#include <string>
using namespace std;
struct Register {
string courseId;
string courseName;
};
struct Student {
string studentId;
string firstName;
string lastName;
string cellNo;
string email;
Register reg;
};
int main() {
Student students[5];
for(int i = 0; i < 5; i++) {
cout << "Enter details for student " << i + 1 << endl;
cout << "Enter Course ID: ";
cin >> students[i].reg.courseId;
cout << "Enter Course Name: ";
cin.ignore();
getline(cin, students[i].reg.courseName);
cout << "Enter Student ID: ";
cin >> students[i].studentId;
cout << "Enter First Name: ";
cin.ignore();
getline(cin, students[i].firstName);
cout << "Enter Last Name: ";
getline(cin, students[i].lastName);
cout << "Enter Cell No: ";
getline(cin, students[i].cellNo);
cout << "Enter Email: ";
getline(cin, students[i].email);
cout << endl;
}
cout << "\nDisplaying Student Information:\n";
for(int i = 0; i < 5; i++) {
cout << "Student " << i + 1 << " details:" << endl;
cout << "Course ID: " << students[i].reg.courseId << endl;
cout << "Course Name: " << students[i].reg.courseName << endl;
cout << "Student ID: " << students[i].studentId << endl;
cout << "First Name: " << students[i].firstName << endl;
cout << "Last Name: " << students[i].lastName << endl;
cout << "Cell No: " << students[i].cellNo << endl;
cout << "Email: " << students[i].email << endl;
cout << endl;
}
return 0;
}
