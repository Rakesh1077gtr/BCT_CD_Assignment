#include <iostream>
#include <string>
using namespace std;

class Employee {
    int empId;
    string empName;
    float empSalary;

public:
    Employee() {}

    void getInput() {
        cout << "Enter the Employee ID: ";
        cin >> empId;
        cin.ignore();  // To ignore the newline character after entering ID
        cout << "Enter the Employee Name: ";
        getline(cin, empName);
        cout << "Enter the Employee Salary: ";
        cin >> empSalary;
    }

    void show() const {
        cout << "ID: " << empId << endl
             << "Name: " << empName << endl
             << "Salary: " << empSalary << endl;
    }

    float getSalary() const {
        return empSalary;
    }
};

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter details for Employee " << i + 1 << ": " << endl;
        employees[i].getInput();
        cout << endl;
    }

    float salaryThreshold;
    cout << "Enter the salary amount to compare: ";
    cin >> salaryThreshold;

    cout << "Employees with a salary greater than " << salaryThreshold << " are:" << endl;
    bool found = false;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].getSalary() > salaryThreshold) {
            employees[i].show();
            found = true;
        }
    }

    if (!found) {
        cout << "No employees found with a salary greater than " << salaryThreshold << "." << endl;
    }

    delete[] employees;
    return 0;
}
