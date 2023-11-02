#include<iostream>
#include "Application.h"


using namespace std;



void menuDisplay(){
    int option;

    cout << endl << " Schedule " << endl<<endl;
    cout << "1 - All" << endl;
    cout << "2 - Class" << endl;
    cout << "3 - Student " << endl;
    cout << "4 - Uc " << endl<<endl;
    cout << "5 - Return"<<endl;
    cout << "Option -> ";
    cin >> option;

    switch (option) {
        case 1: //missing
            break;
        case 2: //missing
            break;
        case 3: //missing
            break;
        case 4: //missing
            break;
        case 5: return;
            break;
        default: cout << endl << "Invalid option. Try again.";
    }

}


void menu(Application a) {
    int option;

    cout << endl << " Schedule " << endl<<endl;
    cout << "1 - Display" << endl;
    cout << "2 - Add" << endl;
    cout << "3 - Remove" << endl;
    cout << "4 - Change" << endl;
    cout << "5 - Process" << endl;
    cout << "6 - Change" << endl<<endl;
    cout << "Option -> ";
    cin >> option;

    switch (option) {
        case 1: menuDisplay();
            break;
        case 2: //missing
            break;
        case 3: //missing
            break;
        case 4: //missing
            break;
        case 5: //missing
            break;
        case 6: return;
        default: cout << endl << "Invalid option. Try again.";
    }
    system("pause");
    system("cls");
    menu(a);
}

int main(){

    Application a;
    a.loadFiles();

    menu(a);


    return 0;
}
