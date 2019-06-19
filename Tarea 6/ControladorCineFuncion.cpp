#include "ControladorCineFuncion.h"
#include <iostream>

ControladorCineFuncion* ControladorCineFuncion::instancia = NULL;

ControladorCineFuncion::ControladorCineFuncion(){
	this->idCine = 0;
	listaCines.clear();
}

ControladorCineFuncion* ControladorCineFuncion::getInstancia(){
	if (instancia == NULL)
		instancia = new ControladorCineFuncion();
	return instancia;
}

void ControladorCineFuncion::agregarCine(DtDireccion direccion, list<DtSala> listaDtSala){
	IControladorUsuario* c = ControladorUsuario::getInstancia();
	if(c->usuarioLogueadoEsAdmin()){
		idCine++;
		int idSala=0;
		Cine* nuevoCine = new Cine(idCine, direccion);
		for (std::list<DtSala>::iterator it=listaDtSala.begin(); it != listaDtSala.end(); ++it){
			idSala++;
			DtSala ds= *it;
			Sala* s = new Sala(idSala, ds.getCapacidad(), nuevoCine);
			nuevoCine->agregarSala(s);	
		}
		listaCines.push_back(nuevoCine);
	}
	else
		cout << "No es admin" << endl; 
}

ControladorCineFuncion::~ControladorCineFuncion(){}
