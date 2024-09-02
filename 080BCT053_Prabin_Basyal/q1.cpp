#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char name[30];
    int dob; 

public:
    
    Student() {
        strcpy(name, "");
        dob = 0;
    }

    
    Student( char* nam, int doo) {
        strcpy(name, nam);
        dob = doo;
    }


    void getdata() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter DOB (YYYYMMDD): ";
        cin >> dob;
    }

    
    int getDob()  {
        return dob;
    }


     char* getName()  {
        return name;
    }
};

int main() {
    Student a[100];
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        a[i].getdata();
    }

    int searchDOB;
    cout << "Enter DOB to search (YYYYMMDD): ";
    cin >> searchDOB;

    cout << "Persons with DOB " << searchDOB << " are:" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].getDob() == searchDOB) {
            cout << a[i].getName() << endl;
        }
    }

    return 0;
}
