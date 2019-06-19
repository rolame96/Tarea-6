#include "Fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
	if (instancia == NULL)
		instancia = new Fabrica();
	return instancia;
}

IControladorUsuario* Fabrica::getIControladorUsuario(){
	IControladorUsuario* c = ControladorUsuario::getInstancia();
	return c;
}

IControladorCineFuncion* Fabrica::getIControladorCineFuncion(){
	IControladorCineFuncion* c = ControladorCineFuncion::getInstancia();
	return c;
}

Fabrica::~Fabrica(){}
