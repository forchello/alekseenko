int main()
{

    const float x = -2;
    float y;

    if ( x < -1 && x >= -3 ) {
        y = -x - 1;
    }
    else if ( x < 0 ) {
        y = x - 1;
    }
    else if ( x < 1 ) {
        y = -x - 1;
    }
    else if ( x <= 3 ) {
        y = x - 1;
    }
    return 0;

}