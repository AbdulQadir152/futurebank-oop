#ifndef CORPORATEACCOUNT_H
#define CORPORATEACCOUNT_H

#include <string>
#include "Account.h"

class CorporateAccount : virtual public Account
{
protected:
    float interestRate;
    std::string openingDate;

public:
    CorporateAccount();
    CorporateAccount(int accNo, int bal, float intRate, std::string openDate);

    void applyAnnualInterest();
    void updateInterestRate(float newRate);
    void showCorporateAccountInfo() const;
};

#endif
