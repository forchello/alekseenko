#include "array.h"

BOOK_ARRAY::BOOK_ARRAY( int n )
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃       Вызвался конструктор BOOK_ARRAY      ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    size = n;
	book_type = new int[size];
	for ( int i = 0; i < size; i++ )
		book_type[i] = 2;

    array = new BOOK* [n];

	for( int i = 0; i < size; i++ )
		array[i] = new SCIENTIFIC_BOOK;
}

BOOK_ARRAY::~BOOK_ARRAY()
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃       Вызвался деструктор BOOK_ARRAY      ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    for( int i = 0; i < size; i++)
        delete array[i];
	delete[] array;

	delete[] book_type;
}

BOOK_ARRAY::BOOK_ARRAY( const BOOK_ARRAY &object )		// констуктор копирования
{
	BOOK_ARRAY(object.size);
	
    for( int i = 0; i < size; i++) 
	{
        *array[i] = object.array[i][0];
		book_type[i] = object.book_type[i];
	}

}

BOOK_ARRAY BOOK_ARRAY::operator = ( const BOOK_ARRAY &object )
{
    for( int i = 0; i < size; i++)
        delete array[i];
	delete[] array;

	delete[] book_type;

    size = object.size;
	
	book_type = new int[size];

    array = new BOOK* [size];

    for( int i = 0; i < size; i++) 
	{
        *array[i] = object.array[i][0];
		book_type[i] = object.book_type[i];
	} 
    
}

void BOOK_ARRAY::read_from_file(string path)
{
    ifstream fin(path);

	fin.seekg(0,ios::cur);				//переместил курсор на начало файла

	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃  Читаются файлы из " << __FUNCTION__ <<" ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";


    if ( !fin.is_open() ) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
		for ( int i = 0; i < size; i++ )
		{	
			int book_type_one;

			fin >> book_type_one;			// читаем 1 значение в файле. если 1 - это первый наследник, если 2 - второй
			fin.seekg(1,ios::cur);

			string tmp_result;
			getline(fin, tmp_result);
			
			if ( book_type_one == 2 ) 
				((SCIENTIFIC_BOOK*)array[i])->from_string(tmp_result), book_type[i] = book_type_one;

			else if ( book_type_one == 1 )
				((ARTISTIC_BOOK*)array[i])->from_string(tmp_result), book_type[i] = book_type_one;

			else
				exit(1);
		}
	}

	fin.seekg(0,ios::cur);
}

void BOOK_ARRAY::write_to_file( string path )
{
	ofstream fout(path);

	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃   Записываются файлы в " << __FUNCTION__ <<"   ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    if ( !fout.is_open() ) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		for ( int i = 0; i < size; i++ )
		{
			if ( book_type[i] == 2 ) 
				fout << ((SCIENTIFIC_BOOK*)array[i])->to_string();

			else if ( book_type[i] == 1 )
				fout << ((ARTISTIC_BOOK*)array[i])->to_string();
			
			if ( i != size - 1 )
				fout << endl;
		}
	}
}


