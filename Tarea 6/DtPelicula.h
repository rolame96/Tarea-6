#ifndef DtPelicula_H
#define DtPelicula_H
#include <cstdlib>
#include <iostream>

using namespace std;

class DtPelicula{

private : 
	string titulo, sinopsis, poster;
	float puntajePromedio;
public :
	DtPelicula();
	DtPelicula(string, string, string, float);
	string getTitulo();
	string getSinopsis();
	string getPoster();
	float getPuntajePromedio();
	friend ostream& operator << (ostream&, const DtPelicula&);
	~DtPelicula();
};

#endif
