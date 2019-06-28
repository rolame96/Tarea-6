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
	cout << "Reserva confirmada"<<endl;
}

void ControladorReserva::crearReserva(const DtReserva& dtReserva){
	
	ControladorUsuario* cu = ControladorUsuario::getInstancia();
	ControladorCineFuncion* ccf = ControladorCineFuncion::getInstancia();
	float costoEntrada = 100;
	try{
		DtCredito dtCredito = dynamic_cast<const DtCredito&>(dtReserva);
		idReserva++;
		//parametro constructor de Reserva ---- int id, float costo,int cantEntradas, Funcion* funcion, Usuario* usuario
		nuevaReserva = new Credito(idReserva,costoEntrada,dtCredito.getCantEntradas(),ccf->getFuncionSeleccionada(),cu->getUsuarioLogueado(),dtCredito.getPorcentajeDescuento(),dtCredito.getFinanciera());
		//revisar porque no anda todo junto en el constructor de Credito
		/*nuevaReserva->setId(idReserva);
		nuevaReserva->setCosto(costoEntrada);
		nuevaReserva->setCantEntradas(dtCredito.getCantEntradas());
		nuevaReserva->setFuncion(ccf->getFuncionSeleccionada());
		nuevaReserva->setUsuario(cu->getUsuarioLogueado());		*/							
		}catch(std::bad_cast){
			try{
				DtDebito dtDebito = dynamic_cast<const DtDebito&>(dtReserva);
				idReserva++;
				nuevaReserva = new Debito(idReserva,costoEntrada,dtDebito.getCantEntradas(),ccf->getFuncionSeleccionada(),cu->getUsuarioLogueado(),dtDebito.getBanco());
				/*nuevaReserva->setId(idReserva);
				nuevaReserva->setCosto(costoEntrada);
				nuevaReserva->setCantEntradas(dtDebito.getCantEntradas());
				nuevaReserva->setFuncion(ccf->getFuncionSeleccionada());
				nuevaReserva->setUsuario(cu->getUsuarioLogueado());	*/			
		  	}catch(std::bad_cast){
	        	cout << "Error al crear reserva.\n";
	    }
	}
	
}

void ControladorReserva::cancelarReserva(){
	delete this->nuevaReserva;
}

float ControladorReserva::mostrarCostoNuevaReserva(){
	Credito* credito = dynamic_cast<Credito*>(nuevaReserva);
	if (credito != NULL){
		return credito->obtenerPrecioTotal();			
	}else{
		Debito* debito = dynamic_cast<Debito*>(nuevaReserva);	
		return debito->obtenerPrecioTotal();				
	}
	//return nuevaReserva->obtenerPrecioTotal();
}

ControladorReserva::~ControladorReserva(){}
