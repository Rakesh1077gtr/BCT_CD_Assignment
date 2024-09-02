// Define a class Library with bookTitle, author annd numberOfCopies as data members. Implement methods to add new books, issue bookds and return books. Ensure that the number of copies is appropriately updated for each operation.

#include <iostream>
#include <string.h>
using namespace std;

class Book
{
    int bookId;
    char bookTitle[50];
    char author[50];
    int numberOfCopies;

public:
    void input(int bookId, char *bookTitle, char *author, int numberOfCopies)
    {
        this->bookId = bookId;
        strcpy(this->bookTitle, bookTitle);
        strcpy(this->author, author);
        this->numberOfCopies = numberOfCopies;
    }

    int getNumberOfCopies()
    {
        return numberOfCopies;
    }

    void issueBook()
    {
        cout << bookTitle << " has been issued" << endl;
        numberOfCopies--;
    }

    char *getBookTitle()
    {
        return bookTitle;
    }

    char *getAuthor()
    {
        return author;
    }

    void returnBook()
    {
        cout << bookTitle << " has been returned" << endl;
        numberOfCopies++;
    }

    int getBookId()
    {
        return bookId;
    }
};

class Library
{
    Book books[100];
    static int noOfBooks;

public:
    Library()
    {
        books[0].input(1, "The Alchemist", "Paulo Coelho", 10);
        books[1].input(2, "The Da Vinci Code", "Dan Brown", 20);
        books[2].input(3, "The Kite Runner", "Khaled Hosseini", 30);
        books[3].input(4, "The Great Gatsby", "F. Scott Fitzgerald", 40);
        books[4].input(5, "The Catcher in the Rye", "J.D. Salinger", 50);
        books[5].input(6, "The Hobbit", "J.R.R. Tolkien", 60);
        books[6].input(7, "The Hunger Games", "Suzanne Collins", 70);
    }

    bool isBookIdAvailable(int bookId)
    {
        for (int i = 0; i < noOfBooks; i++)
        {
            if (books[i].getBookId() == bookId)
            {
                return false;
            }
        }

        return true;
    }

    void AddBook(int bookId, char *bookTitle, char *author, int numberOfCopies)
    {
        books[noOfBooks].input(bookId, bookTitle, author, numberOfCopies);
        noOfBooks++;
    }

    void IssueBook(int bookId)
    {

        for (int i = 0; i < noOfBooks; i++)
        {
            if (books[i].getBookId() == bookId)
            {
                if (books[i].getNumberOfCopies() == 0)
                {
                    cout << "Book is out of stock" << endl;
                    return;
                }

                books[i].issueBook();
                break;
            }
        }
    }

    void BrowseBooks()
    {
        for (int i = 0; i < noOfBooks; i++)
        {
            cout << books[i].getBookId() << ". " << books[i].getBookTitle() << " - " << books[i].getAuthor() << " (" << books[i].getNumberOfCopies() << ")" << endl;
        }
    }

    void ReturnBook(int bookId)
    {
        for (int i = 0; i < noOfBooks; i++)
        {
            if (books[i].getBookId() == bookId)
            {
                books[i].returnBook();
                break;
            }
        }
    }
};

int Library::noOfBooks = 7;

int main()
{
    Library library;

    library.AddBook(8, "The Lord of the Rings", "J.R.R. Tolkien", 2);

    while (true)
    {
        cout << "LIBRARY" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Browse Books" << endl;
        cout << "5. Exit" << endl;

        int choice;
        int bookId;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter book id: ";
            cin >> bookId;

            if (!library.isBookIdAvailable(bookId))
            {
                cout << "Book id already exists" << endl;
                cin.ignore();
                cin.get();
                system("clear");
                break;
            }

            char bookTitle[50];
            cout << "Enter book title: ";
            cin.ignore();
            cin.getline(bookTitle, 50);
            // cin >> bookTitle;
            char author[50];
            cout << "Enter author: ";
            cin.getline(author, 50);
            // cin >> author;
            int numberOfCopies;
            cout << "Enter number of copies: ";
            cin >> numberOfCopies;
            library.AddBook(bookId, bookTitle, author, numberOfCopies);

            cout << "Book added successfully" << endl;

            cin.ignore();
            cin.get();

            system("clear");
            break;
        case 2:
            cout << "Enter book id: ";
            cin >> bookId;
            library.IssueBook(bookId);

            cin.ignore();
            cin.get();

            system("clear");
            break;
        case 3:
            cout << "Enter book id: ";
            cin >> bookId;
            library.ReturnBook(bookId);

            cin.ignore();
            cin.get();

            system("clear");
            break;
        case 4:
            library.BrowseBooks();

            cin.ignore();
            cin.get();

            system("clear");
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}