#include <iostream>
using namespace std;

class SmartDevice{
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus()=0;
};

class LightBulb : public SmartDevice{
    bool isOn;
    int brightness;
    public:
    LightBulb() : isOn(false) , brightness(100) {}
    void turnOn(){
        isOn = true;
        cout << "LIght turned ON" << endl;
    }

    void turnOff(){
        isOn = false;
        cout << "LIght turned OFF" << endl;
    }
    
    void getStatus(){
        if(isOn==true) { cout << "Light is currently turned ON" << endl; }
        else { cout << "Light is currently turned OFF" << endl; }
    }
};

class Thermostat : public SmartDevice{
    bool isOn;
    double temperature;
    public:
    Thermostat() : isOn(false) , temperature(32.0) {}
    void turnOn(){
        isOn = true;
        cout << "Thermostat turned ON" << endl;
    }

    void turnOff(){
        isOn = false;
        cout << "Thermostat turned OFF" << endl;
    }
    
    void getStatus(){
        if(isOn==true) { cout << "Thermostat is currently turned ON" << endl; }
        else { cout << "Thermostat is currently turned OFF" << endl; }
    }
};

int main(){
    LightBulb lb;
    Thermostat th;

    lb.turnOn();
    th.turnOn();

    lb.getStatus();
    th.getStatus();

    lb.turnOff();
    th.turnOff();

    lb.getStatus();
    th.getStatus();
}