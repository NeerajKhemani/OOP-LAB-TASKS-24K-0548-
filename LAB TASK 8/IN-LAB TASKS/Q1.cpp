#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;
public:
    Device(string id, string type, double power) : deviceID(id), deviceType(type), powerRating(power), status(false) {}
    virtual void turnOn() { status = true; cout << deviceType << " [ID: " << deviceID << "] turned ON." << endl; }
    virtual void turnOff() { status = false; }
    virtual double calculatePowerUsage(int hours) = 0;
    string getID() { return deviceID; }
};

class Light : public Device {
public:
    Light(string id, string type, double power) : Device(id, type, power) {}
    double calculatePowerUsage(int hours) override { return powerRating * hours; }
};

class Fan : public Device {
    int speedFactor;
public:
    Fan(string id, string type, double power, int speed) : Device(id, type, power), speedFactor(speed) {}
    void turnOn() override { status = true; cout << deviceType << " [ID: " << deviceID << "] turned ON at Speed " << speedFactor << "." << endl; }
    double calculatePowerUsage(int hours) override { return powerRating * hours * speedFactor; }
};

class AirConditioner : public Device {
    double currentTemp;
    double desiredTemp;
public:
    AirConditioner(string id, string type, double power) : Device(id, type, power), currentTemp(30), desiredTemp(25) {}
    void turnOn() override { status = true; currentTemp = 25; cout << deviceType << " [ID: " << deviceID << "] turned ON. Cooling to " << currentTemp << "°C." << endl; }
    double calculatePowerUsage(int hours) override { return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100); }
};

class SecuritySystem : public Device {
public:
    SecuritySystem(string id, string type, double power) : Device(id, type, power) {}
    void turnOn() override { status = true; cout << deviceType << " [ID: " << deviceID << "] activated." << endl; }
    void turnOff() override {}
    double calculatePowerUsage(int hours) override { return powerRating * hours + 100; }
    friend class MaintenanceTool;
    friend class User;
};

class MaintenanceTool {
public:
    static void resetSecurity(SecuritySystem& sec) { sec.status = false; }
};

class User {
    string userID;
    string role;
    int accessLevel;
public:
    User(string id, string r, int level) : userID(id), role(r), accessLevel(level) {}
    void viewAccessibleDevices() {
        cout << "User " << userID << " - Accessible Devices:" << endl;
        cout << "- LED Light" << endl;
        cout << "- Ceiling Fan" << endl;
        cout << "- Split AC" << endl;
    }
    void accessSecurityLogs(SecuritySystem& sec) {
        if (accessLevel == 2) {
            cout << "User " << userID << " - Security Logs Accessed:" << endl;
            cout << "- Intrusion Detected at 3:00 AM" << endl;
            cout << "- System Reset Required" << endl;
        }
    }
};

int main() {
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);
    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AirConditioner ac1("AC001", "Split AC", 1500);
    SecuritySystem secSys1("S001", "Home Alarm", 100);
    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();
    cout << "\nPower Consumption:" << endl;
    cout << "LED Light: " << light1.calculatePowerUsage(5) << " Watts" << endl;
    cout << "Ceiling Fan: " << fan1.calculatePowerUsage(3) << " Watts" << endl;
    cout << "Split AC: " << ac1.calculatePowerUsage(6) << " Watts" << endl;
    cout << "Security System: " << secSys1.calculatePowerUsage(24) << " Watts" << endl;
    cout << "\n";
    user1.viewAccessibleDevices();
    cout << "\n";
    user2.accessSecurityLogs(secSys1);
    return 0;
}
