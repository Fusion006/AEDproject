#ifndef PROJ_UC_H
#define PROJ_UC_H

#include <string>
#include <vector>
#include "classes.h"
using namespace std;

class uc {
public:
    uc(string uccode_);
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
    string getuccode() const;
    vector<UniClassInfo> getclass() const;

    void setuccode(const string& newcode);
    void setclass(const vector<UniClassInfo>& newclass);
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
    void addnewclass(UniClassInfo& newclass);
    void rmexistingclass(const string& classcode);

    void addnewuc(const uc& uc);
    void rmexistinguc(const string& uccode);
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
private:
    string uccode_;
    vector<UniClassInfo> classes;
};

#endif //PROJ_UC_H
