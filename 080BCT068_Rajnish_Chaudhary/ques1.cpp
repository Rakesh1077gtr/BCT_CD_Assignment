#include<iostream>
#include<cstring>
using namespace std;
int initial=0;

class person
{
    char name[30];
    int yr;
    int month;
    int day;

    public:
    person()
    {

    }
    person(int d,int m,int y){
        day=d;
        month=m;
        yr=y;
    }
    void input()
    {
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter Date of birth (DD|MM|YY): ";
        cin>>day>>month>>yr;
    }
    void display()
    {
        cout<<"Name of the person with same DOB: \n"<<name<<endl;
    }
    bool operator==(person &p1)
    {
        if((yr==p1.yr)&&(month==p1.month)&&(day==p1.day))
        {
            ::initial=1;
            return true;
        }
        else
            return false;
    }
};
int main()
{
    int n,d,m,y;
    cout<<"Enter number of persons: ";
    cin>>n;
    person p1[100];
    for(int i=0;i<n;i++)
    {
        p1[i].input();
    }
    cout<<"Enter the date of birth you are searching:"<<endl;
    cin>>d>>m>>y;
    person p2(d,m,y);
    for(int i=0;i<n;i++)
    {
        if(p2==p1[i]){
            cout<<"Match found\n";
            p1[i].display();
        }
    }
    if(::initial!=1){
        cout<<"No match found\n";
    }
    return 0;
}