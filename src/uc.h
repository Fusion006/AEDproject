#ifndef UC_H
#define UC_H

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <map>


using namespace std;

class Uc {

private:
    string ucCode;
    string classCode;
    map<string, set<string>> ucClasses;


public:
    // constructor
    Uc();
    Uc(string ucCode, string classCode);
    Uc(string ucCode, map<string, set<string>> ucClasses);


    // methods

    string get_UcCode() const;
    map<string, set<string>> get_UcClasses() const;




};

#endif //UC_H



