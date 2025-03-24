#include <iostream>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void calculateInterest() = 0;
    virtual void withdraw(double amount) = 0;

    double getBalance() const { return balance; } 

    void deposit(double amount, string type = "default") {
        cout << "Deposit via " << type << ": Rs" << amount << endl;
        balance += amount;
    }

    virtual BankAccount* operator+(const BankAccount& other) const = 0;
    virtual BankAccount* operator-(double amount) const = 0;
    virtual BankAccount* operator*(double rate) const = 0;
    virtual BankAccount* operator/(int months) const = 0;

    friend ostream& operator<<(ostream& out, const BankAccount& acc) {
        out << "Account Number: " << acc.accountNumber << " | Balance: Rs" << acc.balance;
        return out;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void calculateInterest() override {
        balance += balance * 0.05;
    }

    void withdraw(double amount) override {
        if (balance - amount < 500) {
            cout << "Withdrawal denied! Minimum balance requirement of Rs500 not met.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
    }

    BankAccount* operator+(const BankAccount& other) const override {
        return new SavingsAccount("Merged", balance + other.getBalance());
    }

    BankAccount* operator-(double amount) const override {
        return new SavingsAccount(accountNumber, balance - amount);
    }

    BankAccount* operator*(double rate) const override {
        return new SavingsAccount(accountNumber, balance * rate);
    }

    BankAccount* operator/(int months) const override {
        return new SavingsAccount(accountNumber, balance / months);
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accNum, double bal) : BankAccount(accNum, bal) {}

    void calculateInterest() override {}

    void withdraw(double amount) override {
        if (balance - amount < -1000) {
            cout << "Overdraft limit exceeded! Withdrawal denied.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
    }

    BankAccount* operator+(const BankAccount& other) const override {
        return new CurrentAccount("Merged", balance + other.getBalance());
    }

    BankAccount* operator-(double amount) const override {
        return new CurrentAccount(accountNumber, balance - amount);
    }

    BankAccount* operator*(double rate) const override {
        return new CurrentAccount(accountNumber, balance * rate);
    }

    BankAccount* operator/(int months) const override {
        return new CurrentAccount(accountNumber, balance / months);
    }
};

int main() {
    SavingsAccount savings("SA123", 1000);
    CurrentAccount current("CA456", 500);

    cout << "Initial Balances:\n" << savings << "\n" << current << "\n\n";

    savings.deposit(500, "cash");
    current.deposit(700, "online transfer");

    cout << "After Deposits:\n" << savings << "\n" << current << "\n\n";

    savings.withdraw(1200);
    current.withdraw(1300);

    cout << "After Withdrawals:\n" << savings << "\n" << current << "\n\n";

    savings.calculateInterest();
    cout << "After Interest Calculation (Savings Account):\n" << savings << "\n\n";

    BankAccount* total = savings + current;
    cout << "Combined Balance:\n" << *total << "\n\n";

    delete total;
    return 0;
}
