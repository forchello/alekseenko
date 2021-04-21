#ifndef DEFEND_2
#define DEFEND_2


/**
 * @file data.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 27-feb-2021
 * @version 1.0
 */

#include "list.h"

void output(list_type *list_begin, int N);

void write_to_file(FILE *p_write, list_type *list_begin, int N);

void search(list_type *list_begin, int N);

list_type* push( list_type *list_begin );

list_type* add_to_list(list_type *list_begin, int pos_book);

void delete_elem_list(list_type **list_begin, int pos_book );



list_type* sorting ( list_type *list_begin, int N );
list_type* unisort( list_type* list_begin, int k );


#endif