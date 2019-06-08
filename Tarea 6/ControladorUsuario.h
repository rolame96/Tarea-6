#ifndef ControladorUsuario_H
#define ControladorUsuario_H
#include "Usuario.h"
#include "IControladorUsuario.h"
#include <list>

using namespace std;

class  ControladorUsuario: public IControladorUsuario{
	private:
		static ControladorUsuario* instancia;
		list<Usuario*> listaUsuarios;
		Usuario* usuarioLogueado;
		ControladorUsuario();
	public:
		static ControladorUsuario* getInstancia();
		void agregarUsuario(string, string, string, bool);
		bool iniciarSesion(string, string);
		bool usuarioLogueadoEsAdmin();		
		~ControladorUsuario();
};

#endif

