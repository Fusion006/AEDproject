#ifndef PROJ_UC_H
#define PROJ_UC_H

#include <string>
#include <vector>
using namespace std;

class uc {
public:
    uc(string uccode_);
    bool operator==(const uc& other) const {
        return uccode_ == other.uccode_;
    }
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
    string getuccode() const;

    void setuccode(const string& newcode);
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
    void addnewuc(const uc& newuc);
    void rmexistinguc(const string& uccode);
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
private:
    string uccode_;

    vector<uc> uclist;
};

#endif //PROJ_UC_H
