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
		void setPuntos(int);
		Usuario* getUsuario();
		void setUsuario(Usuario*);
		~Puntaje();
};

#endif
