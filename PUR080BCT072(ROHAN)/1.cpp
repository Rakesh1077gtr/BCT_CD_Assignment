/*
create a class person with name and date of birth as data members.Ask the user to enter a date of birth and print all persons name matched DOB.
*/
#include<iostream>
#include<cstring>
using namespace std;

class person {
    char name[50], dob[50];
public:
    void input() {
        cout << "Enter the name of person" << endl;
        cin >> name;
        cout << "Enter the date of birth in Y/M/D format!";
        cin >> dob;
    }

    char* getdob() {
        return dob;
    }

    void output() {
        cout << "The Name and DOB of matched person is:";
        cout << name << '\t' << dob << endl;
    }
};

int main() {
    person p[100];
    int n;
    char dob[50];
    cout << "Enter the number of person" << endl;
    cin >> n;
    cout << "Enter the Date of birth(Y/M/D) of person for sorting!";
    cin >> dob;
    for (int i = 0; i < n; i++) {
        p[i].input();
    }
    cout << "The sorted list is " << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(dob, p[i].getdob()) == 0) {
            p[i].output();
        }
    }
    return 0;
}