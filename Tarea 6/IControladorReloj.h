#ifndef IControladorReloj_H
#define IControladorReloj_H

using namespace std;

class IControladorReloj{
	public:
		virtual void modificarFecha(DtFecha,DtHorario)=0;
		virtual void imprimirFecha()=0;		
		virtual ~IControladorReloj(){};
};

#endif

