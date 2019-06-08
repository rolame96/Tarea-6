#include <cstdlib>
#include <iostream>
#include "Fabrica.h"
#include "IControladorUsuario.h"

using namespace std;

void agregarUsuario(){
	Fabrica* f = Fabrica::getInstancia();
	IControladorUsuario* contUsuario= f->getIControladorUsuario();
	contUsuario->agregarUsuario("user", "user", "www.google.com/1", false);
	contUsuario->agregarUsuario("ezequiel", "4525255", "www.google.com/2", false);
	contUsuario->agregarUsuario("rodrigo", "4672749", "www.google.com/3", false);
	contUsuario->agregarUsuario("enzo", "4330024", "www.google.com/4", false);
	contUsuario->agregarUsuario("federico", "12345", "www.google.com/5", false);
	contUsuario->agregarUsuario("admin", "admin", "www.google.com/6", true);
}

int main() {

	cout << "Bienvenido. Elija la opcion" << endl; 
	while(true)
	{		
		cout << "1) Iniciar Sesi�n " << endl; 
		cout << "2) Alta Cine " << endl; 
		cout << "3) Alta Funci�n " << endl; 
		cout << "4) Crear Reserva " << endl; 
		cout << "5) Puntuar Pel�cula " << endl; 
		cout << "6) Comentar Pel�cula  " << endl; 
		cout << "7) Eliminar Pel�cula  " << endl; 
		cout << "8) Ver Informaci�n de Pel�cula  " << endl; 
		cout << "9) Ver Comentarios y Puntajes de Pel�cula  " << endl; 
	    cout << "10) Cargar datos " << endl; 
		int comando;
		cin >> comando;			

		if (comando == 1){	//Iniciar Sesi�n
			string nickname, password;
			bool sesionOK;
			cout << "Ingrese nickname: " << endl; 
			cin >> nickname;	
		 	cout << "Ingrese contrase�a: " << endl; 
			cin >> password;
			Fabrica* f = Fabrica::getInstancia();
			IControladorUsuario* contUsuario= f->getIControladorUsuario();
			sesionOK = contUsuario->iniciarSesion(nickname, password);
			if (sesionOK)			
				cout << "ok";
			else	
				cout << "Nook";
				
		}else if (comando == 2){ //Alta Cine
			
			
		}else if (comando == 3){//Alta Funci�n
		
		
		}else if (comando == 4){//Crear Reserva

			
		}else if (comando == 5){//Puntuar Pel�cula
			
			
		}else if (comando == 6){//Comentar Pel�cula
		
		
		}else if (comando == 7){//Eliminar Pel�cula		
		
		
		}else if (comando == 8){//Ver Informaci�n de Pel�cula				
		
		
		}else if (comando == 9){//Ver Comentarios y Puntajes de Pel�culas
		
		
		}else if (comando == 10){//Cargar datos
			
								
		}else if (comando ==0 )
		
		
		
			return(0);
					
	}
}