#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
protected:
    int acctNumber;
    float acctBalance;
public:
    BankAccount(int num = 0, float bal = 0.0) : acctNumber(num), acctBalance(bal) {}

    virtual void addFunds() = 0;
    virtual void removeFunds() = 0;

    void inputAccountData()
    {
        cout << "Enter the account number: ";
        cin >> acctNumber;
        cout << "Enter the initial balance: ";
        cin >> acctBalance;
    }

    void showDetails(const string &acctType)
    {
        cout << "Account Type: " << acctType << endl;
        cout << "Account Number: " << acctNumber << endl;
        cout << "Current Balance: " << acctBalance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(int num = 0, float bal = 0.0) : BankAccount(num, bal) {}

    void addFunds() override
    {
        float depositAmount;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;
        acctBalance += depositAmount;
        cout << "Deposit successful\n";
    }

    void removeFunds() override
    {
        float withdrawalAmount;
        cout << "Enter the amount to withdraw: ";
        cin >> withdrawalAmount;
        if (acctBalance - withdrawalAmount >= 0)
        {
            acctBalance -= withdrawalAmount;
            cout << "Withdrawal successful\n";
        }
        else
        {
            cout << "Insufficient funds\n";
        }
    }
};

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount(int num = 0, float bal = 0.0) : BankAccount(num, bal) {}

    void addFunds() override
    {
        float depositAmount;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;
        acctBalance += depositAmount;
        cout << "Deposit successful\n";
    }

    void removeFunds() override
    {
        float withdrawalAmount;
        cout << "Enter the amount to withdraw: ";
        cin >> withdrawalAmount;
        if (acctBalance - withdrawalAmount >= 0)
        {
            acctBalance -= withdrawalAmount;
            cout << "Withdrawal successful\n";
        }
        else
        {
            cout << "Insufficient funds\n";
        }
    }
};

int main()
{
    BankAccount *accountPtr = nullptr;
    int acctChoice;

    cout << "1. Savings Account\n2. Checking Account\nEnter your choice: ";
    cin >> acctChoice;

    switch (acctChoice)
    {
    case 1:
        accountPtr = new SavingsAccount();
        accountPtr->inputAccountData();
        accountPtr->addFunds();
        accountPtr->removeFunds();
        accountPtr->showDetails("Savings Account");
        break;
    case 2:
        accountPtr = new CheckingAccount();
        accountPtr->inputAccountData();
        accountPtr->addFunds();
        accountPtr->removeFunds();
        accountPtr->showDetails("Checking Account");
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    delete accountPtr; // Clean up allocated memory
    return 0;
}
