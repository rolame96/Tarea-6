#include "Pelicula.h"

Pelicula::Pelicula () {
	this->titulo = "";
	this->sinopsis = "";
	this->poster = "";
}

Pelicula::Pelicula (string titulo,string sinopsis, string poster) {
	this->titulo = titulo;
	this->sinopsis = sinopsis;
	this->poster = poster;
}

string Pelicula::getTitulo(){ 
	return this->titulo;
}

string Pelicula::getSinopsis(){
	return this->sinopsis;
}

string Pelicula::getPoster(){
	return this->poster;
}

float Pelicula::getPuntajePelicula(){
	if (listaPuntaje.size() > 0){
		int sum=0;
		for (std::list<Puntaje*>::iterator it=listaPuntaje.begin(); it != listaPuntaje.end(); ++it){
			Puntaje* p = *it;
			sum=sum+p->getPuntos();
		}
		return sum/listaPuntaje.size();
	}
	else
		return 0;
	
}

void Pelicula::agregarPuntaje(Puntaje* puntaje){
	this->listaPuntaje.push_back(puntaje);
}

void Pelicula::agregarComentario(Comentario* comentario){
	this->listaComentario.push_back(comentario);
}

DtPelicula Pelicula::getDatosPelicula(){
	DtPelicula dp = DtPelicula(this->titulo,this->sinopsis, this->poster, this->getPuntajePelicula());
	return dp;
}

Pelicula::~Pelicula(){}

