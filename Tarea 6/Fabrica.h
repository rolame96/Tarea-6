#ifndef Fabrica_H
#define Fabrica_H
#include "IControladorUsuario.h"
#include "ControladorUsuario.h"


class Fabrica{
	private:
		static Fabrica* instancia;
		Fabrica();
	public:
		static Fabrica* getInstancia();
		IControladorUsuario* getIControladorUsuario();
		~Fabrica();
};

#endif

