#include <iostream>
#include <vector>
#include "classesperucclass.h"
#include "classes.h"
#include "studentclasses.h"
using namespace std;

int main() {

    vector<UniClass> classes; // vector to hold 'uniclass' objects that contain uccode and classcode info per item
    vector<UniClassInfo> classinfo; // vector that holds info about each class separately
    vector<StudentClass> studentinfo; // vector with student info (code, name, uccode, classcode)

    string option = "";
    // Boolean values are used to check if a load action has already been made or not
    bool prscls = true;
    bool clsinfo = true;
    bool sdtinfo = true;

    while (true){
        cin >> option;

        if (option == "exit" || option == "e") break; // terminate

        // Load all Data
        if (option == "0"){
            if (prscls && clsinfo && sdtinfo){
                classes = parseClasses("classes_per_uc.csv");
                classinfo = parseClassInfo("classes.csv");
                studentinfo = studentclassinfo("students_classes.csv");
                prscls = false;
                clsinfo = false;
                sdtinfo = false;
                cout << "Successful full data load.\n";
            }
            else { cout << "Data has previously been fully or partly loaded.\n"; }
        }
        // Parse Classes
        if (option == "1"){
            if (prscls){
                classes = parseClasses("classes_per_uc.csv");
                for (UniClass& i : classes)
                    cout << i.uccode_ << " " << i.classcode_; // to be removed later (test purposes)
                prscls = false;
                cout << "\nParsed classes successfully\n";
            }
            else { cout << "Classes have been previously parsed.\n"; }
        }
        // Load classes info
        if (option == "2"){
            if (clsinfo){
                classinfo = parseClassInfo("classes.csv");
                for (UniClassInfo& i : classinfo)
                    cout << i.uccode_ << " " << i.classcode_ << " " << i.weekday_ << " " << i.starthour_ << " " <<
                    i.duration_ << " " << i.type_;
                clsinfo = false;
                cout << "\nLoaded classes info successfully\n";
            }
            else { cout << "Classes info has been previously loaded.\n"; }
        }
        // Load students info
        if (option == "3"){
            if (sdtinfo){
                studentinfo = studentclassinfo("students_classes.csv");
                for (StudentClass& i : studentinfo)
                    cout << i.studentcode_ << " " << i.studentname_ << " " << i.uccode_ << " " << i.classcode_;
                sdtinfo = false;
                cout << "\nLoaded students info successfully\n";
            }
            else { cout << "Students info has been previously loaded.\n"; }
        }
    }
    return 0;

}
