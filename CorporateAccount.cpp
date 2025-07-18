#include "CorporateAccount.h"
#include <iostream>

using namespace std;

CorporateAccount::CorporateAccount() : Account(), interestRate(0.0), openingDate("") {}

CorporateAccount::CorporateAccount(int accNo, int bal, float intRate, string openDate)
    : Account(accNo, bal), interestRate(intRate), openingDate(openDate) {}

void CorporateAccount::applyAnnualInterest()
{
    int balanceBefore = getBalance();
    int interest = static_cast<int>(balanceBefore * interestRate / 100);
    deposit(interest);
    cout << "Annual interest of " << interest << " applied at rate " << interestRate << "%.\n";
}

void CorporateAccount::updateInterestRate(float newRate)
{
    if (newRate >= 0.0)
    {
        interestRate = newRate;
        cout << "Interest rate updated to " << interestRate << "%.\n";
    }
    else
    {
        cout << "Invalid interest rate.\n";
    }
}

void CorporateAccount::showCorporateAccountInfo() const
{
    cout << "Corporate Account Info:\n";
    cout << "  Opening Date: " << openingDate << endl;
    cout << "  Interest Rate: " << interestRate << "%" << endl;
    cout << "  Current Balance: " << getBalance() << endl;
}
