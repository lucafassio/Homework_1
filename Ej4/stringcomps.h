#ifndef STRINGCOMPS_H
#define STRINGCOMPS_H

#include "../Ej2/logmsg.h"
#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

typedef basic_string<char> string;

bool str_comps(const string str1, const string str2);

bool chars_comps(const char* str1, const char* str2);

constexpr bool const_chars_comps(const char* str1, const char* str2);

void run_4();

#endif // STRINGCOMPS_H