#include <iostream>
#include <string>
using namespace std;

class Account {
    string accountNumber;
    string accountHolder;
    double balance;
public:
    Account(string accNum, string holder, double bal) : accountNumber(accNum), accountHolder(holder), balance(bal) {}
    
    Account operator+(const Account &acc) {
        return Account("", "", balance + acc.balance);
    }
    
    Account &operator-=(double amount) {
        balance -= amount;
        return *this;
    }
    
    bool operator>(const Account &acc) const {
        return balance > acc.balance;
    }
    
    friend ostream &operator<<(ostream &out, const Account &acc) {
        out << "Account Number: " << acc.accountNumber << " | Holder: " << acc.accountHolder << " | Balance: $" << acc.balance;
        return out;
    }
    
    void displayBalance() {
        cout << accountHolder << "'s New Balance: " << balance << endl;
    }
    
    void transferAmount(Account &to, double amount) {
        *this -= amount;
        to.balance += amount;
    }
    
    string getHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account acc1("101", "Shafique Rehman", 5000);
    Account acc2("102", "Talha", 3000);
    
    cout << "Performing:" << endl;
    cout << "1. Adding Account 1 and Account 2 balances." << endl;
    Account totalBalance = acc1 + acc2;
    cout << "Total Balance (After Addition): " << totalBalance.getBalance() << endl;
    
    cout << "\n2. Transferring 2000 from Account 1 to Account 2." << endl;
    acc1.transferAmount(acc2, 2000);
    cout << "After Transfer:" << endl;
    acc1.displayBalance();
    acc2.displayBalance();
    
    cout << "\n3. Checking which account has a higher balance." << endl;
    if (acc1 > acc2)
        cout << acc1.getHolder() << " has more balance than " << acc2.getHolder() << "." << endl;
    else
        cout << acc1.getHolder() << " has less balance than " << acc2.getHolder() << "." << endl;
    
    cout << "\n4. Displaying final account details." << endl;
    cout << acc1 << endl;
    cout << acc2 << endl;
    
    return 0;
}
