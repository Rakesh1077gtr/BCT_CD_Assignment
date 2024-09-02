// create a base class account with data members accountnumber and balance.
// derive two classese savingsaccount and checkingaccount from account.
// implement polymorphic behaviour where the base class pointer can point to a objects of derived classes ,
// and call their respective member functions to deposit and withdraw money, applying specific rules for each account type.

#include <iostream>
using namespace std;
class Account {
protected:
    int accountNumber;
    double balance;

public:

    Account(int accNo, double bal) : accountNumber(accNo), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs" << amount << " to account number " << accountNumber << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from account number " << accountNumber << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayBalance() const {
        cout << "Account Number: " << accountNumber << ", Balance: Rs" << balance << endl;
    }

    virtual ~Account() {}
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:

    SavingsAccount(int accNo, double bal, double rate) : Account(accNo, bal), interestRate(rate) {}


    void deposit(double amount) override {
        double interest = amount * interestRate / 100;
        balance += amount + interest;
        cout << "Deposited Rs" << amount << " with Rs" << interest << " interest to savings account number " << accountNumber << endl;
    }


    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Cannot withdraw Rs" << amount << " from savings account number " << accountNumber << ". Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from savings account number " << accountNumber << endl;
        }
    }


    void displayBalance() const override {
        cout << "Savings ";
        Account::displayBalance();
    }
};


class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:

    CheckingAccount(int accNo, double bal, double overdraft) : Account(accNo, bal), overdraftLimit(overdraft) {}


    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Cannot withdraw Rs" << amount << " from checking account number " << accountNumber << ". Overdraft limit exceeded!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from checking account number " << accountNumber << endl;
        }
    }


    void displayBalance() const override {
        cout << "Checking ";
        Account::displayBalance();
    }
};

int main() {
    int accType;
    int accNo;
    double initbalance;
    double interestRate;
    double overdraftLimit;
    double amount;

    Account* accPtr = nullptr;

    cout << "Welcome to the Bank Account Management System" << endl;
    cout << "Please choose account type: 1. Savings Account 2. Checking Account: ";
    cin >> accType;

    cout << "Enter account number: ";
    cin >> accNo;

    cout << "Enter initial balance: ";
    cin >> initbalance;

    if (accType == 1) {
        cout << "Enter interest rate (%): ";
        cin >> interestRate;
        accPtr = new SavingsAccount(accNo, initbalance, interestRate);
    } else if (accType == 2) {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
        accPtr = new CheckingAccount(accNo, initbalance, overdraftLimit);
    } else {
        cout << "Invalid account type selected!" << endl;
        return 1;
    }

    char option;
    do {
        cout << "\nPlease Choose an operation: " << endl;
        cout << "1. Deposit amount" << endl;
        cout << "2. Withdraw amount" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case '1':
                cout << "Enter amount to deposit: ";
                cin >> amount;
                accPtr->deposit(amount);
                break;

            case '2':
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                accPtr->withdraw(amount);
                break;

            case '3':
                accPtr->displayBalance();
                break;

            case '4':
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid option. Please select a valid option." << endl;
                break;
        }

    } while (option != '4');


    delete accPtr;

    return 0;
}

