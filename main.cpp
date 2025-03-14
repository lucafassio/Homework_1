#include "Ej1/squaremtx.cpp"
#include "Ej2/logmsg.cpp"
#include "Ej3/list.cpp"
#include "Ej4/stringcomps.cpp"

int main(){
    int error_line;
    int option;
    while (true){
        try{ 
            cout << endl << "========== Homework 1 - Luca Fassio ==========" << endl;
            cout << endl << "Choose an option:" << endl << "1. Square matrix" << endl << "2. Log manager" << endl << "3. Linked list" << endl << "4. String comparisons" << endl << "5. Exit" << endl;
            cout << endl << "> ";
            cin >> option;
            switch (option){
                case 1: run_1(); break;
                case 2: if (run_2()) cout << "Program stopped due to an error." << endl; break;
                case 3: run_3(); break;
                case 4: run_4(); break;
                case 5: return 0;
                default: error_line=__LINE__+1; throw invalid_argument("ERROR - Invalid option."); break;
            }
        }
        catch (invalid_argument &e){
            cout << e.what() << endl;
            logMessage(e.what(), __FILE__, error_line);
        }
        catch (...){
            cout << "Unexpected error" << endl;
            logMessage("Unexpected error", __FILE__, __LINE__);
        }
    }
    return 0;
}