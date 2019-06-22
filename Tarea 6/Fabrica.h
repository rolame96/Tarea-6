#ifndef Fabrica_H
#define Fabrica_H
#include "IControladorUsuario.h"
#include "ControladorUsuario.h"
#include "ControladorCineFuncion.h"
#include "IControladorCineFuncion.h"
#include "IControladorPelicula.h"
#include "ControladorPelicula.h"


class Fabrica{
	private:
		static Fabrica* instancia;
		Fabrica();
	public:
		static Fabrica* getInstancia();
		IControladorUsuario* getIControladorUsuario();
		IControladorCineFuncion* getIControladorCineFuncion();
		IControladorPelicula* getIControladorPelicula();
		~Fabrica();
};

#endif

