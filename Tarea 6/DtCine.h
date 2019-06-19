#ifndef DtCine_H
#define DtCine_H

#include <cstdlib>
#include <iostream>
#include "Cine.h"
#include "DtDireccion.h"

using namespace std;

class DtCine{

private : 
	int id;
    DtDireccion direccion;

public :
	DtCine();
	DtCine(int ,DtDireccion);
	//DtCine(Cine*);
	int getId();
	DtDireccion getDireccion();
	friend ostream& operator << (ostream&, const DtCine&);
	~DtCine();

};
#endif
