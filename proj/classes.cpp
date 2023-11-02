#include "classes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
// GETTERS
string UniClassInfo::getclasscode() const                   { return classcode_; }
string UniClassInfo::getuccode() const                      { return uccode_; }
string UniClassInfo::getweekday() const                     { return weekday_; }
double UniClassInfo::getstarthour() const                   { return starthour_; }
double UniClassInfo::getduration() const                    { return duration_; }
string UniClassInfo::gettype() const                        { return type_; }
// SETTERS
void UniClassInfo::setclasscode(const string& newclasscode) { classcode_ = newclasscode; }
void UniClassInfo::setuccode(const string& newuccode)       { uccode_ = newuccode; }
void UniClassInfo::setweekday(const string& newweekday)     { weekday_ = newweekday; }
void UniClassInfo::setstarthour(double newstarthour)        { starthour_ = newstarthour; }
void UniClassInfo::setduration(double newduration)          { duration_ = newduration; }
void UniClassInfo::settype(const string& newtype)           { type_ = newtype; }

//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅

vector<UniClassInfo> UniClassInfo::parseClassInfo(const string& file_name) {
    vector<UniClassInfo> classinfo;
    ifstream file(file_name);

    if (!file.is_open()) { // if statement checks for failure when opening
        std::cerr << "Couldn't open " << file_name + "." << std::endl;
        return classinfo;
    }

    bool removedtitles = true;
    string line;
    while (getline(file, line)){
        stringstream stringline(line);
        string uccode, classcode, weekday, type;
        double starthour, duration;
        // LINE READER:
        getline(stringline,uccode, ',');
        getline(stringline,classcode, ',');
        getline(stringline,weekday, ',');
        stringline >> starthour; // read this way, since it is a double
        stringline.ignore(1);
        stringline >> duration; // same thing as the 'starthour' above
        stringline.ignore(1);
        getline(stringline,type, '\r');
        // if statement checks for failure when opening:
        if (removedtitles){
            removedtitles = false;
            continue;
        }
        // Assemble a complex value to add to vector:
        UniClassInfo newClassInfo;
        newClassInfo.setuccode(uccode);
        newClassInfo.setclasscode(classcode);
        newClassInfo.setweekday(weekday);
        newClassInfo.setstarthour(starthour);
        newClassInfo.setduration(duration);
        newClassInfo.settype(type);
        classinfo.push_back(newClassInfo);
        // reset temporary variables to ready next read
        uccode = "";
        classcode = "";
        weekday = "";
        starthour = 0;
        duration = 0;
        type = "";
    }
    file.close();
    return classinfo;
};
