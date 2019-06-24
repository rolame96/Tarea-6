#include "Credito.h"

Credito::Credito () {
	this->porcentajeDescuento=0;
	this->financiera=" ";
}

Credito::Credito (float porcentajeDescuento,string financiera): Reserva(id, costo, cantEntrada, funcion, usuario) {
	this->porcentajeDescuento = porcentajeDescuento;
	this->financiera = financiera;
}

float Credito::getPorcentajeDescuento(){ 
	return this->porcentajeDescuento;
}

void Credito::setPorcentajeDescuento(){ 
	this->porcentajeDescuento=porcentajeDescuento;
}

string Credito::getFinanciera(){
	return this->financiera;
}

void Credito::setFinanciera(){ 
	this->financiera=financiera;
}

float Credito::obtenerPrecioTotal{	
	return this->costo*this->cantEntradas *  ( 1 - this->porcentajeDescuento/100);
}

Credito::~Credito(){}

