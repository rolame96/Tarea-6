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
public :
	DtReserva();
	DtReserva(int, float , int);
	int getId();
	float getCosto();
	int getCantEntradas();
	friend ostream& operator << (ostream&, const DtReserva&);
	virtual ~DtReserva();

};
#endif
