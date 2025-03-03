#include <iostream>
using namespace std;

class LoanHelper {
	private:
    double loanAmount;
    int repaymentMonths;
public:
    const double interestRate;

    LoanHelper(double loanAmount, int repaymentMonths , const double interestRate)   : loanAmount(loanAmount), repaymentMonths(repaymentMonths), interestRate(interestRate) {}

    double calculateMonthlyPayment() {
        double monthlyPayment = loanAmount / repaymentMonths;
        double monthlyInterest = monthlyPayment * (interestRate/100);
        return monthlyPayment + monthlyInterest;
    }

    string getRepaymentMessage() {
        double monthlyPayment = calculateMonthlyPayment();
        cout <<  "You have to pay " << monthlyPayment << " every month for " << repaymentMonths << " months to repay your loan." << endl;
    }


};

int main() {
    LoanHelper loanHelper(100000, 12 , 0.5);
    cout << loanHelper.getRepaymentMessage() << endl;
    return 0;
}

