#ifndef Sala_H
#define Sala_H
#include "Cine.h"
#include "DtSala.h"

class DtSala;
class Cine;

using namespace std;

class Sala{
	private:
		int id;
		int capacidad;
		Cine* cine;
	public:
		Sala();
		Sala(int, int, Cine*);
		int getId();
		int getCapacidad();
		DtSala getDatosSala();
		Cine* getCine();
		~Sala();
};

#endif
