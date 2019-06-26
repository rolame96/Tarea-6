#include "ControladorUsuario.h"
#include <iostream>

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){
	this->usuarioLogueado = NULL;
	listaUsuarios.clear();
}

ControladorUsuario* ControladorUsuario::getInstancia(){
	if (instancia == NULL)
		instancia = new ControladorUsuario();
	return instancia;
}

void ControladorUsuario::agregarUsuario(string nickname, string password, string urlFoto, bool admin){
	Usuario* nuevoUsuario = new Usuario(nickname, password, urlFoto, admin);
	listaUsuarios.push_back(nuevoUsuario);
}

Usuario* ControladorUsuario::getUsuarioLogueado(){
	return this->usuarioLogueado;
}

bool ControladorUsuario::iniciarSesion(string nickname, string password){
	if(usuarioLogueado==NULL){
		Usuario* u = NULL;
		for (std::list<Usuario*>::iterator it=listaUsuarios.begin(); it != listaUsuarios.end(); ++it){
			u = *it;
			if (u->getNickname() == nickname && u->getPassword() == password){
				usuarioLogueado = u;				
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
