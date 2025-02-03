#include <iostream>
#include <conio.h>
using namespace std;

class tollBooth{
    private:
    unsigned int totalCars;
    double totalCash;
    public:
    tollBooth(){
        totalCars = 0;
        totalCash = 0;
        }
    void payingCar(){
        totalCars++;
            totalCash += 0.50;
            }
    void nopayCar(){
        totalCars++;
            }
    void display() const{
        cout << "Total Cars: " << totalCars << endl;
        cout << "Total Cash: $" << totalCash << endl;
            }
        };
int main(){
    tollBooth toll;
    char choice;
    while (choice != 27) {
        cout << "Press 'p' for paying car, 'n' for nonpaying car" << endl;
        choice = _getch();
        switch (choice) {
                case 'p':
                case 'P':
                    toll.payingCar();
                    break;
                case 'n':
                case 'N':
                    toll.nopayCar();
                    break;
                case 27:
				     toll.display();
					 break;    
                default:
                    cout << "Invalid choice. Please try again." << endl;
                        }
    }

}
