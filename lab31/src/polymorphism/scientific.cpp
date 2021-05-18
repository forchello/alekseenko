#include "scientific.h"

SCIENTIFIC_BOOK::SCIENTIFIC_BOOK()
{
    scope = programming;
    certification = false;
}

SCIENTIFIC_BOOK::SCIENTIFIC_BOOK( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version, scope_type scope, bool certification )
{
    ((BOOK*)this)->SetParam( ebook, name, pages, material, pub_name, pub_version );
    this->scope = scope;
    this->certification = certification;
}

void SCIENTIFIC_BOOK::SetParam( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version, scope_type scope, bool certification )
{
    ((BOOK*)this)->SetParam( ebook, name, pages, material, pub_name, pub_version );
    this->scope = scope;
    this->certification = certification;
}  

void SCIENTIFIC_BOOK::GetParam(  bool* ebook, string* name, int* pages, BOOK::cover* material, string* pub_name, int* pub_version, scope_type *scope, bool *certification )
{
    ((BOOK*)this)->GetParam( ebook, name, pages, material, pub_name, pub_version );
    *scope = this -> scope;
	*certification = this -> certification;
}

SCIENTIFIC_BOOK::SCIENTIFIC_BOOK( const SCIENTIFIC_BOOK &object )           // КОПИРОВАНИЯ
{
    *(BOOK*)this = object;
    this -> scope = object.scope;
    this -> certification = object.certification;
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


ostream& operator<< (ostream &out, const SCIENTIFIC_BOOK &object)
{   
    string temp_scope, temp_cert;

    if ( object.scope == SCIENTIFIC_BOOK::chemistry )
        temp_scope = "chemistry";    
    else if ( object.scope == SCIENTIFIC_BOOK::biology )
        temp_scope = "biology"; 	
    else if ( object.scope == SCIENTIFIC_BOOK::physics )
        temp_scope = "physics";
    else if ( object.scope == SCIENTIFIC_BOOK::programming )
        temp_scope = "programming";	 

    if ( object.certification == true )
        temp_cert = "true";
    else if ( object.certification == false )
        temp_cert = "false";

    out << *(BOOK*)&object << " " << temp_scope << " " << temp_cert;

    return out;
}

istream& operator>> (istream &in, SCIENTIFIC_BOOK &object)
{
    string temp_scope, temp_cert;
    
    in >> *(BOOK*)&object >> temp_scope >> temp_cert;

    if ( temp_scope == "chemistry" )
        object.scope = SCIENTIFIC_BOOK::chemistry;
    else if ( temp_scope == "biology" )
		object.scope = SCIENTIFIC_BOOK::biology;
    else if ( temp_scope == "physics" )
		object.scope = SCIENTIFIC_BOOK::physics;  
    else if ( temp_scope == "programming" )
		object.scope = SCIENTIFIC_BOOK::programming;   

    if ( temp_cert == "true" )
        object.certification = true;
    else
        object.certification = false; 

    return in;
}

int SCIENTIFIC_BOOK::GetPages()
{
	return ( this->pages );
}