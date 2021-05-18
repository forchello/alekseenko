#include "polymorphism/array.h"

int main()
{
    BOOK_ARRAY library(6);
    library.read_from_file( "files/heir1_read.txt" );
    library.print_library();

    library.write_to_file( "files/write.txt ");


    SCIENTIFIC_BOOK* book = new SCIENTIFIC_BOOK;
    book->from_string("true ADDED_BOOK 135 небо 34 myaka programming true");

    library.add_book( book, 7 );
    library.print_library();

    library.delete_book( 7 ); 
    library.print_library();

    cout << endl << endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃    Программа нашла " << library.find_ranok_book() << " книг(и/у) издательства 'РАНОК'    ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃              Cамая большая книга - №" << library.biggest_book() << "                  ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃     Программа нашла " << library.find_detective() << " детектив (а/ов) с эл.версией     ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    cout << endl << endl;

    return 0;
}