#ifndef defend
#define defend

/**
 * @file lib.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 12-yan-2021
 * @version 1.0
 */
 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	char name[100];
	unsigned short version;
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
 * @function read_from_file
 *
 */

int read_from_file( FILE *read, book *book_array, int N );

/**
 * @function write_to_file
 *
 */

void write_to_file( FILE *write, book *book_array, int N );

/**
 * @function output
 *
 */

void output(book *book_array, int N);

/**
 * @function sorting
 *
 */

void sorting ( book *book_array, int N );

/**
 * @function sorting_tf
 *
 */
void sorting_tf( book *book_array, int N, int k );

/**
 * @function sorting_abc
 *
 */
void sorting_abc( book *book_array, int N, int k );

/**
 * @function sorting_increase
 *
 */
void sorting_increase( book *book_array, int N, int k );




/**
 * @function search_publish
 *
 */
int search_publish ( book arr[], int N );

/**
 * @function random_filling
 *
 */
void random_filling ( book *book_array, int N );

/**
 * @function write_to_binfile
 *
 */
void write_to_binfile ( FILE *binwrite, book *book_array, int N ); 

/**
 * @function read_from_binfile
 *
 */	
void read_from_binfile ( FILE *binread, book *book_array, int N );
								

#endif