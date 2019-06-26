#include "DtDebito.h"

DtDebito::DtDebito () {
	this->banco=" ";
	this->precioTotal=0;
}

DtDebito::DtDebito (string banco,float precioTotal) {
	this->banco = banco;
	this->precioTotal = precioTotal;
}

string DtDebito::getBanco(){
	return this->banco;
}

float DtDebito::obtenerPrecioTotal(){	
	return this->precioTotal;
}

DtDebito::~DtDebito(){}