void BOOK_ARRAY::print_library()
{	
	for ( int i = 0; i < size; i++ )
	{
		if ( book_type[i] == 2 ) 
		{
			bool temp_ebook, certification;
			string tmp_name_book, tmp_pub_name, scope;
			int tmp_pages, tmp_pub_version;
			SCIENTIFIC_BOOK::cover temp_material;
			SCIENTIFIC_BOOK::scope_type temp_scope;
			((SCIENTIFIC_BOOK*)array[i])->GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, 
												&tmp_pub_version, &temp_scope, &certification );
			
			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
			cout << "┃           BOOK #" << i+1 << "             ┃" << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
			cout << "┃" << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Есть эл.версия? ┃" << TAB << bool_output(temp_ebook) << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Название книги: ┃" << TAB << tmp_name_book << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Кол-во страниц: ┃" << TAB << tmp_pages << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃   Вид обложки:   ┃" << TAB << ( temp_material == BOOK::tverda ? "Твердая" : "Мягкая" ) << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃   Издательство:  ┃" << TAB << tmp_pub_name << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Версия издания: ┃" << TAB << tmp_pub_version << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			
			if ( temp_scope == SCIENTIFIC_BOOK::chemistry )
				scope = "chemistry";    
			else if ( temp_scope == SCIENTIFIC_BOOK::biology )
				scope = "biology"; 	
			else if ( temp_scope == SCIENTIFIC_BOOK::physics )
				scope = "physics";
			else if ( temp_scope == SCIENTIFIC_BOOK::programming )
				scope = "programming";	

			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃       Сфера:     ┃" << TAB << scope << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";	
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃    Сертификат:   ┃" << TAB << ( certification == true ? "есть" : "нет" ) << endl;
			cout << "┗━━━━━━━━━━━━━━━━━━┛\n" << endl << endl;
		}
				
		else if ( book_type[i] == 1 )
		{
			bool temp_ebook;
			string tmp_name_book, tmp_pub_name, temp_dir_str, temp_genre_str;
			int tmp_pages, tmp_pub_version;
			ARTISTIC_BOOK::cover temp_material;
			ARTISTIC_BOOK::direction_type temp_dir;
			ARTISTIC_BOOK::genre_type temp_genre;

			((ARTISTIC_BOOK*)array[i])->GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name,
																			   &tmp_pub_version, &temp_dir, &temp_genre );
	
			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
			cout << "┃           BOOK #" << i+1 << "             ┃" << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
			cout << "┃" << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Есть эл.версия? ┃" << TAB << bool_output(temp_ebook) << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Название книги: ┃" << TAB << tmp_name_book << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Кол-во страниц: ┃" << TAB << tmp_pages << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃   Вид обложки:   ┃" << TAB << ( temp_material == BOOK::tverda ? "Твердая" : "Мягкая" ) << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃   Издательство:  ┃" << TAB << tmp_pub_name << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃  Версия издания: ┃" << TAB << tmp_pub_version << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";
			
			if ( temp_dir == ARTISTIC_BOOK::renaissance )
				temp_dir_str = "renaissance";
			else if ( temp_dir == ARTISTIC_BOOK::modern )
				temp_dir_str = "modern";
			else if ( temp_dir = ARTISTIC_BOOK::postmodern )
				temp_dir_str = "postmodern";

			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃    Направление:  ┃" << TAB << temp_dir_str << endl;
			cout << "┣━━━━━━━━━━━━━━━━━━┛\n";

			if ( temp_genre == ARTISTIC_BOOK::roman )
				temp_genre_str = "roman";    
			else if ( temp_genre == ARTISTIC_BOOK::detective )
				temp_genre_str = "detective"; 	
			else if ( temp_genre == ARTISTIC_BOOK::novel )
				temp_genre_str = "novel";
			else if ( temp_genre == ARTISTIC_BOOK::story )
				temp_genre_str = "story";	

			cout << "┣━━━━━━━━━━━━━━━━━━┓\n";
			cout << "┃       Жанр:      ┃" << TAB << temp_genre_str << endl;
			cout << "┗━━━━━━━━━━━━━━━━━━┛\n" << endl << endl;
		}

	}
}

void BOOK_ARRAY::add_book( BOOK* object, int index )
{
	this->size++;

	BOOK** temp_book = new BOOK* [size];

	int* book_type_temp = new int[size];
	
	// создаем массив указателей буков
	// заполняем его указателями на научную книгу
	// теперь переписываем эти указатели на указатели из массива библиотеки 

	for ( int i = 0 , j = 0; i < size; i++)
	{
		if ( i == index - 1  ) 
			temp_book[i] = object;
		else
			temp_book[i] = array[j++];	
	}

	delete[] array;
	array = temp_book;


	for ( int i = 0 , j = 0; i < size; i++)
	{
		if ( i == index - 1 ) 
			book_type_temp[i] = 2;
		else
			book_type_temp[i] = book_type[j++];	
	}
	
	delete[] book_type;

	book_type = book_type_temp;
}

