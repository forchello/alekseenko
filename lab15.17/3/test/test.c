/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Alekseenko Nikita
 * @date 21-feb-2021
 * @version 1.0
 */
 
#include "lib.h"

unsigned short test_ranok()
{
	int n = 3;

	book test[n];

	strcpy(test[0].myauthor.name, "ранок");
	strcpy(test[1].myauthor.name, "sdfsd");
	strcpy(test[2].myauthor.name, "dsffd");


	int count = search_publish (test, n);

	if ( count == 1 )
		printf("\nTest: successful\n");
	else 
		printf("\nTest: failed\n");
}

int main()
{
	test_ranok();
	return 0;
}


