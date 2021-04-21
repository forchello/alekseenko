/**
 * @mainpage
 * # Загальне завдання
 * 1. **Прочитати за записити** файл у бінар
 * @author Alekseenko N.
 * @date 05-mar-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Alekseenko N.
 * @date 05-mar-2021
 * @version 1.0
 */

#include "lib.h"
#include <regex.h>

int main()
{
	FILE *read = fopen("files/read.txt", "r");

	list_type* head = create_list(read, 6 );
	head = push(head);
	fclose(read);

	output( head, 6 );
	printf("\n\n\n");
	output_format(head, 6);
	return 0;
}