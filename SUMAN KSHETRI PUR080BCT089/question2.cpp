// Design a class Employee with id, name, and salary as data members.
// Implement functions to input employee data and display employees who have a salary greater than a user-specified amount.

#include<iostream>
#include<string>
using namespace std;
class Employee
{
    private:
    int id;
    string name;
    float salary;
public:
   Employee()
    {}
    void getinfo()
    {
        cout<<"Enter the ID of the employee:";
        cin>>id;
        cin.ignore();
        cout<<"Enter the name of the employee:";
        getline(cin,name);
        cout<<"Enter the salary of the employee:";
        cin>>salary;
    }
    void showinfo()
    {
        cout << "ID: " << id <<endl<< "Name: " << name <<endl<< " Salary: " << salary << endl;
    }
    float getsalary()
    {
        return salary;
    }
};
int main()
{
    int n,i;
    cout<<"Enter the number of employees whose data you want to compare with ?"<<endl;
    cin>>n;
    Employee* e = new Employee[n];
    for(i=0;i<n;i++)
    {
    cout<<"enter the data of Employee number "<<(i+1)<<endl;
    e[i].getinfo();
    cout<<endl;
    }
    float amount;
    cout<<"Enter the required amount to be compared";
    cin>>amount;
    cout<<"Employees having salary greater than "<<amount<<":"<<endl;
    bool found=false;
    for(i=0;i<n;i++)
    {
        if(e[i].getsalary()>amount)
        {
            e[i].showinfo();
            found=true;
        }
    }
    if(!found)
    {
        cout<<"Employees having salary greater than"<<amount<<" not found.";
    }
    delete[] e;
    return 0;
}