#include "squaremtx.h"

vector<vector<int>> create_mtx(int size){
    vector<vector<int>> mtx(size, vector<int>(size, 0));
    int val=size*size;
    for (int i = size*size-1; i>=0; i--) {
        mtx[i/size][i%size]=val;
        val--;
    }
    return mtx;
  }

void print_mtx(vector<vector<int>> mtx, int size){
    for(int i=size*size-1; i>=0; i--){
        cout << "M₁[" << i/size << "][" << i%size << "] = " << mtx[i/size][i%size] << " " << endl;
    }
  }