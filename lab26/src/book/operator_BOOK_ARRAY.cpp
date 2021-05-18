#include "book_array_class.h"

BOOK& BOOK_ARRAY::operator[] (int index)
{
    return library[index];
}

BOOK& BOOK_ARRAY::operator[] (int index) const 
{
    return library[index];
}

ostream& operator<< (ostream &out, const BOOK_ARRAY &object)
{   
    int n = object.size;

    for ( int i = 0; i < n; i++ )
    {
        out << object[i] << ( i != n - 1 ? "\n" : "" );
    }   

    return out;
}

istream& operator>> (istream &in, BOOK_ARRAY &object)
{ 
    int n = object.size;

    for ( int i = 0; i < n; i++ )
    {
        in >> object[i];
    }

    return in;
}

ofstream& operator<< (ofstream &out, const BOOK_ARRAY &object)
{
    int n = object.size;

    for ( int i = 0; i < n; i++ )
    {
        out << object[i] << ( i != n - 1 ? "\n" : "" );
    }   

    return out;
}

ifstream& operator>> (ifstream &in, BOOK_ARRAY &object)
{
    int n = object.size;

    for ( int i = 0; i < n; i++ )
    {
        in >> object[i];
    }

    return in;
}