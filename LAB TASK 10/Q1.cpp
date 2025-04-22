#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

void writeFile(Student students[], int size, const string& filename) {
    ofstream File(filename, ios::out);
    if (!File) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        File << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
    }

    File.close();
}

void appendFile(const Student& student, const string& filename) {
    ofstream File(filename, ios::app);
    if (!File) {
        cerr << "Error opening file for appending!" << endl;
        return;
    }

    File << student.id << " " << student.name << " " << student.gpa << endl;
    File.close();
}

void readFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Student student;
    cout << "\nAll Student Records:" << endl;
    while (inFile >> student.id >> student.name >> student.gpa) {
        cout << "ID: " << student.id << ", Name: " << student.name << ", GPA: " << student.gpa << endl;
    }

    inFile.close();
}                              

int main() {
    const string filename = "students.txt";
    Student students[5];

    cout << "Enter data for 5 students (id name gpa):" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> students[i].id >> students[i].name >> students[i].gpa;
    }

    writeFile(students, 5, filename);

    Student newStudent;
    cout << "\nEnter data for 1 more student to append: ";
    cin >> newStudent.id >> newStudent.name >> newStudent.gpa;
    appendFile(newStudent, filename);

    readFile(filename);

    return 0;
}
