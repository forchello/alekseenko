/**
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Alekseenko N.
 * @date 21-yan-2021
 * @version 1.0
 */
 
#include "lib.h"

char* bool_output(bool b)
{
    return (b) ? ("есть") : ("нет");
}

bool bool_input(char *str)
{
    return ( strcmp(str, "true") == 0 ) ? true : false;
}


int read_from_file( FILE *read, book *book_array, int n )
{   
    int i;

    for ( i = 0; i < n; i++)
    {
        char material[20];
        char ebook[20];

        fscanf(read,"%s", ebook );
        fscanf(read,"%s", &book_array[i].name );
        fscanf(read,"%d", &book_array[i].pages );

        fscanf(read,"%s", &book_array[i].myauthor.name );
        fscanf(read,"%hd", &book_array[i].myauthor.version );

        fscanf(read,"%s", material );

        if ( strcmp(material, "tverda") == 0 )
            book_array[i].material = 0;

        if ( strcmp(material, "myaka") == 0 )
            book_array[i].material = 1;
        
        book_array[i].ebook = bool_input(ebook); 
    }

    return(i);
}

void output ( book *book_array, int n )
{   
    

    for ( int i = 0; i < n; i++)
    {
        printf("Книга №%d\n-------------\n", i+1 );
        printf("Существует электронная версия книги - %s\n", bool_output(book_array[i].ebook) );
        

        printf("Название книги: %s\n", book_array[i].name );
        printf("Количество страниц: %d\n", book_array[i].pages );

        printf("Название издательства: %s\n", book_array[i].myauthor.name );
        printf("Версия книги: %d\n", book_array[i].myauthor.version );

        if ( book_array[i].material == tverda )
            printf("Обложка книги - твердая\n" );

        if ( book_array[i].material == myaka )
            printf("Обложка книги - мягкая\n" );

        printf("\n\n\n");

    }

    printf("\n\n\n\n");
}

void write_to_file( FILE *write, book *book_array, int n )
{   
    for ( int i = 0; i < n; i++)
    {
        fprintf(write, "%s %s %d %s %d %s", bool_output(book_array[i].ebook), book_array[i].name, book_array[i].pages, 
         book_array[i].myauthor.name, book_array[i].myauthor.version, book_array[i].material == tverda ? "твердая" : "мягкая" );
    }
}


void sorting ( book *book_array, int n )
{
    printf("----------------------------------------\nЗадания на хорошо\n----------------------------------------\n----------------------------------------\nЗадание 2\n----------------------------------------\n\n\n");

    printf("[1]  · Наличие электронной версии;\n");
    printf("[2]  · Название книги;\n");
    printf("[3]  · Количество страниц;\n");
    printf("[4]  · Название издательства;\n");
    printf("[5]  · Версия изданной книги;\n");
    printf("[6]  · Вариант обложки;\n");


    int k = 0;

    printf("\n\nВведите критерий: ");
    scanf("%d", &k);

    printf("---------------------\n\n");
    switch ( k )
    {
        case 1:
            sorting_tf( book_array, n, k );
          break;

        case 2:
            sorting_abc( book_array, n, k );
            break;

        case 3:
            sorting_increase( book_array, n, k );
            break;   

        case 4:
            sorting_abc( book_array, n, k );
            break;

        case 5:
            sorting_increase( book_array, n, k );
            break;

        case 6:
            sorting_tf( book_array, n, k );
            break;
    }


    printf("\n\n\n\n");
}


void sorting_tf( book *book_array, int n, int k )
{
    bool temp;
    enum obl temp1;

    if ( k == 1 )
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n-1; j++) 
            {
                if (book_array[j].ebook < book_array[j+1].ebook) 
                {    
                    temp = book_array[j+1].ebook;
                    book_array[j+1].ebook = book_array[j].ebook;
                    book_array[j].ebook = temp;
                }
            }           
        
        }

        for (int i = 0; i < n; i++) 
            printf("%s\n", book_array[i].ebook == 1 ? "true" : "false"); 
    }
    
    if ( k == 6 )
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n-1; j++) 
            {   
                if (book_array[j].material < book_array[j+1].material) 
                {    
                    temp1 = book_array[j+1].material;
                    book_array[j+1].material = book_array[j].material;
                    book_array[j].material = temp1;
                }
            }           
        
        }

        for (int i = 0; i < n; i++) 
            printf("%s\n", book_array[i].material == tverda ? "твердая" : "мягкая"  ); 
    }
    
}


