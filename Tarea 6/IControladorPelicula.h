#ifndef IControladorPelicula_H
#define IControladorPelicula_H
#include "DtPelicula.h"
#include "DtPuntaje.h"

using namespace std;

class IControladorPelicula{
	public:

		virtual void agregarPelicula(DtPelicula)=0;
		virtual list<DtPelicula> listarPelicula()=0;
		virtual bool usuarioPuntuoPelicula()=0;
		virtual DtPuntaje mostrarPuntaje()=0;
		virtual Pelicula* getpeliculaSeleccionada()=0;
		virtual DtPelicula getDatosPeliculaSeleccionada()=0;
		virtual void agregarPuntaje(DtPuntaje)=0;
		virtual void seleccionarPelicula(DtPelicula)=0;
		virtual ~IControladorPelicula(){};
};

#endif

