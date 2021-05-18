#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

class Array
{
    int size;
    int* CreateArray(int n);

public:

    int** ReadFile(string filename);

    double* Minimal( int** arrays );
    void WriteOut( string filename, double* res_arr );    
    void FreeMemory( int** arr );
};