#ifndef BOOK_ARRAY_CLASS
#define BOOK_ARRAY_CLASS

#include "book/book.h"
#include "artistic/artistic.h"
#include "scientific/scientific.h"

class BOOK_ARRAY
{   
    protected:

        int size;

        vector <BOOK*> array;
    
        int* book_type;

    public:

        // ------------------------------------------
        // конструтор / деструктор
        BOOK_ARRAY();
        BOOK_ARRAY( int n );

        BOOK_ARRAY( const BOOK_ARRAY &object );
        
        ~BOOK_ARRAY();

        BOOK_ARRAY operator = ( const BOOK_ARRAY &object );

        // ------------------------------------------
        // МЕТОДЫ

        //void read_from_file(string path);
        //void write_to_file(string path);
    
        void print_library();

        
        void add_book( BOOK* object, int index );

        void delete_book( int index );

    
        //--------------------------

        void ConcVec( vector<BOOK*> array2 );

        void clear();
};

#endif