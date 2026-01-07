#include "Book.h"
#include "Library.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Lib::loadBooksFromFile() {
    ifstream in("books.txt");
    if (!in) return;

    books.clear();

    int id, copies;
    string title, author;

    while (in >> id) {
        in.ignore();  
        getline(in, title, ',');
        getline(in, author, ',');
        in >> copies;

        books.push_back(Book(id, title, author, copies));
    }

    in.close();
}

void Lib::saveBooksToFile() {
    ofstream out("books.txt");

    for (const auto& b : books) {
        out << b.id << "," << b.title << ","
            << b.authorname << "," << b.copies << endl;
    }

    out.close();
}


void Lib::loadMembersFromFile() {
    ifstream in("members.txt");
    if (!in) return;

    members.clear();

    while (true) {
        int memberId;
        string name;

        if (!(in >> memberId))
            break;              

        in.ignore();            

        getline(in, name, ',');

        Member m(memberId, name);

        int bookId;
        while (in >> bookId) {
            m.ibIds.push_back(bookId);
        }

        in.clear();
        in.ignore(1000, '\n');

        members.push_back(m);
    }

    in.close();
}

void Lib::saveMembersToFile() {
    ofstream out("members.txt");

    for (const auto& m : members) {
        out << m.memId << "," << m.name << ",";
        for (int id : m.ibIds)
            out << id << " ";
        out << endl;
    }

    out.close();
}

Member* Lib::findmember(int memberId) {
    for (auto& m : members) {
        if (m.memId == memberId)
            return &m;
    }
    return nullptr;
}

void Lib::addmember() {
    int id;
    string name;

    cout << "Enter Member ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));
    cout << "Member added successfully\n";
}

void Lib::addbook() {
    int id, copies;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Copies: ";
    cin >> copies;

    books.push_back(Book(id, title, author, copies));

    cout << "Book added successfully\n";
}

void Lib::displaybooks() {
        if (books.empty()) {
        cout << "No books available\n";
        return;
    }

    for (const auto& b : books) {
        b.display();
    }
}

void Lib::issuebook() {
    int choice;
    cout << "1. New Member\n2. Existing Member\n";
    cout << "Enter choice: ";
    cin >> choice;

    Member* member = nullptr;

    if (choice == 1) {
        addmember();
        member = &members.back();
    } else {
        int id;
        cout << "Enter Member ID: ";
        cin >> id;

        member = findmember(id);
        if (!member) {
            cout << "Member not found\n";
            return;
        }

        cout << "Books already issued:\n";
        member->display();
    }

    int bookId;
    cout << "Enter Book ID to issue: ";
    cin >> bookId;

    for (auto& b : books) {
        if (b.id == bookId && b.copies > 0) {
            b.copies--;
            member->ibIds.push_back(bookId);
            cout << "Book issued successfully\n";
            return;
        }
    }

    cout << "Book not available\n";
}

void Lib::returnbook() {
int memberId, bookId;

    cout << "Enter Member ID: ";
    cin >> memberId;

    Member* member = findmember(memberId);
    if (!member) {
        cout << "Member not found\n";
        return;
    }

    cout << "Enter Book ID to return: ";
    cin >> bookId;

    for (auto it = member->ibIds.begin();
         it != member->ibIds.end(); ++it) {

        if (*it == bookId) {
            member->ibIds.erase(it);

            for (auto& b : books) {
                if (b.id == bookId) {
                    b.copies++;
                    break;
                }
            }

            cout << "Book returned successfully\n";
            return;
        }
    }
}