#include <stdio.h>

int main ()
{
    const float a = 2;
    float a2, a4, a6, a8, a10; 

    a2 = a * a; // создадим вспомогательную переменную

    a4 = a2 * a2;
    a6 = a4 * a2;
    a8 = a4 * a4;
    a10 = a4 * a6;

    printf ("Дано а = %f, тогда:\n", a);
    printf ("a^4 = %f, a^6 = %f, a^8 = %f, a^10 = %f\n", a4, a6, a8, a10);
    return 0;
}