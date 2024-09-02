/* define a class library with book title , author, and number of copies,
as data members. implement methods to add new books, issue books,
 and return books. Ensure that the number of copies is appropriately
  updated for each operation  */

  #include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string title;
    string author;
    int copies;

public:
    Library() : title(""), author(""), copies(0) {}

    void addBook(const string& newTitle, const string& newAuthor, int numCopies) {
        title = newTitle;
        author = newAuthor;
        copies = numCopies;
        cout << "Book added: " << title << " by " << author << " with " << copies << " copies.\n";
    }

    void issueBook() {
        if (copies > 0) {
            copies--;
            cout << "Book issued: " << title << " by " << author << ". Copies left: " << copies << ".\n";
        } else {
            cout << "No copies of " << title << " by " << author << " are available for issue.\n";
        }
    }

    void returnBook() {
        copies++;
        cout << "Book returned: " << title << " by " << author << ". Copies available now: " << copies << ".\n";
    }

    void displayBookInfo() const {
        cout << "Title: " << title << ", Author: " << author << ", Copies: " << copies << endl;
    }
};

int main() {
    Library book;
    int choice;
    string title, author;
    int numCopies;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add new book\n";
        cout << "2. Issue book\n";
        cout << "3. Return book\n";
        cout << "4. Display book information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore(); // Ignore leftover newline character
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter number of copies: ";
                cin >> numCopies;
                book.addBook(title, author, numCopies);
                break;
            case 2:
                book.issueBook();
                break;
            case 3:
                book.returnBook();
                break;
            case 4:
                book.displayBookInfo();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

