#include<iostream>
using namespace std;

int matchCount = 0;

class Individual
{
    char individualName[30];
    int birthYear;
    int birthMonth;
    int birthDay;
    public:
    Individual(){}
    Individual(int d, int m, int y) {
        birthDay = d;
        birthMonth = m;
        birthYear = y;
    }
    void inputDetails() {
        cout << "Enter name: ";
        cin >> individualName;
        cout << "Enter DOB (dd/mm/yr): ";
        cin >> birthDay >> birthMonth >> birthYear;
    }
    void displayDetails() {
        cout << "Name of the person with the given date of birth: \n" << individualName << endl;
    }
    bool operator==(Individual &ind) {
        if((birthYear == ind.birthYear) && (birthMonth == ind.birthMonth) && (birthDay == ind.birthDay)) {
            ::matchCount = 1;
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    int numIndividuals, d, m, y;
    cout << "Enter number of individuals: ";
    cin >> numIndividuals;
    Individual individuals[100];
    for(int i = 0; i < numIndividuals; i++) {
        individuals[i].inputDetails();
    }
    cout << "Enter the date of birth to search:" << endl;
    cin >> d >> m >> y;
    Individual searchIndividual(d, m, y);
    for(int i = 0; i < numIndividuals; i++) {
        if(searchIndividual == individuals[i]) {
            cout << "Match is found\n";
            individuals[i].displayDetails();
        }
    }
    if(::matchCount != 1) {
        cout << "No match found\n";
    }
    return 0;
}
