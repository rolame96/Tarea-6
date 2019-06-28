#include "Debito.h"

Debito::Debito () {
	this->banco=" ";
}

Debito::Debito (int id,float costo,int cantEntradas,Funcion* funcion,Usuario* usuario,string banco):Reserva(id, costo, cantEntradas, funcion, usuario) {
	this->banco = banco;
}

string Debito::getBanco(){
	return this->banco;
}

void Debito::setBanco(string banco){ 
	this->banco=banco;
}

float Debito::obtenerPrecioTotal(){	
	return this->costo*this->cantEntradas;
}

Debito::~Debito(){}

