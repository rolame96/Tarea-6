#ifndef Fabrica_H
#define Fabrica_H
#include "IControladorUsuario.h"
#include "ControladorUsuario.h"
#include "ControladorCineFuncion.h"
#include "IControladorCineFuncion.h"
#include "IControladorPelicula.h"
#include "ControladorPelicula.h"
#include "ControladorReserva.h"
#include "IControladorReserva.h"
#include "IControladorReloj.h"
#include "Reloj.h"

class Fabrica{
	private:
		static Fabrica* instancia;
		Fabrica();
	public:
		static Fabrica* getInstancia();
		IControladorUsuario* getIControladorUsuario();
		IControladorReserva* getIControladorReserva();
		IControladorCineFuncion* getIControladorCineFuncion();
		IControladorPelicula* getIControladorPelicula();
		IControladorReloj* getIControladorReloj();
		~Fabrica();
};

#endif

