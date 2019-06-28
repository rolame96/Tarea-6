#include "DtCredito.h"

DtCredito::DtCredito () {
	this->porcentajeDescuento=0;
	this->financiera=" ";
	this->precioTotal = 0;
}

DtCredito::DtCredito (int id,float costo,int cantEntradas,float porcentajeDescuento,string financiera, float precioTotal) : DtReserva(id,costo,cantEntradas){
	this->porcentajeDescuento = porcentajeDescuento;
	this->financiera = financiera;
	this->precioTotal = 0;
}

float DtCredito::getPorcentajeDescuento(){ 
	return this->porcentajeDescuento;
}

string DtCredito::getFinanciera(){
	return this->financiera;
}

float DtCredito::obtenerPrecioTotal(){	
	return this->precioTotal;
}

DtCredito::~DtCredito(){}

