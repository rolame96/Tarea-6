#ifndef Cine_H
#define Cine_H
#include "DtDireccion.h"
#include "DtCine.h"
#include "Sala.h"
#include <list>

using namespace std;

class DtCine;
class Sala;

class Cine{
	private:
		int id;
		DtDireccion direccion;
		list<Sala*> listaSala;
	public:
		Cine();
		Cine(int, DtDireccion);
		int getId();
		DtDireccion getDireccion();
		DtCine getDatosCine();
		void agregarSala(Sala*);
		friend ostream& operator << (ostream&, const Cine&);
		~Cine();

};

#endif
