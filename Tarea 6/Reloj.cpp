#include "Reloj.h"

Reloj* Reloj::instancia = NULL;

Reloj* Reloj::getInstancia(){
	if (instancia == NULL)
		instancia = new Reloj();
	return instancia;
}

Reloj::Reloj() {
	this->fecha=DtFecha();
	this->horario=DtHorario();
}

DtFecha Reloj::getFecha(){
	return this->fecha;
}

DtHorario Reloj::getHorario(){
	return this->horario;
}

void Reloj::setFecha(DtFecha fecha){
	this->fecha=fecha;
}

void Reloj::setHorario(DtHorario horario){
	this->horario=horario;
}

void Reloj::modificarFecha(DtFecha dtFecha, DtHorario dtHorario){
	this->setFecha(dtFecha);
	this->setHorario(dtHorario);
}

void Reloj::imprimirFecha(){
	cout << this->getFecha() << " " << this->getHorario()<<endl;
}	

Reloj::~Reloj(){}
