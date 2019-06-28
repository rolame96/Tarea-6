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

IControladorReserva* Fabrica::getIControladorReserva(){
	IControladorReserva* c = ControladorReserva::getInstancia();
	return c;
}

IControladorCineFuncion* Fabrica::getIControladorCineFuncion(){
	IControladorCineFuncion* c = ControladorCineFuncion::getInstancia();
	return c;
}

IControladorPelicula* Fabrica::getIControladorPelicula(){
	IControladorPelicula* c = ControladorPelicula::getInstancia();
	return c;
}

IControladorReloj* Fabrica::getIControladorReloj(){
	IControladorReloj* c = Reloj::getInstancia();
	return c;
}

Fabrica::~Fabrica(){}
