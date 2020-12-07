#include <stdio.h>
#include "start_info.h"
#include "find_root.h"

int main()
{
    info();



    int a = 0;
    int b = 0;       // переменные
    int c = 0;
    int x = 0;
    int x1 = 0;
    int x2 = 0;

    scanf("%d %d %d", &a, &b, &c);      // задаем переменные

    int D = b * b - 4 * a * c;          // дискриминант

    if (D < 0) 
    {
        printf("Решений нет\n");
        return 0;
    }


    int i;                              // корень из дискриминанта

    for ( i = 0; i <= D / 2; i++)
    {
        if ( i * i >= D)
        {
            break;
        }
    }
 
    if  (( D - ( i - 1 ) * ( i - 1 ) < i * i - D ) && i != 0) i--;

    if ( D == 0 )
    {

        x = ( ( -1 * b ) + i ) / ( 2 * a );
        printf("Ответ: x = %d\n", x );

    }
    else 
    {
    
        x1 = ( -1 * b + i ) / 2 * a;
        x2 = ( -1 * b - i ) / 2 * a;

        printf("Ответ: x1 = %d, x2 = %d \n", x1, x2) ;

    }

    return 0;
}
    






