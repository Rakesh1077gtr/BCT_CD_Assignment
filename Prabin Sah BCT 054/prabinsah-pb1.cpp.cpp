/*create a class person with name and date of birth as data members ask
user to enter a date of birth and pfrint all person name with matched date of
birth */

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    string dateOfBirth;

    Person(string n = "", string dob = "") : name(n), dateOfBirth(dob) {}
};

int main() {
    const int MAX_PERSONS = 4; // Fixed size array
    Person persons[MAX_PERSONS]; // Declare a static array of Person objects

    // Initialize persons in the array
    persons[0] = Person("Prabin", "2000-01-01");
    persons[1] = Person("Karan", "1995-05-12");
    persons[2] = Person("Bashyal", "2000-01-02");
    persons[3] = Person("Pritam", "1988-03-23");

    string searchDate;
    cout << "Enter the date of birth to search (YYYY-MM-DD): ";
    cin >> searchDate;

    bool found = false;
    cout << "Persons with the date of birth " << searchDate << ":\n";
    for (int i = 0; i < MAX_PERSONS; ++i) {
        if (persons[i].dateOfBirth == searchDate) {
            cout << persons[i].name << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No persons found with the date of birth " << searchDate << "." << endl;
    }

    return 0;
}
