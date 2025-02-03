#include <iostream>
using namespace std;
struct Student {
string name;
int math_marks;
int english_marks;
int science_marks;
int total_marks;
float average_marks;
char grade;
};
char Grade(float average) {
if (average >= 90)
return 'A';
else if (average >= 80)
return 'B';
else if (average >= 70)
return 'C';
else if (average >= 60)
return 'D';
else
return 'F';
}
int main() {
int num_students;
int i;
cout << "Enter the number of students: ";
cin >> num_students;
Student students[num_students];
for (i = 0; i < num_students; i++) {
cout << "Enter the name of student " << i + 1 << ": ";
cin >> students[i].name;
cout << "Enter marks for Mathematics: ";
cin >> students[i].math_marks;
cout << "Enter marks for English: ";
cin >> students[i].english_marks;
cout << "Enter marks for Science: ";
cin >> students[i].science_marks;
students[i].total_marks = students[i].math_marks +
students[i].english_marks + students[i].science_marks;
students[i].average_marks = students[i].total_marks / 3.0;
students[i].grade = Grade(students[i].average_marks);
}
for (i = 0; i < num_students; i++) {
cout << "Name: " << students[i].name << endl;
cout << "Mathematics: " << students[i].math_marks << endl;
cout << "English: " << students[i].english_marks << endl;
cout << "Science: " << students[i].science_marks << endl;
cout << "Total Marks: " << students[i].total_marks << endl;
cout << "Average Marks: " << students[i].average_marks << endl;
cout << "Grade: " << students[i].grade << endl;
}
return 0;
}