#include "ControladorUsuario.h"


ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario* ControladorUsuario::getInstancia(){
	if (instancia == NULL)
		instancia = new ControladorUsuario();
	return instancia;
}

void ControladorUsuario::agregarUsuario(string nickname, string password, string urlFoto, bool admin){
	Usuario* nuevoUsuario = new Usuario(nickname, password, urlFoto, admin);
	listaUsuarios.push_back(nuevoUsuario);
}

bool ControladorUsuario::iniciarSesion(string nickname, string password){
	if(usuarioLogueado==NULL){
		for (std::list<Usuario*>::iterator it=listaUsuarios.begin(); it != listaUsuarios.end(); ++it){
			Usuario* u = dynamic_cast<Usuario*>(*it);
			if (u->getNickname() == nickname && u->getPassword() == password){
				return true;
			}	
		}
	}
	return false;		
}

bool ControladorUsuario::usuarioLogueadoEsAdmin(){
	if(usuarioLogueado==NULL)
		return false;
	else
		return usuarioLogueado->esAdmin();
}

ControladorUsuario::~ControladorUsuario(){}
