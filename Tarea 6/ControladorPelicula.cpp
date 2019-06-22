#include "ControladorPelicula.h"
#include <iostream>

ControladorPelicula* ControladorPelicula::instancia = NULL;

ControladorPelicula::ControladorPelicula(){
	this->peliculaSeleccionada=NULL;
	this->listaPeliculas.clear();
}

ControladorPelicula* ControladorPelicula::getInstancia(){
	if (instancia == NULL)
		instancia = new ControladorPelicula();
	return instancia;
}

void ControladorPelicula::agregarPelicula(DtPelicula dtPelicula){
	Pelicula* nuevaPelicula = new Pelicula(dtPelicula.getTitulo(), dtPelicula.getSinopsis(), dtPelicula.getPoster());
	listaPeliculas.push_back(nuevaPelicula);
}

list<DtPelicula> ControladorPelicula::listarPelicula(){
	list<DtPelicula> listaDtPelicula;
	for (std::list<Pelicula*>::iterator it=listaPeliculas.begin(); it != listaPeliculas.end(); ++it){
		Pelicula* p = *it;
		listaDtPelicula.push_back(p->getDatosPelicula());
	}
	return listaDtPelicula;
}

void ControladorPelicula::seleccionarPelicula(DtPelicula dtPelicula){	
	for (std::list<Pelicula*>::iterator it=listaPeliculas.begin(); it != listaPeliculas.end(); ++it){
		Pelicula* p = *it;
		if(p->getTitulo()==dtPelicula.getTitulo()){
 			peliculaSeleccionada = p;
			 break;	    
 		}
	}	
}
Pelicula* ControladorPelicula::getpeliculaSeleccionada(){
	return this->peliculaSeleccionada;
}

ControladorPelicula::~ControladorPelicula(){}
