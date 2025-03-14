#include "stringcomps.h"

bool char_comps(const char *str1, const char *str2){
    if (*str1=='\0' && *str2=='\0') return true;
    if (*str1=='\0' || *str2=='\0') return false;
    if (*str1==*str2) return char_comps(str1+1, str2+1);
    return false;
}

bool str_comps(const string& str1, const string& str2){
    return char_comps(str1.c_str(), str2.c_str());
}

constexpr bool const_char_comps(const char* str1, const char* str2){
    // if (*str1 == '\0' && *str2 == '\0') return true;
    // if (*str1 == '\0' || *str2 == '\0') return false;
    // if (*str1==*str2) return char_comps(str1+1, str2+1);
    // return false;

    return (*str1 == '\0' && *str2 == '\0') ? true  // Ambos vacíos -> iguales
           : (*str1 == '\0' || *str2 == '\0') ? false // Uno vacío y otro no -> distintos
           : (*str1 == *str2) ? const_char_comps(str1 + 1, str2 + 1) // Comparar el siguiente char
           : false; // Si hay diferencia, retorna false
}

void comp_time(){
    static_assert(const_char_comps("hola", "hola"), "Error: No son iguales");
    static_assert(!const_char_comps("hola", "mundo"), "Error: No debería ser igual");


    auto startTime = chrono::high_resolution_clock::now();
    char_comps("Según datos del Banco Central de la República Argentina (BCRA), alrededor del 60e los egresos por Viajes, pasajes y otros pagos con tarjeta son cancelados directamente por los clientes con fondos propios en moneda extranjera, lo que reduce el impacto deficitario de estos consumos en el mercado de cambios y en las reservas internacionales.", "Según datos del Banco Central de la República Argentina (BCRA), alrededor del 60e los egresos por Viajes, pasajes y otros pagos con tarjeta son cancelados directamente por los clientes con fondos propios en moneda extranjera, lo que reduce el impacto deficitario de estos consumos en el mercado de cambios y en las reservas internacionalas.");
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "A char_comps le tomo: " << elapsedTime.count() << " nanosegundos" << endl;

    startTime = chrono::high_resolution_clock::now();
    const_char_comps("Según datos del Banco Central de la República Argentina (BCRA), alrededor del 60e los egresos por Viajes, pasajes y otros pagos con tarjeta son cancelados directamente por los clientes con fondos propios en moneda extranjera, lo que reduce el impacto deficitario de estos consumos en el mercado de cambios y en las reservas internacionales.", "Según datos del Banco Central de la República Argentina (BCRA), alrededor del 60e los egresos por Viajes, pasajes y otros pagos con tarjeta son cancelados directamente por los clientes con fondos propios en moneda extranjera, lo que reduce el impacto deficitario de estos consumos en el mercado de cambios y en las reservas internacionalas.");
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<chrono::nanoseconds>(
    endTime - startTime);
    cout << "A const_char_comps le tomo: " << elapsedTime.count() << " nanosegundos" << endl;
}
