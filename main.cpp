#include "Ej1/squaremtx.cpp"
#include "Ej2/logmsg.cpp"
#include "Ej3/list.cpp"
#include "Ej4/stringcomps.cpp"

int main(){
    int option;
    while (true){
        cout << endl << "========== Homework 1 - Luca Fassio ==========" << endl;
        cout << endl << "Choose an option:" << endl << "1. Square matrix" << endl << "2. Log manager" << endl << "3. Linked list" << endl << "4. String comparisons" << endl << "5. Autorun" << endl << "6. Exit" << endl;
        cout << endl << "> ";
        cin >> option;
        switch (option){
            case 1: run_1(); break;
            case 2: 
                if (run_2()) cout << "Program stopped due to an error." << endl; 
                break;
            case 3: run_3(); break;
            case 4: comp_time(); break;
            case 5:
                cout << "Autorun" << endl; //se vienen cositas
                break;
            case 6:
                return 0;
            default:
                cout << "ERROR - Invalid option." << endl;
                break;
        }
    }
    return 0;
}