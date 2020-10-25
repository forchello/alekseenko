#include <stdio.h>

int main ()
{
    const int x = 259;
    int x1;                 // старшая цифра
    int x2;                 // средняя цифра
    int x3;                 // младшая цифра
    float y = 100;

    x1 = x / 100;
    x2 = x / 10 % 10;
    x3 = x % 10;

    printf ("Result = %f\n", x1 * 100 / x3 / y);
    return 0;
}