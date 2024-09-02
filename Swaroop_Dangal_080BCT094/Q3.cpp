#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Library {
private:
    string ISBN;
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    // Constructor
    Library() : ISBN(""), bookTitle(""), author(""), numberOfCopies(0) {}

    // Methods for managing library catalog
    void getBookDetails();
    void displayBookDetails() const;

    bool isBookExists(const string& isbn);
    void addBook();
    void issueBook();
    void returnBook();
    void updateBookDetails();
    void deleteBook();

    // Utility method to handle file operations
    void saveToFile();
    void loadFromFile();
};

void Library::getBookDetails() {
    cout << "Enter ISBN: ";
    cin >> ISBN;
    cout << "Enter Book Title: ";
    cin.ignore(); // Clear input buffer
    getline(cin, bookTitle);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Number of Copies: ";
    cin >> numberOfCopies;
}

void Library::displayBookDetails() const {
 
    cout << "ISBN: " << ISBN << "\n"
         << "Title: " << bookTitle << "\n"
         << "Author: " << author << "\n"
         << "Number of Copies: " << numberOfCopies << endl<<endl;
        
}

bool Library::isBookExists(const string& isbn) {
    ifstream file("library_catalog.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return false;
    }
    string bookIsbn, title, auth;
    int copies;
    while (file >> bookIsbn) {
        file.ignore(); // Ignore space
        getline(file, title, '|'); // Title until delimiter
        getline(file, auth, '|');  // Author until delimiter
        file >> copies; // Number of copies
        file.ignore(); // Ignore newline
        if (bookIsbn == isbn) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void Library::addBook() {
    char choice;
    do {
         system("cls");
        getBookDetails();
        if (isBookExists(ISBN)) {
            cout << "Book with ISBN " << ISBN << " already exists." << endl;
            return;
        }
        saveToFile();
        cout << "Book added successfully." << endl;
        cout << "Do you want to add a new record(Y/N):";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void Library::issueBook() {
    system("cls");
    string isbn;
    cout << "Enter ISBN to issue: ";
    cin >> isbn;

    ifstream file("library_catalog.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    string bookIsbn, title, auth;
    int copies;
    bool found = false;

    while (file >> bookIsbn) {
        file.ignore();
        getline(file, title, '|');
        getline(file, auth, '|');
        file >> copies;
        file.ignore();

        if (bookIsbn == isbn && copies > 0) {
            tempFile << bookIsbn << " " << title << "|" << auth << "|" << (copies - 1) << endl;
            found = true;
            cout << "Book issued successfully." << endl;
        } else {
            tempFile << bookIsbn << " " << title << "|" << auth << "|" << copies << endl;
        }
    }

    file.close();
    tempFile.close();
    remove("library_catalog.txt");
    rename("temp.txt", "library_catalog.txt");

    if (!found) {
        cout << "Book not found or no copies available." << endl;
    }
    cout << "Press any key to return to the main menu...";
    
    cin.get(); // Wait for the user to press a key
}

void Library::returnBook() {
     system("cls");
    string isbn;
    cout << "Enter ISBN to return: ";
    cin >> isbn;

    ifstream file("library_catalog.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    string bookIsbn, title, auth;
    int copies;
    bool found = false;

    while (file >> bookIsbn) {
        file.ignore();
        getline(file, title, '|');
        getline(file, auth, '|');
        file >> copies;
        file.ignore();

        if (bookIsbn == isbn) {
            tempFile << bookIsbn << " " << title << "|" << auth << "|" << (copies + 1) << endl;
            found = true;
            cout << "Book returned successfully." << endl;
        } else {
            tempFile << bookIsbn << " " << title << "|" << auth << "|" << copies << endl;
        }
    }

    file.close();
    tempFile.close();
    remove("library_catalog.txt");
    rename("temp.txt", "library_catalog.txt");

    if (!found) {
        cout << "Book not found." << endl;
    }
    cout << "Press any key to return to the main menu...";
    cin.get();
    cin.get(); // Wait for the user to press a key
}

void Library::updateBookDetails() {
     system("cls");
    string isbn;
    cout << "Enter ISBN to update: ";
    cin >> isbn;

    if (!isBookExists(isbn)) {
        cout << "Book with ISBN " << isbn << " not found." << endl;
        return;
    }

    ifstream file("library_catalog.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    string bookIsbn, title, auth;
    int copies;
    bool found = false;

    while (file >> bookIsbn) {
        file.ignore();
        getline(file, title, '|');
        getline(file, auth, '|');
        file >> copies;
        file.ignore();

        if (bookIsbn == isbn) {
            cout << "Updating details for book with ISBN: " << isbn << endl;
            
            // Get new details
            string newISBN, newTitle, newAuthor;
            int newCopies;
            cout << "Enter new ISBN: ";
            cin >> newISBN;
            cout << "Enter new Book Title: ";
            cin.ignore();
            getline(cin, newTitle);
            cout << "Enter new Author: ";
            getline(cin, newAuthor);
            cout << "Enter new Number of Copies: ";
            cin >> newCopies;

            // Check if the new ISBN already exists and it's different from the current one
            if (newISBN != isbn && isBookExists(newISBN)) {
                cout << "Book with ISBN " << newISBN << " already exists. Update aborted." << endl;
                tempFile << bookIsbn << " " << title << "|" << auth << "|" << copies << endl; // Write original details back
            } else {
                tempFile << newISBN << " " << newTitle << "|" << newAuthor << "|" << newCopies << endl;
                found = true;
                cout << "Book details updated successfully." << endl;
            }
        } else {
            tempFile << bookIsbn << " " << title << "|" << auth << "|" << copies << endl;
        }
    }

    file.close();
    tempFile.close();
    remove("library_catalog.txt");
    rename("temp.txt", "library_catalog.txt");

    if (!found) {
        cout << "Book details not updated." << endl;
    }

    cout << "Press any key to return to the main menu...";
    cin.get(); // Wait for the user to press a key
}


void Library::deleteBook() { 
    system("cls");
    string isbn;
    cout << "Enter ISBN to delete: ";
    cin >> isbn;

    ifstream file("library_catalog.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    string bookIsbn, title, auth;
    int copies;
    bool found = false;

    while (file >> bookIsbn) {
        file.ignore();
        getline(file, title, '|');
        getline(file, auth, '|');
        file >> copies;
        file.ignore();

        if (bookIsbn == isbn) {
            if (copies == 0) {
                found = true;
                continue;
            } else {
                cout << "Cannot delete book with available copies." << endl;
                tempFile << bookIsbn << " " << title << "|" << auth << "|" << copies << endl;
            }
        } else {
            tempFile << bookIsbn << " " << title << "|" << auth << "|" << copies << endl;
        }
    }

    file.close();
    tempFile.close();
    remove("library_catalog.txt");
    rename("temp.txt", "library_catalog.txt");

    if (found) {
        cout << "Book deleted successfully." << endl;
    } else {
        cout << "Book not found or cannot be deleted due to outstanding issues." << endl;
    }
    cout << "Press any key to return to the main menu...";
    cin.get();
    cin.get(); // Wait for the user to press a key
}

void Library::saveToFile() {
    ofstream file("library_catalog.txt", ios::app);
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }
    file << ISBN << " " << bookTitle << "|" << author << "|" << numberOfCopies << endl;
    file.close();
}

void Library::loadFromFile() {
    ifstream file("library_catalog.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return;
    }
    while (file >> ISBN) {
        file.ignore();
        getline(file, bookTitle, '|');
        getline(file, author, '|');
        file >> numberOfCopies;
        file.ignore();
        displayBookDetails();
    }
    
    file.close();
}

int main() {
    Library library;
    int choice;

    do {
        
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Update Book Details\n";
        cout << "5. Delete Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.issueBook();
                break;
            case 3:
                library.returnBook();
                break;
            case 4:
                library.updateBookDetails();
                break;
            case 5:
                library.deleteBook();
                break;
            case 6:
                library.loadFromFile();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
