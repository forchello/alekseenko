#ifndef DEFEND_1
#define DEFEND_1

#define DEBUG printf("'%s' function - %s  /  %s\n\n",  __FUNCTION__, __DATE__, __TIME__ )

/**
 * @file list.h
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

typedef struct list_name
{
	book mybook;
	struct list_name *next, *prev;
} list_type;




list_type* create_list( FILE *read, int lines );

#endif