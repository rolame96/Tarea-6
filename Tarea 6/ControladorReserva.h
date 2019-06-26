#ifndef ControladorReserva_H
#define ControladorReserva_H
#include <list>
#include "Reserva.h"
#include "DtReserva.h"
#include "IControladorReserva.h"

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
		float mostrarCosto();
		string ingresarBanco(string);
		string ingresarFinanciera(string);
		~ControladorReserva();
};

#endif
