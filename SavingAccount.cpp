#include "SavingAccount.h"
#include <iostream>

using namespace std;

SavingAccount::SavingAccount() : Account(), minBalance(0.0), openingDate("") {}

SavingAccount::SavingAccount(int accNo, int bal, float minBal, string openDate)
    : Account(accNo, bal), minBalance(minBal), openingDate(openDate) {}

bool SavingAccount::isBelowMinimum() const
{
    return getBalance() < minBalance;
}

void SavingAccount::showStatus() const
{
    cout << "Saving Account Status:" << endl 
         << "  Opening Date: " << openingDate << endl 
         << "  Minimum Required Balance: " << minBalance << endl
         << "  Current Balance: " << getBalance() << endl;

    if (isBelowMinimum())
        cout << "  Warning: Balance is below the required minimum!" << endl;
    else
        cout << "  Balance is healthy." << endl;
}

void SavingAccount::updateMinimumBalance(float newMin)
{
    if (newMin > 0)
    {
        minBalance = newMin;
        cout << "Minimum balance updated to " << minBalance << endl;
    }
    else
    {
        cout << "Invalid minimum balance.\n";
    }
}

string SavingAccount::getOpeningDate() const
{
    return openingDate;
}
