#include <stdio.h>

int main () 
{
    int x = 1599;       // создаем переменную 
    char a[100];        // создаем массив для хранения результирующей строки
    int p = 0;
    int w = 1000;
    int z;

    const char s[5][10][20] = {                 // 3-х мерный массив с вариациями названий частей числа
        { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" },
        { "", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" },
        { "", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred" },
        { "", "one thousand", "two thousand", "three thousand", "four thousand", "five thousand", "six thousand", "seven thousand", "eight thousand", "nine thousand" },
        { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" }
    } ;
 
    if ( x == 0 )                   // проверка на 0
    { 
        a[0] = 'z' ;
        a[1] = 'e' ;
        a[2] = 'r' ;
        a[3] = 'o' ;
        a[4] = '\0';
    }   
    else                           // если не 0, выполняется следующее:
    {
    	for ( int i = 3; i >= 0; i--)      // цикл перебора цифр числа, начиная со старшей
    	{

        	z = x / w % 10;                // выделение цифры из числа

        	if ( i == 1 && z == 1 )        // случай чисел от 10 до 19, стоящих в конце числа
        	{
            	i = 4;                     // используем отдельную часть массива с названиями чисел от 10 до 19
            	z = x % 10;                // нужное число определяется по младшей цифре
        	}

        	for ( int c = 0; s[i][z][c] != 0; c++)         // цикл копирования очередного названия части числа в строку результата
        	{
            	a[p++] = s[i][z][c];    
        	}

        	a[p++] = ' ';                                  // разделяем названия частей числа пробелами
        	w /= 10;

        	if (i == 4) break;                             // если уже есть числа от 11 до 19 - единицы не пишем
    	}

    	a[--p] = '\0';                                     // заканчиваем строку
    }

    printf("%i = %s\n", x , a);                             // вывод
    return 0;
}

    






