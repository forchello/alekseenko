#include "book.h"

BOOK::BOOK()
{
	ebook = true;
	name = "defolt_name";
	pages = 123;

	material = tverda;

	pub.name = "defolt_pub";
	pub.version = 1;
}

BOOK::BOOK( bool ebook, string name, int pages,  BOOK::cover material, string pub_name, int pub_version ) 
{
	this -> ebook = ebook;
	this -> name = name;
	this -> pages = pages;

	this -> material = material;

	this -> pub.name = pub_name;
	this -> pub.version = pub_version;
}

BOOK::BOOK( const BOOK &object )               // конструктор копирования 
{
	this -> ebook = object.ebook;
	this -> name =  object.name;
	this -> pages =  object.pages;

	this -> material =  object.material;

	this -> pub.name =  object.pub.name;
	this -> pub.version =  object.pub.version; 
} 

void BOOK::SetParam( bool ebook, string name, int pages, BOOK::cover material, string pub_name, int pub_version )
{
	this -> ebook = ebook;
	this -> name = name;
	this -> pages = pages;

	this -> material = material;

	this -> pub.name = pub_name;
	this -> pub.version = pub_version;           
}

void BOOK::GetParam( bool *ebook, string *name, int *pages, BOOK::cover *material, string *pub_name, int *pub_version )
{
	*ebook = this -> ebook;
	*name = this -> name;
	*pages = this -> pages;

	*material = (BOOK::cover)this -> material;

	*pub_name = this -> pub.name;
	*pub_version = this -> pub.version;
}

string BOOK::to_string()
{
	stringstream result;

	result << BoolToString(ebook) << " " << name << " " << pages << " " << pub.name << " " << pub.version
									<< ( material == tverda ? " tverda" : " myaka" );

	return result.str();
}

void BOOK::from_string( string result2 )
{	
	from_string_prot(result2);
	stringstream result(result2);

	string tmp_ebook, tmp_material;

	result >> tmp_ebook >> name >> pages >> pub.name >> pub.version >> tmp_material;

	ebook = StringToBool(tmp_ebook);

	if ( tmp_material == "tverda" )
		material = BOOK::tverda;
	else if ( tmp_material == "myaka" )
		material = BOOK::myaka;
}

string BOOK::from_string_prot( string result2 )
{
	stringstream result(result2);

	string tmp_ebook, tmp_material, ostatok;

	result >> tmp_ebook >> name >> pages >> pub.name >> pub.version >> tmp_material;
	getline(result, ostatok);
	ebook = StringToBool(tmp_ebook);

	if ( tmp_material == "tverda" )
		material = BOOK::tverda;
	else if ( tmp_material == "myaka" )
		material = BOOK::myaka;

	return ostatok;
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

