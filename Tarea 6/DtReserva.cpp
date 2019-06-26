#include "DtReserva.h"

DtReserva::DtReserva () {
	this->id=0;
	this->costo=0;
	this->cantEntradas=0;
}

DtReserva::DtReserva (int id, float costo,int cantEntradas) {
	this->id = id;
	this->costo = costo;
	this->cantEntradas = cantEntradas;
}

int DtReserva::getId(){
	return this->id;
}

float DtReserva::getCosto(){ 
	return this->costo;
}

int DtReserva::getCantEntradas(){
	return this->cantEntradas;
}

DtReserva::~DtReserva(){}
