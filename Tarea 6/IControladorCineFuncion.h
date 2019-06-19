#ifndef IControladorCineFuncion_H
#define IControladorCineFuncion_H
#include "DtSala.h"
#include <string>
using namespace std;

class IControladorCineFuncion{
	public:
		virtual void agregarCine(DtDireccion,list<DtSala>)=0;
		virtual ~IControladorCineFuncion(){};
};

#endif

