#include "stringcomps.h"

bool str_comps(const string str1, const string str2){
    if (str1[0]=='\0' && str2[0]=='\0') return true;
    if (str1[0]==str2[0]) return str_comps(str1.substr(1), str2.substr(1));
    return false;
}

bool chars_comps(const char* str1, const char* str2){
    if (*str1=='\0' && *str2=='\0') return true;
    if (*str1=='\0' || *str2=='\0') return false;
    if (*str1==*str2) return chars_comps(str1+1, str2+1);
    return false;
}

constexpr bool const_chars_comps(const char *str1, const char *str2){
    if (*str1=='\0' && *str2=='\0') return true;
    if (*str1==*str2) return const_chars_comps(str1+1, str2+1);
    return false;
}

void run_4(){
    cout << endl << "========== Ej 4: String comparisons ==========" << endl;
    cout << "Comparing two strings, 507 characters each." << endl;

    string str1="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";
    string str2="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";

    char* chars1 = new char[str1.length()+1];
    char* chars2 = new char[str2.length()+1];

    str1.copy(chars1, str1.length());
    str2.copy(chars2, str2.length());
    chars1[str1.length()] = '\0';
    chars2[str2.length()] = '\0';
    
    auto startTime = chrono::high_resolution_clock::now();
    chars_comps(chars1, chars2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "Runtime: " << elapsedTime.count() << " nanoseconds." << endl;

    delete[] chars1;
    delete[] chars2;

    constexpr const char* const_char1="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";
    constexpr const char* const_char2="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";

    startTime = chrono::high_resolution_clock::now();
    constexpr bool const_result=const_chars_comps(const_char1, const_char2);
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "Compilation time: " << elapsedTime.count() << " nanoseconds." << endl;
}