void BOOK_ARRAY::delete_book( int index )
{	
	int n = --this->size;

	for ( int i = index - 1; i < n; i++)
	{
		array[i] = array[i-1]; 
	}
}

int BOOK_ARRAY::find_ranok_book()
{   
    int k = 0;
	for ( int i = 0; i < size; i++ )
	{
		if ( book_type[i] == 2)
		{
			bool temp_ebook, certification;
			string tmp_name_book, tmp_pub_name, scope;
			int tmp_pages, tmp_pub_version;
			SCIENTIFIC_BOOK::cover temp_material;
			SCIENTIFIC_BOOK::scope_type temp_scope;
			
		
			((SCIENTIFIC_BOOK*)array[i])->GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name,
																				&tmp_pub_version, &temp_scope, &certification );

			if( tmp_pub_name == "ранок" ) k++;
		}

		else if ( book_type[i] == 1 )
		{
			bool temp_ebook;
			string tmp_name_book, tmp_pub_name, temp_dir_str, temp_genre_str;
			int tmp_pages, tmp_pub_version;
			ARTISTIC_BOOK::cover temp_material;
			ARTISTIC_BOOK::direction_type temp_dir;
			ARTISTIC_BOOK::genre_type temp_genre;

			((ARTISTIC_BOOK*)array[i])->GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name,
																			   &tmp_pub_version, &temp_dir, &temp_genre );

			if( tmp_pub_name == "ранок" ) k++;
		}
	}    

    return k;
}

int BOOK_ARRAY::biggest_book()
{   
    int count_pages = 0, num_book = 0;

	for ( int i = 0; i < size; i++ )
	{
		if ( book_type[i] == 2)
		{
			bool temp_ebook, certification;
			string tmp_name_book, tmp_pub_name, scope;
			int tmp_pages, tmp_pub_version;
			SCIENTIFIC_BOOK::cover temp_material;
			SCIENTIFIC_BOOK::scope_type temp_scope;
			
		
			((SCIENTIFIC_BOOK*)array[i])->GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name,
																				&tmp_pub_version, &temp_scope, &certification );

			if ( i == 0)
				count_pages = tmp_pages;	
			else
			{
				if ( count_pages < tmp_pages )
				{
					count_pages = tmp_pages;
					num_book = i;
				}
			}
		}

		else if ( book_type[i] == 1 )
		{
			bool temp_ebook;
			string tmp_name_book, tmp_pub_name, temp_dir_str, temp_genre_str;
			int tmp_pages, tmp_pub_version;
			ARTISTIC_BOOK::cover temp_material;
			ARTISTIC_BOOK::direction_type temp_dir;
			ARTISTIC_BOOK::genre_type temp_genre;

			((ARTISTIC_BOOK*)array[i])->GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name,
																			   &tmp_pub_version, &temp_dir, &temp_genre );

			if ( i == 0)
				count_pages = tmp_pages;	
			else
			{
				if ( count_pages < tmp_pages )
				{
					count_pages = tmp_pages;
					num_book = i;
				}
			}
		}
	}    

    return num_book + 1;
}

int BOOK_ARRAY::find_detective()
{
	int count = 0;

	for ( int i = 0; i < size; i++ )
	{
		if ( book_type[i] == 1 )	
		{
			bool temp_ebook;
			string tmp_name_book, tmp_pub_name, temp_dir_str, temp_genre_str;
			int tmp_pages, tmp_pub_version;
			ARTISTIC_BOOK::cover temp_material;
			ARTISTIC_BOOK::direction_type temp_dir;
			ARTISTIC_BOOK::genre_type temp_genre;

			((ARTISTIC_BOOK*)array[i])->GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name,
																			   &tmp_pub_version, &temp_dir, &temp_genre );

			if ( temp_genre == ARTISTIC_BOOK::detective && temp_ebook == true ) count ++;
		}
		else if ( book_type[i] == 1 ) continue;	
	}

	return count;
}