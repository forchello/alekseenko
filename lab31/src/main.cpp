#include "polymorphism/array.h"

int main()
{
    BOOK_ARRAY l1(6);
    BOOK_ARRAY l2(6);
    BOOK_ARRAY l3(6);
    vector <BOOK_ARRAY> lib{ l1, l2, l3 };

    for( vector<BOOK_ARRAY>::iterator it = lib.begin(); it != lib.end(); it++)
    {
        SCIENTIFIC_BOOK sb;
        ARTISTIC_BOOK ab;
        it->read_from_file( &sb, &ab, "files/heir1_read.txt" );
        it->print_library();

        cout << endl << endl;
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃    Программа нашла " << it->find_ranok_book() << " книг(и/у) издательства 'РАНОК'    ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃              Cамая большая книга - №" << it->biggest_book() << "                  ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃     Программа нашла " << it->find_detective() << " детектив (а/ов) с эл.версией     ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << endl << endl;
    }
    return 0;
}