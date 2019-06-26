#include "ControladorReserva.h"


ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::ControladorReserva(){
	this->idReserva= 0;
	this->listaReserva.clear();
}

ControladorReserva* ControladorReserva::getInstancia(){
	if (instancia == NULL)
		instancia = new ControladorReserva();
	return instancia;
}

void ControladorReserva::confirmarReserva(){
	listaReserva.push_back(this->nuevaReserva);
}

void ControladorReserva::crearReserva(DtReserva dtReserva){
	/*
	idReserva++;
	try{
		DtCredito dtCredito = dynamic_cast<const DtCredito&>(dtReserva);				
		nuevaReserva = new Credito(idReserva, 100, DtCredito.getCantEntradas(), DtCredito.);											
		//cout << "-------------------------- agrego GATO en registrar socio " << mascota->getNombre()  <<"\n";	
		}catch(std::bad_cast){
			try{
			
				//DtPerro dtPerro = dynamic_cast<DtPerro&>(dtMascota);
				DtPerro dtPerro = dynamic_cast<const DtPerro&>(dtMascota);
				mascota = new Perro(dtPerro.getNombre(),dtPerro.getgenero(),dtPerro.getPeso(),dtPerro.getRazaPerro(),dtPerro.getVacunaCachorro());
				//cout << "-------------------------- agrego perro en registrar socio " << mascota->getNombre()  <<"\n";	
		  	}catch(std::bad_cast){
	        	cout << "Error al registrar socio.\n";
	      }
	}
	*/
}

void ControladorReserva::cancelarReserva(){
	delete this->nuevaReserva;
}

float ControladorReserva::mostrarCosto(){
	return 1;
}

ControladorReserva::~ControladorReserva(){}
