//xyz Bank Account Management System
//This file defines the Account class and its core banking operations such as deposits and withdrwals
#include <iostream>
using namespace std;

class Account
{
private:
    double balance;

public:
    Account(double initialBalance)
    {
        if (initialBalance >= 1000.00)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0;
            cout << "Warning: Initial balance invalid. Balance set to $0.00" << endl;
        }
    }

    //deposit money
    void Deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }
//Withdraws money from the account
    //withdraw function
    void Withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Debit amount exceeded account balance." << endl;
        }
        else if (amount <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << endl;
        }
    }

    double GetBalance() const
    {
        return balance;
    }
};

int main()
{
    double initialBalance;

    cout << "===== Welcome to XYZ Bank ATM =====" << endl;
    cout << "Enter Initial Deposit (Minimum: $1000): ";
    cin >> initialBalance;

    //create the account
    Account userAccount(initialBalance);

    int choice;
    do
    {
        cout << "\n=== MAIN MENU ===" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Your current balance is: $" << userAccount.GetBalance() << endl;
            break;

        case 2:
        {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            userAccount.Deposit(amount);
            break;
        }

        case 3:
        {
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            userAccount.Withdraw(amount);
            break;
        }

        case 4:
            cout << "Thank you for using XYZ Bank ATM!" << endl;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}

