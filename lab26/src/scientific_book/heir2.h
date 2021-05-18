#include "artistic_book/heir1.h"

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
        SCIENTIFIC_BOOK( BOOK &object, scope_type scope, bool certification );

        SCIENTIFIC_BOOK( const SCIENTIFIC_BOOK &object );              // конструктор копирования  

        void SetParam( BOOK &object, scope_type scope, bool certification  );          
        void GetParam( BOOK *object, scope_type *scope, bool *certification  );


        SCIENTIFIC_BOOK& operator= ( const SCIENTIFIC_BOOK &object );

        bool operator ==(const SCIENTIFIC_BOOK &object);
        bool operator !=(const SCIENTIFIC_BOOK &object);

        bool operator <(const SCIENTIFIC_BOOK &object);
        bool operator <=(const SCIENTIFIC_BOOK &object);
        bool operator >(const SCIENTIFIC_BOOK &object);
        bool operator >=(const SCIENTIFIC_BOOK &object);

        string to_string();
        void from_string( string result );
};