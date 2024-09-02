/*
create a class person with name and date of birth as data members.Ask the user to enter a date of birth and print all persons name matched DOB.
*/
#include<iostream>
using namespace std;
#define size 50
int flag=0;
class person
{
    char name[size];
    int year;
    int month;
    int day;
    public:
    void input()
    {
        if(flag!=1)
        {
        cout<<"Enter name: ";
        cin>>name;
        }
        cout<<"enter dob(dd mm yr)AD:";
        cin>>day>>month>>year;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
    }
    void operator==(person &p)
    {
        if((year==p.year)&&(month==p.month)&&(day==p.day))
        {
            p.display();
        }
    }
};
int main()
{
    int n;
    cout<<"Enter number of persons: ";
    cin>>n;
    cin.ignore(10,'\n');
    person p[n],a;
    for(int i=0;i<n;i++)
    {
        p[i].input();
    }
    cout<<"Enter dob to search matched result:";
    flag=1;
    a.input();
    for(int i=0;i<n;i++)
    a==p[i];
    return 0;
}
