int main()
{

    const float x = 2;
    float y;

    if ( x < -1 ) {
        y = -1 / x;
    }
    else if ( x < 1 ) {
        y = x * x;
    }
    else {
        y = 1;
    }

    return 0;

}