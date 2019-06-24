#include "Debito.h"

Debito::Debito () {
	this->banco=" ";
}

Debito::Debito (string banco): Reserva(id, cost, cantEntrada, funcion, usuario) {
	this->banco = banco;
}

string Debito::getBanco(){
	return this->banco;
}

void Debito::setBanco(){ 
	this->banco=banco;
}

float Debito::obtenerPrecioTotal{	
	return this->costo*this->cantEntradas;
}

Debito::~Debito(){}

