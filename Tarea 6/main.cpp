#include <cstdlib>
#include <iostream>
#include "Fabrica.h"
#include "IControladorUsuario.h"
#include <list>

using namespace std;

list<DtSala> listaDtSalas;

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
	agregarUsuario();
	cout << "Bienvenido. Elija la opcion" << endl; 
	while(true)
	{		
		cout << "1) Iniciar Sesión " << endl; 
		cout << "2) Alta Cine " << endl; 
		cout << "3) Alta Función " << endl; 
		cout << "4) Crear Reserva " << endl; 
		cout << "5) Puntuar Película " << endl; 
		cout << "6) Comentar Película  " << endl; 
		cout << "7) Eliminar Película  " << endl; 
		cout << "8) Ver Información de Película  " << endl; 
		cout << "9) Ver Comentarios y Puntajes de Película  " << endl; 
	    cout << "10) Cargar datos " << endl; 
		int comando;
		cin >> comando;			

		if (comando == 1){	//Iniciar Sesión
			string nickname, password;
			bool sesionOK;
			cout << "Ingrese nickname: " << endl; 
			cin >> nickname;	
		 	cout << "Ingrese contraseña: " << endl; 
			cin >> password;
			Fabrica* f = Fabrica::getInstancia();
			IControladorUsuario* contUsuario= f->getIControladorUsuario();
			sesionOK = contUsuario->iniciarSesion(nickname, password);
			if (sesionOK)			
				cout << "ok" << endl;
			else	
				cout << "Nook"<< endl; 
				
		}else if (comando == 2){ //Alta Cine
			string calle;
			int numero, capacidad, opcion;
			cout << "Ingrese calle: " << endl; 
			cin >> calle;	
			cout << "Ingrese numero: " << endl; 
			cin >> numero;
			opcion=3;
			while(opcion==3){
				cout << "Ingrese capacidad: " << endl; 
				cin >> capacidad;
				DtSala ds = DtSala(0,capacidad);
				listaDtSalas.push_back(ds);
				cout << "1) Confirmar " << endl; 
				cout << "2) Cancelar " << endl; 
				cout << "3) Agregar otra sala " << endl; 
				cin >> opcion;
			}
			if(opcion==2)
				listaDtSalas.clear();
			else if(opcion==1){
				Fabrica* f = Fabrica::getInstancia();
				IControladorCineFuncion* controladorCineFuncion= f->getIControladorCineFuncion();
				controladorCineFuncion->agregarCine(DtDireccion(calle,numero),listaDtSalas);	
			}
			
		}else if (comando == 3){//Alta Función
		
		
		}else if (comando == 4){//Crear Reserva

			
		}else if (comando == 5){//Puntuar Película
			
			
		}else if (comando == 6){//Comentar Película
		
		
		}else if (comando == 7){//Eliminar Película		
		
		
		}else if (comando == 8){//Ver Información de Película				
		
		
		}else if (comando == 9){//Ver Comentarios y Puntajes de Películas
		
		
		}else if (comando == 10){//Cargar datos
			
								
		}else if (comando ==0 )
		
		
		
			return(0);
					
	}
}
