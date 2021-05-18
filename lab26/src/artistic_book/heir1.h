#include "book/book_array_class.h"

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
    ARTISTIC_BOOK( BOOK &object, direction_type direction, genre_type genre);

    ARTISTIC_BOOK( const ARTISTIC_BOOK &object );              // конструктор копирования  

    void SetParam( BOOK &object, direction_type direction, genre_type genre );          
    void GetParam( BOOK *object, direction_type *direction, genre_type *genre );



    ARTISTIC_BOOK& operator =(const ARTISTIC_BOOK &object);
    bool operator ==(const ARTISTIC_BOOK &object);
    bool operator !=(const ARTISTIC_BOOK &object);

    bool operator <(const ARTISTIC_BOOK &object);
    bool operator <=(const ARTISTIC_BOOK &object);
    bool operator >(const ARTISTIC_BOOK &object);
    bool operator >=(const ARTISTIC_BOOK &object);

    string to_string();
    void from_string( string result );

};