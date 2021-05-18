#include "general_book.h"

GENERAL_BOOK::GENERAL_BOOK()
{
}

GENERAL_BOOK::GENERAL_BOOK( bool ebook, string name, int pages,  BOOK::cover material, string pub_name, int pub_version ) : BOOK( ebook,  name,  pages,  (BOOK::cover)material,  pub_name,  pub_version)
{
}

GENERAL_BOOK::GENERAL_BOOK( const GENERAL_BOOK &object ) : BOOK( object ) // конструктор копирования 
{
}