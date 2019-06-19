#ifndef DtDireccion_H
#define DtDireccion_H

#include <cstdlib>
#include <iostream>


using namespace std;

class DtDireccion{

private : 
	string calle;
    int numero;

public :
	DtDireccion();
	DtDireccion(string ,int);
	string getCalle();
	int getNumero();
	friend ostream& operator << (ostream&, const DtDireccion&);
	~DtDireccion();

};
#endif

