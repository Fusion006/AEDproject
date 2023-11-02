#ifndef PROJ_CLASSES_H
#define PROJ_CLASSES_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UniClassInfo {
public:
    // function to read classes.csv file
    static vector<UniClassInfo> parseClassInfo(const string& file_name);
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
    string getclasscode() const;
    string getuccode() const;
    string getweekday() const;
    double getstarthour() const;
    double getduration() const;
    string gettype() const;
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
    void setclasscode(const string& newclasscode);
    void setuccode(const string& newuccode);
    void setweekday(const string& newweekday);
    void setstarthour(double newstarthour);
    void setduration(double newduration);
    void settype(const string& newtype);
    //▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅
private:
    string classcode_;
    string uccode_;
    string weekday_;
    double starthour_;
    double duration_;
    string type_;
};

#endif //PROJ_CLASSES_H
