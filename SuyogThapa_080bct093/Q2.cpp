/*Design a class Employee with id, name, and salary as data members.
Implement functions to input employee data and display employees who have a salary greater than a user-specified amount.*/

#include<iostream>
#include<string>
using namespace std;

class Employee
{
    int id;
    string name;
    float salary;
public:
   Employee()
    {}
    void getInput()
    {
        cout<<"Enter the ID:";
        cin>>id;
        cout<<"Enter the name:";
        cin>>name;
        cout<<"Enter the salary:";
        cin>>salary;
    }
    void show()
    {
        cout << "ID: " << id <<endl<<
         "Name: " << name <<endl<<
         "Salary: " << salary << endl;
    }
    float getsalary()
    {
        return salary;
    }
};
int main()
{
    int n,i,c=0;
    cout<<"No of employee:"<<endl;
    cin>>n;
    Employee* e = new Employee[n];
    
    for(i=0;i<n;i++)
    {
    cout<<"Enter employee id,name and salary: "<<endl;
    e[i].getInput();
    cout<<endl;
    }

    float money;
    cout<<"Enter the amount to be compared:";
    cin>>money;
    cout<<"Employees having salary greater than the entered amount is"<<":"<<endl;
    
    for(i=0;i<n;i++)
    {
        if(e[i].getsalary()>money)
        {
            c=1;
            e[i].show();  
        }
    }
    if(c==0){
        cout<<"No Employee found\n";
    }
    delete[] e;
    return 0;
}