#ifndef LOAN_H
#define LOAN_H

#include <string>
#include "Account.h"

class Loan : virtual public Account
{
protected:
    int totalLoansTaken;
    float totalAmount;
    std::string types[5];
    int typeCount;

public:
    Loan();
    Loan(int accNo, int bal);

    void takeLoan(float amount, const std::string& reason);
    void repayLoan(float amount);
    void showLoanHistory() const;
    void showTotalLoan() const;
    void displayLoanCount() const;
};

#endif
