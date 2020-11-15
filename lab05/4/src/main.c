int main()
{
    int a = 6;
    int s = 0;
    int b = 0;  // переменная слежения 

    for ( int i = 1; i < a; i++ ) 
    {

        if ( a % i == 0 ) 
        {
            s += i; 

            if ( s == a )
            {
                b = 1;    // если b = 1 - число совершенно
                break;
            }
            else if ( s > a )
            {
                break;
            }
        }

    } 
    return 0;
}