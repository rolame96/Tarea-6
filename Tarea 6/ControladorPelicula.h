#ifndef ControladorPelicula_H
#define ControladorPelicula_H
#include "Pelicula.h"
#include "DtPelicula.h"
#include "IControladorPelicula.h"
#include <list>


using namespace std;

class  ControladorPelicula: public IControladorPelicula{
	private:
		static ControladorPelicula* instancia;
		list<Pelicula*> listaPeliculas;
		Pelicula* peliculaSeleccionada;
		ControladorPelicula();
	public:
		static ControladorPelicula* getInstancia();
		void agregarPelicula(DtPelicula);
		list<DtPelicula> listarPelicula();
		void seleccionarPelicula(DtPelicula);
		~ControladorPelicula();
};

#endif
