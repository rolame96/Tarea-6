#include "Reserva.h"

Reserva::Reserva () {
	this->id=0;
	this->costo=0;
	this->cantEntradas=0;
	this->funcion= getFuncion();
	this->usuario= getUsuario();
}

Reserva::Reserva (int id, float costo,int cantEntradas, Funcion* funcion, Usuario* usuario) {
	this->id = id;
	this->costo = costo;
	this->cantEntradas = cantEntradas;
	this->funcion = funcion;
	this->usuario = usuario;
}

int Reserva::getId(){
	return this->id;
}

void Reserva::setId(int id){ 
	this->id=id;
}

float Reserva::getCosto(){ 
	return this->costo;
}

void Reserva::setCosto(float costo){ 
	this->costo=costo;
}

int Reserva::getCantEntradas(){
	return this->cantEntradas;
}

void Reserva::setCantEntradas(int cantEntradas){ 
	this->cantEntradas=cantEntradas;
}

Funcion* Reserva::getFuncion(){
	return this->funcion;
}

void Reserva::setFuncion(Funcion* funcion){ 
	this->funcion=funcion;
}

Usuario* Reserva::getUsuario(){
	return this->usuario;
}

void Reserva::setUsuario(Usuario* usuario){ 
	this->usuario=usuario;
}

Reserva::~Reserva(){}

