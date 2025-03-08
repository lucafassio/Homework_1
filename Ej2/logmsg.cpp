#include "logmsg.h"

bool file_exists(const string& file_name){
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
    ofstream levels("Ej2/levels.txt", ios::app);
    levels << new_level << endl;
    levels.close();
    return new_level;
}