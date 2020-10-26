int main ()
{
    const float a = 2;
    float a2, a4, a6, a8, a10; 

    a2 = a * a; // создадим вспомогательную переменную

    a4 = a2 * a2;
    a6 = a4 * a2;
    a8 = a4 * a4;
    a10 = a4 * a6;
    
    return 0;
}
