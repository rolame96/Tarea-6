#include "DtCine.h"

DtCine::DtCine () {
	this->id=0;
	this->direccion=DtDireccion();
}

DtCine::DtCine (int id,DtDireccion direccion) {
	this->id = id;
	this->direccion = direccion;
}

/*
DtCine::DtCine(Cine* cine){
	this->id=cine->getId();
	this->direccion=cine->getDireccion();
}
*/

int DtCine::getId(){ 
	return this->id;
}

DtDireccion DtCine::getDireccion(){
	return this->direccion;
}

ostream& operator <<(ostream& salida, const DtCine& dtCine) {
	cout << dtCine.id << " - " << dtCine.direccion;
	return salida;
}

DtCine::~DtCine(){}
