#ifndef Credito_H
#define Credito_H
#include "Reserva.h"

using namespace std;


class Credito:public Reserva{
	private:
		float porcentajeDescuento;
		string financiera;
	public:
		Credito();
		Credito(float, string);
		float getPorcentajeDescuento();
		void setPorcentajeDescuento(float);
		string getFinanciera();
		void setFinanciera(string);
		float obtenerPrecioTotal();
		~Credito();
};

#endif
