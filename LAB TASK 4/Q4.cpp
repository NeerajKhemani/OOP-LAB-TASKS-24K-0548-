#include <iostream>

using namespace std;
class Car{
	int carID;
	string model;
    int year;
    bool isRented;
    
    public :
    Car(){
    	isRented = false;
	}
	Car(int carID, string model, int year){
		this->carID = carID;
		this->model = model;
		this->year = year;
		isRented = false;
	}
	void rentCar() {
        if (!isRented) {
            isRented = true;
            cout << "Car " << model << " (ID: " << carID << ") has been rented.\n";
        } else {
            cout << "Car " << model << " (ID: " << carID << ") is already rented.\n";
        }
    }
	void returnCar() {
        if (isRented) {
            isRented = false;
            cout << "Car " << model << " (ID: " << carID << ") has been returned.\n";
        } else {
            cout << "Car " << model << " (ID: " << carID << ") is already available.\n";
        }
    }
	bool isVintage() {
        return year < 2000;
    }
	void displayCarDetails() {
        cout << "Car ID: " << carID << ", Model: " << model << ", Year: " << year 
                  << ", Status: " << (isRented ? "Rented" : "Available") << "\n";
    }
};

 int main(){
    Car car1(1, "Toyota Corolla", 1998);
    Car car2(2, "Honda Civic", 2005);
    Car car3(3, "Ford Mustang", 1965);

    car1.displayCarDetails();
    car2.displayCarDetails();
    car3.displayCarDetails();
   
    car1.rentCar();
    car2.rentCar();
    car3.rentCar();

    car1.displayCarDetails();
    car2.displayCarDetails();
    car3.displayCarDetails();
 
    car1.returnCar();
    car2.returnCar();
    car3.returnCar();

    cout << "Is car1 vintage? " << (car1.isVintage() ? "Yes" : "No") << "\n";
    cout << "Is car2 vintage? " << (car2.isVintage() ? "Yes" : "No") << "\n";
    cout << "Is car3 vintage? " << (car3.isVintage() ? "Yes" : "No") << "\n";

    return 0;
 }
