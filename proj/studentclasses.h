#ifndef PROJ_STUDENTCLASSES_H
#define PROJ_STUDENTCLASSES_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StudentClass {
public:
    string studentcode_;
    string studentname_;
    string uccode_;
    string classcode_;
};

vector<StudentClass> studentclassinfo(const string& file_name);




#endif //PROJ_STUDENTCLASSES_H
