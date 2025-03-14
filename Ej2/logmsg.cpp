#include "logmsg.h"

void logMessage(string msg, int level){
    vector<string> level_names={"[DEBUG]", "[INFO]", "[WARNING]", "[ERROR]", "[CRITICAL]", "[SECURITY]"};
    ofstream log("Ej2/log.txt", ios::app);
    log << level_names[level] + " <" + msg + ">" << endl;
    log.close();
}

void logMessage(string msg, string file_name, int line){
    ofstream log("Ej2/log.txt", ios::app);
    log << "[ERROR] " << file_name << ":" << to_string(line) << " - <" << msg << ">" << endl;
    log.close();
}

void logMessage(string msg, string username){
    ofstream log("Ej2/log.txt", ios::app);
    log << "[SECURITY] User: " << username << " - " << msg << endl;
    log.close();
}

int case_error(string msg){
    cout << "Enter the file name (enter . to skip file snipping): ";
    string file_name;
    cin >> file_name;
    if (file_name[0]=='.'){
        logMessage(msg, 3);
        cout << endl;
        return 0;
    };
    if (cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        return __LINE__+1;
    }
    cout << "Enter the line number: ";
    int line;
    cin >> line;
    if (cin.fail() || line<0){
        cin.clear();
        cin.ignore(10000, '\n');
        return __LINE__+1;
    }
    logMessage(msg, file_name, line);
    return 0;
}

int case_user(string msg){ 
    cout << "Enter the username: ";
    string username;
    cin >> username;
    if (cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        return __LINE__+1;
    }
    logMessage(msg, username);
    return 0;
}

int run_2(){
    int LEVELS_QUANTITY=6;
    enum levels {DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY};
    cout << endl << "========== Ej 2: Log messages ==========" << endl;
    int error_line;
    try{
        while (true){
            cout << "Select the event level:" << endl;
            int num=1;
            cout << "1. DEBUG\n2. INFO\n3. WARNING\n4. ERROR\n5.CRITICAL\n6.SECURITY\n7. Exit" << endl << "> ";
            int level_selected;
            cin >> level_selected;
            if (cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                error_line=__LINE__+1;
                throw invalid_argument("ERROR - Invalid option.");
            }
            string msg;
            if (level_selected>0 && level_selected<=LEVELS_QUANTITY){
                cout << "Enter the message: ";
                cin.ignore();
                getline(cin, msg);
            }
            switch (level_selected){
                case 1: logMessage(msg, 0); break;
                case 2: logMessage(msg, 1); break;
                case 3: logMessage(msg, 2); break;
                case 4: if (case_error(msg)) throw("ERROR - Invalid input"); break;
                case 5: logMessage(msg, 4); break;
                case 6: if (case_user(msg)) throw("ERROR - Invalid username"); break;
                case 7: return 0;
                default: error_line=__LINE__; throw invalid_argument("ERROR - Invalid option."); break;
            }
        }
    }
    catch (runtime_error &e){
        cout << e.what() << endl;
        logMessage("File 'levels.txt' failed to open", __FILE__, error_line);
        return 1;
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
        logMessage("Invalid input recived", __FILE__, error_line);
        return 1;
    }
    catch (...){
        cout << "ERROR - Unexpected error." << endl;
        logMessage("Unexpected error", __FILE__, __LINE__);
        return 1;
    }
}