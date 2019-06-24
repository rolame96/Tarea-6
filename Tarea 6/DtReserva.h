#ifndef DtReserva_H
#define DtReserva_H
#include <cstdlib>
#include <iostream>
#include "Reserva.h"

using namespace std;

class DtReserva{

protected : 
	int id;
	float costo;
	int cantEntradas;
	float precioTotal;
public :
	DtReserva();
	DtReserva(int, float , int);
	int getId();
	void setId();
	float getCosto();
	void setCosto();
	int getCantEntradas();
	void setCantEntradas();
	virtual float obtenerPrecioTotal() = 0;
	friend ostream& operator << (ostream&, const DtReserva&);
	virtual ~DtReserva();

};
#endif
