#include "Loan.h"
#include <iostream>

using namespace std;

Loan::Loan() : Account(), totalLoansTaken(0), totalAmount(0.0), typeCount(0) {}

Loan::Loan(int accNo, int bal) : Account(accNo, bal), totalLoansTaken(0), totalAmount(0.0), typeCount(0) {}

void Loan::takeLoan(float amount, const string& reason)
{
    if (typeCount < 5)
    {
        totalAmount += amount;
        types[typeCount++] = reason;
        totalLoansTaken++;
        cout << "Loan of " << amount << " taken for: " << reason << endl;
    }
    else
    {
        cout << "Loan limit reached. Cannot take more than 5 loans per account.\n";
    }
}

void Loan::repayLoan(float amount)
{
    if (amount <= 0)
    {
        cout << "Invalid repayment amount.\n";
    }
    else if (amount > totalAmount)
    {
        cout << "You are trying to repay more than your total loan amount.\n";
    }
    else
    {
        totalAmount -= amount;
        cout << "Repayment of " << amount << " successful. Remaining Loan: " << totalAmount << endl;
    }
}

void Loan::showLoanHistory() const
{
    cout << "Loan History (Reasons):\n";
    for (int i = 0; i < typeCount; i++)
    {
        cout << "  - " << types[i] << endl;
    }
}

void Loan::showTotalLoan() const
{
    cout << "Total Loan Amount: " << totalAmount << endl;
}

void Loan::displayLoanCount() const
{
    cout << "Total loans taken by this customer: " << totalLoansTaken << endl;
}
