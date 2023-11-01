//
// Created by Utilizador on 14/10/2023.
//

#include "Student.h"


// Construct a new Student:: Student object
// studentCode code of the student
// studentName name of the student

Student::Student(string studentCode, string studentName) :studentCode(studentCode), studentName(studentName){}


 // returns the code of the student
 // return string with the code of the student

string Student::get_studentCode() const{
    return studentCode;
}

// returns the name of the student
// string with the name of the student

string Student::get_studentName() const{
    return studentName;
}


// returns all the UCs the student is enrolled in and the respective class
// return map<string, string> with all the UCs the student is enrolled in and the respective class

map<string, string> Student::get_ucs() const{
    return ucs;
}


// returns all the classes the student is in
// return set<string> with all the classes the student is in

set<string> Student::get_classes() const{
    return classes;
}


// returns the UCs the student is enrolled in
// return set<string> with the UCs the student is enrolled in

set<string> Student::get_uc() const{
    return uc;
}



