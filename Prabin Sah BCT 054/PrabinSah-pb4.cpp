/* 4 create a base class account with data members account
 number and balance. Derive two classes SavingAccount
  and Checking Account from Account .  implement
  polymorphic behavior where the base class pointer
  can point to objects of derived classes and call
  their respective member functions to deposit and withdraw money ,
  applying specific rules for each account type */

#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string& accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) = 0;  // Pure virtual function
    virtual void withdraw(double amount) = 0; // Pure virtual function
    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingAccount : public Account {
public:
    SavingAccount(const string& accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " into Savings Account." << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds in Savings Account." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Savings Account." << endl;
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& accNum, double bal, double overdraft)
        : Account(accNum, bal), overdraftLimit(overdraft) {}

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " into Checking Account." << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Insufficient funds in Checking Account, including overdraft limit." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Checking Account." << endl;
        }
    }
};

int main() {
    Account* accounts[2];

    accounts[0] = new SavingAccount("PA12345", 3000.0);
    accounts[1] = new CheckingAccount("KA67890", 1110.0, 500.0);

    for (int i = 0; i < 2; ++i) {
        accounts[i]->display();
        accounts[i]->deposit(500.0);
        accounts[i]->withdraw(150.0);
        accounts[i]->display();
        delete accounts[i];  // Clean up
    }

    return 0;
}

