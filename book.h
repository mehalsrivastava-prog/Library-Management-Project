#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
public:
    int id;
    string title;
    string authorname;
    int copies;

    Book();
    Book(int i, string name, string authname, int cp);
    void display() const;
};

#endif