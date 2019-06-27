#include "Debito.h"

Debito::Debito () {
	this->banco=" ";
}

Debito::Debito (string banco):Reserva(id, costo, cantEntradas, funcion, usuario) {
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

