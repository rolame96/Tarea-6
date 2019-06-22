#ifndef IControladorCineFuncion_H
#define IControladorCineFuncion_H
#include "DtSala.h"
#include "DtFuncion.h"
#include <string>
using namespace std;

class IControladorCineFuncion{
	public:
		virtual void agregarCine(DtCine,list<DtSala>)=0;
		virtual void agregarFuncion(DtFuncion)=0;
		virtual void SeleccionarCine(DtCine)=0;
		virtual void SeleccionarSala(DtSala)=0;
		virtual list<DtCine> listarCine()=0;
		virtual list<DtSala> listarSala(DtCine)=0;
		virtual ~IControladorCineFuncion(){};
};

#endif

