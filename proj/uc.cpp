#include "uc.h"
#include "classes.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
// GETTERS:
string uc::getuccode() const                            { return uccode_; }
vector<UniClassInfo> uc::getclass() const               { return classes; }
// SETTERS:
void uc::setuccode(const string& newcode)               { uccode_ = newcode; }
void uc::setclass(const vector<UniClassInfo>& newclass) { classes = newclass; }

//▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅

// ADDERS: -------------------------------------------------------------------------------------------------------------
void uc::addnewclass(UniClassInfo& newclass) {
    for (const UniClassInfo i : classes){ // all existing classes will be checked
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
    classes.push_back(newclass);
}
void uc::addnewuc(const uc& newuc){
    if (find(uclist.begin(), uclist.end(), newuc) == uclist.end()) {
        uclist.push_back(newuc);
        cout << "Added student with code " << newuc.getuccode();
    }
    else cout << "Student with code " << newuc.getuccode() << "has already been added." << endl;
}

// REMOVERS: -----------------------------------------------------------------------------------------------------------
void uc::rmexistingclass(const string& classcode){
    for (auto i = classes.begin(); i != classes.end(); i++) {
        if (i->getclasscode() == classcode) {
            classes.erase(i);
            cout << "Removed class with code: " << classcode << endl;
            return;
        }
    }
    cout << "Class with code: " << classcode << ", was not found on the list." << endl;
}

void uc::rmexistinguc(const string& uccode){
    for (auto i = uclist.begin(); i != uclist.end(); i++) {
        if (i->getuccode() == uccode) {
            uclist.erase(i);
            cout << "Removed uc with code: " << uccode << endl;
            return;
        }
    }
    cout << "Uc with code: " << uccode << ", was not found on the list." << endl;
}



