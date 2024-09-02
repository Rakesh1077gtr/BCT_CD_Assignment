#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int empID;
    string empName;
    double empSalary;

public:
    void input()
    {
        cout << "Enter employee ID: ";
        cin >> empID;
        cin.ignore();
        cout << "Enter employee name: ";
        getline(cin, empName);
        cout << "Enter employee salary: ";
        cin >> empSalary;
    }

    bool isSalaryAbove(double amount) const
    {
        return empSalary > amount;
    }

    void display() const
    {
        cout << "ID: " << empID << ", Name: " << empName << ", Salary: " << empSalary << endl;
    }
};

int main()
{
    int totalEmployees;
    double salaryLimit;
    Employee staff[100];
    
    cout << "Enter the number of employees: ";
    cin >> totalEmployees;
    
    for (int i = 0; i < totalEmployees; i++)
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        staff[i].input();
    }
    
    cout << "Enter the salary limit: ";
    cin >> salaryLimit;
    
    cout << "Employees with salary above " << salaryLimit << ":\n";
    
    bool found = false;
    for (int i = 0; i < totalEmployees; i++)
    {
        if (staff[i].isSalaryAbove(salaryLimit))
        {
            staff[i].display();
            found = true;
        }
    }
    
    if (!found)
    {
        cout << "No employees with salary above " << salaryLimit << endl;
    }
    
    return 0;
}
