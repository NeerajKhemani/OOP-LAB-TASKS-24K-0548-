#include <iostream>
#include <string>
using namespace std;

class Controller;
class MaintenanceTool;

class Device {
protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;

public:
    Device(string id, string type, double power)
        : deviceID(id), deviceType(type), powerRating(power), status(false) {}

    friend class Controller;
    friend class MaintenanceTool;
};

class Light : public Device {
public:
    Light(string id, string type, double power) : Device(id, type, power) {}
};

class Fan : public Device {
    int speed;
public:
    Fan(string id, string type, double power, int spd) : Device(id, type, power), speed(spd) {}

    friend class Controller;
};

class AirConditioner : public Device {
    int currentTemp, desiredTemp;
public:
    AirConditioner(string id, string type, double power, int current, int desired)
        : Device(id, type, power), currentTemp(current), desiredTemp(desired) {}

    friend class Controller;
};

class SecuritySystem : public Device {
    string logs;
public:
    SecuritySystem(string id, string type, double power)
        : Device(id, type, power), logs("- Motion Detected\n- Alarm Triggered") {}

    friend class MaintenanceTool;
};

class User {
    string userID;
    string role;
    int accessLevel;
public:
    User(string id, string r, int level) : userID(id), role(r), accessLevel(level) {}

    friend class MaintenanceTool;
    friend class Controller;
};

class Controller {
public:
    static void turnOn(Device& d) {
        d.status = true;
    }

    static void turnOff(Device& d) {
        d.status = false;
    }

    static void showStatus(Device& d) {
        if (d.status) {
            cout << d.deviceType << " [" << d.deviceID << "] is ON.\n";
        } else {
            cout << d.deviceType << " [" << d.deviceID << "] is OFF.\n";
        }
    }

    static double computePower(Device& d, int hours) {
        if (d.deviceType == "fan") {
            Fan* f = (Fan*)&d;
            return f->powerRating * f->speed * hours;
        }
        if (d.deviceType == "AC") {
            AirConditioner* ac = (AirConditioner*)&d;
            double factor = 1 - ((ac->currentTemp - ac->desiredTemp) / 100.0);
            return ac->powerRating * factor * hours;
        }
        return d.powerRating * hours;
    }

    static void accessibleDevices(User& u, Device& d1, Device& d2, Device& d3, Device& d4) {
        cout << "\nUser: " << u.userID << " has access to:\n";
        showStatus(d1);
        showStatus(d2);
        showStatus(d3);
        if (u.role == "Maintenance Staff") showStatus(d4);
    }
};

class MaintenanceTool {
public:
    static void accessLogs(User& u, SecuritySystem& sec) {
        if (u.role == "Maintenance Staff") {
            cout << "\nSecurity Logs:\n" << sec.logs << "\n";
        } else {
            cout << "\nAccess Denied: Unauthorized User.\n";
        }
    }
};

int main() {
    User user1("U101", "Regular User", 1);
    User user2("U202", "Maintenance Staff", 2);

    Light light1("L001", "light", 12);
    Fan fan1("F001", "fan", 75, 3);
    AirConditioner ac1("AC001", "AC", 1500, 30, 25);
    SecuritySystem sec1("S001", "security", 50);

    Controller::turnOn(light1);
    Controller::turnOn(fan1);
    Controller::turnOn(ac1);
    Controller::turnOn(sec1);

    Controller::showStatus(light1);
    Controller::showStatus(fan1);
    Controller::showStatus(ac1);
    Controller::showStatus(sec1);

    cout << "\nPower Consumption:\n";
    cout << "Light: " << Controller::computePower(light1, 4) << "W\n";
    cout << "Fan: " << Controller::computePower(fan1, 3) << "W\n";
    cout << "AC: " << Controller::computePower(ac1, 5) << "W\n";
    cout << "Security System: " << Controller::computePower(sec1, 24) << "W\n";

    Controller::accessibleDevices(user1, light1, fan1, ac1, sec1);
    MaintenanceTool::accessLogs(user2, sec1);

    return 0;
}

