#include <stdio.h>

int main ()
{
    const int p = 8;    // основание системы исчисления
    int x1 = 5;         // старшая цифра                     
    int x2 = 4;                             
    int x3 = 2;                             
    int x4 = 5;         // младшая цифра
    float result;
      
    result = ((x1 * p + x2) * p + x3) * p + x4;
    return 0;
}
