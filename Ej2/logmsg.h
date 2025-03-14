#include <iostream>
#include <string>
#include <fstream>
#include "../Ej4/stringcomps.h"
using namespace std;

typedef basic_string<char> string;

bool file_exists(string nombreArchivo);

void logMessage(string msg, int level);

void logMessage(string msg, string file_name, int line);

void logMessage(string msg, string username);

string set_level(int level);

string add_level();