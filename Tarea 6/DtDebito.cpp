#include "DtDebito.h"

DtDebito::DtDebito () {
	this->banco=" ";
	this->precioTotal=0;
}

DtDebito::DtDebito (int id,float costo,int cantEntradas,string banco,float precioTotal) : DtReserva(id,costo,cantEntradas){
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
