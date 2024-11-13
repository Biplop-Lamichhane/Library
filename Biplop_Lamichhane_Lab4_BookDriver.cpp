// Name: Biplop Lamichhane
//Student ID: w10185331
//Program Description: This is a library program designed in c++ using constructors, classes and method functions to do the basic functions of how an actual library functions with checking in and checking out of a book functions.
#include "Biplop_Lamichhane_Lab4_BookClass.hpp"
#include <iostream>
using namespace std;

void createLibrary(Book library[]) {
    library[0] = Book("The Hobbit", "J.R.R Tolkien", 12345);
    library[1] = Book("The Lord of the Rings", "J.R.R Tolkien", 23456);
    library[2] = Book("Crime and Punishment", "Fyodor Dostoevsky", 34567);
    library[3] = Book("Frankenstein", "Mary Shelly", 45678);
    library[4] = Book("The Road", "Cormac McCarthy", 56789);
}

int ISBNLookup(Book library[], int size, int ISBN) {
    for (int i = 0; i < size; i++) {
        if (library[i].getISBN() == ISBN) {
            return i;
        }
    }
    return -1;
}

int main() {
    Book library[5];
    createLibrary(library);
    int choice;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Search by ISBN\n";
        cout << "2. Checkout a book\n";
        cout << "3. Return a book\n";
        cout << "4. Quit Program\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int ISBN;
            cout << "Enter ISBN to search: ";
            cin >> ISBN;
            int index = ISBNLookup(library, 5, ISBN);
            if (index == -1) {
                cout << "Book not found.\n";
            } else {
                library[index].outputBook();
            }
        } else if (choice == 2) {
            int ISBN;
            cout << "Enter ISBN of book to check out: ";
            cin >> ISBN;
            int index = ISBNLookup(library, 5, ISBN);
            if (index == -1) {
                cout << "Book not found.\n";
            } else if (library[index].getStatus()) {
                cout << "Book is already checked out.\n";
            } else {
                string name;
                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, name);
                if (library[index].checkOutBook(name)) {
                    cout << "Book checked out successfully.\n";
                } else {
                    cout << "Book is already checked out.\n";
                }
            }
        } else if (choice == 3) {
            int ISBN;
            cout << "Enter ISBN of book to return: ";
            cin >> ISBN;
            int index = ISBNLookup(library, 5, ISBN);
            if (index == -1) {
                cout << "Book not found.\n";
            } else if (!library[index].getStatus()) {
                cout << "Book is not checked out.\n";
            } else {
                library[index].returnBook();
                cout << "Book returned successfully.\n";
            }
        } else if (choice == 4) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
