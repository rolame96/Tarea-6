#ifndef DtDebito_H
#define DtDebito_H
#include <cstdlib>
#include <iostream>
#include "DtReserva.h"

using namespace std;

class DtDebito:public DtReserva{

private : 
	string banco
public :
	Debito();
	Debito(string);
	string getBanco();
	void setBanco();
	float obtenerPrecioTotal();
	~Debito();
};
#endif
