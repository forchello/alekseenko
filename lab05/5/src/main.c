int main()
{
    int x = 625;
    int i;

    for ( i = 1; i < x / 2; i++)
    {
        if ( i * i >= x)
        {
            break;
        }
    }

    if  ( x - ( i - 1 ) * ( i - 1 ) < i * i - x ) i--;

    return 0;
}   