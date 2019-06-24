#ifndef Reserva_H
#define Reserva_H
#include "Funcion.h"
#include "Usuario.h"

using namespace std;


class Reserva{
	protected:
		int id;
		float costo;
		int cantEntradas;
		Funcion* funcion;
		Usuario* usuario;
	public:
		Reserva();
		Reserva(float, int, Funcion*, Usuario*);
		int getId();
		void setId();
		float getCosto();
		void setCosto();
		int getCantEntradas();
		void setCantEntradas();
		Funcion* getFuncion();
		void setFuncion();
		Usuario* getUsuario();
		void setUsuario();
		virtual float obtenerPrecioTotal() = 0;
		virtual ~Reserva();
};

#endif
