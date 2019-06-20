#ifndef IControladorPelicula_H
#define IControladorPelicula_H
#include <string>
using namespace std;

class IControladorPelicula{
	public:

		virtual void agregarPelicula(DtPelicula)=0;
		virtual list<DtPelicula> listarPelicula()=0;
		virtual void seleccionarPelicula(DtPelicula)=0;
		virtual ~IControladorPelicula(){};
};

#endif

