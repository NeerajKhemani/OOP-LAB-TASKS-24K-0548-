#include <iostream>
#include <string>
using namespace std;

class Calendar {
private:
    string months[12][31];
    int year;

public:
    Calendar(int y) {
        year = y;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 31; j++)
                months[i][j] = "";
    }

    void addTask(string task, int day, int month) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date!\n";
            return;
        }
        months[month - 1][day - 1] = task;
    }

    void removeTask(int day, int month) {
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            cout << "Invalid date!\n";
            return;
        }
        months[month - 1][day - 1] = "";
    }

    void showTasks() {
        cout << "Tasks for the year " << year << ":\n";
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                if (!months[i][j].empty()) {
                    cout << "Month " << i + 1 << ", Day " << j + 1 
                         << ": " << months[i][j] << endl;
                }
            }
        }
    }
};

int main() {
    Calendar myCalendar(2025);

    myCalendar.addTask("Doctor's appointment", 5, 3);
    myCalendar.addTask("Project deadline", 15, 6);
    myCalendar.addTask("Friend's wedding", 20, 7);
    myCalendar.addTask("Flight to NY", 10, 9);
    myCalendar.addTask("Parent's anniversary", 25, 12);
    
    cout << "Before removing a task:\n";
    myCalendar.showTasks();

    myCalendar.removeTask(15, 6);
    
    cout << "\nAfter removing the task on June 15:\n";
    myCalendar.showTasks();

    return 0;
}
