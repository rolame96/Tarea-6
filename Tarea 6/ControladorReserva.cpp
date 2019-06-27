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
	
	ControladorUsuario* cu = ControladorUsuario::getInstancia();
	ControladorCineFuncion* ccf = ControladorCineFuncion::getInstancia();	
	try{
		DtCredito dtCredito = dynamic_cast<const DtCredito&>(dtReserva);
		idReserva++;
		//int id, float costo,int cantEntradas, Funcion* funcion, Usuario* usuario
		nuevaReserva = new Credito(idReserva, 100, dtCredito.getCantEntradas(), ccf->getFuncionSeleccionada(), cu->getUsuarioLogueado(), dtCredito.getPorcentajeDescuento(), dtCredito.getFinanciera());											
		}catch(std::bad_cast){
			try{
				DtDebito dtDebito = dynamic_cast<const DtDebito&>(dtReserva);
				idReserva++;
				nuevaReserva = new Debito(idReserva, 100, dtDebito.getCantEntradas(), ccf->getFuncionSeleccionada(), cu->getUsuarioLogueado(), dtDebito.getBanco());
		  	}catch(std::bad_cast){
	        	cout << "Error al crear reserva.\n";
	    }
	}
	
}

void ControladorReserva::cancelarReserva(){
	delete this->nuevaReserva;
}

float ControladorReserva::mostrarCosto(){
	return nuevaReserva->obtenerPrecioTotal();
}


void ControladorReserva::confirmarReserva(){
	listaReserva->push_back(nuevaReserva);
}

ControladorReserva::~ControladorReserva(){}
