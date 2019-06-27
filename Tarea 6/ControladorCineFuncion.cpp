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
	ControladorUsuario* c = ControladorUsuario::getInstancia();
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

void ControladorCineFuncion::SeleccionarFuncion(DtFuncion dtFuncion){
	for (std::list<Funcion*>::iterator it=listaFuncion.begin(); it != listaFuncion.end(); ++it){
		Funcion* f = *it;
		if(f->getId()==dtFuncion.getId()){
 			funcionSeleccionada = f;
			break;	    
 		}
	}		
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
	list<Sala*> ls = cineSeleccionado->getlistaSala();
	for (std::list<Sala*>::iterator it=ls.begin(); it != ls.end(); ++it){
		Sala* s = *it;
		if(s->getId()==dtSala.getId()){
			salaSeleccionada = s;
			break;	    
		} 			
	}	
		
}

list<DtFuncion> ControladorCineFuncion::listarFuncionCineSeleccionadoPeliculaSeleccionada(){
	ControladorPelicula* c = ControladorPelicula::getInstancia();
	list<DtFuncion> listaDtFuncion;
	listaDtFuncion.clear();
	for (std::list<Funcion*>::iterator it=listaFuncion.begin(); it != listaFuncion.end(); ++it){
		Funcion* f = *it;
		if(f->getPelicula()->getTitulo()==c->getpeliculaSeleccionada()->getTitulo()){
			Sala* sala = f->getSala();
			Cine* cine = sala->getCine();
			if(cine->getId()==cineSeleccionado->getId()){
				DtFecha dtfaux = DtFecha(26,6,2019);
				if(dtfaux<=f->getFecha())
					listaDtFuncion.push_back(DtFuncion(f->getId(),f->getFecha(),f->getHorario()));
			}
		}
	}
	return listaDtFuncion;
}

list<DtCine> ControladorCineFuncion::listarCinePeliculaSeleccionada(){
	ControladorPelicula* c = ControladorPelicula::getInstancia();
	list<DtCine> listaDtCine;
	listaDtCine.clear();
	for (std::list<Funcion*>::iterator it=listaFuncion.begin(); it != listaFuncion.end(); ++it){
		Funcion* f = *it;
		if(f->getPelicula()->getTitulo()==c->getpeliculaSeleccionada()->getTitulo()){
			Sala* sala = f->getSala();
			Cine* cine = sala->getCine();		
			if(yaEstaCineListaDtCine(cine,listaDtCine)==false)
				listaDtCine.push_back(DtCine(cine->getId(),cine->getDireccion()));
 		}
	}
	return listaDtCine;
}

bool ControladorCineFuncion::yaEstaCineListaDtCine(Cine* cine, list<DtCine> listaDtCine){
	bool yaEsta = false;
	DtCine dc;
	for (std::list<DtCine>::iterator it=listaDtCine.begin(); it != listaDtCine.end(); ++it){
		dc = *it;
		if(dc.getId()==cine->getId()){
			yaEsta=true;
			break;
		}
	}
	return yaEsta;
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

Funcion* ControladorCineFuncion::getFuncionSeleccionada(){
	return funcionSeleccionada;
}


ControladorCineFuncion::~ControladorCineFuncion(){}
