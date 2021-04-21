/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Alekseenko Nikita
 * @date 21-feb-2021
 * @version 1.0
 */
 
#include "lib.h"

void test_insert()
{
	char *arr1 = (char *) malloc(sizeof(char));
	char *arr2 = (char *) malloc(sizeof(char));
	int n = 4;

	arr1 = "abrakadabra";
	arr2 = "TEXT2";

	if ( strcmp(insert(arr1, arr2, n), "abraTEXT2kadabra") == NULL )
		printf("\n--- Function 'INSERT' ---\n\nTest: successful\n\n\n");
	else 
		printf("\n--- Function 'INSERT' ---\n\nTest: failed\n\n\n");
}

void test_reduce()
{
	char *arr1 = (char *) malloc(sizeof(char));
	int n1 = 4, n2 = 8;

	arr1 = "abrakadabra";

	if ( strcmp(reduce(arr1, n1, n2), "abrara") == NULL )
		printf("\n--- Function 'REDUCE' ---\n\nTest: successful\n\n\n");
	else 
		printf("\n--- Function 'REDUCE' ---\n\nTest: failed\n\n\n");
}

void test_add_struct()
{

	book *test_array = (book*)malloc(sizeof(book));

	int n = 3, sum = 0;

	for ( int i = 0; i < n; i++ )
	{
	    test_array[i].pages = 4;		
	}

	add_struct ( test_array, n );

	for (  int i = 0; i < n+1; i++ )
	{
		sum += test_array[i].pages;	
	}

	if ( sum = 16 )
		printf("\n--- Function 'ADD_STRUCT' ---\n\nTest: successful\n\n\n");
	else 
		printf("--- Function 'ADD_STRUCT' ---\n\nTest: failed\n\n\n");
}

void test_remove_struct()
{
	book *test_array = (book*)malloc(sizeof(book));

	int n = 3, to_remove = 2;

	for ( int i = 0; i < n; i++ )
	{
	    test_array[i].pages = 4;		
	}

	remove_struct ( test_array, n, to_remove );

	if ( test_array[to_remove].pages == 0 )
		printf("\n--- Function 'REMOVE_STRUCT' ---\n\nTest: successful\n\n\n");
	else 
		printf("\n--- Function 'REMOVE_STRUCT' ---\n\nTest: failed\n\n\n");
}

int main()
{
	test_insert();
	test_reduce();

	test_add_struct();
	test_remove_struct();

	return 0;
} 



