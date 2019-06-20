#ifndef DtHorario_H
#define DtHorario_H
#include <cstdlib>
#include <iostream>

using namespace std;

class DtHorario{

private : 
	int hora;
	int minutos;
public :
	DtHorario();
	DtHorario(int, int);
	int getHora();
	int getMinutos();
	friend ostream& operator << (ostream&, const DtHorario&);
	~DtHorario();

};
#endif
