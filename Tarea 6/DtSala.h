#ifndef DtSala_H
#define DtSala_H
#include <cstdlib>
#include <iostream>
#include "Sala.h"

using namespace std;

class Sala;

class DtSala{

private : 
	int id;
    int capacidad;

public :
	DtSala();
	DtSala(int ,int);
	DtSala(Sala*);
	int getId();
	int getCapacidad();
	friend ostream& operator << (ostream&, const DtSala&);
	~DtSala();

};
#endif
