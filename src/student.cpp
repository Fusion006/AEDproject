#include "Student.h"


Student::Student(){}
Student::Student(string studentCode, string studentName, string uccode, string classecode): studentCode(studentCode), studentName(studentName), uccode(uccode), classecode(classecode){}



string Student::get_studentCode() const{
    return studentCode;
}



string Student::get_studentName() const{
    return studentName;
}

string Student::get_ucCode() const{
    return uccode;
}

string Student::get_classeCode() const{
    return classecode;
}




