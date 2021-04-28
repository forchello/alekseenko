#include "book_array_class.h"

BOOK::BOOK()
{
	ebook = true;
	name = "defolt_name";
	pages = 123;

	material = tverda;

	pub.name = "defolt_pub";
	pub.version = 1;
};

BOOK::BOOK( bool ebook, string name, int pages, cover material, string pub_name, int pub_version )
{
	this -> ebook = ebook;
	this -> name = name;
	this -> pages = pages;

	this -> material = material;

	this -> pub.name = pub_name;
	this -> pub.version = pub_version; 
};

void BOOK::SetParam( bool ebook, string name, int pages, cover material, string pub_name, int pub_version )
{
	this -> ebook = ebook;
	this -> name = name;
	this -> pages = pages;

	this -> material = material;

	this -> pub.name = pub_name;
	this -> pub.version = pub_version;           
};

void BOOK::GetParam( bool *ebook, string *name, int *pages, cover *material, string *pub_name, int *pub_version )
{
	*ebook = this -> ebook;
	*name = this -> name;
	*pages = this -> pages;

	*material = this -> material;

	*pub_name = this -> pub.name;
	*pub_version = this -> pub.version;
}; 

BOOK::BOOK( const BOOK &object )               // конструктор копирования 
{
	this -> ebook = object.ebook;
	this -> name =  object.name;
	this -> pages =  object.pages;

	this -> material =  object.material;

	this -> pub.name =  object.pub.name;
	this -> pub.version =  object.pub.version; 
};  

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