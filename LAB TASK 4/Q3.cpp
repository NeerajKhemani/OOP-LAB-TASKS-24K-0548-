#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account() {
        balance = 0.0;
    }

    Account(string accountNumber, string accountHolderNamee, double balance) {
        this->accountNumber =  accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    } 

   
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

   
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawn: " << amount << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

   
    void checkBalance() const {
        cout << "Account Balance: " << balance << endl;
    }
};

int main() {
    Account account1("1001", "Ali", 1000.0);
    Account account2("1002", "Neeraj", 500.0);

    account1.checkBalance();
    account1.deposit(200.0);
    account1.withdraw(150.0);
    account1.checkBalance();

    account2.checkBalance();
    account2.deposit(100.0);
    account2.withdraw(600.0);
    account2.checkBalance();

    return 0;
}

