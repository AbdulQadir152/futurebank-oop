#ifndef COOPERATEACCOUNT_H
#define COOPERATEACCOUNT_H

#include <string>
#include "Account.h"

class CooperateAccount : virtual public Account
{
protected:
    float interestRate;
    std::string openingDate;

public:
    CooperateAccount();
    CooperateAccount(int accNo, int bal, float intRate, std::string openDate);

    void applyAnnualInterest();
    void updateInterestRate(float newRate);
    void showCorporateAccountInfo() const;
};

#endif
