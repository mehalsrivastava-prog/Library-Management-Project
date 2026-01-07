#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include "book.h"
#include "Member.h"

using namespace std;

class Lib {
public:
    vector<Book> books;
    vector<Member> members;

    void loadBooksFromFile();
    void saveBooksToFile();
    void loadMembersFromFile();
    void saveMembersToFile();

    Member* findmember(int memberId);
    void addmember();

    void addbook();
    void displaybooks();
    void issuebook();
    void returnbook();
};

#endif