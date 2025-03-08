#include "stringcomps.h"

bool char_comps(const char *str1, const char *str2){
    if (*str1=='\0' && *str2=='\0') return true;
    if (*str1=='\0' || *str2=='\0') return false;
    if (*str1==*str2) return char_comps(str1+1, str2+1);
    return false;
}

bool str_comps(const string& str1, const string& str2){
    if (str1.empty() && str2.empty()) return true;
    if (str1.empty() || str2.empty()) return false;
    if (str1[0]==str2[0]) return str_comps(str1.substr(1), str2.substr(1));
    return false;
}

void comp_time(){
    auto startTime = chrono::high_resolution_clock::now();
    char_comps("Hello", "Hella");
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "A char_comps le tomo: " << elapsedTime.count()/1000 << " microsegundos" << endl;

    startTime = chrono::high_resolution_clock::now();
    str_comps("Hello", "Hella");
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "A str_comps le tomo: " << elapsedTime.count()/1000 << " microsegundos" << endl;
}
