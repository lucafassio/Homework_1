#include "logmsg.h"

int error_line;

bool file_exists(string file_name){
    ifstream archivo(file_name);
    return archivo.good();
}

void logMessage(string msg, int level){
    if (!file_exists("Ej2/log.txt")){
        ifstream log("Ej2/log.txt"); 
        log.close();
    } 
    ofstream log("Ej2/log.txt", ios::app);
    log << set_level(level) + " <" + msg + ">" << endl;
    log.close();
}

void logMessage(string msg, string file_name, int line){
    if (!file_exists("Ej2/log.txt")){
        ifstream log("Ej2/log.txt"); 
        log.close();
    }
    ofstream log("Ej2/log.txt", ios::app);
    log << "[ERROR] " << file_name << ":" << to_string(line) << " - <" << msg << ">" << endl;
    log.close();
}

void logMessage(string msg, string username){
    if (!file_exists("Ej2/log.txt")){
        ifstream log("Ej2/log.txt"); 
        log.close();
    }
    ofstream log("Ej2/log.txt", ios::app);
    log << "[SECURITY] User: " << username << " - " << msg << endl;
    log.close();
}

string set_level(int level){
    ifstream levels("Ej2/levels.txt");
    string level_str;
    for (int i=0; i<level; i++)
        if (!getline(levels, level_str)){
            level_str=add_level();
            break;
        }
    levels.close();
    return level_str;
}

string add_level(){
    string new_level;
    cout << "Enter the new level: ";
    cin >> new_level;
    new_level="["+new_level+"]";
    string comparing;
    ifstream levels_reading("Ej2/levels.txt");
    while (getline(levels_reading, comparing))
        if (str_comps(comparing, new_level)){
            cout << "ERROR - The level already exists." << endl;
            levels_reading.close();
            return new_level;
        }
    levels_reading.close();
    ofstream levels_app("Ej2/levels.txt", ios::app);
    levels_app << new_level << endl;
    levels_app.close();
    return new_level;
}

void reset_levels(){
    ifstream old_levels("Ej2/levels.txt");
    vector<string> lines;
    string line;
    int count = 0;
    while (getline(old_levels, line) && count < 6) {
        lines.push_back(line);
        count++;
    }
    old_levels.close();
    ofstream new_levels("Ej2/levels.txt", ofstream::trunc);
    for (const string &l : lines){
        new_levels << l << endl;
    }
    new_levels.close();
}

int run_2(){
    cout << endl << "========== Ej 2: Log messages ==========" << endl;
    
    try{
        while (true){
            cout << "Select the event level:" << endl;
            int num=1;
            string option;
            ifstream levels_file("Ej2/levels.txt");
            if (!levels_file.is_open()){
                error_line=__LINE__+1;
                throw runtime_error("ERROR - File 'levels.txt' failed to open.");
            } 
            while (getline(levels_file, option)){
                cout << num << ". " << option << endl;
                num++;
            }
            levels_file.close();
            cout << num << ". Add new level" << endl  << num+1 << ". Reset levels" << endl << num+2 << ". Exit" << endl << "> ";
            int level_selected;
            cin >> level_selected;
            if (cin.fail() || level_selected>num+2){
                cin.clear();
                cin.ignore(10000, '\n');
                error_line=__LINE__+1;
                throw invalid_argument("ERROR - Invalid option.");
            }
            if (level_selected==num) {add_level();  continue;}
            else if (level_selected==num+1) {reset_levels(); continue;}
            else if (level_selected==num+2) return 0;

            string msg;
            cout << "Enter the message: ";
            cin.ignore();
            getline(cin, msg);

            if (level_selected==4) {
                cout << "Enter the file name: ";
                string file_name;
                cin >> file_name;
                cout << "Enter the line number: ";
                int line;
                cin >> line;
                if (line<0){
                    error_line=__LINE__+1;
                    throw invalid_argument("ERROR - Invalid line number.");
                }
                logMessage(msg, file_name, line);
            } else if (level_selected==6) {
                cout << "Enter the username: ";
                string username;
                cin.ignore();
                getline(cin, username);
                logMessage(msg, username);
            } 
            else logMessage(msg, level_selected);
            cout << endl;
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
        cout << "ERROR - Unknown error." << endl;
        logMessage("Unknown error", __FILE__, -1);
        return 1;
    }
}