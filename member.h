#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
using namespace std;

class Member {
public:
    int memId;
    string name;
    vector<int> ibIds;

    Member();
    Member(int id, string name);
    void display() const;
};

#endif