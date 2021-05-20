#ifndef _PARENT_BOOK_
#define _PARENT_BOOK_

/**
 * @file book_class.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 11-apr-2021
 * @version 1.0
 */
 
#include "../lib.h"

class BOOK
{
    protected:

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

    protected:

        cover material;

	    struct PUBLISHER           
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

        virtual ~BOOK(){};         // виртуальный деструктор

        void SetParam( bool ebook, string name, int pages, cover material, string pub_name, int pub_version );          
        void GetParam( bool *ebook, string *name, int *pages, cover *material, string *pub_name, int *pub_version );

        virtual string to_string() = 0;
        virtual void from_string( string result ) = 0;

        bool operator ==(const BOOK &object);
        bool operator !=(const BOOK &object);

        friend ostream& operator<< (ostream &out, const BOOK &object);
        friend istream& operator>> (istream &in, BOOK &object); 

        virtual int GetPages();
        virtual string GetName();
        virtual bool GetEbook();
    
    protected:

        string from_string_prot( string result );

};

#endif