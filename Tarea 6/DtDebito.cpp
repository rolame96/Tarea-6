#include "DtDebito.h"

DtDebito::DtDebito () {
	this->banco=" ";
}

DtDebito::DtDebito (string banco) {
	this->banco = banco;
}

string DtDebito::getBanco(){
	return this->banco;
}

float DtDebito::obtenerPrecioTotal{	
	return this->precioTotal;
}

Debito::~Debito(){}
