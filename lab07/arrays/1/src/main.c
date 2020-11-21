
#include <stdio.h>

void result( char user[], char fill )
{
    int lw = 0;                  // длина слова 
    int ls;                      // длина строки

    int a;
    int b;

    for ( int i = 0; ; i++ )        
    {

        if ( user[i] == ' ' && lw == 0)
        {
            lw = i;
        }
        if ( user[i] == 0 )
        {
            ls = i;
            break;
        }
    }

    a = ( ls - lw ) / 2;
    b = a + lw - 1;

    printf("%d %d %d %d\n", a, b, lw, ls );

    for ( int i = ls - 1; i >= 0; i-- )
    {

        if ( i < a || i > b )
        {
            user[i] = fill;
        }
        else 
        {
            user[i] = user[i - a] ; 
        }
    }
}

int main()
{

    char user[] = "Ivanov        \0";
    char fill = '_';

    result( user, fill );

    printf("%s\n", user );

    return 0;
}

