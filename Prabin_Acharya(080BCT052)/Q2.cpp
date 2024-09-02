// Design a class Employee with id, name, and salary as data members. Implement functions to input employee data and display employees who havea a salary greater than a user-specified amount.

#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
    int id;
    char name[50];
    float salary;

public:
    void input(int id, char *name, float salary)
    {
        this->id = id;
        strcpy(this->name, name);
        this->salary = salary;
    }

    void display(float salary)
    {
        if (this->salary > salary)
        {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Salary: " << this->salary << endl
                 << endl;
        }
    }
};

int main()
{
    Employee employees[10];

    employees[0].input(1, "Naruto Uzumaki", 10000);
    employees[1].input(2, "Sasuke Uchiha", 20000);
    employees[2].input(3, "Hinata Hyuga", 30000);
    employees[3].input(4, "Sakura Haruno", 40000);
    employees[4].input(5, "Kakashi Hatake", 50000);
    employees[5].input(6, "Itachi Uchiha", 60000);
    employees[6].input(7, "Jiraiya", 70000);
    employees[7].input(8, "Minato Namikaze", 80000);
    employees[8].input(9, "Gaara", 90000);
    employees[9].input(10, "Rock Lee", 100000);

    float salary;
    cout << "Enter the salary: ";
    cin >> salary;

    for (int i = 0; i < 10; i++)
    {
        employees[i].display(salary);
    }

    return 0;
}