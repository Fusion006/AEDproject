#include "Uc.h"



// constructor

Uc::Uc(string ucCode, map<string, set<string>> classes):ucCode(ucCode), ucClasses(ucClasses) {}
Uc::Uc(string ucCode, string classCode) : ucCode(ucCode),classCode(classCode){}
// set's and get's

string Uc::get_UcCode() const{
    return ucCode;
}


map<string, set<string>> Uc::get_UcClasses() const{
    return ucClasses;
}

