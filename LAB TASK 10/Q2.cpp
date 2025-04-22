#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string name, email, summary;
    int yearsOfExperience;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your years of experience: ";
    cin >> yearsOfExperience;
    cin.ignore(); 

    cout << "Enter your professional summary: ";
    getline(cin, summary);

    ofstream File("resume.txt", ios::trunc);
    if (!File) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    File << "Name: " << name << endl;
    File << "Email: " << email << endl;
    File << "Years of Experience: " << yearsOfExperience << endl;
    File << "Summary: " << summary << endl;
    File.close();

    ifstream inFile("resume.txt");
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    cout << "\nResume Content:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
