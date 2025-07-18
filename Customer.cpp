#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer() : custID(0), name(""), address("") {}

Customer::Customer(int id, string n, string a, int accNo, int bal, string date)
    : Account(accNo, bal),
      Loan(accNo, bal),
      SavingAccount(accNo, bal, 0.0, date),
      CooperateAccount(accNo, bal, 0.0, date),
      custID(id), name(n), address(a) {}

void Customer::setAddress(const string& address)
{
    this->address = address;
}

string Customer::getAddress() const
{
    return address;
}

void Customer::showCustomerDetails() const
{
    cout << "\n====== Customer Details ======\n";
    cout << "CustomerID: " << custID << endl;
    cout << "Name      : " << name << endl;
    cout << "Address   : " << address << endl;
    cout << "Account # : " << getAccountNum() << endl;
    cout << "Balance   : " << getBalance() << endl;
    cout << "===============================\n";
}

void Customer::showAllAccountDetails()
{
    showCustomerDetails();
    showStatus();
    showCorporateAccountInfo();
    showLoanHistory();
    showTotalLoan();
}
