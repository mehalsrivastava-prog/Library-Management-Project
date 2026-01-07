#include "Book.h"
#include <iostream>

using namespace std;

Book::Book() {
    id = 0;
    title = "";
    authorname = "";
    copies = 0;
}

Book::Book(int i, string name, string authname, int cp) {
        id = i;
        title = name;
        authorname = authname;
        copies = cp;
    }

void Book::display() const {
    cout << id << " "
              << title << " "
              << authorname << " "
              << copies;
}
