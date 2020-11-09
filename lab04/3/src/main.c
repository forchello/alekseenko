int main () 
{
    int k = 6;
    int m = 5;
    int n = 5;
    int z;

    if ( k == m && m == n && k == n) {
        return 2;

    }
    else {
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
    }



    return 0;
}