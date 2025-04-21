#include <iostream>
using namespace std;

class Activity {
  public:
    virtual double calculateCaloriesBurned() = 0; 
};

class Running : public Activity {
    double distance; 
    double time;     
public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() override {
        double timeHours = time / 60.0;
        double speed = distance / timeHours;

        double MET = 9.8; 

        return MET * 70 * timeHours; 
    }
};

class Cycling : public Activity {
    double speed; 
    double time;  
public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() override {
        double MET = 6.8; 

        return MET * 70 * time; 
    }
};

int main() {
    Running r(5.0, 30.0);     
    Cycling c(18.0, 1.0);      

    cout << "Calories burned (Running): " << r.calculateCaloriesBurned() << " kcal" << endl;
    cout << "Calories burned (Cycling): " << c.calculateCaloriesBurned() << " kcal" << endl;

    return 0;
}
