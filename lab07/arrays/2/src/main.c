#include <stdio.h>
#include <stdlib.h>

void result( int m[10] )
{
    int c = 0; 

    if (10 <= 0) 
    {
        exit(1);
    }

    for (int i = 2; i <= 10; i++)
    { 
        c = 0; 
        
        for (int z = 2; z < i; z++)
        {

            if (i % z == 0)
            {
                c = 1;
                break;
            }
        }
         
        if ( c == 0 )
        {
            
            m[i] = i;
        }       
    }
}


int main()
{

    int m[10] = {};
    
    result( m );

    return 0;
}