#ifndef DtFuncion_H
#define DtFuncion_H
#include <cstdlib>
#include <iostream>
#include "DtFecha.h"
#include "DtHorario.h"

using namespace std;

class DtFuncion{

private : 
	int id;
	DtFecha fecha;
	DtHorario horario;
public :
	DtFuncion();
	DtFuncion(int, DtFecha, DtHorario);
	int getId();
	DtFecha getFecha();
	DtHorario getHorario();
	friend ostream& operator << (ostream&, const DtFuncion&);
	~DtFuncion();
};

#endif
