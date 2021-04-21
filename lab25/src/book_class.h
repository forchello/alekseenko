#ifndef BOOK_CLASS
#define BOOK_CLASS

/**
 * @file book_class.h
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

        string to_string();
        void from_string( string result );
       
};

#endif