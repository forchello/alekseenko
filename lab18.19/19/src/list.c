/**
 * @file list.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Alekseenko N.
 * @date 21-yan-2021
 * @version 1.0
 */
 
#include "list.h"

list_type* create_list( FILE *read, int N )
{
    list_type* node = NULL;
    list_type* node_start = NULL;
    list_type* prev_node = NULL;

    char material[20];
    char ebook[6];

    for ( int i = 0; i < N; i++ )
    {
        node = (list_type*) malloc (sizeof(list_type));              // мы выделили место под один узел списка

        if ( node_start == NULL )
        {
            node_start = node;
            node -> prev = NULL;
        }   

        fscanf(read,"%s", ebook );
        node->mybook.ebook = bool_input(ebook);

        fscanf(read,"%s", node->mybook.name );
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