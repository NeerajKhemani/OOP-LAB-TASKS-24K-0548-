#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; 

public:
    Currency(double amt, const string& code, const string& symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual ~Currency() {}

    virtual double convertToBase() const {
        return amount * exchangeRate; 
    }

    virtual double convertTo(const Currency& targetCurrency) const {
        double baseAmount = this->convertToBase(); 
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << fixed << setprecision(2);
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
    string getSymbol() const { return currencySymbol; }
    string getCode() const { return currencyCode; }
    double getRate() const { return exchangeRate; }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() const override {
        cout << "US Dollar: ";
        Currency::displayCurrency();
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.08) {}

    void displayCurrency() const override {
        cout << "Euro: ";
        Currency::displayCurrency();
    }
};

class PakistaniRupee : public Currency {
public:
    PakistaniRupee(double amt) : Currency(amt, "PKR", "Rs", 0.0036) {}

    void displayCurrency() const override {
        cout << "Pakistani Rupee: ";
        Currency::displayCurrency();
    }
};

int main() {
    Dollar d(50);               
    Euro e(100);               
    PakistaniRupee pkr(1000);   

    cout << "---- Currency Details ----\n";
    d.displayCurrency();
    e.displayCurrency();
    pkr.displayCurrency();

    cout << "\n---- Conversions ----\n";

    cout << fixed << setprecision(2);

    cout << "50 USD in PKR = " << pkr.getSymbol() << d.convertTo(pkr) << endl;
    cout << "100 EUR in PKR = " << pkr.getSymbol() << e.convertTo(pkr) << endl;
    cout << "1000 PKR in USD = " << d.getSymbol() << pkr.convertTo(d) << endl;
    cout << "1000 PKR in EUR = " << e.getSymbol()  << pkr.convertTo(e) << endl;

    return 0;
}
