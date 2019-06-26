#ifndef ControladorPelicula_H
#define ControladorPelicula_H
#include "Pelicula.h"
#include "DtPelicula.h"
#include "IControladorPelicula.h"
#include <list>
#include "DtPuntaje.h"
#include "IControladorUsuario.h"
#include "Puntaje.h"
#include "ControladorUsuario.h"

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
		DtPuntaje mostrarPuntaje();
		void agregarPuntaje(DtPuntaje);
		bool usuarioPuntuoPelicula();
		Pelicula* getpeliculaSeleccionada();
		void seleccionarPelicula(DtPelicula);
		~ControladorPelicula();
};

#endif
