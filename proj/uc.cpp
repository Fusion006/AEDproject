#include "uc.h"
#include <iostream>
using namespace std;

uc::uc(string ucCode) : ucCode(ucCode) {} //Constructor

// Getters
string UC::getUcCode() const { return ucCode;}

vector<classes> UC::getClasses() const { return classes;}

// Setters
void UC::setUcCode(const string& code) { ucCode = code;}

void UC::setClasses(const vector<Class>& newClasses) {
    classes = newClasses;

    void UC::addClass(Class &newClass) {
        // Check if there are any conflicting classes in the UC
        for (const Class &existingClass : classes) {
            if (existingClass.getWeekday() == newClass.getWeekday()) {
                double existingStartHour = existingClass.getStartHour();
                double existingEndHour = existingStartHour + existingClass.getDuration();
                double newStartHour = newClass.getStartHour();
                double newEndHour = newStartHour + newClass.getDuration();

                if ((newStartHour >= existingStartHour && newStartHour < existingEndHour) ||
                    (newEndHour > existingStartHour && newEndHour <= existingEndHour)) {
                    // There is a time conflict
                    cout << "Error: Class " << newClass.getClassCode() << " conflicts with existing class "
                         << existingClass.getClassCode() << endl;
                    return; //return with no value associated, so we can break the function
                }
            }
        }
        // Add newClass to classes
        classes.push_back(newClass);
    }

    void UC::removeClass(const string &classCode) {
        auto it = remove_if(classes.begin(), classes.end(), [&](const Class &c) { return c.getClassCode() == classCode;});
        //Erase some elements of the vector according to the condition in the lambda function
        if (it != classes.end()) {
            classes.erase(it, classes.end());
            cout << "Class " << classCode << " removed from UC." << endl;
        }
        else {
            cout << "Error: Class " << classCode << " not found in UC." << endl;
        }
    }
}
