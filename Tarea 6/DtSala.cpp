#include "DtSala.h"

DtSala::DtSala () {
	this->id=0;
	this->capacidad=0;
}

DtSala::DtSala (int id,int capacidad) {
	this->id = id;
	this->capacidad = capacidad;
}

DtSala::DtSala(Sala* sala){
	this->id=sala->getId();
	this->capacidad=sala->getCapacidad();
}

int DtSala::getId(){ 
	return this->id;
}

int DtSala::getCapacidad(){
	return this->capacidad;
}

ostream& operator <<(ostream& salida, const DtSala& dtSala) {
	cout << dtSala.id << " - " << dtSala.capacidad << "\n";
	return salida;
}

DtSala::~DtSala(){}
