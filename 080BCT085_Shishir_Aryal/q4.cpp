#include <iostream>

using namespace std;

class BankAccount
{
protected:
    int idNumber;
    double accountBalance;

public:
    BankAccount(int num, double bal) : idNumber(num), accountBalance(bal) {}

    virtual void makeDeposit(double amount) = 0;
    virtual void makeWithdrawal(double amount) = 0;

    void showBalance() const
    {
        cout << "Account ID: " << idNumber << ", Balance: $" << accountBalance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsBankAccount : public BankAccount
{
public:
    SavingsBankAccount(int num, double bal) : BankAccount(num, bal) {}

    void makeDeposit(double amount) 
    {
        accountBalance += amount;
        cout << "Savings Account: Deposited $" << amount << endl;
    }

    void makeWithdrawal(double amount) 
    {
        if (amount <= accountBalance)
        {
            accountBalance -= amount;
            cout << "Savings Account: Withdrawn $" << amount << endl;
        }
        else
        {
            cout << "Savings Account: Insufficient balance for withdrawal!" << endl;
        }
    }
};

class CheckingBankAccount : public BankAccount
{
public:
    CheckingBankAccount(int num, double bal) : BankAccount(num, bal) {}

    void makeDeposit(double amount) 
    {
        accountBalance += amount;
        cout << "Checking Account: Deposited $" << amount << endl;
    }

    void makeWithdrawal(double amount) 
    {

        double serviceCharge = 1.0;
        if (amount + serviceCharge <= accountBalance)
        {
            accountBalance -= (amount + serviceCharge);
            cout << "Checking Account: Withdrawn $" << amount << " (Charge: $" << serviceCharge << ")" << endl;
        }
        else
        {
            cout << "Checking Account: Insufficient balance for withdrawal!" << endl;
        }
    }
};

int main()
{
    SavingsBankAccount savings(12345, 1000.0);
    CheckingBankAccount checking(67890, 500.0);
    BankAccount *accPtr;
    accPtr = &savings;
    accPtr->makeDeposit(200.0);
    accPtr->makeWithdrawal(150.0);
    accPtr->showBalance();
    cout << endl;
    accPtr = &checking;
    accPtr->makeDeposit(300.0);
    accPtr->makeWithdrawal(200.0);
    accPtr->showBalance();
    return 0;
}
