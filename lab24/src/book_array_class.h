#ifndef BOOK_ARRAY_CLASS
#define BOOK_ARRAY_CLASS

#include "book_class.h"

class BOOK_ARRAY
{
    BOOK* library;
    int size;

public:

    //BOOK_ARRAY();

    BOOK_ARRAY( int n );

    ~BOOK_ARRAY();

    //----------------------------------

        //  МЕТОДЫ КЛАССА

    void read_from_file(string path);
    void write_to_file(string path);
    
    void print_library();

    int find_ranok_book();              // метод ищет все книги издательства "РАНОК" в массиве, 
                                        // созданном на основе public полей класса BOOK

    void add_book( BOOK &object, int index );
    void delete_book( int index );

};

#endif