#include "Comentario.h"

Comentario::Comentario () {
	this->texto = "";
	this->usuario = NULL;
}

Comentario::Comentario (string texto,Usuario* usuario) {
	this->texto = texto;
	this->usuario = usuario;
}

string Comentario::getTexto(){ 
	return this->texto;
}

void Comentario::setTexto(string texto){
	this->texto=texto;
}

Usuario* Comentario::getUsuario(){ 
	return this->usuario;
}

void Comentario::setUsuario(Usuario* usuario){
	this->usuario=usuario;
}

void Comentario::agregarRespuesta(Comentario* comentario){
	this->listaRespuesta.push_back(comentario);
}

Comentario::~Comentario(){}

