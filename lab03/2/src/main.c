#include <stdio.h>

int main ()
{
    const int x = 456;
    int x1; // старшая цифра
    int x2; // средняя цифра
    int x3; // младшая цифра
    float result;
    
    x1 = x / 100;
    x2 = x / 10 % 10;
    x3 = x % 10;
    result = x3 * 100 + x2 * 10 + x1;
    return 0;
}
