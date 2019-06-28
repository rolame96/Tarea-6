#ifndef Reloj_H
#define Reloj_H
#include "DtHorario.h"
#include "DtFecha.h"
#include "IControladorReloj.h"

using namespace std;


class Reloj: public IControladorReloj{
	private:
		static Reloj* instancia;
		DtFecha fecha;
		DtHorario horario;
		Reloj();
	public:
		static Reloj* getInstancia();
		DtFecha getFecha();
		DtHorario getHorario();
		void setFecha(DtFecha);
		void setHorario(DtHorario);
		void modificarFecha(DtFecha, DtHorario);
		void imprimirFecha();	
		~Reloj();
};

#endif
