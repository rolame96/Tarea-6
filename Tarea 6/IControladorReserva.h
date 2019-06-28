#ifndef IControladorReserva_H
#define IControladorReserva_H
#include <string>
#include "Reserva.h"
#include "DtReserva.h"

using namespace std;

class IControladorReserva{
	public:
		virtual void confirmarReserva()=0;
		virtual void crearReserva(const DtReserva&)=0;
		virtual void cancelarReserva()=0;
		virtual float mostrarCostoNuevaReserva()=0;
		virtual ~IControladorReserva(){};
};

#endif

