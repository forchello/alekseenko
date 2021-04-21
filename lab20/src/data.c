/**
 * @file data.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Alekseenko N.
 * @date 21-yan-2021
 * @version 1.0
 */
 
#include "list.h"
#include "data.h"

//---------------------------------------------//
//                bool settings                //
//                                             //
char* bool_output(bool b)
{
    return (b) ? ("есть") : ("нет");
}

char* bool_help_output(bool b)
{
    return (b) ? ("true") : ("false");
}

bool bool_input(char *str)
{
    if ( strcmp(str, "true") == 0 )
        return true;
    else
        return false;
}

//---------------------------------------------//



int find_strings(FILE *read)
{
    

    int lines_count = 0;
    while (! feof(read))
    {
        if (fgetc(read) == '\n')
            lines_count++;
    }

	fseek(read, sizeof(read), SEEK_SET);
    rewind(read);

    return lines_count + 1;
}

void output ( list_type *list_begin, int n )                                           // вывод списка на экран
{   
    
    list_type *node = list_begin;
    
    for ( int i = 0; i < n || node != NULL; i++)
    {
        
        printf("Книга №%d\n-------------\n", i+1 );
        printf("Существует электронная версия книги - %s\n", bool_output(node->mybook.ebook) );
        

        printf("Название книги: %s\n", node->mybook.name );
        printf("Количество страниц: %d\n", node->mybook.pages );

        printf("Название издательства: %s\n", node->mybook.myauthor.name );
        printf("Версия книги: %d\n", node->mybook.myauthor.version );

        if ( node->mybook.material == tverda )
            printf("Обложка книги - твердая\n" );

        if ( node->mybook.material == myaka )
            printf("Обложка книги - мягкая\n" );

        printf("\n");

        node = node -> next;

    }
    printf("\n\n\n\n");
}

void write_to_file(FILE *write, list_type *list_begin, int n)
{
    fseek(write, sizeof(write), SEEK_SET);
    rewind(write);

    list_type *node = list_begin;

    for ( int i = 0; i < n; i++)
    {
        fprintf(write, "%s ", bool_help_output(node->mybook.ebook));
        fprintf(write, "%s ", node->mybook.name);
        fprintf(write, "%d ", node->mybook.pages);
        fprintf(write, "%s ", node->mybook.myauthor.name);
        fprintf(write, "%d ", node->mybook.myauthor.version);
        if( node->mybook.material == 0 )
            fprintf(write, "tverda" );
        if( node->mybook.material == 1 )
            fprintf(write, "myaka" );

        if( i + 1 != n)    
            fprintf(write, "\n");


        node = node -> next;
    }

    fseek(write, sizeof(write), SEEK_SET);
    rewind(write);
}

void search( list_type *list_begin, int n)
{   
    DEBUG;
    list_type *node = list_begin;

    printf("\n");
    printf("[1]  · Наличие электронной версии;\n");
    printf("[2]  · Название книги;\n");
    printf("[3]  · Количество страниц;\n");
    printf("[4]  · Название издательства;\n");
    printf("[5]  · Версия изданной книги;\n");
    printf("[6]  · Вариант обложки;\n");

    short int flag1;
    int flag3;
    char flag2[100];
    printf("\nВведите критерий: ");
    scanf("%hd", &flag1 );
    
    
    switch(flag1)
    {
        case 1:
        {
            scanf("%s", flag2);
            for ( int i = 0; i < n; i++)
            {   
                if ( node->mybook.ebook == bool_input(flag2) )
                    printf("- %s (%s)\n", bool_output(node->mybook.ebook), node->mybook.name );

                node = node->next;
            }

            break;
        }
            
        case 2:
        {
            scanf("%s", flag2);
            for ( int i = 0; i < n; i++)
            {   
                if ( strcmp(flag2, node->mybook.name) == 0 )
                {
                    printf("\n\t- %s\n", node->mybook.name );
                    printf("\n- Такая книга существует, она %d по номеру.\n", i+1 );
                }
                    
                    
                node = node->next;
            }

            break;
        }
        case 3:
        {
            scanf("%d", &flag3);
            for ( int i = 0; i < n; i++)
            {
                if ( flag3 == node->mybook.pages )
                    printf("- %d страниц (%s)\n", node->mybook.pages, node->mybook.name  );

                node = node->next;
            }

            break;
        }
        case 4:
        {
            scanf("%s", flag2);
            for ( int i = 0; i < n; i++)
            {
                if ( strcmp(flag2, node->mybook.myauthor.name) == 0 )
                    printf("- %s (%s)\n", node->mybook.myauthor.name, node->mybook.name);

                node = node->next;
            }

            break;
        }
        case 5:
        {
            scanf("%d", &flag3);
            for ( int i = 0; i < n; i++)
            {
                if ( flag3 == node->mybook.myauthor.version )
                    printf("- %d (%s)\n", node->mybook.myauthor.version, node->mybook.name);

                node = node->next;
            }

            break;
        }
        case 6:
        {
            printf("\tтвердая обложка - 0, мягкая - 1\n\n");
            scanf("%d", &flag3);
        
            for ( int i = 0; i < n; i++)
            {
                if ( flag3 == node->mybook.material )
                {
                    if( node->mybook.material == 0 )
                        printf("- твердая обложка (%s)\n", node->mybook.name);
                    if( node->mybook.material == 1 )
                        printf("- мягкая обложка (%s)\n", node->mybook.name);
                }

                node = node->next;
            }

            break;
        }
    }
}

