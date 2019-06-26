#ifndef DtDebito_H
#define DtDebito_H
#include <cstdlib>
#include <iostream>
#include "DtReserva.h"

using namespace std;

class DtDebito:public DtReserva{

private : 
	string banco;
	float precioTotal;
public :
	DtDebito();
	DtDebito(string,float);
	string getBanco();
	float obtenerPrecioTotal();
	~DtDebito();
};
#endif
