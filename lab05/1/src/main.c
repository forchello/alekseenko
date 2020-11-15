#include <stdbool.h>

int main()
{
    int a = 2800;
    int b = 3500;
    int z;
    int f;

    if ( a < b ) {
        z = a;
        a = b;
        b = z;
    }
	
    while ( true )
    {
	f = a % b;
	
	if  ( f == 0 ) break;
	
	a = b;
	b = f;
    }
}

