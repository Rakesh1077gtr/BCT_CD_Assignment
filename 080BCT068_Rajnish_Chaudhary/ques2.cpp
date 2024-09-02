#include<iostream>
#include<cstring>
using namespace std;

class Employee
{
    int id;
    string name;
    float salary;
    public:
    Employee()
    {
        id=0;
        name="";
        salary=0;
    }
    Employee(int i, string n, float s)
    {
        id = i;
        name = n;
        salary = s;
    }
    void getData()
    {
        cout << "Enter the id: ";
        cin >> id;
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the salary: ";
        cin >> salary;
    }
    void showData() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    void Review_salary(float s) const
    {
        if(salary > s)
        {
            showData();
        }
    }
};

int main(){
    int n;
    cout << "Enter the no of employees: ";
    cin >> n;

    Employee *e1 = new Employee[n];

    for(int i = 0; i < n; i++)
    {
        e1[i].getData();
    }

    float s;
    cout << "Enter the salary for searching : ";
    cin >> s;

    cout << "\nEmployees with salary greater than " << s << ":\n";
    for(int i = 0; i < n; i++)
    {
        e1[i].Review_salary(s);
    }

    delete[] e1;

    return 0;
}