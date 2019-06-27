#ifndef IControladorUsuario_H
#define IControladorUsuario_H
#include "Usuario.h"

using namespace std;

class IControladorUsuario{
	public:
		virtual void agregarUsuario(string, string, string, bool)=0;
		virtual bool iniciarSesion(string, string)=0;
		virtual void cerrarSesion()=0;
		virtual bool usuarioLogueadoEsAdmin()=0;		
		virtual ~IControladorUsuario(){};
};

#endif

