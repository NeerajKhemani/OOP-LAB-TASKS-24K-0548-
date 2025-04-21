#include <iostream>
using namespace std;

class PaymentMethod{
 public:
 virtual void processPayment(double amount) = 0;

};

class CreditCard : public PaymentMethod{
  string cardNumber;
  public:
  CreditCard(string Number) : cardNumber(Number) {}
  void processPayment(double amount){
     if (amount > 0){
        cout << "Payment processed successfully" << endl;
     }
     else{
        cout << "Invalid amount. Can't process payment" << endl;
     }
  }
};

class DigitalWallet : public PaymentMethod{
  double balance;
  public:
  DigitalWallet (double initialbalance) : balance(initialbalance) {}
  void processPayment(double amount){
    if (amount < 0){
        cout << "Invalid amount. Can't process payment" << endl;
    }
    else if (balance >= amount){
        balance = balance - amount;
       cout << "Payment processed successfully. Remaining balance: " << balance << endl;
    }
    else{
       cout << "Not enough funds. Can't process payment" << endl;
    }
 }
};

int main(){
    CreditCard c1("ABC-001"),c2("XYZ-002");
    DigitalWallet d1(50000.00),d2(30000.00);

    c1.processPayment(3000.00);
    c2.processPayment(-5000.00);

    d1.processPayment(40000.00);
    d2.processPayment(50000.00);

}