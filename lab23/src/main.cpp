#include "class.h"

using namespace std;

int main()
{
    string path;

    cout << "Введите путь к читаемому файлу: " << endl;
    getline(std::cin, path);
    cout << "Вы ввели: " << path << endl << endl << endl;

    BOOK_ARRAY MY_COLLECTION(6);


    MY_COLLECTION.read_from_file( path );
    MY_COLLECTION.print_library();

    cout << endl << endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃    Программа нашла " << MY_COLLECTION.find_ranok_book() << " книг(и/у) издательства 'РАНОК'    ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    BOOK new_book;
    int index = 0;
    
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃     На какой элемент нужно переместить новую книгу?    ┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	cout << "┃" << endl;
	cout << "┣━━━━━━━━━━━━━━┓\n";
	cout << "┃      ";
    cin >> index; 
	cout << "┗━━━━━━━━━━━━━━┛\n";


    MY_COLLECTION.add_book( new_book, index-1 );
    MY_COLLECTION.print_library();

    
    
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃          C какого элемента нужно удалить книгу?        ┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	cout << "┃" << endl;
	cout << "┣━━━━━━━━━━━━━━┓\n";
	cout << "┃      ";
    cin >> index; 
	cout << "┗━━━━━━━━━━━━━━┛\n";

    MY_COLLECTION.delete_book( index-1 );
    MY_COLLECTION.print_library();
    
}
