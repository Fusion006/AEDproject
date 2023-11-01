#include "classes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


vector<UniClassInfo> parseClassInfo(const string& file_name) {
    vector<UniClassInfo> classinfo;

    // if statement checks for failure when opening
    ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Couldn't open " << file_name + "." << std::endl;
        return classinfo;
    }
    string uccode, classcode, weekday, starthour, duration, type;
    while (file.peek() != EOF){
        getline(file,uccode, ','); getline(file,classcode, ',');
        getline(file,weekday, ','); getline(file,starthour, ',');
        getline(file,duration, ','); getline(file,type, '\r');
        UniClassInfo newClassInfo;
        newClassInfo.uccode_ = uccode;
        newClassInfo.classcode_ = classcode;
        newClassInfo.weekday_ = weekday;
        newClassInfo.starthour_ = starthour;
        newClassInfo.duration_ = duration;
        newClassInfo.type_ = type;
        classinfo.push_back(newClassInfo);
        uccode = "";
        classcode = "";
        weekday = "";
        starthour = "";
        duration = "";
        type = "";
    }
    file.close();
    return classinfo;
};