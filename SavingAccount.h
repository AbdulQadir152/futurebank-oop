#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include <string>
#include "Account.h"

class SavingAccount : virtual public Account
{
protected:
    float minBalance;
    std::string openingDate;

public:
    SavingAccount();
    SavingAccount(int accNo, int bal, float minBal, std::string openDate);

    bool isBelowMinimum() const;
    void showStatus() const;
    void updateMinimumBalance(float newMin);
    std::string getOpeningDate() const;
};

#endif
