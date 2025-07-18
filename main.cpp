#include <iostream>
#include <string>
#include "Bank.h"
#include "Branch.h"
#include "Customer.h"

using namespace std;

int main()
{
    Bank myBank("FutureBank", "Islamabad", 101);
    int choice;

    while (true)
    {
        cout << "\n========= FutureBank Menu =========\n";
        cout << "1. Add New Branch\n";
        cout << "2. Add New Customer to Branch\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Take Loan\n";
        cout << "6. Repay Loan\n";
        cout << "7. Apply Annual Interest\n";
        cout << "8. Show Customer Details\n";
        cout << "9. Show Branch Details\n";
        cout << "10. Show All Branches\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        int branchCode, accNum, bal;
        string name, city, address, reason, openDate;
        float amount, rate;
        Account* accPtr;
        Branch* branchPtr;
        Customer* cust;

        switch (choice)
        {
            case 1:
                cout << "\nEnter city(location) of Branch: ";
                cin >> city;
                cout << "Enter branch code: ";
                cin >> branchCode;
                myBank.addBranch(city, branchCode);
                break;

            case 2:
            {
                cout << "\nEnter branch code: ";
                cin >> branchCode;
                branchPtr = myBank.getBranchPtr(branchCode);
                if (!branchPtr)
                {
                   cout << "Branch not found.\n";
                   break;
                }

                int id, accNo;
                float minBal;
                cout << "Enter customer ID: ";
                cin >> id;
                cout << "Enter customer name: ";
                cin.ignore(); // Clear newline before getline
                getline(cin, name);
                cout << "Enter customer address: ";
                getline(cin, address);
                cout << "Enter account number: ";
                cin >> accNo;
                cout << "Enter initial balance: ";
                cin >> bal;
                cout << "Enter account opening date (DD-MM-YYYY): ";
                cin.ignore();
                getline(cin, openDate);
                cout << "Enter minimum balance for Saving Account: ";
                cin >> minBal;

                cust = new Customer(id, name, address, accNo, bal, openDate);
                cust->updateMinimumBalance(minBal);

                branchPtr->addAccount(cust);
                cout << "Customer added.\n";
                break;
            }

            case 3:
                cout << "\nEnter branch code and account number: ";
                cin >> branchCode >> accNum;
                branchPtr = myBank.getBranchPtr(branchCode);
                if (!branchPtr || !(accPtr = branchPtr->getAccountPtr(accNum)))
                {
                    cout << "Invalid branch/account.\n";
                    break;
                }
                cout << "Enter amount to deposit: ";
                cin >> bal;
                accPtr->deposit(bal);
                break;

            case 4:
                cout << "\nEnter branch code and account number: ";
                cin >> branchCode >> accNum;
                branchPtr = myBank.getBranchPtr(branchCode);
                if (!branchPtr || !(accPtr = branchPtr->getAccountPtr(accNum)))
                {
                    cout << "Invalid branch/account.\n";
                    break;
                }
                cout << "Enter amount to withdraw: ";
                cin >> bal;
                accPtr->withdraw(bal);
                break;

            case 5:
                cout << "\nEnter branch code and account number: ";
                cin >> branchCode >> accNum;
                branchPtr = myBank.getBranchPtr(branchCode);
                accPtr = branchPtr ? branchPtr->getAccountPtr(accNum) : nullptr;
                cust = dynamic_cast<Customer*>(accPtr);
                if (!cust)
                {
                    cout << "Customer not found or invalid type.\n";
                    break;
                }
                cout << "Enter loan amount and reason: ";
                cin >> amount;
                cin.ignore();
                getline(cin, reason);
                cust->takeLoan(amount, reason);
                break;

            case 6:
                cout << "\nEnter branch code and account number: ";
                cin >> branchCode >> accNum;
                branchPtr = myBank.getBranchPtr(branchCode);
                accPtr = branchPtr ? branchPtr->getAccountPtr(accNum) : nullptr;
                cust = dynamic_cast<Customer*>(accPtr);
                if (!cust)
                {
                    cout << "Customer not found or invalid type.\n";
                    break;
                }
                cout << "Enter repayment amount: ";
                cin >> amount;
                cust->repayLoan(amount);
                break;

            case 7:
                cout << "\nEnter branch code and account number: ";
                cin >> branchCode >> accNum;
                branchPtr = myBank.getBranchPtr(branchCode);
                accPtr = branchPtr ? branchPtr->getAccountPtr(accNum) : nullptr;
                cust = dynamic_cast<Customer*>(accPtr);
                if (!cust)
                {
                    cout << "Customer not found or invalid type.\n";
                    break;
                }
                cout << "Enter new interest rate: ";
                cin >> rate;
                cust->updateInterestRate(rate);
                cust->applyAnnualInterest();
                break;

            case 8:
                cout << "\nEnter branch code and account number: ";
                cin >> branchCode >> accNum;
                branchPtr = myBank.getBranchPtr(branchCode);
                accPtr = branchPtr ? branchPtr->getAccountPtr(accNum) : nullptr;
                cust = dynamic_cast<Customer*>(accPtr);
                if (cust)
                    cust->showAllAccountDetails();
                else
                    cout << "Customer not found.\n";
                break;

            case 9:
                cout << "\nEnter branch code: ";
                cin >> branchCode;
                myBank.getBranch(branchCode);
                break;

            case 10:
                myBank.getAllBranch();
                break;

            default:
                cout << "Invalid option.\n";
        }
    }

    cout << "Exiting... Thank you!\n";
    return 0;
}
