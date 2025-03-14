#include "squaremtx.h"

vector<vector<int>> create_mtx(int size){
    if (size<1) return vector<vector<int>>();
    vector<vector<int>> mtx;
    int val=1;
    for (int i=0; i<size; i++){
        vector<int> line;
        for (int j=0; j<size; j++) 
            line.push_back(val++);
        mtx.push_back(line);
    }
    return mtx;
}

void print_mtx(vector<vector<int>> mtx, int size){
    if (mtx.size()==0) return;
    if (size<1) return;
    if (size>15){
        for(int i=size*size-1; i>=size*size-225; i--)
            cout << "M₁[" << i/size << "][" << i%size << "] = " << mtx[i/size][i%size] << " " << endl;
            cout << "." << endl << "." << endl << "." << endl;
    }
    else{
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
        if (cin.fail() || size<1) {
            error_line=__LINE__+1;
            throw invalid_argument("ERROR - Invalid size.");
        }
        cout << "Creating " << size << "x" << size << " matrix..." << endl;
        vector<vector<int>> mtx=create_mtx(size);
        cout << "Matrix created." << endl << endl;
        print_mtx(mtx, size);
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
        logMessage(e.what(), __FILE__, error_line);
    }
    catch(...){
        cout << "Unknown error" << endl;
        logMessage("Unknown error", __FILE__, __LINE__);
    }
}