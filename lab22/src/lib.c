#include "lib.h"

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

list_type* create_list( FILE *read, int N )
{
    list_type* node = NULL;
    list_type* node_start = NULL;
    list_type* prev_node = NULL;

    char material[20];
    char ebook[6];

    // подключаем библиотеку regex
    regex_t regex;                      

    // компилируем регулярку в переменную return_value;                       
    int return_value = regcomp(&regex, "^[A-ZА-ЯЁ]([A-ZА-Яa-zа-яё0-9]|([,?!\\. ][^\\.,?! ]))+", REG_EXTENDED);
    
    for ( int i = 0; i < N; i++ )
    {
        char temp[256] = {};

        node = (list_type*) malloc (sizeof(list_type));              // мы выделили место под один узел списка

        if ( node_start == NULL )
        {
            node_start = node;
            node -> prev = NULL;
        }   

        fscanf(read,"%s", ebook );
        node->mybook.ebook = bool_input(ebook);

        // читаем переменную с названием книги в temp переменную
        fscanf(read,"%s", temp );
        // если temp подходит требованиям regex и regexec вернул NULL - слово прошло проверку регулярки
        if ( regexec(&regex, temp, 0, NULL, 0 ) == 0 )
        {
            printf("%d.  REGEX SUCCESSFUL\n", i+1);
            strcpy(node->mybook.name, temp);
        }
        else
        {
            printf("%d.  REGEX ERROR\n", i+1);
        }

        fscanf(read,"%d", &node->mybook.pages );

        fscanf(read,"%s", node->mybook.myauthor.name );
        fscanf(read,"%d", &node->mybook.myauthor.version );

        fscanf(read,"%s", material );

        if ( strcmp(material, "tverda") == 0 )
            node->mybook.material = 0;

        if ( strcmp(material, "myaka") == 0 )
            node->mybook.material = 1;
        
        node -> next = NULL;
        node -> prev = prev_node; 

        if ( prev_node != NULL )
            prev_node -> next = node;

        prev_node = node;
                 
    }
    
    fseek(read, sizeof(read), SEEK_SET);
    rewind(read);
    
    return node_start;
}

list_type *push(list_type *list_begin)
{
    list_type *newNode = (list_type *)malloc(sizeof(list_type));

    newNode->mybook.ebook = rand() % 2;
    strcpy(newNode->mybook.name, "Моя книггер");         
    newNode->mybook.pages = rand() % 136 + 15;
    sprintf(newNode->mybook.myauthor.name, "Издательство №%d", rand() % 136 + 15);
    newNode->mybook.myauthor.version = rand() % 136 + 15;
    newNode->mybook.material = rand() % 2;

    newNode->next = list_begin;
    list_begin = newNode;

    return list_begin;
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

void output2 ( list_type *list_begin )                                           // вывод списка на экран
{   
    
    list_type *node = list_begin;
    int i = 0;
    printf("Книга №%d\n-------------\n", i++ );
    printf("Существует электронная версия книги - %s\n", bool_output(node->mybook.ebook) );
    

    printf("Название книги: %s\n", node->mybook.name );
    printf("Количество страниц: %d\n", node->mybook.pages );

    printf("Название издательства: %s\n", node->mybook.myauthor.name );
    printf("Версия книги: %d\n", node->mybook.myauthor.version );

    if ( node->mybook.material == tverda )
        printf("Обложка книги - твердая\n" );

    if ( node->mybook.material == myaka )
        printf("Обложка книги - мягкая\n" );

    printf("\n\n\n");
}

void output_format( list_type *list_begin, int n )
{
    list_type *node = list_begin;
    // подключаем библиотеку regex
    regex_t regex;
    // компилируем регулярку в переменную return_value;   
    int return_value = regcomp(&regex, ".+ .+", REG_EXTENDED);

    
    for ( int i = 0; i < n || node != NULL; i++)
    {   
        // если node->mybook.name подходит требованиям regex и regexec вернул NULL - слово прошло проверку регулярки
        if (regexec(&regex, node->mybook.name, 0, NULL, 0) == 0)
        {   
            // вызываем функцию output2
            output2( node );
        }

        node = node -> next;
    }
    // освобождаем место занятое regex
    regfree(&regex);
}