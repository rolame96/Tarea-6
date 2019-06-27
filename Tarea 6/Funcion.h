#ifndef Funcion_H
#define Funcion_H
#include "DtHorario.h"
#include "DtFecha.h"
#include "Sala.h"
#include "Pelicula.h"
#include "DtFuncion.h"

using namespace std;

class Sala;

class Funcion{
	private:
		int id;
		DtFecha fecha;
		DtHorario horario;
		Sala* sala;
		Pelicula* pelicula;
	public:
		Funcion();
		Funcion(int, DtFecha, DtHorario, Sala*, Pelicula*);
		int getId();
		DtFecha getFecha();
		DtHorario getHorario();
		Sala* getSala();
		void setSala(Sala*);
		Pelicula* getPelicula();
		void setPelicula(Pelicula*);
		DtFuncion getDatosFuncion();
		~Funcion();
};

#endif
