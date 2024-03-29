#include "Usuario.h"

//constructor por defecto
Usuario::Usuario(){
  this->nickname= "admin";
  this->password= "admin";
  this->urlFoto= "";
  this->admin= true;
}

Usuario::Usuario(string nickname, string password, string urlFoto, bool admin){
  this->nickname= nickname;
  this->password= password;
  this->urlFoto= urlFoto;
  this->admin= admin;
}

void Usuario::setNickname(string nickname){
	this->nickname = nickname;	
}

string Usuario::getNickname(){
	return this->nickname;
}

void Usuario::setPassword(string password){
	this->password=password;
}
string Usuario::getPassword(){
	return this->password;
}

void Usuario::setUrlFoto(string urlFoto){
	this->urlFoto=urlFoto;
}
string Usuario::getUrlFoto(){
	return this->urlFoto;
}

bool Usuario::esAdmin(){
	return this->admin;
}

Usuario::~Usuario(){}
