#include "Class.h"


// constructor

Classe::Classe(){}
Classe::Classe(string classcode, string uccode, string weekday, float starthour, float duration, string type):classcode(classcode), uccode(uccode), weekday(weekday), starthour(starthour), duration(duration), type(type){}



// set's and get's


string Classe::get_Classcode() const{
    return classcode;
}

string Classe::get_Uccode() const{
    return uccode;
}

string Classe::get_Weekday() const{
    return weekday;
}

float Classe::get_Starthour() const{
    return starthour;
}

float Classe::get_Duration() const{
    return duration;
}

string Classe::get_Type() const{
    return type;
}






