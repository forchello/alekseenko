int main()
{
    const float r = 4;
    const float PI = 3.14;
    float l;
    float s;
    float v;
    const char c;


    switch (c) {
        case 'l': 
            l = 2 * PI * r;
            break;

        case 's': 
            s = 2 * PI * r * r;
            break;

        case 'v': 
            v = (4 * PI * r * r* r) / 3;
            break;
    }

    return 0;
}