#ifndef DtCredito_H
#define DtCredito_H
#include "DtReserva.h"

using namespace std;


class DtCredito: public DtReserva{
	private:
		float porcentajeDescuento;
		string financiera;
		float precioTotal;
	public:
		DtCredito();
		DtCredito(float, string, float);
		float getPorcentajeDescuento();
		string getFinanciera();
		float obtenerPrecioTotal();
		~DtCredito();
};

#endif
