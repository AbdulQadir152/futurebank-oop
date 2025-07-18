#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    int accountNum;
    int balance;

public:
    Account();
    Account(int code, int accountBalance);

    void deposit(int amount);
    void withdraw(int amount);
    void viewCurrentBalance() const;

    void setBalance(int balance);
    int getBalance() const;

    void setAccountNum(int accountNum);
    int getAccountNum() const;

    virtual ~Account();
};

#endif
