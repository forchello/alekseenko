#include <stdio.h>

int main ()
{
    const int p = 8;    // основание системы исчисления
    int x1 = 5;         // старшая цифра                     
    int x2 = 4;                             
    int x3 = 2;                             
    int x4 = 5;         // младшая цифра

    printf ("Дано p = %d, a = %X%X%X%X, тогда:\n", p, x1, x2, x3, x4);
    printf ("Результат = %d\n", ((x1 * p + x2) * p + x3) * p + x4);
    return 0;
}