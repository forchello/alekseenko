#include "ARR_heir1.h"

ARTISTIC_BOOK_ARRAY::ARTISTIC_BOOK_ARRAY( int n )
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃  Вызвался конструктор ARTISTIC_BOOK_ARRAY  ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    size = n;
    art_array = new ARTISTIC_BOOK[n];
}

ARTISTIC_BOOK_ARRAY::~ARTISTIC_BOOK_ARRAY()
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃  Вызвался деструктор ARTISTIC_BOOK_ARRAY  ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    delete[] art_array;
}

void ARTISTIC_BOOK_ARRAY::read_from_file( string path )
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
			string tmp_result;

			getline(fin, tmp_result);
			
			art_array[i].from_string(tmp_result);

		}
	}

	fin.seekg(0,ios::cur);
}
void ARTISTIC_BOOK_ARRAY::write_to_file( string path )
{
	ofstream fout(path);

	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃   Записываются файлы в " << __FUNCTION__ <<" ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    if ( !fout.is_open() ) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		for ( int i = 0; i < size; i++ )
		{
			fout << art_array[i].to_string();
			
			if ( i != size - 1 )
				fout << endl;
		}
	}
}

void ARTISTIC_BOOK_ARRAY::print_library()
{	
	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook;
		string tmp_name_book, tmp_pub_name, temp_dir_str, temp_genre_str;
		int tmp_pages, tmp_pub_version;
		ARTISTIC_BOOK::cover temp_material;
		ARTISTIC_BOOK::direction_type temp_dir;
		ARTISTIC_BOOK::genre_type temp_genre;
		BOOK temper;
		art_array[i].GetParam( &temper, &temp_dir, &temp_genre  );
		temper.GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, &tmp_pub_version );

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
};

void ARTISTIC_BOOK_ARRAY::add_book( ARTISTIC_BOOK &object, int index )
{
	int n = ++this->size;

	ARTISTIC_BOOK* temp_book = new ARTISTIC_BOOK[n];

	for ( int i = 0 , j = 0; i < n-1; i++)
	{
		if ( i == index ) 
			temp_book[j++] = object;

		temp_book[j++] = art_array[i];		
	}

	delete[] art_array;	

	art_array = temp_book;
};

void ARTISTIC_BOOK_ARRAY::delete_book( int index )
{
	int n = --this->size;

	for ( int i = index; i < n; i++)
	{
		art_array[i] = art_array[i+1]; 
	}
};


// МЕТОДЫ ИЗ РГЗ ---------------------------------

int ARTISTIC_BOOK_ARRAY::find_ranok_book()
{   
    int k = 0;
	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook;
		string tmp_name_book, tmp_pub_name;
		int tmp_pages, tmp_pub_version;
		ARTISTIC_BOOK::cover temp_material;
		ARTISTIC_BOOK::direction_type temp_dir;
		ARTISTIC_BOOK::genre_type temp_genre;

		BOOK temper;
		art_array[i].GetParam( &temper, &temp_dir, &temp_genre  );
		temper.GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, &tmp_pub_version );

		if( tmp_pub_name == "ранок" )
			k++;
	}    

    return k;
}

int ARTISTIC_BOOK_ARRAY::find_detective()
{
	int count = 0;

	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook;
		string tmp_name_book, tmp_pub_name;
		int tmp_pages, tmp_pub_version;
		ARTISTIC_BOOK::cover temp_material;
		ARTISTIC_BOOK::direction_type temp_dir;
		ARTISTIC_BOOK::genre_type temp_genre;

		BOOK temper;
		art_array[i].GetParam( &temper, &temp_dir, &temp_genre  );
		temper.GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, &tmp_pub_version );

		if ( temp_genre == ARTISTIC_BOOK::detective && temp_ebook == true )
			count ++;
	}

	return count;
}

int ARTISTIC_BOOK_ARRAY::biggest_book()
{
	int count_pages = 0, num_book = 0;

	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook;
		string tmp_name_book, tmp_pub_name;
		int tmp_pages, tmp_pub_version;
		ARTISTIC_BOOK::cover temp_material;
		ARTISTIC_BOOK::direction_type temp_dir;
		ARTISTIC_BOOK::genre_type temp_genre;

		BOOK temper;
		art_array[i].GetParam( &temper, &temp_dir, &temp_genre  );
		temper.GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, &tmp_pub_version );

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

	return num_book + 1;
}