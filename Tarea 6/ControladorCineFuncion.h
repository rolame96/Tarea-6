#ifndef ControladorCineFuncion_H
#define ControladorCineFuncion_H
#include "Cine.h"
#include "Sala.h"
#include "IControladorCineFuncion.h"
#include <list>
#include "ControladorUsuario.h"
#include "DtSala.h"
#include "DtFuncion.h"
#include "Funcion.h"

using namespace std;

class  ControladorCineFuncion: public IControladorCineFuncion{
	private:
		static ControladorCineFuncion* instancia;
		list<Cine*> listaCine;
		list<Funcion*> listaFuncion;
		int idCine;
		int idFuncion;
		Cine* cineSeleccionado;
		Sala* salaSeleccionada;
		ControladorCineFuncion();
	public:
		static ControladorCineFuncion* getInstancia();
		void agregarCine(DtCine,list<DtSala>);
		void agregarFuncion(DtFuncion);
		void SeleccionarCine(DtCine);
	 	void SeleccionarSala(DtSala);
		list<DtCine> listarCine();
		list<DtSala> listarSala(DtCine);
		~ControladorCineFuncion();
};

#endif
