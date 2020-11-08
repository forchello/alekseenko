int main()
{
    float x = 123.456;
    int x1 = x;
    int x2 = (x - x1) * 1000;
    float rel;

    if ( x1 != 0 ) {
        rel = (x2 * 100 / x1) / 100.0;
    }
  
    return 0;
}