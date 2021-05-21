#include "array/array.h"

class CONTROLLER : public BOOK_ARRAY
{

    public:

        void read_from_file(string path);       // чтение из файла
        void write_to_file(string path);        // запись в файл

        void sorting();    

    private:

        void SortingByPages();              // сортировка по страницам
        void SortingByName();               // сортировка по названию книги
        void SortingByEbook();              // сортировка по наличии эл.версии

    public:

        int find_ranok_book();              // метод ищет все книги издательства "РАНОК" в массиве,                                    
        int biggest_book();                 // метод ищем самую большую по количеству страниц книгу 
        int find_detective();               // метод ищет детективы с эл.версией
};

