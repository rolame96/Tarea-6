#include "Funcion.h"

Funcion::Funcion () {
	this->id=0;
	this->fecha=DtFecha();
	this->horario=DtHorario();
	this->sala=NULL;
	this->pelicula = NULL;
}

Funcion::Funcion (int id,DtFecha fecha,DtHorario horario, Sala* sala,Pelicula* pelicula) {
	this->id = id;
	this->fecha = fecha;
	this->horario = horario;
	this->sala = sala;
	this->pelicula = pelicula;
}

int Funcion::getId(){ 
	return this->id;
}

DtFecha Funcion::getFecha(){
	return this->fecha;
}

DtHorario Funcion::getHorario(){
	return this->horario;
}

Sala* Funcion::getSala(){
	return this->sala;
}

void Funcion::setSala(Sala* sala){
	this->sala=sala;
}

Pelicula* Funcion::getPelicula(){
	return this->pelicula;
}

void Funcion::setPelicula(Pelicula* pelicula){
	this->pelicula=pelicula;
}

DtFuncion Funcion::getDatosFuncion(){
	DtFuncion df = DtFuncion(this->id,this->fecha, this->horario);
	return df;
}

Funcion::~Funcion(){}

