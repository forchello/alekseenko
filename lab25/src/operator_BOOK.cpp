#include "book_class.h"

void BOOK::operator =(const BOOK &object)
{
    this->ebook = object.ebook;
    this->name = object.name;
    this->pages = object.pages;

    this->material = object.material;

    this->pub.name = object.pub.name;
    this->pub.version = object.pub.version;
}

bool BOOK::operator ==(const BOOK &object)
{
    return this->ebook == object.ebook 
    && this->name == object.name 
    && this->pages == object.pages
    && this->material == object.material
    && this->pub.name == object.pub.name
    && this->pub.version == object.pub.version;
}

bool BOOK::operator !=(const BOOK &object)
{
    return !(*this == object);
}

bool BOOK::operator <(const BOOK &object)
{
    return this->ebook < object.ebook 
    && this->name < object.name 
    && this->pages < object.pages
    && this->material < object.material
    && this->pub.name < object.pub.name
    && this->pub.version < object.pub.version;
}

bool BOOK::operator >(const BOOK &object)
{
    return !(*this < object);
}

bool BOOK::operator <=(const BOOK &object)
{
    return this->ebook <= object.ebook 
    && this->name <= object.name 
    && this->pages <= object.pages
    && this->material <= object.material
    && this->pub.name <= object.pub.name
    && this->pub.version <= object.pub.version;
}

bool BOOK::operator >=(const BOOK &object)
{
    return !(*this <= object);
}

ostream& operator<< (ostream &out, const BOOK &object)
{   
    out << BoolToString(object.ebook) << " " << object.name << " " << object.pages << " " 
    << object.pub.name << " " << object.pub.version << ( object.material == BOOK::tverda ? " tverda" : " myaka" );
    return out;
}

istream& operator>> (istream &in, BOOK &object)
{
    string temp_ebook, temp_material, temp_name;
    regex regular("^[A-Z]([A-Za-z0-9]|([,?!\\._ ][^\\.,?!_ ]))+");

    in >> temp_ebook >> temp_name >> object.pages >> object.pub.name >> object.pub.version >> temp_material ; 
    object.ebook = StringToBool(temp_ebook); 

    temp_material == "tverda" ? object.material = BOOK::tverda : object.material = BOOK::myaka;

    if ( regex_match(temp_name.c_str(), regular ) )
        object.name = temp_name;
    else
        object.name = "INVALID_NAME";

    return in;
}