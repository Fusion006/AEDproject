//
// Created by dark on 02-11-2023.
//

#ifndef PROJ_STUDENT_H
#define PROJ_STUDENT_H
#include <iostream>
#include <vector>
using namespace std;

class student {
private:
    string studentcode_;
    string studentname_;
    vector<student> studentlist;
public:
    student(string studentcode_, string studentname_);
    string getstudentcode() const;
    string getstudentname() const;
    void setstudentcode(const string& newcode);
    void setstudentname(const string& newname);
    void addnewstudent(student& newstudent);
    void removestudent(string& studentcode);
    bool operator==(const student& other) const {
        return studentcode_ == other.studentcode_ && studentname_ == other.studentname_;
    }
};


#endif //PROJ_STUDENT_H
