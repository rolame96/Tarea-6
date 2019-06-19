#include "Cine.h"

Cine::Cine () {
	this->id=0;
	this->direccion=DtDireccion();
}

Cine::Cine (int id,DtDireccion direccion) {
	this->id = id;
	this->direccion = direccion;
}

int Cine::getId(){ 
	return this->id;
}

DtDireccion Cine::getDireccion(){
	return this->direccion;
}

DtCine Cine::getDatosCine(){
	DtCine dc = DtCine(this->id,this->direccion);
	return dc;
}

void Cine::agregarSala(Sala* sala){
	this->listaSala.push_back(sala);
}

ostream& operator <<(ostream& salida, const Cine& cine) {
	cout << cine.id << " - " << cine.direccion << "\n";
	return salida;
}

Cine::~Cine(){}

