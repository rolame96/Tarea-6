#include "Sala.h"

Sala::Sala () {
	this->id=0;
	this->capacidad=0;
}

Sala::Sala (int id,int capacidad, Cine* cine) {
	this->id = id;
	this->capacidad = capacidad;
	this->cine=cine;
}

int Sala::getId(){ 
	return this->id;
}

int Sala::getCapacidad(){
	return this->capacidad;
}

DtSala Sala::getDatosSala(){
	
	return DtSala();
}

Cine* Sala::getCine(){
	return this->cine;
}

Sala::~Sala(){}

