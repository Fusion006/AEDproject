#include <iostream>
#include "classucloader.h"
#include <string>
using namespace std;


int main() {
    string option = "";
    while (true){
        cin >> option;
        if (option == "exit" || option == "e") break;
        // Below this if we will have all function calls
        if (option == "cpu") {
            classucloader::classes_per_uc_loader(); }
    }
    return 0;
}


        