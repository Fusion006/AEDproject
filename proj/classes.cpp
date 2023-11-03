#include "classes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<UniClassInfo> UniClassInfo::scheduleclasses; // vector that holds classes specific to a schedule
vector<UniClassInfo> UniClassInfo::allexistingclasses; // lists all existing possible classes to attend

//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
// GETTERS
string UniClassInfo::getclasscode() const                         { return classcode_; }
string UniClassInfo::getuccode() const                            { return uccode_; }
string UniClassInfo::getweekday() const                           { return weekday_; }
double UniClassInfo::getstarthour() const                         { return starthour_; }
double UniClassInfo::getduration() const                          { return duration_; }
string UniClassInfo::gettype() const                              { return type_; }
vector<UniClassInfo> UniClassInfo::getclass() const               { return scheduleclasses; }
// SETTERS
void UniClassInfo::setclasscode(const string& newclasscode)       { classcode_ = newclasscode; }
void UniClassInfo::setuccode(const string& newuccode)             { uccode_ = newuccode; }
void UniClassInfo::setweekday(const string& newweekday)           { weekday_ = newweekday; }
void UniClassInfo::setstarthour(double newstarthour)              { starthour_ = newstarthour; }
void UniClassInfo::setduration(double newduration)                { duration_ = newduration; }
void UniClassInfo::settype(const string& newtype)                 { type_ = newtype; }
void UniClassInfo::setclass(const vector<UniClassInfo>& newclass) { scheduleclasses = newclass; }
//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅

vector<UniClassInfo> UniClassInfo::parseClassInfo(const string& file_name) {
    ifstream file(file_name);

    if (!file.is_open()) { // if statement checks for failure when opening
        std::cerr << "Couldn't open " << file_name + "." << std::endl;
        return allexistingclasses;
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
        allexistingclasses.push_back(newClassInfo);
        // reset temporary variables to ready next read
        uccode = "";
        classcode = "";
        weekday = "";
        starthour = 0;
        duration = 0;
        type = "";
    }
    file.close();
    return allexistingclasses;
};

// ADD CLASS TO SCHEDULE
void UniClassInfo::addnewclass(UniClassInfo& newclass) {
    for (const UniClassInfo i : scheduleclasses){ // all existing classes will be checked
        if (i.getweekday() == newclass.getweekday()){ // if they happen in the same day, we must check for conflicts
            // start hours are collected and end hours are calculated:
            double newclassstart, newclassend, istart, iend;
            newclassstart = newclass.getstarthour(); newclassend = newclass.getduration() + newclassstart;
            istart = i.getstarthour(); iend = i.getduration() + istart;
            bool beginsduring = istart <= newclassstart && iend > newclassend;
            bool endsduring = istart < newclassend && newclassend <= iend;
            if (beginsduring || endsduring){
                cout << "Class rejected due to time conflict:\n▶ Existing class: " << i.getclasscode()
                     << "\n▶ Class to be added: " << newclass.getclasscode() << endl;
                return;
            }
        }
    }
    scheduleclasses.push_back(newclass);
}

// REMOVE CLASS TO SCHEDULE
void UniClassInfo::rmexistingclass(const string& classcode){
    for (auto i = scheduleclasses.begin(); i != scheduleclasses.end(); i++) {
        if (i->getclasscode() == classcode) {
            scheduleclasses.erase(i);
            cout << "Removed class with code: " << classcode << endl;
            return;
        }
    }
    cout << "Class with code: " << classcode << ", was not found on the list." << endl;
}

