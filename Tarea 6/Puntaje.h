#ifndef Puntaje_H
#define Puntaje_H
#include "Usuario.h"

using namespace std;

//class Sala;

class Puntaje{
	private:
		int puntos;
		Usuario* usuario;
	public:
		Puntaje();
		Puntaje(int, Usuario*);
		int getPuntos();
		void setPuntos();
		Usuario* getUsuario();
		void setUsuario();
		~Puntaje();
};

#endif
