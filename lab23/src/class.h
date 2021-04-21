#ifndef DEFEND_1
#define DEFEND_1

/**
 * @file class.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 11-apr-2021
 * @version 1.0
 */
 
#include "lib.h"

class BOOK
{
    private:

        // ПОЛЯ КЛАССА 

        bool ebook;             // есть ли электронная книга
	    string name;            // название книги
	    int pages;              // к-во страниц

    public:

        typedef enum   // материал обложки книги
        {
            tverda,
            myaka
        } cover;

    private:

        cover material;

	    struct PUBLISHER            // ВЛОЖЕННЫЙ КЛАСС
        {
            string name;                // название издательства
            int version;                // версия изданной книги
        };

        PUBLISHER pub;

        // ТЕПЕРЬ ДОБАВИМ КОНСТРУКТОР ПО УМОЛЧАНИЮ
        
    public:

        //КОНСТРУКТОР
        BOOK();             // конструктор по умолчанию

        BOOK( bool ebook, string name, int pages, cover material, string pub_name, int pub_version );          // конструктор с параметрами

        BOOK( const BOOK &object );              // конструктор копирования  

        void SetParam( bool ebook, string name, int pages, cover material, string pub_name, int pub_version );
        void GetParam( bool *ebook, string *name, int *pages, cover *material, string *pub_name, int *pub_version );

};

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
    void print_library();
    int find_ranok_book();              // метод ищет все книги издательства "РАНОК" в массиве, 
                                        // созданном на основе public полей класса BOOK

    void add_book( BOOK &object, int index );
    void delete_book( int index );

};

#endif