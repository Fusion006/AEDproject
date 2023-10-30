#include <iostream>
#include <fstream>
#include <string>
#include "classucloader.h"
using namespace std;

int classucloader::classes_per_uc_loader() {

    ifstream file("example.csv");

    if(!file.is_open()){
        cout << "Oopsy daisy! Try again\n";
        return 1;
    }

    string uccode, classcode;
    while (file.peek() != EOF){
        getline(file,uccode, ',');
        getline(file,classcode, '\n');
        cout << uccode << " " << classcode << "\n";
    }
    file.close();
    return 0;
}