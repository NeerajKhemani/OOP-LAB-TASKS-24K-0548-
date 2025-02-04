#include <iostream>
#include <string>

using namespace std;

class Smartphone {
private:
    string company;
    string model;
    string displayResolution;
    int ram;
    int rom;
    int storage;

public:
    Smartphone(string comp, string mod, string res, int r, int ro, int stor) {
        company = comp;
        model = mod;
        displayResolution = res;
        ram = r;
        rom = ro;
        storage = stor;
    }

    string getCompany() { return company; }
    string getModel() { return model; }
    string getDisplayResolution() { return displayResolution; }
    int getRAM() { return ram; }
    int getROM() { return rom; }
    int getStorage() { return storage; }

    void setCompany(string comp) { company = comp; }
    void setModel(string mod) { model = mod; }
    void setDisplayResolution(string res) { displayResolution = res; }
    void setRAM(int r) { ram = r; }
    void setROM(int ro) { rom = ro; }
    void setStorage(int stor) { storage = stor; }

    void makeCall(string number) {
        cout << "Calling " << number << "..." << endl;
    }

    void sendMessage(string number, string message) {
        cout << "Sending message to " << number << ": " << message << endl;
    }

    void connectToWiFi(string wifiName) {
        cout << "Connecting to WiFi: " << wifiName << endl;
    }

    void browseInternet(string website) {
        cout << "Browsing website: " << website << endl;
    }

    void displayInfo() {
        cout << "Smartphone Details:\n";
        cout << "Company: " << company << "\nModel: " << model 
             << "\nDisplay Resolution: " << displayResolution
             << "\nRAM: " << ram << "GB"
             << "\nROM: " << rom << "GB"
             << "\nStorage: " << storage << "GB\n";
    }
};

int main() {
    Smartphone phone1("Samsung", "Galaxy S21", "2400x1080", 8, 128, 256);
    Smartphone phone2("Apple", "iPhone 13", "2532x1170", 6, 128, 256);

    phone1.setRAM(12);
    phone2.setStorage(512);

    phone1.displayInfo();
    phone2.displayInfo();

    phone1.makeCall("123-456-7890");
    phone2.sendMessage("987-654-3210", "Hello, how are you?");
    phone1.connectToWiFi("Home_WiFi");
    phone2.browseInternet("www.google.com");

    return 0;
}
