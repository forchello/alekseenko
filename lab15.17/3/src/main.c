/**
 * @mainpage
 * # Загальне завдання
 * 1. **Прочитати за записити** файл у бінар
 * @author Alekseenko N.
 * @date 21-yan-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Alekseenko N.
 * @date 21-yan-2021
 * @version 1.0
 */

#include "lib.h"

#define N 3
int main() 
{  
	FILE *read = fopen("files/read.txt", "r");
	FILE *write = fopen("files/write.txt", "w");
	FILE *sp = fopen("files/function_1.txt", "r");

	



	book book_array[N];

	read_from_file( read, book_array, N );

	write_to_file( write, book_array, N );

	printf("----------------------------------------\nЗадание на удовлетворительно\n----------------------------------------\n\n");
	output( book_array, N );



	book arr[N];
	read_from_file( sp, arr, N );

	sorting ( book_array, N );


	printf("----------------------------------------\nЗадание 3\n----------------------------------------\n\n\n");
    printf("Всего я нашел %d книг(и) издательства 'Ранок'\n", search_publish ( arr, N ) );
    printf("\n\n\n\n");
	

	random_filling ( book_array, N );



	FILE *binwrite = fopen("files/data/write.dat", "wb");
	write_to_binfile( binwrite, book_array, N );
	fclose(binwrite);

	FILE *binread = fopen("files/data/write.dat", "rb");
	read_from_binfile ( binread, book_array, N );
	fclose(binread);

	printf("----------------------------------------\nЗадание на отлично\n----------------------------------------\n\n");
	output( book_array, N );

	fclose(read);
	fclose(write);
	fclose(sp);


	return 0;
}