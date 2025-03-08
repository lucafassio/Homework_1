#include "squaremtx.cpp"
#include "list.cpp"

int main(){
    // EJ 1
    cout << "Ejercicio 1:" << endl;
    int size=3;
    cout << "Enter the size of the matrix: ";
    //cin >> size;
    vector<vector<int>> mtx=create_mtx(size);
    print_mtx(mtx, size);

    // Ej 3
    cout << endl <<  "Ejercicio 3:" << endl;
    // Falta hacer main
    return 0;
  }