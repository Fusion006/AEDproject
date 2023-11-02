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
    string studentName;
    string uccode;
    string classecode;


public:

    // constructor
    Student();
    Student(string studentCode, string studentName,string uccode, string classecode);

    // methods

    string get_studentCode() const;
    string get_studentName() const;
    string get_ucCode() const;
    string get_classeCode() const;



};


#endif //STUDENT_H
