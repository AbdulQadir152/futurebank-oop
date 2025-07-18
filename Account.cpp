#include "Account.h"
#include <iostream>

using namespace std;

Account::Account() : accountNum(0), balance(0) {}

Account::Account(int code, int accountBalance) : accountNum(code), balance(accountBalance) {}

void Account::deposit(int amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "Amount " << amount << " has been deposited." << endl;
    }
    else
    {
        cout << "Invalid deposit amount. Must be greater than 0." << endl;
    }
}

void Account::withdraw(int amount)
{
    if (amount <= 0)
    {
        cout << "Please enter a valid withdrawal amount." << endl;
    }
    else if (amount > balance)
    {
        cout << "Not enough balance." << endl;
    }
    else
    {
        balance -= amount;
        cout << "Amount " << amount << " has been withdrawn." << endl;
    }
}

void Account::viewCurrentBalance() const
{
    cout << "Current Balance: " << balance << endl;
}

void Account::setBalance(int balance)
{
    this->balance = balance;
}

int Account::getBalance() const
{
    return balance;
}

void Account::setAccountNum(int accountNum)
{
    this->accountNum = accountNum;
}

int Account::getAccountNum() const
{
    return accountNum;
}

Account::~Account() {}
