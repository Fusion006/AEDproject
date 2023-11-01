//
// Created by Utilizador on 14/10/2023.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <set>

using namespace std;

class Student{

private:
    string studentCode;
    map<string, string> ucs;
    string studentName;
    set<string> classes;
    set<string> uc;

public:

    // methods

    string get_studentCode() const;
    string get_studentName() const;
    map<string, string> get_ucs() const;
    set<string> get_classes() const;
    set<string> get_uc() const;


};


#endif //STUDENT_H
