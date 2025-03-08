#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef basic_string<char> string;

bool file_exists(const string& nombreArchivo);

void logMessage(string msg, int level);

void logMessage(string msg, string file_name, int line);

void logMessage(string msg, string username);

string set_level(int level);

string add_level();