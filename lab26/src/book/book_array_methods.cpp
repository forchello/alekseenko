#include "book_array_class.h"

BOOK_ARRAY::BOOK_ARRAY( int n )
{	
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃  Вызвался конструктор BOOK_ARRAY  ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	size = n;
	library = new BOOK[n]; 
};

BOOK_ARRAY::~BOOK_ARRAY()
{
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃  Вызвался деструктор  ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	
	// удаление неинециализированной памяти
    delete []library;			
};

void BOOK_ARRAY::read_from_file( string path )
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

			std::getline(fin, tmp_result);

			library[i].from_string(tmp_result);
		}
	}

	fin.seekg(0,ios::cur);
}
void BOOK_ARRAY::write_to_file( string path )
{
	ofstream fout(path);

	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃   Записываются файлы в " << __FUNCTION__ <<" ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    if ( !fout.is_open() ) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		for ( int i = 0; i < size; i++ )
		{
			fout << library[i].to_string();
			
			if ( i != size - 1 )
				fout << endl;
		}
	}
}

void BOOK_ARRAY::print_library()
{	
	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook;
		string tmp_name_book, tmp_pub_name;
		int tmp_pages, tmp_pub_version;
		BOOK::cover temp_material;

		library[i].GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, &tmp_pub_version);

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
		cout << "┗━━━━━━━━━━━━━━━━━━┛\n" << endl << endl;
	}
};

int BOOK_ARRAY::find_ranok_book()
{   
    int k = 0;
	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook;
		string tmp_name_book, tmp_pub_name;
		int tmp_pages, tmp_pub_version;
		BOOK::cover temp_material;

		library[i].GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, &tmp_pub_version);

		if( tmp_pub_name == "ранок" )
			k++;
	}    

    return k;
}

void BOOK_ARRAY::add_book( BOOK &object, int index )
{
	int n = ++this->size;

	BOOK* temp_book = new BOOK[n];

	for ( int i = 0 , j = 0; i < n-1; i++)
	{
		if ( i == index ) 
			temp_book[j++] = object;

		temp_book[j++] = library[i];		
	}

	delete[] library;	

	library = temp_book;
};

void BOOK_ARRAY::delete_book( int index )
{
	int n = --this->size;

	for ( int i = index; i < n; i++)
	{
		library[i] = library[i+1]; 
	}
};