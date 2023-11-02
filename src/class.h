#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>

using namespace std;

class Classe {

private:
    string classcode;
    string uccode;
    string weekday;
    float starthour;
    float duration;
    string type;


    // week days
    //static map<string, int> week;

public:
    // constructor
    Classe();
    Classe(string classcode, string uccode, string weekday, float starthour,
          float duration, string type);

// methods
    string get_Classcode() const;
    string get_Uccode() const;
    string get_Weekday() const;
    float get_Starthour() const;
    float get_Duration() const;
    string get_Type() const;


    //vector<pair<int, string>> get_students() const;
    //map<string, set<string>> get_ucs() const;


};

#endif //_CLASS_H

