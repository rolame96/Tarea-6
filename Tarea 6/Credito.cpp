#include "Credito.h"

Credito::Credito () {
	this->porcentajeDescuento=0;
	this->financiera=" ";
}

Credito::Credito (int id,float costo,int cantEntradas,Funcion* funcion,Usuario* usuario,float porcentajeDescuento,string financiera) :Reserva(id, costo, cantEntradas, funcion, usuario) {
	this->porcentajeDescuento = porcentajeDescuento;
	this->financiera = financiera;
}

float Credito::getPorcentajeDescuento(){ 
	return this->porcentajeDescuento;
}

void Credito::setPorcentajeDescuento(float porcentajeDescuento){ 
	this->porcentajeDescuento=porcentajeDescuento;
}

string Credito::getFinanciera(){
	return this->financiera;
}

void Credito::setFinanciera(string financiera){ 
	this->financiera=financiera;
}

float Credito::obtenerPrecioTotal(){	
	float resultado = this->costo*this->cantEntradas *  ( 1 - this->porcentajeDescuento/100);
	return resultado;
}

Credito::~Credito(){}

