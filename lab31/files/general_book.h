#ifndef BOOK_CLASS_G
#define BOOK_CLASS2_G

/**
 * @file book_class.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 11-apr-2021
 * @version 1.0
 */

#include "book.h"

class GENERAL_BOOK : public BOOK
    {
     
    public:

        //КОНСТРУКТОР
        GENERAL_BOOK();             // конструктор по умолчанию

        GENERAL_BOOK( bool ebook, string name, int pages, cover material, string pub_name, int pub_version );          // конструктор с параметрами

        GENERAL_BOOK( const GENERAL_BOOK &object );              // конструктор копирования  

        virtual ~GENERAL_BOOK(){};         // виртуальный деструктор

        virtual void SetParam( bool ebook, string name, int pages, cover material, string pub_name, int pub_version );          
        virtual void GetParam( bool *ebook, string *name, int *pages, cover *material, string *pub_name, int *pub_version );

        virtual string to_string() override;
        virtual void from_string( string result ) override;

        bool operator ==(const GENERAL_BOOK &object);
        bool operator !=(const GENERAL_BOOK &object);

        friend ostream& operator<< (ostream &out, const GENERAL_BOOK &object);
        friend istream& operator>> (istream &in, GENERAL_BOOK &object); 
    
    protected:

        virtual string from_string_prot( string result ) override;
};

#endif