int main () 
{
    int k = 6;
    int m = 9;
    int n = 3;
    int z;

    if ( k >= m ) {
        z = k;
        k = m;
        m = z;
    }
     
    if ( m >= n ) {
        z = m;
        m = n;
        n = z;

        if ( k >= m ) {
            z = k;
            k = m;
            m = z;
        }
    }

    return 0;
}