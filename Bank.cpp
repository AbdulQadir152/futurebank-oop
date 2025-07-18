#include "Bank.h"
#include <iostream>

using namespace std;

Bank::Bank() : name(""), location(""), bankCode(0), branchCount(0), size(5)
{
    branch = new Branch*[size];
}

Bank::Bank(string bankName, string bankLocation, int code) : name(bankName), location(bankLocation), bankCode(code), branchCount(0), size(10)
{
    branch = new Branch*[size];
}

Bank::Bank(const Bank& other) : name(other.name), location(other.location), bankCode(other.bankCode), size(other.size), branchCount(other.branchCount)
{
    branch = new Branch*[size];
    for(int i = 0; i < branchCount; i++)
        branch[i] = new Branch(*other.branch[i]);
}

Bank& Bank::operator=(const Bank &other)
{
    if(this != &other)
    {
        for (int i = 0; i < branchCount; i++)
            delete branch[i];
        delete[] branch;

        name = other.name;
        location = other.location;
        bankCode = other.bankCode;
        size = other.size;
        branchCount = other.branchCount;

        branch = new Branch*[size];
        for(int i = 0; i < branchCount; i++)
            branch[i] = new Branch(*other.branch[i]);
    }
    return *this;
}

Bank::~Bank()
{
    for (int i = 0; i < branchCount; i++)
        delete branch[i];
    delete[] branch;
}

void Bank::addBranch(string city, int code)
{
    if (branchCount < size)
        branch[branchCount++] = new Branch(city, code);
    else
        cout << "Cannot add more branches.\n";
}

void Bank::removeBranch(int branchCode)
{
    for(int i = 0; i < branchCount; ++i)
    {
        if(branch[i]->getBranchCode() == branchCode)
        {
            delete branch[i];
            for (int j = i; j < branchCount - 1; ++j)
                branch[j] = branch[j + 1];
            --branchCount;
            cout << "Branch removed.\n\n";
            return;
        }
    }
    cout << "Branch not found.\n";
}

void Bank::getBranch(int searchCode) const
{
    for(int i = 0; i < branchCount; i++)
    {
        if(branch[i]->getBranchCode() == searchCode)
        {
            branch[i]->showDetails();
            return;
        }
    }
    cout << "Branch not found.\n";
}

void Bank::getAllBranch() const
{
    if(branchCount == 0)
    {
        cout << "No branch currently present:\n";
        return;
    }

    cout << "\n========== " << name << " Bank Branches ==========\n";
    for(int i = 0; i < branchCount; i++)
        branch[i]->showDetails();
    cout << "====================================\n\n";
}

Branch* Bank::getBranchPtr(int searchCode)
{
    for (int i = 0; i < branchCount; i++)
        if (branch[i]->getBranchCode() == searchCode)
            return branch[i];
    return nullptr;
}

void Bank::setBankName(const string& name)
{
    this->name = name;
}

string Bank::getBankName() const
{
    return name;
}

void Bank::setBankLocation(const string& location)
{
    this->location = location;
}

string Bank::getBankLocation() const
{
    return location;
}
