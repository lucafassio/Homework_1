#include "stringcomps.h"

//comparo strings de forma recursiva (no recomendado para strings muy largos).
bool str_comps(const string str1, const string str2){
    //si ambos strings son vacias, llegaron al final, entonces son iguales.
    if (str1[0]=='\0' && str2[0]=='\0') return true;

    //si ambos strings tienen el mismo primer caracter, continuo la comparacion descartando el caracter visto.
    if (str1[0]==str2[0]) return str_comps(str1.substr(1), str2.substr(1));

    //si algun caracter es distinto, corto la comparacion, son distintos.
    return false;
}

//comparo punteros a char siguiendo la misma idea que para los strings.
bool chars_comps(const char* str1, const char* str2){
    if (*str1=='\0' && *str2=='\0') return true;
    if (*str1==*str2) return chars_comps(str1+1, str2+1);
    return false;
}

//agrego constexpr para que la comparacion se haga en tiempo de compilacion, la logica sigue siendo la misma.
constexpr bool const_chars_comps(const char *str1, const char *str2){
    if (*str1=='\0' && *str2=='\0') return true;
    if (*str1==*str2) return const_chars_comps(str1+1, str2+1);
    return false;
}

void run_4(){
    cout << endl << "========== Ej 4: String comparisons ==========" << endl;
    cout << "Comparing two equal strings, 507 characters each." << endl;

    //dos strings iguales de 507 caracteres.
    const char* str1="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";
    const char* str2="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";

    auto startTime = high_resolution_clock::now();
    cout << "Runtime comparison result: ";
    if (chars_comps(str1, str2)) cout << "strings are equal." << endl;
    else cout << "strings are diferent." << endl;
    auto endTime = high_resolution_clock::now();
    auto elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Time: " << elapsedTime.count() << " nanoseconds." << endl;

    //mismos dos strings iguales.
    constexpr const char* const_char1="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";
    constexpr const char* const_char2="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";

    //comparo los strings y mido el tiempo de compilacion.
    startTime = high_resolution_clock::now();
    constexpr bool const_result=const_chars_comps(const_char1, const_char2);
    cout << "Compilation comparison result: ";
    if (const_result) cout << "strings are equal." << endl;
    else cout << "strings are diferent." << endl;
    endTime = high_resolution_clock::now();
    elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Time: " << elapsedTime.count() << " nanoseconds." << endl;

    cout << endl << "Comparing two different strings, 507 characters each." << endl;

    //cambio el ultimo caracter para forzar el peor caso.
    const char* diff_str1="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";
    const char* diff_str2="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer,";

    startTime = high_resolution_clock::now();
    cout << "Runtime comparison result: ";
    if (chars_comps(str1, str2)) cout << "strings are equal." << endl;
    else cout << "strings are diferent." << endl;
    endTime = high_resolution_clock::now();
    elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Time: " << elapsedTime.count() << " nanoseconds." << endl;

    //mismos dos strings con el mismo cambio.
    constexpr const char* diff_const_char1="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer.";
    constexpr const char* diff_const_char2="Lorem ipsum dolor sit amet consectetur adipiscing elit, viverra senectus primis felis sagittis tristique, aliquam duis luctus arcu nibh facilisis. Ultrices nisi tincidunt ante nam gravida scelerisque quam phasellus curae augue eu inceptos lacus habitant, venenatis vel himenaeos varius parturient lectus rutrum mus pretium diam morbi purus. Pellentesque risus commodo dignissim bibendum venenatis ullamcorper fermentum, suspendisse pharetra rutrum dis et ultricies, sollicitudin dictum congue in ac integer,";

    //comparo los strings y mido el tiempo de compilacion.
    startTime = high_resolution_clock::now();
    constexpr bool diff_const_result=const_chars_comps(diff_const_char1, diff_const_char2);
    cout << "Compilation comparison result: ";
    if (diff_const_result) cout << "strings are equal." << endl;
    else cout << "strings are diferent." << endl;
    endTime = high_resolution_clock::now();
    elapsedTime = duration_cast<nanoseconds>(endTime - startTime);
    cout << "Time: " << elapsedTime.count() << " nanoseconds." << endl;
}