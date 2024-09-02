/*
create a base class account with data members accountnumber and balance.
derive two classese savingsaccount and checkingaccount from account.
implement polymorphic behaviour where the base class pointer can point to a objects of derived classes ,
and call their respective member functions to deposit and withdraw money, applying specific rules for each account type.
*/
#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) = 0; // pure virtual function

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    const double interestRate = 0.02; // 2% interest rate

public:
    SavingsAccount(int accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) override {
        balance += amount;
        balance += balance * interestRate; // Apply interest rate on deposit
    }

    void withdraw(double amount) override {
        if (balance - amount >= 0) {
            balance -= amount;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }
};

class CheckingAccount : public Account {
private:
    const double overdraftLimit = 500.0; // Overdraft limit

public:
    CheckingAccount(int accNum, double bal) : Account(accNum, bal) {}

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
        } else {
            cout << "Withdrawal amount exceeds overdraft limit." << endl;
        }
    }
};

void displayMenu() {
    cout << "Account Menu:" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    int choice;
    cout << "Choose account type:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Checking Account" << endl;
    cin >> choice;

    int accountNumber;
    double initialBalance;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Account* account;
    if (choice == 1) {
        account = new SavingsAccount(accountNumber, initialBalance);
    } else if (choice == 2) {
        account = new CheckingAccount(accountNumber, initialBalance);
    } else {
        cout << "Invalid choice. Exiting..." << endl;
        return 1;
    }

    int menuChoice;
    do {
        displayMenu();
        cin >> menuChoice;

        switch (menuChoice) {
            case 1: {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                account->deposit(amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account->withdraw(amount);
                break;
            }
            case 3:
                account->display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (menuChoice != 4);

    delete account;
    return 0;
}