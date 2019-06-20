#include "DtHorario.h"

DtHorario::DtHorario () {
	this->hora=0;
	this->minutos=0;
}

DtHorario::DtHorario (int hora,int minutos) {
	this->hora = hora;
	this->minutos = minutos;
}

int DtHorario::getHora(){ 
	return this->hora;
}

int DtHorario::getMinutos(){
	return this->minutos;
}

ostream& operator <<(ostream& salida, const DtHorario& dtHorario) {
	cout << dtHorario.hora << " : " << dtHorario.minutos << "\n";
	return salida;
}

DtHorario::~DtHorario(){}
