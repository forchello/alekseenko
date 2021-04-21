#define N 3             // задаем константу (размерность матрицы) 

void result( int matr[N][N], int final[N][N])
{
    
    for (int i = 0; i < N; i++)         // цикл для нахождения квадрата матрицы 
    {
        for (int j = 0; j < N; j++) 
        {
            final[i][j] = 0;           // чистим final от мусора

            for(int k = 0; k < N; k++) 
            {
                final[i][j] += matr[i][k] * matr[k][j];   // находим умножение матрицы на нее же.
            }
        }
    }


}



int main()
{
    
    int matr[N][N] = {      // создаем матрицу N-го порядка
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
    };                      

    int final[N][N];        // переменная для результата
    
    result ( matr, final );

    return 0;
}