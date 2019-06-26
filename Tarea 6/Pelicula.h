#ifndef Pelicula_H
#define Pelicula_H
#include "Puntaje.h"
#include "DtPelicula.h"
#include <list>
#include "Comentario.h"
#include <string>

using namespace std;

//class Sala;

class Pelicula{
	private:
		string titulo;
		string sinopsis;
		list<Puntaje*> listaPuntaje;
		list<Comentario*> listaComentario;
		string poster;
	public:
		Pelicula();
		Pelicula(string, string, string);
		string getTitulo();
		string getSinopsis();
		string getPoster();
		list<Puntaje*> getlistaPuntaje();
		float getPuntajePelicula();
		void agregarPuntaje(Puntaje*);
		void agregarComentario(Comentario*);	
		DtPelicula getDatosPelicula();	
		~Pelicula();
};

#endif
