#ifndef ControladorCineFuncion_H
#define ControladorCineFuncion_H
#include "Cine.h"
#include "Sala.h"
#include "IControladorCineFuncion.h"
#include <list>
#include "ControladorUsuario.h"
#include "DtSala.h"

using namespace std;

class  ControladorCineFuncion: public IControladorCineFuncion{
	private:
		static ControladorCineFuncion* instancia;
		list<Cine*> listaCines;
		int idCine;
		ControladorCineFuncion();
	public:
		static ControladorCineFuncion* getInstancia();
		void agregarCine(DtDireccion,list<DtSala>);
		~ControladorCineFuncion();
};

#endif
