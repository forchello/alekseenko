#ifndef MYLIB.H
#define MYLIB.H

#define DEBUG printf("'%s' function - %s  /  %s\n\n",  __FUNCTION__, __DATE__, __TIME__ )

/**
 * @file mylib.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 28-mar-2021
 * @version 1.0
 */
 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	char name[100];
	int version;
} author;

typedef struct
{
	bool ebook;
	char name[100];
	int pages;

	author myauthor;

	enum obl {tverda, myaka} material;

} book;

typedef struct list_name
{
	book mybook;
	struct list_name *next, *prev;
} list_type;

/**
 * *Функція create_list*
 * Создает список количества lines узлов.
 * Сразу заполяет его, читая из файла (указатель на read).
 */
list_type* create_list( FILE *read, int lines );

/**
 * *Функція output*
 * N - количество узлов списка.
 * list_begin (он же head списка) - указатель на начало списка
 */
void output(list_type *list_begin, int N);

/**
 * *Функція write_to_file*
 * N - количество узлов списка.
 * list_begin (он же head списка) - указатель на начало списка
 * p_write - указатель на открытый заранее файл для записи.
 */
void write_to_file(FILE *p_write, list_type *list_begin, int N);

/**
 * *Функція search*
 * N - количество узлов списка.
 * list_begin (он же head списка) - указатель на начало списка
 */
void search(list_type *list_begin, int N);

/**
 * *Функція search_ranok*
 * N - количество узлов списка.
 * list_begin (он же head списка) - указатель на начало списка
 */
int search_ranok( list_type *list_begin, int N );

/**
 * *Функція push*
 * list_begin (он же head списка) - указатель на начало списка
 */
list_type* push( list_type *list_begin );

/**
 * *Функція add_to_list*
 * list_begin (он же head списка) - указатель на начало списка
 * pos_book - позиция добавления нового узла в список.
 */
list_type* add_to_list(list_type *list_begin, int pos_book);

/**
 * *Функція delete_elem_list*
 * list_begin (он же head списка) - указатель на начало списка
 * pos_book - позиция удаления нового узла в список.
 */
void delete_elem_list(list_type **list_begin, int pos_book );


/**
 * *Функція sorting*
 * list_begin (он же head списка) - указатель на начало списка
 * N - количество узлов списка.
 */
list_type* sorting ( list_type *list_begin, int N );

/**
 * *Функція unisort*
 * list_begin (он же head списка) - указатель на начало списка
 * N - количество узлов списка.
 */
list_type* unisort( list_type* list_begin, int k );

#endif