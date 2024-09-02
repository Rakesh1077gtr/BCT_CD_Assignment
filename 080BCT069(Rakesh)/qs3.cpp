#include <iostream>
#include <string>
using namespace std;

class Volume {
private:
    string volumeTitle;
    string writer;
    int copyCount;

public:
    Volume() : volumeTitle(""), writer(""), copyCount(0) {}

    Volume(string t, string w, int c) : volumeTitle(t), writer(w), copyCount(c) {}

    void displayVolume() const {
        cout << "Title: " << volumeTitle << ", Author: " << writer << ", Copies: " << copyCount << endl;
    }

    void issueVolume(const string& studentName, const string& rollNumber, const string& faculty) {
        if (copyCount > 0) {
            copyCount--;
            cout << "Volume issued successfully to " << studentName << " (Roll No: " << rollNumber << ", Faculty: " << faculty << ")." << endl;
        } else {
            cout << "No copies left to issue!" << endl;
        }
    }

    void returnVolume() {
        copyCount++;
        cout << "Volume returned successfully!" << endl;
    }

    string getVolumeTitle() const {
        return volumeTitle;
    }

    void setVolumeDetails(const string& t, const string& w, int c) {
        volumeTitle = t;
        writer = w;
        copyCount = c;
    }
};

class Archive {
private:
    Volume* collection;
    int volumeCount;
    int capacity;

    void resizeCollection() {
        int newCapacity = capacity * 2;
        Volume* newCollection = new Volume[newCapacity];
        for (int i = 0; i < volumeCount; ++i) {
            newCollection[i] = collection[i];
        }
        delete[] collection;
        collection = newCollection;
        capacity = newCapacity;
    }

public:
    Archive(int initialCapacity = 2) : volumeCount(0), capacity(initialCapacity) {
        collection = new Volume[capacity];
    }

    ~Archive() {
        delete[] collection;
    }

    void addVolume() {
        if (volumeCount == capacity) {
            resizeCollection();
        }
        string volumeTitle, writer;
        int copyCount;
        cout << "Enter volume title: ";
        cin.ignore();
        getline(cin, volumeTitle);
        cout << "Enter writer name: ";
        getline(cin, writer);
        cout << "Enter number of copies: ";
        cin >> copyCount;

        collection[volumeCount].setVolumeDetails(volumeTitle, writer, copyCount);
        volumeCount++;
        cout << "Volume added successfully :)" << endl;
    }

    void listVolumes() const {
        if (volumeCount == 0) {
            cout << "No volumes available" << endl;
        } else {
            for (int i = 0; i < volumeCount; ++i) {
                cout << i + 1 << ". ";
                collection[i].displayVolume();
            }
        }
    }

    void issueVolume() {
        string volumeTitle;
        cout << "Enter the title of the volume to issue: ";
        cin.ignore();
        getline(cin, volumeTitle);

        for (int i = 0; i < volumeCount; ++i) {
            if (collection[i].getVolumeTitle() == volumeTitle) {
                string studentName, rollNumber, faculty;
                cout << "Enter student's name: ";
                getline(cin, studentName);
                cout << "Enter roll no: ";
                getline(cin, rollNumber);
                cout << "Enter faculty: ";
                getline(cin, faculty);

                collection[i].issueVolume(studentName, rollNumber, faculty);
                return;
            }
        }
        cout << "Unable to find volume" << endl;
    }

    void returnVolume() {
        string volumeTitle;
        cout << "Enter the title of the volume to return back: ";
        cin.ignore();
        getline(cin, volumeTitle);

        for (int i = 0; i < volumeCount; ++i) {
            if (collection[i].getVolumeTitle() == volumeTitle) {
                collection[i].returnVolume();
                return;
            }
        }
        cout << "Unable to find volume" << endl;
    }
};

int main() {
    Archive archive;
    char option;

    while (true) 
    {
        cout << "\nArchive Management System"<<endl;
        cout << "1.) Add Volume"<<endl;
        cout << "2.) List Volumes"<<endl;
        cout << "3.) Issue Volume"<<endl;
        cout << "4.) Return Volume"<<endl;
        cout << "5.) Exit"<<endl;
        cout << "Enter your option: "<<endl;
        cin >> option;

        switch (option) 
        {
            case '1':
                archive.addVolume();
                break;
            case '2':
                archive.listVolumes();
                break;
            case '3':
                archive.issueVolume();
                break;
            case '4':
                archive.returnVolume();
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
