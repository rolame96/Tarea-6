#include "Reserva.h"

Reserva::Reserva () {
	this->id=0;
	this->costo=0;
	this->cantEntrada=0;
	this->funcion= getFuncion();
	this->usuario= getUsuario();
}

Reserva::Reserva (int id, float costo,int cantEntrada, Funcion* funcion, Usuario* usuario) {
	this->id = id;
	this->costo = costo;
	this->cantEntrada = cantEntrada;
	this->funcion = funcion;
	this->usuario = usuario;
}

int Reserva::getId(){
	return this->id;
}

void Reserva::setId(){ 
	this->id=id;
}

float Reserva::getCosto(){ 
	return this->costo;
}

void Reserva::setCosto(){ 
	this->costo=costo;
}

int Reserva::getCantEntrada(){
	return this->cantEntrada;
}

void Reserva::setCantEntrada(){ 
	this->cantEntrada=cantEntrada;
}

Funcion* Reserva::getFuncion(){
	return this->funcion;
}

void Reserva::setFuncion(){ 
	this->funcion=funcion;
}

Usuario* Reserva::getUsuario(){
	return this->usuario;
}

void Reserva::setUsuario(){ 
	this->usuario=usuario;
}

Reserva::~Reserva(){}

