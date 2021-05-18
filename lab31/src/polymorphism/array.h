#ifndef BOOK_ARRAY_CLASS
#define BOOK_ARRAY_CLASS

#include "polymorphism/book.h"
#include "polymorphism/artistic.h"
#include "polymorphism/scientific.h"

class BOOK_ARRAY
{   
    int size;

    vector <BOOK*> array;
    
    int* book_type;

    public:

        // ------------------------------------------
        // конструтор / деструктор

        BOOK_ARRAY( int n );

        //BOOK_ARRAY( const BOOK_ARRAY &object );
        
        ~BOOK_ARRAY();

        BOOK_ARRAY operator = ( const BOOK_ARRAY &object );

        // ------------------------------------------
        // МЕТОДЫ

        void read_from_file(BOOK *sf, BOOK *ab, string path);
        void write_to_file(string path);
    
        void print_library();

        
        void add_book( BOOK* object, int index );

        void delete_book( int index );

        int find_ranok_book();              // метод ищет все книги издательства "РАНОК" в массиве, 
                                            // созданном на основе public полей класса ARTISTIC_BOOK
        
        int biggest_book();
        
        int find_detective();

        //--------------------------

        void SortByPages();

        void ConcVec( vector<BOOK*> array2 );
};

#endif