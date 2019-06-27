#ifndef ControladorReserva_H
#define ControladorReserva_H
#include <list>
#include "Reserva.h"
#include "DtReserva.h"
#include "DtCredito.h"
#include "DtDebito.h"
#include "Credito.h"
#include "Debito.h"
#include "IControladorReserva.h"
#include "ControladorCineFuncion.h"
#include "ControladorUsuario.h"
#include <stdexcept>
#include <typeinfo>

using namespace std;

class  ControladorReserva: public IControladorReserva{
	private:
		static ControladorReserva* instancia;
		list<Reserva*> listaReserva;
		Reserva* nuevaReserva;
		int idReserva;
		ControladorReserva();
	public:
		static ControladorReserva* getInstancia();
		void confirmarReserva();
		void crearReserva(DtReserva);
		void cancelarReserva();
		float mostrarCostoNuevaReserva();
		~ControladorReserva();
};

#endif
