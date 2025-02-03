#include <iostream>
using namespace std;

class Time {
    public:
    int hours;
    int minutes;
    int seconds;
    
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
        }
    Time(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
    
     }
    void display() {
    	 if(hours>12){
    	 	 hours = hours - 12 ;
    	 	cout << hours << ":" << minutes << ":" << seconds << " pm" << endl;
		  }
		else {
            cout << hours << ":" << minutes << ":" << seconds << " am" << endl;
            }
        }
    Time add(const Time &t) {
                Time temp;
                temp.hours = hours + t.hours;
                temp.minutes = minutes + t.minutes;
                temp.seconds = seconds + t.seconds;
                if (temp.seconds > 59) {
                    temp.seconds = temp.seconds - 60;
                    temp.minutes = temp.minutes + 1;
                    }
                    if (temp.minutes > 59) {
                        temp.minutes = temp.minutes - 60;
                        temp.hours = temp.hours + 1;
                        }
                        return temp;
                        }
                        };


int main() {
    Time t1(11, 30, 27); 
    Time t2(1, 15, 34);
    Time t3 = t1.add(t2);
     
    cout << "t3 = ";
    t3.display();
    return 0;
    
}
