#include "classesperucclass.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<UniClass> parseClasses(const string& file_name) {
    vector<UniClass> classes;

    // if statement checks for failure when opening
    ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Couldn't open " << file_name + "." << std::endl;
        return classes;
    }
    bool removedtitles = true;
    string uccode, classcode;
    while (file.peek() != EOF){
        getline(file,uccode, ',');
        getline(file,classcode, '\r');
        if (removedtitles){
            removedtitles = false;
            continue;
        }
        UniClass newClass;
        newClass.uccode_ = uccode;
        newClass.classcode_ = classcode;
        classes.push_back(newClass);
        uccode = "";
        classcode = "";
    }
    file.close();
    return classes;
}
