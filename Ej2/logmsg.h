#ifndef LOGMSG_H
#define LOGMSG_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

enum levels {
    DEBUG=1,
    INFO, 
    WARNING, 
    ERROR, 
    CRITICAL, 
    SECURITY, 
    EXIT
};

vector<string> level_names={
    "[DEBUG]", 
    "[INFO]", 
    "[WARNING]", 
    "[ERROR]", 
    "[CRITICAL]", 
    "[SECURITY]"
};

typedef basic_string<char> string;

void logMessage(string msg, levels level);

void logMessage(string msg, string file_name, int line);

void logMessage(string msg, string username);

bool has_space(string str);

int case_error(string msg);

int case_user(string msg);

int run_2();

#endif // LOGMSG_H