#include "book_array_class.h"

int main()
{
    BOOK_ARRAY MY_COLLECTION(6);

    string path;
    cout << "Введите путь файла, с которого осуществляется чтение: \n━━ ";
    getline(std::cin, path );
    cout << endl;

    MY_COLLECTION.read_from_file( path );
    cout << endl << endl << endl;

    path = "";
    cout << "Введите путь файла, в который осуществляется запись: \n━━ ";
    getline(std::cin, path );
    MY_COLLECTION.write_to_file( path );


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

    return 0;
}
