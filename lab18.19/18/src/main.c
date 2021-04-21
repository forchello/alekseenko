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

int main() 
{  
	srand((unsigned int)time(0));


	char *array1 = (char *) malloc(sizeof(char));
	char *array2 = (char *) malloc(sizeof(char));  

	strcpy(array1, "abracadabra");
	strcpy(array2, "TEXT2");





	size_t k = 0;

	printf("\n------------------------\nЗадание №1\n------------------------\nВведите индекс, на который нужно осуществить перемещение: ");
	scanf("%ld", &k );

	printf("\n%s\n", insert( array1, array2, k ) );


	size_t start = 0;
	size_t end = 0;

	printf("\n------------------------\nЗадание №2\n------------------------\nВведите индекс, с которого нужно осуществить удаление: ");
	scanf("%ld", &start );
	printf("Введите индекс, до которого нужно осуществить удаление: ");
	scanf("%ld", &end );

	printf("\n%s\n", reduce( array1, start, end ) );



	int n = 3, flag = 0 ;

	book *book_array = (book*)malloc(sizeof(book));

	for ( int i = 0; i < n; i++ )
	{
		book_array[i].ebook = rand() % 2;
        sprintf(book_array[i].name, "Книга №%d", rand() % 136 + 15);
        book_array[i].pages = rand() % 136 + 15;

        sprintf(book_array[i].myauthor.name, "Издательство №%d", rand() % 136 + 15);
        book_array[i].myauthor.version = rand() % 136 + 15;

        book_array[i].material = rand() % 2;		
	}






	printf("\n------------------------\nЗадание №3\n------------------------");
	printf("\nЧто сделать с массивом структур?\n\n[1]  · Добавить структуру\n[0]  · Удалить структуру\n\n\n");

	scanf("%d", &flag);
	printf("\n");

	if ( flag == 1 )
	{
		add_struct((book *)book_array, n);

		for( int i = 0; i < n + 1; i++)
		{
			
	        printf("Книга №%d\n-------------\n", i+1 );

	        printf("Название книги: %s\n", book_array[i].name );
	        printf("Количество страниц: %d\n", book_array[i].pages );

	        printf("Название издательства: %s\n", book_array[i].myauthor.name );
	        printf("Версия книги: %d\n", book_array[i].myauthor.version );

	        if ( book_array[i].material == tverda )
	            printf("Обложка книги - твердая\n" );

	        if ( book_array[i].material == myaka )
	            printf("Обложка книги - мягкая\n" );

	        printf("\n");
		}

	    printf("\n\n\n");


	}
	else if( flag == 0 )
	{	
		printf("\nВведите номер структуры, которую нужно удалить(0-%d): \n", n-1);
    	int to_remove;
    	scanf("%d", &to_remove);

		remove_struct((book *)book_array, n, to_remove);
		printf("\n");

		for( int i = 0; i < n - 1; i++)
		{

			printf("Книга №%d\n-------------\n", i+1 );
	        

	        printf("Название книги: %s\n", book_array[i].name );
	        printf("Количество страниц: %d\n", book_array[i].pages );

	        printf("Название издательства: %s\n", book_array[i].myauthor.name );
	        printf("Версия книги: %d\n", book_array[i].myauthor.version );

	        if ( book_array[i].material == tverda )
	            printf("Обложка книги - твердая\n" );

	        if ( book_array[i].material == myaka )
	            printf("Обложка книги - мягкая\n" );

	        printf("\n");
		}

		printf("\n");
	}
	
	free(book_array);
	return 0;
}