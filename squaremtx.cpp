#include "squaremtx.h"

vector<int> create_mtx(int size){
    vector<int> mtx(size);
    for(int i=0; i<size; i++){
        vectro<int> row(size);
        for(int j=0; j<size; j++){
            row[j] = i*size+j;
        }
        mtx.push_back(row);
    }
    return mtx;
}

void print_mtx(vector<int> mtx, int size){
    for(int i=size*size-1; i>=0; i--){
        cout << "M₁[" << i/size << "][" << i%size << "] = " << mtx[i] << " ";
        cout << endl;
    }
}