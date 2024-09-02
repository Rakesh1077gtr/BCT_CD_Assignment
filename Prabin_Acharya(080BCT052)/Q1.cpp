// create a class person with name and date of birth as data members. Ask the user to enter a date of birth and print all persons name with a matched date of birth

#include <iostream>
#include <string.h>
using namespace std;
class DOB
{
    int day, month, year;

public:
    DOB(int day = 0, int month = 0, int year = 0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void input(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    bool operator==(DOB &d)
    {
        if (day == d.day && month == d.month && year == d.year)
            return true;
        return false;
    }
};

class person
{
    char name[50];
    DOB dob;

public:
    person(char *name = "", DOB dob = DOB())
    {
        strcpy(this->name, name);
        this->dob = dob;
    }

    void input(char *name, DOB dob)
    {
        strcpy(this->name, name);
        this->dob = dob;
    }

    DOB getDOB()
    {
        return dob;
    }

    char *getName()
    {
        return name;
    }

    void getData()
    {
        int day, month, year;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Year of birth: ";
        cin >> year;
        cout << "Enter Month of birth: ";
        cin >> month;
        cout << "Enter Day of birth: ";
        cin >> day;

        dob.input(day, month, year);
    }
};

int main()
{
    person persons[50];

    persons[0].input("Prabin Acharya", DOB(7, 2, 2004));
    persons[1].input("Prajwal Gautam", DOB(5, 4, 2005));
    persons[2].input("Rohan Subedi", DOB(23, 6, 2004));
    persons[3].input("Pallav Bastola", DOB(32, 3, 2003));
    persons[4].input("Kaushal Chapagain", DOB(2, 6, 2004));
    persons[5].input("Ganesh Dahal", DOB(16, 11, 2005));
    persons[6].input("Ankit Khanal", DOB(19, 3, 2004));
    persons[7].input("Madhav Chaudhari", DOB(20, 2, 2002));
    persons[8].input("Sital Adhikari", DOB(2, 6, 2004));

    int day, month, year;
    cout << "Enter Year of birth: ";
    cin >> year;
    cout << "Enter Month of birth: ";
    cin >> month;
    cout << "Enter Day of birth: ";
    cin >> day;

    DOB dob(day, month, year);

    for(int i = 0; i < 9; i++)
    {
        if(persons[i].getDOB() == dob)
        {
            cout << persons[i].getName() << endl;
        }
    }

    return 0;
}