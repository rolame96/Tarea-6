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
		Funcion* funcionSeleccionada;
		Cine* cineSeleccionado;
		Sala* salaSeleccionada;
		ControladorCineFuncion();
	public:
		static ControladorCineFuncion* getInstancia();
		void agregarCine(DtCine,list<DtSala>);
		void agregarFuncion(DtFuncion);
		void SeleccionarFuncion(DtFuncion);
		void SeleccionarCine(DtCine);
	 	void SeleccionarSala(DtSala);
	 	bool yaEstaCineListaDtCine(Cine*,list<DtCine>);
	 	list<DtCine> listarCinePeliculaSeleccionada();
		list<DtCine> listarCine();
		list<DtSala> listarSala(DtCine);
		list<DtFuncion> listarFuncionCineSeleccionadoPeliculaSeleccionada();
		~ControladorCineFuncion();
};

#endif
