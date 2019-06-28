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
	ControladorUsuario* cu = ControladorUsuario::getInstancia();
	if(cu->getUsuarioLogueado()==NULL){
		cout << "Debe iniciar sesion."<< endl;
	}else{
		Pelicula* nuevaPelicula = new Pelicula(dtPelicula.getTitulo(), dtPelicula.getSinopsis(), dtPelicula.getPoster());
		listaPeliculas.push_back(nuevaPelicula);
		cout << "Pelicula ingresada."<< endl;
	}
}

void ControladorPelicula::eliminarPeliculaSeleccionada(){
	cout << "Implementar eliminarPeliculaSeleccionada."<< endl;
}

list<DtPelicula> ControladorPelicula::listarPelicula(){
	list<DtPelicula> listaDtPelicula;
	for (std::list<Pelicula*>::iterator it=listaPeliculas.begin(); it != listaPeliculas.end(); ++it){
		Pelicula* p = *it;
		listaDtPelicula.push_back(p->getDatosPelicula());
	}
	return listaDtPelicula;
}

DtPuntaje ControladorPelicula::mostrarPuntaje(){
	ControladorUsuario* cu = ControladorUsuario::getInstancia();
	Puntaje* p;
	list<Puntaje*> lp = peliculaSeleccionada->getlistaPuntaje();
	for (std::list<Puntaje*>::iterator it=lp.begin(); it != lp.end(); ++it){
		p = *it;
		if(p->getUsuario()->getNickname()==cu->getUsuarioLogueado()->getNickname()){
			break;
		}		
	}
	DtPuntaje dp = DtPuntaje(p->getPuntos());
	return dp;
}

void ControladorPelicula::agregarPuntaje(DtPuntaje dtPuntaje){
	ControladorUsuario* cu = ControladorUsuario::getInstancia();
	if(cu->getUsuarioLogueado()==NULL){
		cout << "Debe iniciar sesion."<< endl; 
	}else{
		Puntaje* p = NULL;
		if(usuarioPuntuoPelicula()==true){
			list<Puntaje*> lp = peliculaSeleccionada->getlistaPuntaje();
			for (std::list<Puntaje*>::iterator it=lp.begin(); it != lp.end(); ++it){
				p = *it;
				if(cu->getUsuarioLogueado()->getNickname()==p->getUsuario()->getNickname()){
					p->setPuntos(dtPuntaje.getPuntos());
					break;
				}		
			}		
		}else{
			p = new Puntaje(dtPuntaje.getPuntos(), cu->getUsuarioLogueado());
			peliculaSeleccionada->agregarPuntaje(p);
		}
	}	
}

DtPelicula ControladorPelicula::getDatosPeliculaSeleccionada(){
	DtPelicula dp = peliculaSeleccionada->getDatosPelicula();
	return dp;
}

bool ControladorPelicula::usuarioPuntuoPelicula(){
	ControladorUsuario* cu = ControladorUsuario::getInstancia();	
	bool yaPuntuo=false;
	Puntaje* p = NULL;
	list<Puntaje*> lp = peliculaSeleccionada->getlistaPuntaje();
	for (std::list<Puntaje*>::iterator it=lp.begin(); it != lp.end(); ++it){
		p = *it;
		if(cu->getUsuarioLogueado()->getNickname()==p->getUsuario()->getNickname()){
			yaPuntuo=true;
			break;
		}		
	}
	return yaPuntuo;
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
