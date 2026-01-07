#include "Member.h"
#include <iostream>

using namespace std;


Member::Member() {
    memId = 0;
    name = "";
}

Member::Member(int id, string n) {
    memId = id;
    name = n;
}

void Member::display() const {
    cout << "Member ID: " << memId;
    cout << "Name: " << name;
    cout << "Issued Books: ";

    if (ibIds.empty()) {
        cout << "None";
    } else {
        for (int bookId : ibIds) {
            cout << bookId << " ";
        }
    }
}