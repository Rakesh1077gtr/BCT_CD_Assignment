/* 2 .design a class employee with id, name, and salary as data members.
Implement functions to input employee data and display employees
 who have salary greater than a user specified amount */

 #include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    void input() {
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
    }

    void displaySalaryGreater(double amount) const {
        if (salary > amount) {
            cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
        }
    }
};

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    if (n > MAX_EMPLOYEES) {
        cout << "Number of employees exceeds the maximum allowed (" << MAX_EMPLOYEES << ")." << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for employee " << i + 1 << ":\n";
        employees[i].input();
    }

    double salaryThreshold;
    cout << "\nEnter the salary amount to filter employees: ";
    cin >> salaryThreshold;

    cout << "\nEmployees with salary greater than " << salaryThreshold << ":\n";

    for (int i = 0; i < n; ++i) {
        employees[i].displaySalaryGreater(salaryThreshold);
    }

    return 0;
}

