#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
    char fullName[50];
    char birthDate[11];
    void setDetails(const char *name, const char *dob)
    {
        strcpy(fullName, name);
        strcpy(birthDate, dob);
    }
};

int main()
{
    int totalPeople;
    char name[50], dob[11], searchDate[11];
    cout << "Enter the number of people: ";
    cin >> totalPeople;
    Person people[100];
    
    for (int i = 0; i < totalPeople; i++)
    {
        cout << "Enter name for person " << i + 1 << ": ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter birth date for person " << i + 1 << " (format: YYYY-MM-DD): ";
        cin.getline(dob, 11);
        people[i].setDetails(name, dob);
    }

    cout << "Enter the birth date to search for (format: YYYY-MM-DD): ";
    cin.getline(searchDate, 11);
    bool found = false;
    
    for (int i = 0; i < totalPeople; i++)
    {
        if (strcmp(people[i].birthDate, searchDate) == 0)
        {
            cout << "Person with matching birth date: " << people[i].fullName << endl;
            found = true;
        }
    }
    
    if (!found)
    {
        cout << "No people found with the birth date: " << searchDate << endl;
    }
    
    return 0;
}