void sorting_increase( book *book_array, int n, int k)
{
    int temp;

    if ( k == 3 )
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n-1; j++) 
            {
                if (book_array[j].pages > book_array[j+1].pages) 
                {    
                    temp = book_array[j+1].pages;
                    book_array[j+1].pages = book_array[j].pages;
                    book_array[j].pages = temp;
                }
            }           
        
        }

        for (int i = 0; i < n; i++) 
            printf("%d\n", book_array[i].pages ); 
    }

    if ( k == 5 )
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n-1; j++) 
            {
                if (book_array[j].myauthor.version > book_array[j+1].myauthor.version) 
                {    
                    temp = book_array[j+1].myauthor.version;
                    book_array[j+1].myauthor.version =  book_array[j].myauthor.version;
                    book_array[j].myauthor.version = temp;
                }
            }           
        
        }

        for (int i = 0; i < n; i++) 
            printf("%d\n", book_array[i].myauthor.version ); 
    }

}

void sorting_abc( book *book_array, int n, int k)
{
    char temp[100];
    if ( k == 2 )
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n-1; j++) 
            {
                if ( strcmp( book_array[j].name, book_array[j+1].name) >= 0 ) 
                {    
                    strcpy(temp, book_array[j+1].name );
                    strcpy(book_array[j+1].name, book_array[j].name);
                    strcpy(book_array[j].name, temp );
                }
            }           
        
        }

        for (int i = 0; i < n; i++) 
            printf("%s\n", book_array[i].name ); 
    }
    
    if ( k == 4 )
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n-1; j++) 
            {
                if (strcmp( book_array[j].myauthor.name, book_array[j+1].myauthor.name) >= 0 ) 
                {    
                    strcpy(temp, book_array[j+1].myauthor.name );
                    strcpy(book_array[j+1].myauthor.name, book_array[j].myauthor.name);
                    strcpy(book_array[j].myauthor.name, temp );
                }
            }           
        
        }

        for (int i = 0; i < n; i++) 
            printf("%s\n", book_array[i].myauthor.name ); 
    }
}



int search_publish ( book arr[], int n )
{   

    int k = 0;

    for ( int i = 0; i < n; i++)
    {
        
        if ( strcmp(arr[i].myauthor.name, "ранок") == NULL )
            k++;
    }

    return k;
}



void random_filling ( book *book_array, int n )
{
    srand((unsigned int) time(NULL));

    for ( int i = 0; i < n; i++)
    {
        book_array[i].ebook = rand() % 2;
        sprintf(book_array[i].name, "Книга №%d", rand() % 136 + 15);
        book_array[i].pages = rand() % 136 + 15;


        sprintf(book_array[i].myauthor.name, "Издательство №%d", rand() % 136 + 15);
        book_array[i].myauthor.version = rand() % 136 + 15;

        book_array[i].material = rand() % 2;
    }

    printf("----------------------------------------\nЗадание 4\n----------------------------------------\n\n");

    for ( int i = 0; i < n; i++)
    {
        printf("Название книги: %s\n", book_array[i].name );
        printf("Количество страниц: %d\n", book_array[i].pages );

        printf("Название издательства: %s\n", book_array[i].myauthor.name );
        printf("Версия книги: %d\n", book_array[i].myauthor.version );

        if ( book_array[i].material == tverda )
            printf("Обложка книги - твердая\n" );

        if ( book_array[i].material == myaka )
            printf("Обложка книги - мягкая\n" );
        printf("\n\n");
    }

    printf("\n\n\n\n");

    printf("----------------------------------------\nЗадание 5\n----------------------------------------\n\n");

    printf("Передал структуру с указателем\n");
    printf("\n\n\n\n");
}


void write_to_binfile ( FILE *binwrite, book *book_array, int n )
{
    fwrite(book_array, sizeof(book), n, binwrite );
}


void read_from_binfile ( FILE *binread, book *book_array, int n)
{
    for ( int i = 0; i < n; i++)
    {
        fread(book_array + i, sizeof(book), 1, binread );
    }
}