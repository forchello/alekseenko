#include <stdlib.h>
#include <time.h>

int result(int x)
{
    int a1 = 0;
    int a2 = 0;
    int b = 0;

    for ( int i = 1; i < 4; i++ )
    {
        a1 = a1 + ( x % 10 );
        x /= 10;
    }


    for ( int i = 1 ; i < 4; i++ )
    {
        a2 = a2 + ( x % 10 );
        x /= 10;
    }


    if ( a1 == a2 ) 
    {
        b = 2; // если билет счастливый
    } 
    else 
    {
        b = 1; // если билет несчатливый
    }  

    return b;
} 



int main () 
{

    srand ( time(NULL) );

    int x = rand() % 1000000;
    int b = 0;

    b = result(x);

    return 0;
}

    






