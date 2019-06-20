#include "Puntaje.h"

Puntaje::Puntaje () {
	this->puntos = 0;
	this->usuario = NULL;
}

Puntaje::Puntaje (int puntos,Usuario* usuario) {
	this->puntos = puntos;
	this->usuario = usuario;
}

int Puntaje::getPuntos(){ 
	return this->puntos;
}

void Puntaje::setPuntos(){
	this->puntos=puntos;
}

Usuario* Puntaje::getUsuario(){
	return this->usuario;
}

void Puntaje::setUsuario(){
	this->usuario=usuario;
}

Puntaje::~Puntaje(){}
