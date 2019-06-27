#include "DtDireccion.h"

DtDireccion::DtDireccion () {
	this->calle="";
	this->numero=0;
}

DtDireccion::DtDireccion (string calle,int numero) {
	this->calle = calle;
	this->numero = numero;
}

string DtDireccion::getCalle(){ 
	return this->calle;
}

int DtDireccion::getNumero(){
	return this->numero;
}

ostream& operator <<(ostream& salida, const DtDireccion& dtDireccion) {
	cout << dtDireccion.calle << " " << dtDireccion.numero << "\n";
	return salida;
}

DtDireccion::~DtDireccion(){}
