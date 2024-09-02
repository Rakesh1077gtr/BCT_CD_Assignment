/*
define a class library with booktitle,  author, and numberofcopies as data members.
implement methods to add new books,issue books and return books.ensure that the number of copies is
appropriately updated for each operation.
*/
#include <iostream>
#include <string>
using namespace std;
class Library {
    struct Book {
        string title;
        string author;
        int numberOfCopies;
    };
    Book books[100]; 
    int bookCount;

public:
    Library() : bookCount(0) {}
    void addBook(string title, string author, int numberOfCopies) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title && books[i].author == author) {
                cout << "Book already exists in the library. Updating the number of copies." << endl;
                books[i].numberOfCopies += numberOfCopies;
                return;
            }
        }
        if (bookCount < 100) {
            books[bookCount].title = title;
            books[bookCount].author = author;
            books[bookCount].numberOfCopies = numberOfCopies;
            bookCount++;
            cout << "Book added to the library successfully." << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }
    void issueBook(string title, string author) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title && books[i].author == author) {
                if (books[i].numberOfCopies > 0) {
                    books[i].numberOfCopies--;
                    cout << "Book issued successfully." << endl;
                } else {
                    cout << "No copies available for this book." << endl;
                }
                return;
            }
        }

        cout << "Book not found in the library." << endl;
    }
    void returnBook(string title, string author) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title && books[i].author == author) {
                books[i].numberOfCopies++;
                cout << "Book returned successfully." << endl;
                return;
            }
        }

        cout << "Book not found in the library." << endl;
    }
    void displayBooks() {
        cout << "List of books in the library:" << endl;
        for (int i = 0; i < bookCount; i++) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Number of Copies: " << books[i].numberOfCopies << endl;
        }
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Issue a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Display all books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                int numberOfCopies;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> numberOfCopies;
                library.addBook(title, author, numberOfCopies);
                break;
            }
            case 2: {
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.issueBook(title, author);
                break;
            }
            case 3: {
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.returnBook(title, author);
                break;
            }
            case 4:
                library.displayBooks();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}