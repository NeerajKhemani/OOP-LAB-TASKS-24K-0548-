#include <iostream>
#include <string>
using namespace std;
struct Event {
string name;
string date;
string venue;
string organizer;
};
void addEvents(Event* events, int totalEvents) {
for (int i = 0; i < totalEvents; i++) {
cout << "Enter details for event " << i + 1 << ":\n";
cout << "Event Name: ";
cin.ignore();
getline(cin, events[i].name);
cout << "Date (DD-MM-YYYY): ";
getline(cin, events[i].date);
cout << "Venue: ";
getline(cin, events[i].venue);
cout << "Organizer: ";
getline(cin, events[i].organizer);
}
}
void displayAllEvents(Event* events, int totalEvents) {
    cout << "\nAll Event Details:\n";
for (int i = 0; i < totalEvents; i++) {
cout << "\nEvent " << i + 1 << ":\n";
cout << "Name: " << events[i].name << "\n";
cout << "Date: " << events[i].date << "\n";
cout << "Venue: " << events[i].venue << "\n";
cout << "Organizer: " << events[i].organizer << "\n";
}
}
void searchEventsByDate(Event* events, int totalEvents, const
string& searchDate) {
bool found = false;
cout << "\nEvents on " << searchDate << ":\n";
for (int i = 0; i < totalEvents; i++) {
if (events[i].date == searchDate) {
found = true;
cout << "\nEvent " << i + 1 << ":\n";
cout << "Name: " << events[i].name << "\n";
cout << "Venue: " << events[i].venue << "\n";
cout << "Organizer: " << events[i].organizer << "\n";
}
}
if (!found) {
cout << "No events found on this date.\n";
}
}
int main() {
int totalEvents;
cout << "Enter the total number of events: ";
cin >> totalEvents;
Event* events = new Event[totalEvents];
addEvents(events, totalEvents);
char choice;
do {
cout << "\nMenu:\n";
cout << "1. Display all events\n";
cout << "2. Search events by date\n";
cout << "3. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case '1':
displayAllEvents(events, totalEvents);
break;
case '2': {
string searchDate;
cout << "Enter the date to search (DD-MM-YYYY): ";
cin.ignore();
getline(cin, searchDate);
searchEventsByDate(events, totalEvents, searchDate);
break;
}
case '3':
cout << "Exiting the program.\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
}
} while (choice != '3');
delete[] events;
return 0;
}