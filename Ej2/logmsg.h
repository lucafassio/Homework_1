#include <iostream>
#include <string>
#include <fstream>
#include "../Ej4/stringcomps.h"
using namespace std;

typedef basic_string<char> string;

void logMessage(string msg, int level);

void logMessage(string msg, string file_name, int line);

void logMessage(string msg, string username);

int case_error(string msg);

int case_user(string msg);

int run_2();