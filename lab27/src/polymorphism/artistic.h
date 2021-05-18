#ifndef _ARTISTIC_BOOK_
#define _ARTISTIC_BOOK_

/**
 * @file book_class.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Alekseenko N.
 * @date 11-apr-2021
 * @version 1.0
 */

#include "book.h"

class ARTISTIC_BOOK : public BOOK
{
    public:

    typedef enum   // художественное направление
    {
        renaissance,
        modern,
        postmodern
    } direction_type;

    typedef enum   // жанр
    {
        roman,
        detective,
        novel,
        story
    } genre_type;

    private:

    direction_type direction;
    genre_type genre;

    public:

    ARTISTIC_BOOK();
    ARTISTIC_BOOK( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version, direction_type direction, genre_type genre);

    ARTISTIC_BOOK( const ARTISTIC_BOOK &object );              // конструктор копирования  

    virtual ~ARTISTIC_BOOK(){};         // виртуальный деструктор

    void SetParam( bool ebook, string name, int pages, cover material, string pub_name, int pub_version, direction_type direction, genre_type genre );          
    void GetParam( bool* ebook, string* name, int* pages, BOOK::cover* material, string* pub_name, int* pub_version, direction_type *direction, genre_type *genre );


    bool operator ==(const ARTISTIC_BOOK &object);
    bool operator !=(const ARTISTIC_BOOK &object);

    virtual string to_string() final;
    virtual void from_string( string result ) final;

    friend ostream& operator<< (ostream &out, const ARTISTIC_BOOK &object);
    friend istream& operator>> (istream &in, ARTISTIC_BOOK &object);

    bool IsDetectiv();  

};

#endif