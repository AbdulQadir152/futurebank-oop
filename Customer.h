#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Loan.h"
#include "SavingAccount.h"
#include "CooperateAccount.h"

class Customer : public Loan, public SavingAccount, public CooperateAccount
{
private:
    int custID;
    std::string name;
    std::string address;

public:
    Customer();
    Customer(int id, std::string n, std::string a, int accNo, int bal, std::string date);

    void setAddress(const std::string& address);
    std::string getAddress() const;

    void showCustomerDetails() const;
    void showAllAccountDetails();
};

#endif
