#include <iostream>
#include <cstring>
using namespace std;

#define MAX_BOOKS 100
#define TITLE_SIZE 30

int totalBooks = 0;
int bookIndex = 0;

class Library {
    char bookTitle[TITLE_SIZE];
    char bookAuthor[TITLE_SIZE];
    int copyCount;

public:
    Library() {
        strcpy(this->bookTitle, "");
        strcpy(this->bookAuthor, "");
        this->copyCount = 0;
    }

    void addBooks(bool promptAuthor = true) {
        if (promptAuthor) {
            cout << "Enter the author's name: ";
            cin >> bookAuthor;
        }
        cout << "Enter the number of copies: ";
        int copies;
        cin >> copies;
        copyCount += copies;
    }

    string getTitle() {
        return bookTitle;
    }

    void setTitle(const char* newTitle) {
        strcpy(bookTitle, newTitle);
    }

    void issueBook() {
        if (copyCount == 0) {
            cout << "Book not available" << endl;
        } else {
            int issuedCopies;
            cout << "Enter the number of books to issue: ";
            cin >> issuedCopies;
            if (issuedCopies > copyCount) {
                cout << "Only " << copyCount << " copies available" << endl;
            } else {
                copyCount -= issuedCopies;
                cout << "Book issued successfully" << endl;
            }
        }
    }

    void returnBook() {
        int returnedCopies;
        cout << endl << "Enter the number of books to return: ";
        cin >> returnedCopies;
        copyCount += returnedCopies;
        cout << "Book returned successfully" << endl;
    }

    bool checkBookExists(Library libraryArray[MAX_BOOKS]) {
        char title[TITLE_SIZE];
        cout << "Enter the book title: ";
        cin >> title;
        for (int i = 0; i < totalBooks; i++) {
            if (strcmp(title, libraryArray[i].getTitle().c_str()) == 0) {
                bookIndex = i;
                return true;
            }
        }
        libraryArray[totalBooks].setTitle(title);
        return false;
    }
};

int main() {
    Library library[MAX_BOOKS];

    while (true) {
        int choice;
        cout << "Library Management System" << endl
             << "1. Add New Books" << endl
             << "2. Issue Books" << endl
             << "3. Return Books" << endl
             << "4. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (library[totalBooks].checkBookExists(library)) {
                cout << "Book already exists" << endl;
                library[bookIndex].addBooks(false);
            } else {
                library[totalBooks].addBooks(true);
                totalBooks++;
            }
            break;
        case 2:
            if (library[totalBooks].checkBookExists(library)) {
                library[bookIndex].issueBook();
            } else {
                cout << "Book not found" << endl;
            }
            break;
        case 3:
            if (library[totalBooks].checkBookExists(library)) {
                library[bookIndex].returnBook();
            } else {
                cout << "Book not found" << endl;
            }
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
