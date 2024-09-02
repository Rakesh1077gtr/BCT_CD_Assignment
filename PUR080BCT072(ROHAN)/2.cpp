/*
design a class employee with id, name and salary as data members.
implement functions to input employee data and display employees 
who have a salary greater than a user specified amount.
*/
#include <iostream>
#include <cstring>

using namespace std;

class Employee {
    int id;
    string name;
    double salary;

public:

    void disp() {
        cout << "Employee " << id << ": " << name << ", Salary: " << salary << endl;
    }

    double getSal() {
        return salary;
    }

    void inp() {
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
    }
};

int main() {
    Employee emp[100];
     int size;
        cout<< "Enter how many employee you want to enter?"<<endl;
        cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter employee data ";
        emp[i].inp();
        }
    cout << "Enter salary threshold: ";
    double salThresh;
    cin >> salThresh;

    for (int i = 0; i < size; i++) {
        if (emp[i].getSal() > salThresh) {
            emp[i].disp();
        }
    }

    return 0;
}