#include "DtFuncion.h"

DtFuncion::DtFuncion () {
	this->id=0;
	this->fecha=DtFecha();
	this->horario=DtHorario();
}

DtFuncion::DtFuncion (int id,DtFecha fecha,DtHorario horario) {
	this->id = id;
	this->fecha = fecha;
	this->horario = horario;
}

int DtFuncion::getId(){ 
	return this->id;
}

DtFecha DtFuncion::getFecha(){
	return this->fecha;
}

DtHorario DtFuncion::getHorario(){
	return this->horario;
}

ostream& operator <<(ostream& salida, const DtFuncion& dtFuncion) {
	cout << dtFuncion.id << " - " << dtFuncion.fecha << " " << dtFuncion.horario;
	return salida;
}

DtFuncion::~DtFuncion(){}
