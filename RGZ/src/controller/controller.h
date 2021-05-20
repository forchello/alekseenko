#include "array/array.h"

class CONTROLLER : public BOOK_ARRAY
{

    public:

        void read_from_file(string path);       // чтение из файла
        void write_to_file(string path);        // запись в файл

        void sorting();    

    private:

        void SortingByPages();
        void SortingByName();
        void SortingByEbook();

    public:

        int find_ranok_book();              // метод ищет все книги издательства "РАНОК" в массиве,                                    
        int biggest_book(); 
        int find_detective();
};

