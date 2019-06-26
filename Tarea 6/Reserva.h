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
		Reserva(int, float, int, Funcion*, Usuario*);
		int getId();
		void setId(int);
		float getCosto();
		void setCosto(float);
		int getCantEntradas();
		void setCantEntradas(int);
		Funcion* getFuncion();
		void setFuncion(Funcion*);
		Usuario* getUsuario();
		void setUsuario(Usuario*);
		virtual float obtenerPrecioTotal() = 0;
		virtual ~Reserva();
};

#endif
