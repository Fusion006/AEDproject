#include "student.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
string student::getstudentcode() const { return studentcode_; }
string student::getstudentname() const { return studentname_; }

void student::setstudentcode(const string& newcode) { studentcode_ = newcode; }
void student::setstudentname(const string& newname) { studentname_ = newname; }
//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅

void student::addnewstudent(student& newstudent){
    if (find(studentlist.begin(), studentlist.end(), newstudent) == studentlist.end()) {
        studentlist.push_back(newstudent);
        cout << "Added student with code " << newstudent.getstudentcode();
    }
    else cout << "Student with code " << newstudent.getstudentcode() << "has already been added." << endl;
}

void student::removestudent(string& studentcode) {
    for (auto i = studentlist.begin(); i != studentlist.end(); i++) {
        if (i->getstudentcode() == studentcode) {
            studentlist.erase(i);
            cout << "Removed student with code: " << studentcode << endl;
            return; // return with no value associated, so we can break the function
        }
    }
    cout << "Student with code: " << studentcode << ", was not found on the list." <<
    "\n (consider adding the student)" << endl;
}



