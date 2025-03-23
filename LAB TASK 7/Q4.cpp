#include <iostream>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    virtual void updateInfo(string newAddress, string newPhone, string newEmail) {
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }

    string getName() const { return name; }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string coursesEnrolled;
    float GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string a, string p, string e,
            string courses, float gpa, int year)
        : Person(n, i, a, p, e), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }

    float getGPA() const { return GPA; }
};

class Professor : public Person {
private:
    string department, coursesTaught;
    double salary;

public:
    Professor(string n, string i, string a, string p, string e,
              string dept, string courses, double sal)
        : Person(n, i, a, p, e), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: Rs" << salary << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e,
          string dept, string pos, double sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: Rs" << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;

public:
    Course(string id, string name, int c, string inst, string sched)
        : courseId(id), courseName(name), credits(c), instructor(inst), schedule(sched) {}

    void registerStudent(const Student& student) {
        cout << "\nRegistering student '" << student.getName() << "' to course " << courseName << endl;
        calculateGrades(student);
    }

    void calculateGrades(const Student& student) {
        float gpa = student.getGPA();
        if (gpa >= 3.7)
            cout << "Grade: A" << endl;
        else if (gpa >= 3.0)
            cout << "Grade: B" << endl;
        else if (gpa >= 2.0)
            cout << "Grade: C" << endl;
        else
            cout << "Grade: F" << endl;
    }

    void displayCourse() const {
        cout << "\nCourse ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << endl;
    }
};

int main() {
    Student s("Neeraj Khemani", "S001", "Karachi", "0300-1234567", "ali@edu.nu.pk", "MVC, English", 3.6, 2022);
    Professor p("Dr. Ahmed", "P101", "Karachi", "0333-6543210", "ahmed@edu.nu.pk", "CS", "OOP, AI", 150000);
    Staff st("Sara Malik", "ST12", "Karachi", "0312-9876543", "sara@edu.nu.pk", "Admin", "Clerk", 50000);
    Course c("CS101", "Object Oriented Programming", 3, "Dr. Ahmed", "MWF 10-11 AM");

    cout << "\n--- Student Info ---\n";
    s.displayInfo();

    cout << "\n--- Professor Info ---\n";
    p.displayInfo();

    cout << "\n--- Staff Info ---\n";
    st.displayInfo();

    cout << "\n--- Course Info ---\n";
    c.displayCourse();

    c.registerStudent(s);

    return 0;
}
