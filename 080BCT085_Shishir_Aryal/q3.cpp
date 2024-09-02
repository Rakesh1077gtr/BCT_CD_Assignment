#include <iostream>
#include <string>
using namespace std;

class BookLibrary
{
private:
    string title;
    string writer;
    int copiesAvailable;

public:
    BookLibrary(string bookTitle, string authorName, int initialCopies)
    {
        title = bookTitle;
        writer = authorName;
        copiesAvailable = initialCopies;
    }
    void addCopies(int additionalCopies)
    {
        copiesAvailable += additionalCopies;
        cout << additionalCopies << " copies of '" << title << "' added. Total copies: " << copiesAvailable << endl;
    }
    void issueOneCopy()
    {
        if (copiesAvailable > 0)
        {
            copiesAvailable--;
            cout << "One copy of '" << title << "' issued. Remaining copies: " << copiesAvailable << endl;
        }
        else
        {
            cout << "No copies of '" << title << "' available for issuing." << endl;
        }
    }
    void returnOneCopy()
    {
        copiesAvailable++;
        cout << "One copy of '" << title << "' returned. Total copies: " << copiesAvailable << endl;
    }
    void showBookDetails() const
    {
        cout << "Title: " << title << ", Author: " << writer << ", Copies Available: " << copiesAvailable << endl;
    }
};

int main()
{
    BookLibrary myBook("Math", "Shishir", 4);
    myBook.showBookDetails();
    myBook.addCopies(6);
    myBook.issueOneCopy();
    myBook.returnOneCopy();
    myBook.showBookDetails();
    return 0;
}