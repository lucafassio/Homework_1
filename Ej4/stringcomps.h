#include <iostream>
#include <string>
#include <chrono>
using namespace std;

typedef basic_string<char> string;

bool char_comps(const char *str1, const char *str2);

bool str_comps(const string& str1, const string& str2);

constexpr bool const_char_comps(const string& str1, const string& str2);

void comp_time();
