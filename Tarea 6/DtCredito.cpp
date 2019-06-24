#include "DtCredito.h"

DtCredito::DtCredito () {
	this->porcentajeDescuento=0;
	this->financiera=" ";
}

DtCredito::DtCredito (float porcentajeDescuento,string financiera) {
	this->porcentajeDescuento = porcentajeDescuento;
	this->financiera = financiera;
}

float DtCredito::getPorcentajeDescuento(){ 
	return this->porcentajeDescuento;
}

string DtCredito::getFinanciera(){
	return this->financiera;
}

float DtCredito::obtenerPrecioTotal{	
	return this->precioTotal;
}

DtCredito::~DtCredito(){}

