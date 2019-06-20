#include "DtPelicula.h"

DtPelicula::DtPelicula () {
	this->titulo = "";
	this->sinopsis = "";
	this->poster = "";
	this->puntajePromedio = 0;
}

DtPelicula::DtPelicula (string titulo,string sinopsis,string poster, float puntajePromedio) {
	this->titulo = titulo;
	this->sinopsis = sinopsis;
	this->poster = poster;
	this->puntajePromedio = puntajePromedio;
}

string DtPelicula::getTitulo(){ 
	return this->titulo;
}

string DtPelicula::getSinopsis(){
	return this->sinopsis;
}

string DtPelicula::getPoster(){
	return this->poster;
}

float DtPelicula::getPuntajePromedio(){
	return this->puntajePromedio;
}

ostream& operator <<(ostream& salida, const DtPelicula& dtPelicula) {
	cout << dtPelicula.titulo << " : " << dtPelicula.sinopsis <<  " : " << dtPelicula.poster << " : " << dtPelicula.puntajePromedio << "\n";
	return salida;
}

DtPelicula::~DtPelicula(){}
