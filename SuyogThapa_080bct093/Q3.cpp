#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    Book() : bookTitle(""), author(""), numberOfCopies(0) {}

    Book(string t, string a, int c) : bookTitle(t), author(a), numberOfCopies(c) {}

    void display() const {
        cout << "Title: " << bookTitle << ", Author: " << author << ", Copies: " << numberOfCopies << endl;
    }

    void issue(const string& studentName, const string& rollNumber, const string& faculty) {
        if (numberOfCopies > 0) {
            numberOfCopies--;
            cout << "Book issued successfully to " << studentName << " (Roll No: " << rollNumber << ", Faculty: " << faculty << ")." << endl;
        } else {
            cout << "No books left to issue!" << endl;
        }
    }

    void returnBook() {
        numberOfCopies++;
        cout << "Book returned successfully!" << endl;
    }

    string getbookTitle() const {
        return bookTitle;
    }

    void setDetails(const string& t, const string& a, int c) {
        bookTitle = t;
        author = a;
        numberOfCopies = c;
    }
};

class Library {
private:
    Book* list;
    int book_count;
    int capacity;

    void resizelist() {
        int newCapacity = capacity * 2;
        Book* newlist = new Book[newCapacity];
        for (int i = 0; i < book_count; ++i) {
            newlist[i] = list[i];
        }
        delete[] list;
        list = newlist;
        capacity = newCapacity;
    }

public:
    Library(int initialCapacity = 2) : book_count(0), capacity(initialCapacity) {
        list = new Book[capacity];
    }

    ~Library() {
        delete[] list;
    }

    void addBook() {
        if (book_count == capacity) {
            resizelist();
        }
        string bookTitle, author;
        int numberOfCopies;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter number of copies: ";
        cin >> numberOfCopies;

        list[book_count].setDetails(bookTitle, author, numberOfCopies);
        book_count++;
        cout << "Book added successfully!" << endl;
    }

    void listBooks() const {
        if (book_count == 0) {
            cout << "No books available." << endl;
        } else {
            for (int i = 0; i < book_count; ++i) {
                cout << i + 1 << ". ";
                list[i].display();
            }
        }
    }

    void issueBook() {
        string bookTitle;
        cout << "Enter the title of the book to issue: ";
        cin.ignore();
        getline(cin, bookTitle);

        for (int i = 0; i < book_count; ++i) {
            if (list[i].getbookTitle() == bookTitle) {
                string studentName, rollNumber, faculty;
                cout << "Enter student's name: ";
                getline(cin, studentName);
                cout << "Enter student's roll number: ";
                getline(cin, rollNumber);
                cout << "Enter student's faculty: ";
                getline(cin, faculty);

                list[i].issue(studentName, rollNumber, faculty);
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void returnBook() {
        string bookTitle;
        cout << "Enter the title of the book to return: ";
        cin.ignore();
        getline(cin, bookTitle);

        for (int i = 0; i < book_count; ++i) {
            if (list[i].getbookTitle() == bookTitle) {
                list[i].returnBook();
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    Library L1;
    char option;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. List Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case '1':
                L1.addBook();
                break;
            case '2':
                L1.listBooks();
                break;
            case '3':
                L1.issueBook();
                break;
            case '4':
                L1.returnBook();
                break;
            case '5':
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}