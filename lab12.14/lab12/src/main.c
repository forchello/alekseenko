/**
 * @mainpage
 * # Загальне завдання
 * 1. **Разрахувати** кількість ділянок, які утворюють безперервні послідовності чисел з не-зменшуваними значеннями. Максимальну ділянку переписати у інший масів.
 * @author Alekseenko N.
 * @date 17-jan-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Alekseenko N.
 * @date 17-jan-2021
 * @version 1.0
 */

 #include <stdio.h>

 #define N 4            // количество чисел в массиве
 #define M 10

/**
 * *Функція result*
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *  \param r - показчик на кінець максимальної послідовності
 *  \param l - довжина поточної послідовності
 *  \param c - кількість послідовностей
 *  \param m - довжина максимальної послідовності
 * - шукаємо позитивну послідовность з максимальною сумою
 * - обробляємо останню послідовність
 * - копіюємо максимальну послідовність у вихідний масив
 *  @return кількості послідовності (с)
 */

int result (float *mas, float *res, int n, int *pm )
{
    float *p;
    float *r;                                                       // указатель на конец максимальной последовательности
    float *q;

    int l = 1;                                                      // длина текущей последовательности
    int c = 0;                                                      // количество последовательностей
    int m = 0;                                                      // длина максимальной последовательности


    for ( p = mas; p < mas + n - 1; p++ )                           // поиск положительной последовательности с максимальной суммой
    {
        if ( p[0] > p[1] )                                          // проверка конца последовательности
        {
            c++;
            if (l > m)                                              // ищем максимальную последовательность
            {
                r = p;
                m = l;
                l = 1;
            }
        }
        else
        {
            l++;
        }
    }


    c++;                                     

    if (l > m)                              // обработка последней последовательности
    {
        r = p;
        m = l;
    }

    q = res;                        

    for ( p = r - m + 1; p <= r ; p++ )     // копирование максимальной последовательности в выходной массив       
    {
        *q++ = *p;
    }

    *pm = m;

    return c;
}

/**
 * *Функція main*
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *  \param mas[] - вхідний масив
 *  \param res[N] - результуючий масив
 *  \param c - кількість послідовностей
 *  \param m - довжина максимальної послідовності
 *  @return успішний код повернення з програми (0)
 */

int main () 
{
    float mas[N] = {1.1 , 1.2 , 1.3 , 0.9 };                         // входной массив
                 
    char name;
    char lastname[M+1];

        gets ( lastname );

        printf("Ваша фамилия: ");

        puts ( lastname );

        name = getc ( stdin );

        printf("Ваше имя: ");

        putc ( name, stdout );


    printf("\n\nВход в программу: 1\n");
    printf("Выход из программы: 0\n");
    char on;
    
    read ( 0, &on, 1);
    write ( 1, &on, 1);

    if ( on == '0')
    {
        printf("\n");
        return 0;
    }

    if ( on == '1')
    {

        printf("\nВведите числа:\n");

        for ( int i = 0; i < N; i++)
        {
            scanf("%f", &mas[i] );
        }
        
        float res[ N ];                                                 // результирующий массив

        int c = 1;                                                      
        int m = 0;                                                      

        c = result( mas, res, N, &m );


        //printf("c = %d\n", c);

        printf("\n");

        for ( int i = 0; i < m; i++)            // вывод 
                                        
        {
            printf("res[%d] = %f\n", i, res[i]);
        }
    }




    
    
    return 0;
}

    






