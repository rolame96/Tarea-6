#include "DtReserva.h"

DtReserva::DtReserva () {
	this->id=0;
	this->costo=0;
	this->cantEntrada=0;
}

DtReserva::DtReserva (int id, float costo,int cantEntrada) {
	this->id = id;
	this->costo = costo;
	this->cantEntrada = cantEntrada;
}

int DtReserva::getId(){
	return this->id;
}

void DtReserva::setId(){ 
	this->id=id;
}

float DtReserva::getCosto(){ 
	return this->costo;
}

void DtReserva::setCosto(){ 
	this->costo=costo;
}

int DtReserva::getCantEntrada(){
	return this->cantEntrada;
}

void DtReserva::setCantEntrada(){ 
	this->cantEntrada=cantEntrada;
}

DtReserva::~DtReserva(){}
