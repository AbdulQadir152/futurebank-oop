#ifndef BANK_H
#define BANK_H

#include <string>
#include "Branch.h"

class Bank 
{
private:
    std::string name;
    std::string location;
    int bankCode;
    Branch** branch;
    int branchCount;
    int size;

public:
    Bank();
    Bank(std::string bankName, std::string bankLocation, int code);
    Bank(const Bank& other);
    Bank& operator=(const Bank& other);
    ~Bank();

    void addBranch(std::string city, int code);
    void removeBranch(int branchCode);
    void getBranch(int searchCode) const;
    void getAllBranch() const;
    Branch* getBranchPtr(int searchCode);

    void setBankName(const std::string& name);
    std::string getBankName() const;
    void setBankLocation(const std::string& location);
    std::string getBankLocation() const;
};

#endif
