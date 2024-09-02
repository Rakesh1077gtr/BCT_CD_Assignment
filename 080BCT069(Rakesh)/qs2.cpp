#include<iostream>
#include<cstring>
using namespace std;

class Staff
{
    int empId;
    string empName;
    float empSalary;
    public:
    Staff()
    {
        empId = 0;
        empName = "";
        empSalary = 0;
    }
    Staff(int i, string n, float s)
    {
        empId = i;
        empName = n;
        empSalary = s;
    }
    void getDetails()
    {
        cout << "Enter the ID: ";
        cin >> empId;
        cout << "Enter the name: ";
        cin >> empName;
        cout << "Enter the salary: ";
        cin >> empSalary;
    }
    void displayDetails() const
    {
        cout << "ID: " << empId << endl;
        cout << "Name: " << empName << endl;
        cout << "Salary: " << empSalary << endl;
    }

    void checkSalary(float salaryThreshold) const
    {
        if(empSalary > salaryThreshold)
        {
            displayDetails();
        }
    }
};

int main(){
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Staff *staffArray = new Staff[numEmployees];

    for(int i = 0; i < numEmployees; i++)
    {
        staffArray[i].getDetails();
    }

    float salarySearch;
    cout << "Enter the salary for searching: ";
    cin >> salarySearch;

    cout << "\nEmployees with salary greater than " << salarySearch << ":\n";
    for(int i = 0; i < numEmployees; i++)
    {
        staffArray[i].checkSalary(salarySearch);
    }

    delete[] staffArray;

    return 0;
}
