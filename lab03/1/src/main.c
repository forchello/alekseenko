#include <stdio.h>

int main ()
{
    const float R1 = 2.56646;
    const float R2 = 3.54442;
    const float R3 = 4.54881;
    float result;
    result = 1 / (1 / R1 + 1 / R2 + 1 / R3);
    return 0;
}
