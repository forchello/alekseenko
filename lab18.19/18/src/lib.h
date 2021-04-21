#ifndef defend
#define defend

/**
 * @file lib.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 27-feb-2021
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

/**
 * @function paste_function
 *
 */

char* insert( char *array1, char *array2, size_t k );
char* reduce( char *array1, size_t start, size_t end );					

void add_struct( book * mybook, int n);
void remove_struct( book * mybook, int n, int to_remove);
#endif