#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream archivo("mil_a.txt"); // Crea o abre el archivo

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    for (int i = 0; i < 1000; i++) {
        archivo << "a";
    }

    archivo.close();
    cout << "Se escribieron 1000 'a' en 'mil_a.txt' 😎" << endl;

    return 0;
}
