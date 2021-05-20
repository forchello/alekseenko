#include "artistic.h"

ARTISTIC_BOOK::ARTISTIC_BOOK()
{
    direction = modern;
    genre = detective;
}

ARTISTIC_BOOK::ARTISTIC_BOOK( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version, direction_type direction, genre_type genre )
{
    ((BOOK*)this)->SetParam( ebook, name, pages, material, pub_name, pub_version );
    this->direction = direction;
    this->genre = genre;
}

void ARTISTIC_BOOK::SetParam( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version, direction_type direction, genre_type genre )
{
    ((BOOK*)this)->SetParam( ebook, name, pages, material, pub_name, pub_version );
    this->direction = direction;
    this->genre = genre;
}  

void ARTISTIC_BOOK::GetParam( bool* ebook, string* name, int* pages, BOOK::cover* material, string* pub_name, int* pub_version, direction_type *direction, genre_type *genre )
{
    ((BOOK*)this)->GetParam( ebook, name, pages, material, pub_name, pub_version );
    *direction = this -> direction;
	*genre = this -> genre;
}

ARTISTIC_BOOK::ARTISTIC_BOOK( const ARTISTIC_BOOK &object )
{
    *(BOOK*)this = object;               
    this -> direction = object.direction;
    this -> genre = object.genre;
}

//---------------------------------------

bool ARTISTIC_BOOK::operator ==(const ARTISTIC_BOOK &object)
{
    return *(BOOK*)this == *this && 
        this -> direction == object.direction &&
        this -> genre == object.genre;

}

bool ARTISTIC_BOOK::operator !=(const ARTISTIC_BOOK &object)
{
    return !(*this == object);
}

string ARTISTIC_BOOK::to_string()
{
    stringstream result;
    string temp_dir;
    string temp_genre;

    if ( direction == ARTISTIC_BOOK::renaissance )
		temp_dir = "renaissance";
	else if ( direction == ARTISTIC_BOOK::modern )
        temp_dir = "modern";
    else if ( direction = ARTISTIC_BOOK::postmodern )
        temp_dir = "postmodern";	

    if ( genre == ARTISTIC_BOOK::roman )
        temp_genre = "roman";    
    else if ( genre == ARTISTIC_BOOK::detective )
        temp_genre = "detective"; 	
    else if ( genre == ARTISTIC_BOOK::novel )
        temp_genre = "novel";
    else if ( genre == ARTISTIC_BOOK::story )
        temp_genre = "story";	 

    result << *(BOOK*)this << " " << temp_dir << " " << temp_genre;
	return result.str();
}

void ARTISTIC_BOOK::from_string( string result2 )
{
    stringstream result(from_string_prot(result2));
    string temp_dir, temp_genre;

	result >> temp_dir >> temp_genre;

	if ( temp_dir == "renaissance" )
		direction = renaissance;
	else if ( temp_dir == "modern" )
		direction = modern;
    else if ( temp_dir == "postmodern" )
		direction = postmodern;

    if ( temp_genre == "roman" )
        genre = roman;
    else if ( temp_genre == "detective" )
		genre = detective;
    else if ( temp_genre == "novel" )
		genre = ARTISTIC_BOOK::novel;  
    else if ( temp_genre == "story" )
		genre = ARTISTIC_BOOK::story;       
}

ostream& operator<< (ostream &out, const ARTISTIC_BOOK &object)
{   
    string temp_dir, temp_genre;

    if ( object.direction == ARTISTIC_BOOK::renaissance )
		temp_dir = "renaissance";
	else if ( object.direction == ARTISTIC_BOOK::modern )
        temp_dir = "modern";
    else if ( object.direction == ARTISTIC_BOOK::postmodern )
        temp_dir = "postmodern";	

    if ( object.genre == ARTISTIC_BOOK::roman )
        temp_genre = "roman";    
    else if ( object.genre == ARTISTIC_BOOK::detective )
        temp_genre = "detective"; 	
    else if ( object.genre == ARTISTIC_BOOK::novel )
        temp_genre = "novel";
    else if ( object.genre == ARTISTIC_BOOK::story )
        temp_genre = "story";

    out << *(BOOK*)&object << " " << temp_dir << " " << temp_genre;

    return out;
}

istream& operator>> (istream &in, ARTISTIC_BOOK &object)
{
    string temp_dir, temp_genre;
    
    in >> *(BOOK*)&object >> temp_dir >> temp_genre;

    if ( temp_dir == "renaissance" )
		object.direction = ARTISTIC_BOOK::renaissance;
	else if ( temp_dir == "modern" )
		object.direction = ARTISTIC_BOOK::modern;
    else if ( temp_dir == "postmodern" )
		object.direction = ARTISTIC_BOOK::postmodern;

    if ( temp_genre == "roman" )
        object.genre = ARTISTIC_BOOK::roman;
    else if ( temp_genre == "detective" )
		object.genre = ARTISTIC_BOOK::detective;
    else if ( temp_genre == "novel" )
		object.genre = ARTISTIC_BOOK::novel;  
    else if ( temp_genre == "story" )
		object.genre = ARTISTIC_BOOK::story;

    return in;
}

int ARTISTIC_BOOK::GetPages()
{
	return ( this->pages );
}

string ARTISTIC_BOOK::GetName()
{
	return ( this->name );
}

bool ARTISTIC_BOOK::GetEbook()
{
	return ( this->ebook );
}