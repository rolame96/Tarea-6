#ifndef Debito_H
#define Debito_H
#include "Reserva.h"

using namespace std;


class Debito: public Reserva{
	private:
		string banco;
	public:
		Debito();
		Debito(int ,float ,int ,Funcion* ,Usuario* ,string);
		string getBanco();
		void setBanco(string);
		float obtenerPrecioTotal();
		~Debito();
};

#endif
