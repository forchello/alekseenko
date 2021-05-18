#include "heir2.h"

SCIENTIFIC_BOOK::SCIENTIFIC_BOOK()
{
    scope = programming;
    certification = false;
}

SCIENTIFIC_BOOK::SCIENTIFIC_BOOK( BOOK &object, scope_type scope, bool certification )
{
    *(BOOK*)this = object;
    this->scope = scope;
    this->certification = certification;
}

void SCIENTIFIC_BOOK::SetParam( BOOK &object, scope_type scope, bool certification )
{
    *(BOOK*)this = object;
    this->scope = scope;
    this->certification = certification;
}  

void SCIENTIFIC_BOOK::GetParam( BOOK *object, scope_type *scope, bool *certification )
{
    *object = *this;
    *scope = this -> scope;
	*certification = this -> certification;
}

SCIENTIFIC_BOOK::SCIENTIFIC_BOOK( const SCIENTIFIC_BOOK &object )           // КОПИРОВАНИЯ
{
    *(BOOK*)this = object;
    this -> scope = object.scope;
    this -> certification = object.certification;
}

SCIENTIFIC_BOOK& SCIENTIFIC_BOOK::operator= ( const SCIENTIFIC_BOOK &object )
{
    *(BOOK*)this = object; 

    this -> scope = object.scope;
    this -> certification = object.certification;

    return *this;
}

bool SCIENTIFIC_BOOK::operator ==(const SCIENTIFIC_BOOK &object)
{
    return *(BOOK*)this == (SCIENTIFIC_BOOK)*this && 
        this -> scope == object.scope &&
        this -> certification == object.certification;

}

bool SCIENTIFIC_BOOK::operator !=(const SCIENTIFIC_BOOK &object)
{
    return !(*this == object);
}

bool SCIENTIFIC_BOOK::operator <(const SCIENTIFIC_BOOK &object)
{
    return *(BOOK*)this < (SCIENTIFIC_BOOK)*this && 
        this -> scope < object.scope &&
        this -> certification < object.certification;
}

bool SCIENTIFIC_BOOK::operator >(const SCIENTIFIC_BOOK &object)
{
    return !(*this < object);
}

bool SCIENTIFIC_BOOK::operator <=(const SCIENTIFIC_BOOK &object)
{
    return *(BOOK*)this <= (SCIENTIFIC_BOOK)*this && 
        this -> scope <= object.scope &&
        this -> certification <= object.certification;
}
    
bool SCIENTIFIC_BOOK::operator >=(const SCIENTIFIC_BOOK &object)
{
    return !(*this <= object);
}

string SCIENTIFIC_BOOK::to_string()
{
    stringstream result;
    string temp_scope;
    string temp_cert;

    if ( scope == chemistry )
        temp_scope = "chemistry";    
    else if ( scope == biology )
        temp_scope = "biology"; 	
    else if ( scope == physics )
        temp_scope = "physics";
    else if ( scope == programming )
        temp_scope = "programming";	 

    if ( certification == true )
        temp_cert = "true";
    else if ( certification == false )
        temp_cert = "false";

    result << *(BOOK*)this << " " << temp_scope << " " << temp_cert;
	return result.str();
}

void SCIENTIFIC_BOOK::from_string( string result2 )
{
    stringstream result(from_string_prot(result2));
    string temp_scope, temp_cert;
    
	result >> temp_scope >> temp_cert;

    if ( temp_scope == "chemistry" )
        scope = chemistry;
    else if ( temp_scope == "biology" )
		scope = biology;
    else if ( temp_scope == "physics" )
		scope = physics;  
    else if ( temp_scope == "programming" )
		scope = programming;   

    if ( temp_cert == "true" )
        certification = true;
    else
        certification = false;    
}