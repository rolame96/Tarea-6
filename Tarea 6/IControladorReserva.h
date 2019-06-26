#ifndef IControladorReserva_H
#define IControladorReserva_H
#include <string>
#include "Reserva.h"
#include "DtReserva.h"

using namespace std;

class IControladorReserva{
	public:
		virtual void confirmarReserva()=0;
		virtual void crearReserva(DtReserva)=0;
		virtual void cancelarReserva()=0;
		virtual float mostrarCosto()=0;
		virtual string ingresarBanco(string)=0;
		virtual string ingresarFinanciera(string)=0;		
		virtual ~IControladorReserva(){};
};

#endif

