/**
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Alekseenko N.
 * @date 21-yan-2021
 * @version 1.0
 */
 
#include "lib.h"

char* insert( char *array1, char *array2, size_t k )
{
    int N = strlen ( array1 ) + strlen ( array2 ) + 1;
    
    char *str = (char *) malloc ( N );

    memcpy ( str, array1, k );
    memcpy ( str + k, array2, strlen(array2) );
    memcpy ( str + k + strlen(array2), array1 + k, strlen(array1 + k) );
    
    return str;
}

char* reduce( char *array1, size_t start, size_t end )
{
    char *str = (char *) malloc ( strlen ( array1 ) + 1 );

    memcpy ( str, array1, start );
    memcpy ( str + start, array1 + end + 1, strlen(array1) - end );

    return str;
}

void add_struct( book * book_array, int n)
{
    book add[1];

        add->ebook = rand() % 2;
        sprintf(add->name, "Книга №%d", rand() % 136 + 15);
        add->pages = rand() % 136 + 15;

        sprintf(add->myauthor.name, "Издательство №%d", rand() % 136 + 15);
        add->myauthor.version = rand() % 136 + 15;

        add->material = rand() % 2;
    
    memmove(book_array+n, add, sizeof(book));
}

void remove_struct(book * book_array, int n, int to_remove)
{
   
    memset(book_array+to_remove, ' ', sizeof(book));

    for(int i=to_remove;i<n;i++)
    {
        memmove(book_array+i, book_array+i+1, sizeof(book));
    }
}
