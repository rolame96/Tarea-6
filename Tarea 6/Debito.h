#ifndef Debito_H
#define Debito_H
#include "Reserva.h"

using namespace std;


class Debito: public Reserva{
	private:
		string banco;
	public:
		Debito();
		Debito(string);
		string getBanco();
		void setBanco();
		float obtenerPrecioTotal();
		~Debito();
};

#endif
