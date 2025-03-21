#ifndef SQUAREMTX_H
#define SQUAREMTX_H

#include "../Ej2/logmsg.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> create_mtx(int size);

void print_mtx(vector<int> mtx, int size);

void run_1();

#endif // SQUAREMTX_H