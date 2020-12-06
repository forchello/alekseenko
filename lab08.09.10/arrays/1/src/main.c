/**
 * @mainpage
 * # Загальне завдання
 * 1. **Центрувати** заданий рядок на площині із заданим заповнювачем
 * @author Alekseenko N.
 * @date 05-dec-2020
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Alekseenko N.
 * @date 05-dec-2020
 * @version 1.0
 */

#include <stdio.h>

/**
 * *Функція result*
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *  \param lw - довжина слова
 *  \param ls - довжина рядка
 *  \param fill - заповнювач
 *  \param a - початок слова, яке відцентроване
 *  \param b - кінець слова, яке відцентроване
 *  \param user[] - масив с текстом
 * - Визначення довжини слова та строки
 * - Знаходимо позицію початку і кінця слова, яке відцентроване
 * - Зсув слова в центр з одночасним заповненням решти елементів заповнювачем
 */

void result( char user[], char fill )
{
    int lw = 0;                  // длина слова 
    int ls;                      // длина строки

    int a;
    int b;

    for ( int i = 0; ; i++ )        
    {

        if ( user[i] == ' ' && lw == 0)
        {
            lw = i;
        }
        if ( user[i] == 0 )
        {
            ls = i;
            break;
        }
    }

    a = ( ls - lw ) / 2;
    b = a + lw - 1;

    printf("%d %d %d %d\n", a, b, lw, ls );

    for ( int i = ls - 1; i >= 0; i-- )
    {

        if ( i < a || i > b )
        {
            user[i] = fill;
        }
        else 
        {
            user[i] = user[i - a] ; 
        }
    }
}

/**
 * *Головна функція.*
 *
 * Послідовність дій:
 * - вивід результату роботи функції *result*
 * @return успішний код повернення з програми (0)
 */

int main()
{

    char user[] = "Ivanov        \0";
    char fill = '_';

    result( user, fill );

    printf("%s\n", user );

    return 0;
}

