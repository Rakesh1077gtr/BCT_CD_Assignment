// Create a class person with name and date of birth as data members.
// Ask the user to enter a date of birth and print all persons name
//  with a matched date of birth.


#include<iostream>
using namespace std;
int Count=0;

class person
{
    char name[30];
    int year;
    int month;
    int day;
    public:
    void input()
    {
        if(Count!=1)
        {
        cout<<"Enter name: ";
        cin>>name;
        }
        cout<<"enter dob(dd/mm/yr)BS:";
        cin>>day>>month>>year;
    }
    void display()
    {
        cout<<"Name of the person with the given date of birth: "<<name<<endl;
    }
    bool operator==(person &p)
    {
        if((year==p.year)&&(month==p.month)&&(day==p.day))
        {
            cout<<"The match is found"<<endl;
            p.display();
        }
        else
        cout<<"No match found"<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter number of persons you want to add dob: ";
    cin>>n;
    person p[n],a;
    for(int i=0;i<n;i++)
    {
        p[i].input();
    }
    Count=1;
    cout<<"Enter the date of the birth for searching..."<<endl;
    a.input();

    for(int i=0;i<n;i++)
    {
        a==p[i];
    }
    return 0;
}

