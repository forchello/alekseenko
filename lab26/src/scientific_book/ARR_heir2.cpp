#include "ARR_heir2.h"

SCIENTIFIC_BOOK_ARRAY::SCIENTIFIC_BOOK_ARRAY( int n )
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃  Вызвался конструктор SCIENTIFIC_BOOK_ARRAY  ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    size = n;
    art_array = new SCIENTIFIC_BOOK[n];
}

SCIENTIFIC_BOOK_ARRAY::~SCIENTIFIC_BOOK_ARRAY()
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "┃  Вызвался деструктор SCIENTIFIC_BOOK_ARRAY  ┃\n";
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

    delete[] art_array;
}

void SCIENTIFIC_BOOK_ARRAY::read_from_file( string path )
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
void SCIENTIFIC_BOOK_ARRAY::write_to_file( string path )
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

void SCIENTIFIC_BOOK_ARRAY::print_library()
{	
	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook, certification;
		string tmp_name_book, tmp_pub_name, scope;
		int tmp_pages, tmp_pub_version;
		SCIENTIFIC_BOOK::cover temp_material;
		SCIENTIFIC_BOOK::scope_type temp_scope;
		
		BOOK temper;
		art_array[i].GetParam( &temper, &temp_scope, &certification  );
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
		cout << "┃       Жанр:      ┃" << TAB << ( certification == true ? "есть" : "нет" ) << endl;
		cout << "┗━━━━━━━━━━━━━━━━━━┛\n" << endl << endl;
	}
};

void SCIENTIFIC_BOOK_ARRAY::add_book( SCIENTIFIC_BOOK &object, int index )
{
	int n = ++this->size;

	SCIENTIFIC_BOOK* temp_book = new SCIENTIFIC_BOOK[n];

	for ( int i = 0 , j = 0; i < n-1; i++)
	{
		if ( i == index ) 
			temp_book[j++] = object;

		temp_book[j++] = art_array[i];		
	}

	delete[] art_array;	

	art_array = temp_book;
};

void SCIENTIFIC_BOOK_ARRAY::delete_book( int index )
{
	int n = --this->size;

	for ( int i = index; i < n; i++)
	{
		art_array[i] = art_array[i+1]; 
	}
};


// МЕТОДЫ ИЗ РГЗ ---------------------------------

int SCIENTIFIC_BOOK_ARRAY::find_ranok_book()
{   
    int k = 0;
	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook, certification;
		string tmp_name_book, tmp_pub_name, scope;
		int tmp_pages, tmp_pub_version;
		SCIENTIFIC_BOOK::cover temp_material;
		SCIENTIFIC_BOOK::scope_type temp_scope;
		
		BOOK temper;
		art_array[i].GetParam( &temper, &temp_scope, &certification  );
		temper.GetParam( &temp_ebook, &tmp_name_book, &tmp_pages, &temp_material, &tmp_pub_name, &tmp_pub_version );

		if( tmp_pub_name == "ранок" )
			k++;
	}    

    return k;
}

int SCIENTIFIC_BOOK_ARRAY::biggest_book()
{
	int count_pages = 0, num_book = 0;

	for ( int i = 0; i < size; i++ )
	{
		bool temp_ebook, certification;
		string tmp_name_book, tmp_pub_name, scope;
		int tmp_pages, tmp_pub_version;
		SCIENTIFIC_BOOK::cover temp_material;
		SCIENTIFIC_BOOK::scope_type temp_scope;
		
		BOOK temper;
		art_array[i].GetParam( &temper, &temp_scope, &certification  );
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