#include "uc.h"
#include "classes.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// GETTER: -------------------------------------------------------------------------------------------------------------
string uc::getuccode() const {
    return uccode_;
}
// SETTER: -------------------------------------------------------------------------------------------------------------
void uc::setuccode(const string& newcode){
    uccode_ = newcode;
}
// ADDER: --------------------------------------------------------------------------------------------------------------
void uc::addnewuc(const uc& newuc){
    if (find(uclist.begin(), uclist.end(), newuc) == uclist.end()) {
        uclist.push_back(newuc);
        cout << "Added student with code " << newuc.getuccode();
    }
    else cout << "Student with code " << newuc.getuccode() << "has already been added." << endl;
}
// REMOVER: ------------------------------------------------------------------------------------------------------------
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



