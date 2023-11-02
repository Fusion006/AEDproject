#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "Student.h"
#include "Uc.h"
#include "Class.h"

using namespace std;

class Application {

private:

    vector<Student> student;
    vector<Uc> uc;
    vector<Classe> classe;


public:

    Application();

    int loadFiles();

    //void display_uc_schedule() const;
    //void display_uc_classes() const;
    //void display_uc_students() const;

    //void display_class_schedule() const;
    //void display_class_students() const;

    //void display_student_schedule() const;
    //void display_student_classes() const;
    //void display_student_ucs() const;

    //void display_all_classes() const;
    //void display_all_ucs() const;
    //void display_all_students() const;


};

#endif /*APPLICATION_H_*/
