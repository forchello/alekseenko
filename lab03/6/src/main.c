#include <stdio.h>

int main ()
{
    const int x1 = 50;
    const int x2 = 52;
    int N = x2 - x1 + 1;
    int S = ( x1 + x2 ) * N / 2 ;



    printf ("Result = %d\n", S);
    return 0;
}