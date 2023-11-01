//
// Created by dark on 01-11-2023.
//

#ifndef PROJ_CLASSESPERUCCLASS_H
#define PROJ_CLASSESPERUCCLASS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UniClass {
public:
    string uccode_, classcode_;
};

vector<UniClass> parseClasses(const string& file_name);


#endif //PROJ_CLASSESPERUCCLASS_H
