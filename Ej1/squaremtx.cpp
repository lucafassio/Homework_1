#include "squaremtx.h"

vector<vector<int>> create_mtx(int size){
    //size negativos y 0 no creo la matriz. Devuelvo vacia.
    if (size<1) return vector<vector<int>>();
    vector<vector<int>> mtx;
    int val=1;

    //creo n=size lineas.
    for (int i=0; i<size; i++){
        vector<int> line; 

        //agrego a cada linea n=size valores de forma ascendente.
        for (int j=0; j<size; j++) 
            line.push_back(val++); 
        
        mtx.push_back(line);
    }
    return mtx;
}

void print_mtx(vector<vector<int>> mtx, int size){
    //chequeo que la matriz no este vacia ni pasen mal el size.
    if (mtx.size()==0) return;
    if (size<1) return;

    //si la matriz es mayor a 15x15 solo muestro los ultimos 15^2 elementos de la matriz para no sobrecargar la terminal de numeros.
    if (size>15){
        for(int i=size*size-1; i>=size*size-225; i--)
            cout << "M₁[" << i/size << "][" << i%size << "] = " << mtx[i/size][i%size] << " " << endl;
            cout << "." << endl << "." << endl << "." << endl;
    }
    else{
        //i%n recorre de forma descendente de n-1 a 0 y i/n hace el mismo recorrido pero bajo el ratio un paso cada n-1 iteraciones.  
        for(int i=size*size-1; i>=0; i--)
            cout << "M₁[" << i/size << "][" << i%size << "] = " << mtx[i/size][i%size] << " " << endl;
    }
}

void run_1(){
    int error_line;
    cout << endl << "========== Ej 1: Square matrix ==========" << endl;
    try {
        cout << "Matrix size: ";
        int size;
        cin >> size;

        //si ingresan un size negativo o 0 lanzo un error.
        //si ingresan un char o string en vez de un int, cin.fail() devuelve true y lanzo un error. 
        if (cin.fail() || size<1){
            error_line=__LINE__+1;
            throw invalid_argument("ERROR - Invalid size.");
        }
        cout << "Creating " << size << "x" << size << " matrix..." << endl;

        //creo la matriz y la printeo.
        vector<vector<int>> mtx=create_mtx(size);
        cout << "Matrix created." << endl << endl;
        print_mtx(mtx, size);
    }

    //si detecto algun error lo informo, cierro el programa y loggeo el error.
    catch (invalid_argument &e){
        cout << e.what() << endl;
        logMessage(e.what(), __FILE__, error_line);
    }
    catch(...){
        cout << "Unexpected error" << endl;
        logMessage("Unexpected error", __FILE__, __LINE__);
    }
}