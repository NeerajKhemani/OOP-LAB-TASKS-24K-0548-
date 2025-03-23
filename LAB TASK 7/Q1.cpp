#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int number, double initialBalance, const string& holder, const string& type = "General")
        : accountNumber(number), balance(initialBalance), accountHolderName(holder), accountType(type) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    virtual double calculateInterest() const = 0;
    virtual void printStatement() const = 0;

    virtual void getAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int number, double initialBalance, const string& holder,
                   double rate, double minBalance)
        : Account(number, initialBalance, holder, "Savings"),
          interestRate(rate), minimumBalance(minBalance) {}

    double calculateInterest() const override {
        return balance * interestRate;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw: minimum balance requirement not met." << endl;
        }
    }

    void printStatement() const override {
        cout << "--- Savings Account Statement ---" << endl;
        getAccountInfo();
        cout << "Interest: " << calculateInterest() << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int number, double initialBalance, const string& holder)
        : Account(number, initialBalance, holder, "Checking") {}

    double calculateInterest() const override {
        return 0.0; // No interest for checking accounts
    }

    void printStatement() const override {
        cout << "--- Checking Account Statement ---" << endl;
        getAccountInfo();
    }
};

class FixedDepositAccount : public Account {
private:
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(int number, double initialBalance, const string& holder,
                        const string& maturity, double rate)
        : Account(number, initialBalance, holder, "Fixed Deposit"),
          maturityDate(maturity), fixedInterestRate(rate) {}

    double calculateInterest() const override {
        return balance * fixedInterestRate;
    }

    void withdraw(double amount) override {
        cout << "Withdrawals not allowed before maturity date: " << maturityDate << endl;
    }

    void printStatement() const override {
        cout << "--- Fixed Deposit Account Statement ---" << endl;
        getAccountInfo();
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest: " << calculateInterest() << endl;
    }
};

int main() {
    SavingsAccount sa(1001, 5000, "Faiz", 0.03, 1000);
    CheckingAccount ca(1002, 2000, "Ali");
    FixedDepositAccount fda(1003, 10000, "Neeraj", "2026-01-01", 0.05);

    sa.deposit(1000);
    sa.withdraw(3000);
    sa.printStatement();
    cout << endl;

    ca.deposit(500);
    ca.withdraw(1000);
    ca.printStatement();
    cout << endl;

    fda.deposit(2000);
    fda.withdraw(1000);
    fda.printStatement();

    return 0;
}
