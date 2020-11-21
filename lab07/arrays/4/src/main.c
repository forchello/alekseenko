#include <stdio.h>

int result( int words, int n, char m[] )
{
    while (m[n] != '\0') 
        {
            n++;                // ищу количество символов  в массиве
        }

        for (int i = 0; i < n; i++)        // цикл для определения количества слов
        {

            if (m[i] != ' ' && m[i + 1] <= ' ')     // здесь мы игнорируем пробелы и правильно считаем слова
            {
                words++;
            }
        }

    return words;
}




int main() 
{
        int words = 0;          // количество слов
        int n = 0;              // количество символов в массиве 
        char m[] = "Counter Strike Global Offensive";  // переменная, в которую мы пишем предложение

        words = result( words, n, m );


        printf("%d\n", words );

     	return 0;
}
