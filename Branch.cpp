#include "Branch.h"
#include <iostream>
using namespace std;

Branch::Branch() : city(""), branchCode(0), accountCount(0), size(5)
{
    account = new Account*[size];
}

Branch::Branch(string branchCity, int code) : city(branchCity), branchCode(code), accountCount(0), size(5)
{
    account = new Account*[size];
}

Branch::Branch(const Branch& other) : city(other.city), branchCode(other.branchCode), size(other.size), accountCount(other.accountCount)
{
    account = new Account*[size];
    for (int i = 0; i < accountCount; i++)
        account[i] = other.account[i];  // Shallow copy
}

Branch& Branch::operator=(const Branch& other)
{
    if (this != &other)
    {
        delete[] account;
        city = other.city;
        branchCode = other.branchCode;
        size = other.size;
        accountCount = other.accountCount;
        account = new Account*[size];
        for (int i = 0; i < accountCount; i++)
            account[i] = other.account[i];  // Shallow copy
    }
    return *this;
}

Branch::~Branch()
{
    for (int i = 0; i < accountCount; i++)
        delete account[i];
    delete[] account;
}

void Branch::addAccount(Account* newAccount)
{
    if (accountCount < size)
    {
        account[accountCount++] = newAccount;
    }
    else
    {
        cout << "Cannot add more accounts. Limit reached.\n\n";
    }
}

void Branch::removeAccount(const int accNum)
{
    int i = 0;
    while (i < accountCount && account[i]->getAccountNum() != accNum)
        i++;

    if (i == accountCount)
    {
        cout << "Account not found.\n";
        return;
    }

    while (i < accountCount - 1)
    {
        account[i] = account[i + 1];
        i++;
    }
    --accountCount;
    cout << "Account removed successfully.\n\n";
}

void Branch::showDetails()
{
    cout << city << " Branch Details:\n";
    cout << "Branch Code: " << branchCode << endl;

    if (accountCount == 0)
    {
        cout << "No accounts in this branch.\n";
    }
    else
    {
        cout << "Accounts:\n";
        for (int i = 0; i < accountCount; i++)
        {
            cout << "  Account Number: " << account[i]->getAccountNum() << endl;
        }
    }
    cout << endl;
}

Account* Branch::getAccountPtr(int accountNum)
{
    for (int i = 0; i < accountCount; i++)
        if (account[i]->getAccountNum() == accountNum)
            return account[i];
    return nullptr;
}

void Branch::setBranchCode(const int& branchCode)
{
    this->branchCode = branchCode;
}

int Branch::getBranchCode() const
{
    return branchCode;
}

void Branch::setBranchCity(const string& city)
{
    this->city = city;
}

string Branch::getBranchCity() const
{
    return city;
}
