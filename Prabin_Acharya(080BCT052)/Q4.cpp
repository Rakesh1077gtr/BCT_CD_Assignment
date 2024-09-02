// Create a base class account with data members account number and balance there are two classes savings account and checking account from account implement polymorphic behavior where the base class pointer can point to objects of derived classes and call their respective member functions to deposit and withdraw money applying specific rules for each account type

#include <iostream>
using namespace std;

class Account
{
protected:
    int account_number;
    float balance;

public:
    Account(int account_number, float balance)
    {
        this->account_number = account_number;
        this->balance = balance;
    }
    virtual void deposit(float amount) = 0;
    virtual void withdraw(float amount) = 0;
    float getBalance()
    {
        return balance;
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(int account_number, float balance) : Account(account_number, balance)
    {
    }
    void deposit(float amount)
    {
        balance += amount;
    }
    void withdraw(float amount)
    {
        if (balance - amount >= 500)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int account_number, float balance) : Account(account_number, balance)
    {
    }
    void deposit(float amount)
    {
        balance += amount;
    }
    void withdraw(float amount)
    {
        if (balance - amount >= 1000)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

int main()
{
    Account *account;
    SavingsAccount savings_account(12345, 1000);
    CheckingAccount checking_account(54321, 2000);

    account = &savings_account;
    account->deposit(500);
    account->withdraw(200);
    cout << "Savings Account Balance: " << savings_account.getBalance() << endl;

    account = &checking_account;
    account->deposit(500);
    account->withdraw(200);
    cout << "Checking Account Balance: " << checking_account.getBalance() << endl;

    return 0;
}