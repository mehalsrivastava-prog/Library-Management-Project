#include "Library.h"
#include <iostream>

using namespace std;

int main() {
    Lib lib;
    int choice;

    lib.loadBooksFromFile();
    lib.loadMembersFromFile();

    do {
        cout << "\n LIBRARY MANAGEMENT SYSTEM \n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addbook();
                break;

            case 2:
                lib.displaybooks();
                break;

            case 3:
                lib.issuebook();
                break;

            case 4:
                lib.returnbook();
                break;

            case 5:
                lib.saveBooksToFile();
                lib.saveMembersToFile();
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
