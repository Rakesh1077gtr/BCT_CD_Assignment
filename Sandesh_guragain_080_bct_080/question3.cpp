/*
define a class library with booktitle,  author, and numberofcopies as data members.
implement methods to add new books,issue books and return books.ensure that the number of copies is
appropriately updated for each operation.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library
{
    string title, author;
    int copies;
    
public:
    static int book_count;

    Library() : title(""), author(""), copies(0) {}
    
    Library(string t, string a, int c) : title(t), author(a), copies(c) {}
   

    void addBook()
    {
        cout << "Enter the book title: ";
        cin>>title;
        cout << "Enter the author: ";
        cin>>author;
        cout << "Enter the number of copies: ";
        cin >> copies;
    }

    void issueBook()
    {
        if (copies > 0)
        {
            copies--;
            cout << "Book issued successfully\n"<<endl;
        }
        else
        {
            cout << "Book not available\n"<<endl;
        }
    }

    void returnBook()
    {
        copies++;
        cout << "Book returned successfully\n"<<endl;
    }

    void display() 
    {
        cout << "Title: " << title <<endl<<
         "Author: " << author <<endl<<
          "Copies: " << copies << endl;
    }

    string getTitle() 
    {
        return title;
    }
};

int Library::book_count=1;

int main()
{
    vector<Library> library;
    Library lib[100],l;
    int choice;
    while(true){
    cout << "1. Add Book"<<endl;
    cout<<"2. Issue Book"<<endl;
    cout<<"3. Return Book"<<endl;
    cout<<"4. Display All Books "<<endl;
    cout<<"5. Exit"<<endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;


    switch (choice)
    {
        case 1:
        {
            lib[l.book_count].addBook();
            l.book_count++;
            cout << "Book added successfully!\n";
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter the book title to issue: ";
            cin>>title;
            for (int i=1;i<=l.book_count;i++)
            {
                if (lib[i].getTitle() == title)
                {
                    lib[i].issueBook();
                    break;
                }
                else
                {
                    cout << "Book not found!\n";
                    break;
                }

            }
            break;
        }
        case 3:
        {
            string title;
            cout << "Enter the book title to return: ";
            cin>>title;

           
            for (int i=1;i<=l.book_count;i++)
            {
                if (lib[i].getTitle() == title)
                {
                    lib[i].returnBook();
                    break;
                }
                 else
                {
                    cout << "Book not found!";
                    break;
                }
            }
            break;
        }
        case 4:      
            cout <<endl<< "Displaying all books:"<<endl;
            for(int i=1;i<=l.book_count;i++){
                lib[i].display();
            }
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice!!!\n";
            break;
    }
    }
    return 0;
}
