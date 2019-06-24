#ifndef DtCredito_H
#define DtCredito_H
#include "DtReserva.h"

using namespace std;


class DtCredito: public DtReserva{
	private:
		float porcentajeDescuento;
		string financiera;
	public:
		DtCredito();
		DtCredito(float, string);
		float getPorcentajeDescuento();
		void setPorcentajeDescuento();
		string getFinanciera();
		void setFinanciera();
		float obtenerPrecioTotal();
		~DtCredito();
};

#endif
