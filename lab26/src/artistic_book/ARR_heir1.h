#include "heir1.h"

class ARTISTIC_BOOK_ARRAY
{   
    ARTISTIC_BOOK* art_array;
    int size;

    public:

        // ------------------------------------------

        // конструтор / деструктор

        ARTISTIC_BOOK_ARRAY( int n );
        ~ARTISTIC_BOOK_ARRAY();

        // ------------------------------------------
        // МЕТОДЫ

        void read_from_file(string path);
        void write_to_file(string path);
    
        void print_library();

        
        void add_book( ARTISTIC_BOOK &object, int index );
        void delete_book( int index );


        int find_ranok_book();              // метод ищет все книги издательства "РАНОК" в массиве, 
                                            // созданном на основе public полей класса ARTISTIC_BOOK
        int find_detective();

        int biggest_book();
        
};