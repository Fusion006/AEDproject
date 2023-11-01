#ifndef PROJ_CLASSES_H
#define PROJ_CLASSES_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UniClassInfo {
public:
    string classcode_;
    string uccode_;
    string weekday_;
    string starthour_;
    string duration_;
    string type_;
};

vector<UniClassInfo> parseClassInfo(const string& file_name);



#endif //PROJ_CLASSES_H
