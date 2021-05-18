#include "heir1.h"

ARTISTIC_BOOK::ARTISTIC_BOOK()
{
    direction = modern;
    genre = detective;
}

ARTISTIC_BOOK::ARTISTIC_BOOK( BOOK &object, direction_type direction, genre_type genre )
{
    *(BOOK*)this = object;
    this->direction = direction;
    this->genre = genre;
}

void ARTISTIC_BOOK::SetParam( BOOK &object, direction_type direction, genre_type genre )
{
    *(BOOK*)this = object;
    this->direction = direction;
    this->genre = genre;
}  

void ARTISTIC_BOOK::GetParam( BOOK *object, direction_type *direction, genre_type *genre )
{
    *object = *this;
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

ARTISTIC_BOOK& ARTISTIC_BOOK::operator= (const ARTISTIC_BOOK &object)
{
    *(BOOK*)this = object;   

    this -> direction = object.direction;
    this -> genre = object.genre;

    return *this;
}

//---------------------------------------

bool ARTISTIC_BOOK::operator ==(const ARTISTIC_BOOK &object)
{
    return *(BOOK*)this == (ARTISTIC_BOOK)*this && 
        this -> direction == object.direction &&
        this -> genre == object.genre;

}

bool ARTISTIC_BOOK::operator !=(const ARTISTIC_BOOK &object)
{
    return !(*this == object);
}

bool ARTISTIC_BOOK::operator <(const ARTISTIC_BOOK &object)
{
    return *(BOOK*)this < (ARTISTIC_BOOK)*this && 
        this -> direction < object.direction &&
        this -> genre < object.genre;
}

bool ARTISTIC_BOOK::operator >(const ARTISTIC_BOOK &object)
{
    return !(*this < object);
}

bool ARTISTIC_BOOK::operator <=(const ARTISTIC_BOOK &object)
{
    return *(BOOK*)this <= (ARTISTIC_BOOK)*this && 
        this -> direction <= object.direction &&
        this -> genre <= object.genre;
}
    
bool ARTISTIC_BOOK::operator >=(const ARTISTIC_BOOK &object)
{
    return !(*this <= object);
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