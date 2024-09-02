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

    void display_output() const {
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

    void return_book() {
        numberOfCopies++;
        cout << "Book returned successfully!" << endl;
    }

    string get_title_of_book() const {
        return bookTitle;
    }

    void set_details(const string& t, const string& a, int c) {
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

    void resize_list() {
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

    void add_book() {
        if (book_count == capacity) {
            resize_list();
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

        list[book_count].set_details(bookTitle, author, numberOfCopies);
        book_count++;
        cout << "Book added successfully :)" << endl;
    }

    void list_books() const {
        if (book_count == 0) {
            cout << "No books available" << endl;
        } else {
            for (int i = 0; i < book_count; ++i) {
                cout << i + 1 << ". ";
                list[i].display_output();
            }
        }
    }

    void issue_book() {
        string bookTitle;
        cout << "Enter the title of the book to issue: ";
        cin.ignore();
        getline(cin, bookTitle);

        for (int i = 0; i < book_count; ++i) {
            if (list[i].get_title_of_book() == bookTitle) {
                string studentName, rollNumber, faculty;
                cout << "Enter student's name: ";
                getline(cin, studentName);
                cout << "Enter roll no: ";
                getline(cin, rollNumber);
                cout << "Enter faculty: ";
                getline(cin, faculty);

                list[i].issue(studentName, rollNumber, faculty);
                return;
            }
        }
        cout << "Unable to find book" << endl;
    }

    void return_book() {
        string bookTitle;
        cout << "Enter the title of the book to return back: ";
        cin.ignore();
        getline(cin, bookTitle);

        for (int i = 0; i < book_count; ++i) {
            if (list[i].get_title_of_book() == bookTitle) {
                list[i].return_book();
                return;
            }
        }
        cout << "Unable to find book" << endl;
    }
};

int main() {
    Library lib;
    char option;

    while (true) 
    {
        cout << "\nLibrary Management System"<<endl;
        cout << "1.) Add Book"<<endl;
        cout << "2.) List Books"<<endl;
        cout << "3.) Issue Book"<<endl;
        cout << "4.) Return Book"<<endl;
        cout << "5.) Exit"<<endl;
        cout << "Enter your option: "<<endl;
        cin >> option;

        switch (option) 
        {
            case '1':
                lib.add_book();
                break;
            case '2':
                lib.list_books();
                break;
            case '3':
                lib.issue_book();
                break;
            case '4':
                lib.return_book();
                break;
            case '5':
                cout << "Program has been Exited" << endl;
                return 0;
            default:
                cout << "Invalid option" << endl;
        }
    }

    return 0;
}