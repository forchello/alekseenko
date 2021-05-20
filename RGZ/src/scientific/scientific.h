#ifndef _SCIENTIFIC_BOOK_
#define _SCIENTIFIC_BOOK_

/**
 * @file book_class.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 11-apr-2021
 * @version 1.0
 */

#include "book/book.h"

class SCIENTIFIC_BOOK : public BOOK
{
    public:

        typedef enum   // сфера
        {
            chemistry,
            biology,     
            physics,
            programming
        } scope_type;

    private:
    
        scope_type scope;
        bool certification;

    public:

        SCIENTIFIC_BOOK();
        SCIENTIFIC_BOOK( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version, scope_type scope, bool certification );

        SCIENTIFIC_BOOK( const SCIENTIFIC_BOOK &object );              // конструктор копирования  

        void SetParam( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version, scope_type scope, bool certification  );          
        void GetParam( bool* ebook, string* name, int* pages, BOOK::cover* material, string* pub_name, int* pub_version, scope_type *scope, bool *certification  );

        bool operator ==(const SCIENTIFIC_BOOK &object);
        bool operator !=(const SCIENTIFIC_BOOK &object);

        virtual string to_string() final;
        virtual void from_string( string result ) final;

        friend ostream& operator<< (ostream &out, const SCIENTIFIC_BOOK &object);
        friend istream& operator>> (istream &in, SCIENTIFIC_BOOK &object); 

        virtual int GetPages() override;
        virtual string GetName() override;
        virtual bool GetEbook() override;
};

#endif