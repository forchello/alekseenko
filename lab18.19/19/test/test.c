/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Alekseenko Nikita
 * @date 21-feb-2021
 * @version 1.0
 */
 
#include "list.h"
#include "data.h"

void test( list_type* head, int *mas )
{
	int count = 0, expected = 0;
	list_type* node = head;

	for ( int i = 0; i < 3; i++ )
	{
		count += node -> mybook.pages;
		node = node -> next;
	}

	for ( int i = 0; i < 3; i++ )
		expected += mas[i]; 
	

	if ( count == expected )
	{
		printf("Test succesful\n\n");
		fail_output( head, count );
	}	
	else
	{
		printf("Test failed\n");
		fail_output( head, count );
	}	
}

void fail_output(list_type* head , int count)
{
	list_type* node = head;

	for ( int i = 0; i < 3; i++ )
	{
		printf("%d элемент = %d\n", i+1, node -> mybook.pages );
		node = node -> next;
	}
	printf("Их сумма равна: %d\n", count);
}	

list_type* create_list2( int *mas )
{
    list_type* node = NULL;
    list_type* head = NULL;
    list_type* new_node = NULL;
	
    for ( int i = 0; i < 3; i++ )
    {
        new_node = (list_type*) malloc (sizeof(list_type));              // мы выделили место под один узел списка

        if ( head == NULL )						// сохраняем "голову" нашего списка
    		head = new_node;
		else
			node -> next = new_node;			

		node = new_node;										

		// Заполняем элементы узла
        
        node -> mybook.pages = mas[i];
            
                                   // если мы попали на точку 
        node -> next = NULL;
        				           // объявляем наличие следующего узла списка
    }

    return head;
}

int main()
{
	srand(time(0));
	int mas[3] = {4,5,6};

	list_type* head = create_list2( mas );

	test( head, mas );

	return 0;
}


