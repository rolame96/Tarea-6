#ifndef Comentario_H
#define Comentario_H
#include "Usuario.h"
#include <list>

using namespace std;

//class Sala;

class Comentario{
	private:
		string texto;
		Usuario* usuario;
		list<Comentario*>listaComentarios; 
	public:
		Comentario();
		Comentario(string, Usuario*);
		string getTexto();
		void setTexto(string);
		Usuario* getUsuario();
		void setUsuario(Usuario*);
		void agregarComentario(Comentario*);
		~Comentario();
};

#endif
