#include "ControladorCineFuncion.h"
#include "ControladorPelicula.h"
#include <iostream>

ControladorCineFuncion* ControladorCineFuncion::instancia = NULL;

ControladorCineFuncion::ControladorCineFuncion(){
	this->idCine = 0;
	this->idFuncion = 0;
	listaCine.clear();
	listaFuncion.clear();
}

ControladorCineFuncion* ControladorCineFuncion::getInstancia(){
	if (instancia == NULL)
		instancia = new ControladorCineFuncion();
	return instancia;
}

void ControladorCineFuncion::agregarCine(DtCine dtCine, list<DtSala> listaDtSala){
	IControladorUsuario* c = ControladorUsuario::getInstancia();
	if(c->usuarioLogueadoEsAdmin()){
		idCine++;
		int idSala=0;
		Cine* nuevoCine = new Cine(idCine, dtCine.getDireccion());
		for (std::list<DtSala>::iterator it=listaDtSala.begin(); it != listaDtSala.end(); ++it){
			idSala++;
			DtSala ds= *it;
			Sala* s = new Sala(idSala, ds.getCapacidad(), nuevoCine);
			nuevoCine->agregarSala(s);	
		}
		listaCine.push_back(nuevoCine);
	}
	else
		cout << "No es admin" << endl; 
}

void ControladorCineFuncion::agregarFuncion(DtFuncion dtFuncion){
	idFuncion++;
	ControladorPelicula* c = ControladorPelicula::getInstancia();
	Funcion* nuevaFuncion = new Funcion(idFuncion,dtFuncion.getFecha(),dtFuncion.getHorario(),salaSeleccionada,c->getpeliculaSeleccionada());	
	listaFuncion.push_back(nuevaFuncion);
}

void ControladorCineFuncion::SeleccionarCine(DtCine dtCine){
	for (std::list<Cine*>::iterator it=listaCine.begin(); it != listaCine.end(); ++it){
		Cine* c = *it;
		if(c->getId()==dtCine.getId()){
 			cineSeleccionado = c;
			break;	    
 		}
	}	
}
void ControladorCineFuncion::SeleccionarSala(DtSala dtSala){
	
	/*for (std::list<Cine*>::iterator it=listaCine.begin(); it != listaCine.end(); ++it){
		Cine* c = *it;
		if(c->getId()==cineSeleccionado->getId()){*/
	for (std::list<Sala*>::iterator it=cineSeleccionado->getlistaSala().begin(); it != cineSeleccionado->getlistaSala().end(); ++it){
		Sala* s = *it;
		if(s->getId()==dtSala.getId()){
			salaSeleccionada = s;
			break;	    
		} 			
	}	
		
}
	 	
list<DtCine> ControladorCineFuncion::listarCine(){
	list<DtCine> listaDtCine;
	for (std::list<Cine*>::iterator it=listaCine.begin(); it != listaCine.end(); ++it){
		Cine* c = *it;
		listaDtCine.push_back(DtCine(c->getId(),c->getDireccion()));
	}
	return listaDtCine;
}

list<DtSala> ControladorCineFuncion::listarSala(DtCine dtCine){
	for (std::list<Cine*>::iterator it=listaCine.begin(); it != listaCine.end(); ++it){
		Cine* c = *it;
		if (c->getId() == dtCine.getId() ){
			list<Sala*> listaSala = c->getlistaSala();
			list<DtSala> listaDtSala;
			for (std::list<Sala*>::iterator it=listaSala.begin(); it != listaSala.end(); ++it){
				Sala* c = *it;
				listaDtSala.push_back(DtSala(c));
			}		
			return listaDtSala;
		}
	}
}
		

ControladorCineFuncion::~ControladorCineFuncion(){}
