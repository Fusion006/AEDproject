#include "studentclasses.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<StudentClass> studentclassinfo(const string& file_name) {
    vector<StudentClass> studentinfo;

    // if statement checks for failure when opening
    ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Couldn't open " << file_name + "." << std::endl;
        return studentinfo;
    }
    string studentcode, studentname, uccode, classcode;
    while (file.peek() != EOF){
        getline(file,studentcode, ','); getline(file,studentname, ',');
        getline(file,uccode, ','); getline(file,classcode, '\r');
        StudentClass StudentInfo;
        StudentInfo.studentcode_ = studentcode;
        StudentInfo.studentname_ = studentname;
        StudentInfo.uccode_ = uccode;
        StudentInfo.classcode_ = classcode;
        studentinfo.push_back(StudentInfo);
        studentcode = "";
        studentname = "";
        uccode = "";
        classcode = "";
    }
    file.close();
    return studentinfo;
};