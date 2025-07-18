#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include "Account.h"

class Branch
{
private:
    std::string city;
    int branchCode;
    Account** account;
    int accountCount;
    int size;

public:
    Branch();
    Branch(std::string branchCity, int code);
    Branch(const Branch& other);
    Branch& operator=(const Branch& other);
    ~Branch();

    void addAccount(Account* newAccount);
    void removeAccount(int accNum);
    void showDetails();
    Account* getAccountPtr(int accountNum);

    void setBranchCode(const int& branchCode);
    int getBranchCode() const;
    void setBranchCity(const std::string& city);
    std::string getBranchCity() const;
};

#endif
