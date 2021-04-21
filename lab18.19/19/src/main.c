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

#include "list.h"
#include "data.h"

int main()
{
	FILE *read = fopen("files/read.txt", "r");
	FILE *write = fopen("files/write.txt", "w+");

	list_type* list_begin = NULL;

	int lines = find_strings( read );

	/*
	output( list_begin, lines );

	write_to_file( write, list_begin, lines );
	search( list_begin, lines );

	short int pos_book = 0;
	printf("\n\n\nВведите позицию добавления новой книги: ");
	scanf("%d", &pos_book);
	
	list_begin = add_to_list(list_begin, pos_book - 1);
	output( list_begin, lines );

	fclose(read);
    return 0;*/

	printf("---------------------------------------\n");
	printf("Alekseenko Nikita		  Lab 19       \n");
	printf("---------------------------------------\n");
	list_begin = create_list( read, lines );
	printf("\n\n- Список создан и заполнен из файла.\n\n\n");

	output(list_begin, lines);
	printf("---------------------------------------\n");
	printf("\n- Вывод списка.\n");

	write_to_file(write, list_begin, lines);

	printf("- Запись в файл.\n\n");
	printf("---------------------------------------\n");

	fclose(read);
	fclose(write);

	search(list_begin, lines);
	printf("\n---------------------------------------\n");

	printf("\n- В какую позицию нужно положить книгу?\n\n");
	int pos_book = 0;
	printf("- ");
	scanf("%d", &pos_book);
	
	printf("\n---------------------------------------\n");
	
	list_begin = add_to_list( list_begin, pos_book - 1 );	
	printf("\n");	
	output(list_begin, lines+1);

	printf("\n---------------------------------------\n");

	pos_book = 0;
	printf("- Из какой позиции удалить книгу?\n\n");
	printf("- ");
	scanf("%d", &pos_book);
	printf("\n---------------------------------------\n");
	delete_elem_list( &list_begin, pos_book - 1 );
	printf("\n");	
	output(list_begin, lines);

	printf("\n---------------------------------------\n");

	pos_book = 0;
	//printf("- Из какой позиции удалить книгу?\n\n");
	list_begin = sorting(list_begin, lines);
	output(list_begin, lines);


	return 0;
}