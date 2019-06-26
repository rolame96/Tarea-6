#include "DtPuntaje.h"

DtPuntaje::DtPuntaje () {
	this->puntos = 0;
}

DtPuntaje::DtPuntaje (int puntos) {
	this->puntos = puntos;
}

int DtPuntaje::getPuntos(){ 
	return this->puntos;
}

ostream& operator <<(ostream& salida, const DtPuntaje& dtPuntaje) {
	cout << dtPuntaje.puntos;
	return salida;
}

DtPuntaje::~DtPuntaje(){}
