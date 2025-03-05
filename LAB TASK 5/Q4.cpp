#include <iostream>
using namespace std;

class BankAccount {
    int accountNumber;
    string accountHolderName;
    double balance;

    public:
    BankAccount(int number, string name, double balance) {
        accountNumber = number;
        accountHolderName = name;
        this->balance = balance;
    }
  
    void deposit(double amount){
        if(amount > 0){
             balance += amount;
             cout << "Rs." << amount << " is deposited into account." << endl;
        }
        else{
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount){
        if(amount > 0){
            if(balance > amount){
                 balance -= amount;
                 cout << "Rs." << amount << " is withdrawed from account." << endl;
            }     
            else{
                 cout << "Not Enough Balance." << endl;
            }
        }
        else{
            cout << "Invalid withdraw amount." << endl;
        }
    }
    void display(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Current Balance: " << balance << endl;
    }
};
    
int main() {
    BankAccount accounts[3] = {
            BankAccount(101, "Neeraj", 1000.0),
            BankAccount(102, "Ali", 1500.0),
            BankAccount(103, "Faiz", 2000.0)
        };
    
        for (int i = 0; i < 3; i++) {
            cout << "\nInitial details of account " << i + 1 << ":\n";
            accounts[i].display();
    
            accounts[i].deposit(500.0);
            accounts[i].display();
    
            accounts[i].withdraw(200.0);
            accounts[i].display();
        }
    
        return 0;
    }

