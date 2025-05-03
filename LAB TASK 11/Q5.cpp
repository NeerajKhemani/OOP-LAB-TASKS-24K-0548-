#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class InsufficientFundsException : public exception {
    string message;

public:
    InsufficientFundsException(double deficit) {
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << "InsufficientFundsException - Deficit: $" << deficit;
        message = oss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class BankAccount {
private:
    T balance;

public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    void withdraw(T amount) {
        if (amount > balance) {
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
    }

    T getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount<double> account(500.00);

    cout << "Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;

    try {
        account.withdraw(600.00);
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    }

    return 0;
}