list_type *push(list_type *list_begin)
{
    list_type *newNode = (list_type *)malloc(sizeof(list_type));

    newNode->mybook.ebook = rand() % 2;
    sprintf(newNode->mybook.name, "Книга №%d", rand() % 136 + 15);         
    newNode->mybook.pages = rand() % 136 + 15;
    sprintf(newNode->mybook.myauthor.name, "Издательство №%d", rand() % 136 + 15);
    newNode->mybook.myauthor.version = rand() % 136 + 15;
    newNode->mybook.material = rand() % 2;

    newNode->next = list_begin;
    list_begin = newNode;

    return list_begin;
}

list_type *add_to_list(list_type *list_begin, int index)
{
    if (index == 0)
    {
        list_begin = push(list_begin);
    }
    else
    {
        list_type *node = list_begin;
        int i;
        for (i = 0; i < index - 1; i++)
        {
            node = node->next;
        }
        node->next = push(node->next);
    }

    return list_begin;
}

void delete_elem_list(list_type **list_begin, int index )
{
    list_type *node = *list_begin;
    list_type *del_pos = NULL;
    
    if ( index == 0 )
    {
        del_pos = *list_begin;
        *list_begin = node->next;
        free(del_pos);
        return;
    }

    for ( int i = 0; i < index - 1; i++ )
        node = node->next;                  
    

    del_pos = node->next;
    node->next = node->next->next;
    free(del_pos);
}

list_type* sorting ( list_type *list_begin, int n )
{
    printf("[1]  · Наличие электронной версии;\n");
    printf("[2]  · Название книги;\n");
    printf("[3]  · Количество страниц;\n");
    printf("[4]  · Название издательства;\n");
    printf("[5]  · Версия изданной книги;\n");
    printf("[6]  · Вариант обложки;\n");


    short int k = 0;
    printf("\n\nВведите критерий: ");
    scanf("%hd", &k);

    printf("---------------------\n\n");
    
    list_begin = unisort( list_begin, k );

    printf("\n\n");

    return list_begin;
}

list_type* unisort(list_type *list_begin, int k )
{
    list_type *node = list_begin;
    list_type *n1, *n2, *n3, *n4;

    bool flag;

    while( node -> next != NULL )
    {
        switch ( k )
        {   
            case 1:
            {
                flag = node->mybook.ebook < node->next->mybook.ebook;
                break;
            }
            case 2:
            {
                flag = strcmp( node->mybook.name, node->next->mybook.name ) > 0 ;
                break;
            }
            case 3:
            {
                flag = (node->mybook.pages) > (node->next->mybook.pages);
                break;
            }
            case 4:
            {
                flag = strcmp( node->mybook.myauthor.name, node->next->mybook.myauthor.name ) > 0 ;
                break;
            }
            case 5:
            {
                flag = (node->mybook.myauthor.version) > (node->next->mybook.myauthor.version);
                break;
            }
            case 6:
            {
                flag = node->mybook.material == myaka && node->next->mybook.material == tverda;
                break;
            }
        }

        if( flag )
        {
            n1 = node -> prev;
            n2 = node;
            n3 = node -> next;
            n4 = node -> next -> next;

            if ( n1 == NULL )
                list_begin = n3;
            else
                n1 -> next = n3;

            n3 -> next = n2;
            n2 -> next = n4;

            n3 -> prev = n1;
            n2 -> prev = n3;

            if ( n4 != NULL )
                n4 -> prev = n2;
            
            if ( n1 != NULL)
                node = n1;
        }
        else 
            node = node->next;
    }

    return list_begin;
}