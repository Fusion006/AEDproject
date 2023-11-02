#include "Application.h"



Application::Application(){}



int Application::loadFiles(){

    ifstream classes_per_uc("classes_per_uc.csv");

    string temp;

    if (classes_per_uc.is_open()){

    getline(classes_per_uc, temp); // skip the first line

    map<string, map<string, set<string>>> mappy;

    while (getline(classes_per_uc, temp)){

        istringstream line(temp);

        string ucCode, classCode;

        getline(line, ucCode, ',');
        getline(line, classCode, '\r');

        Uc fields(ucCode,classCode);
        uc.push_back(fields);

        mappy[ucCode][classCode];


    }

    vector<Uc> all_Ucs;
    for (auto it = mappy.begin(); it != mappy.end(); it++){
        Uc uc(it->first, it->second);
        all_Ucs.push_back(uc);
    }
    classes_per_uc.close();
    }

    else cout <<"file1 not opened"<<endl;

// load file2

    ifstream classes("classes.csv");

    if (classes.is_open()){

    getline(classes, temp); // skip the first line

    while (getline(classes, temp)){

        istringstream line(temp);

        string classCode, ucCode, weekday,
                startHour, duration, type;

        getline(line, classCode, ',');
        getline(line, ucCode, ',');
        getline(line, weekday, ',');
        getline(line, startHour, ',');
        getline(line, duration, ',');
        getline(line, type, '\r');

        Classe fields(classCode, ucCode, weekday, stof(startHour), stof(duration), type);

        classe.push_back(fields);



    // atualizar o vetor de UCs
   //     uc.set_schedule(Schedule(uc_blocks[uc.get_ucCode()]));
  //  }

 //   vector<Class> all_classes;
 //   for (auto it = class_blocks.begin(); it != class_blocks.end(); it++){
  //      all_Class.push_back(Class(it->first, Schedule(it->second)));
 //   }
    }
    classes.close();
    }

	 else cout <<"file2 not opened"<<endl;

// load file3

    ifstream students("students_classes.csv");

    if (students.is_open()){

    getline(students, temp); // skip the first line

    while (getline(students, temp)){

        istringstream line(temp);

        string studentcode,studentname,uccode,classcode;

        getline(line, studentcode, ',');
        getline(line, studentname, ',');
        getline(line, uccode, ',');
        getline(line, classcode, '\r');

        Student fields(studentcode, studentname, uccode, classcode);

        student.push_back(fields);




    }
    students.close();
    }

	 else cout <<"file3 not opened"<<endl;


	 return 0;
}


















