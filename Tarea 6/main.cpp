#include <cstdlib>
#include <iostream>
#include "Fabrica.h"
#include "IControladorUsuario.h"
#include "IControladorPelicula.h"
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
void agregarPelicula(){
	Fabrica* f = Fabrica::getInstancia();
	IControladorPelicula* contPelicula= f->getIControladorPelicula();
	contPelicula->agregarPelicula(DtPelicula("Esjubi du","sinosis","www.Boster.jpg",0));
	contPelicula->agregarPelicula(DtPelicula("Madris","sinosisMadris","www.BosterMadris.jpg",0));
}

void agregarCine(){
	
	Fabrica* f = Fabrica::getInstancia();
	IControladorCineFuncion* contCineFuncion= f->getIControladorCineFuncion();
	list<DtSala> ls;
	ls.push_back(DtSala(0,10));	
	ls.push_back(DtSala(0,537));	
	contCineFuncion->agregarCine(DtCine(0,DtDireccion("calle1",1)),ls);	
	ls.push_back(DtSala(0,50));	
	ls.push_back(DtSala(0,5327));	
	contCineFuncion->agregarCine(DtCine(0,DtDireccion("calle2",2)),ls);	
}
int main() {	
	agregarUsuario();
	bool sesionOK = Fabrica::getInstancia()->getIControladorUsuario()->iniciarSesion("admin", "admin");
	agregarPelicula();
	agregarCine();
	
	
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
				controladorCineFuncion->agregarCine(DtCine(0,DtDireccion(calle,numero)),listaDtSalas);	
			}
			
		}else if (comando == 3){//Alta Función
			Fabrica* f = Fabrica::getInstancia();
			IControladorUsuario* contUsuario = f->getIControladorUsuario();
			IControladorPelicula* contPelicula = f->getIControladorPelicula();		
			IControladorCineFuncion* contCineFuncion = f->getIControladorCineFuncion();	
			int peliculaSeleccionada = 0,cineSeleccionado = 0,cont = 0,salaSeleccionada = 0;
			
			
			if (contUsuario->usuarioLogueadoEsAdmin()){
				cout << "Seleccione pelicula " << endl; 
				DtPelicula p;
				list<DtPelicula> lp = contPelicula->listarPelicula();
				for (std::list<DtPelicula>::iterator it=lp.begin(); it != lp.end(); ++it){
					cont++;
					p = *it;
					cout << cont << " - "<< p.getTitulo() << endl; 					
				}
				cin >> peliculaSeleccionada;
				cont = 0;
				for (std::list<DtPelicula>::iterator it=lp.begin(); it != lp.end(); ++it){
					cont++;
					if (cont == peliculaSeleccionada ){					
						p = *it;					
						break;	
					}
				}
				contPelicula->seleccionarPelicula(p);	
				
				cout << "Seleccione cine " << endl; 
				DtCine c;				
				list<DtCine> lc = contCineFuncion->listarCine();
				for (std::list<DtCine>::iterator it=lc.begin(); it != lc.end(); ++it){
					c = *it;
					cout << c.getId() << endl; 					
				}
				cin >> cineSeleccionado;
				for (std::list<DtCine>::iterator it=lc.begin(); it != lc.end(); ++it){
					c = *it;
					if (c.getId() == cineSeleccionado ){
						contCineFuncion->SeleccionarCine(c);
						break;
					}																		
											
				}
					
				cout << "Seleccione sala " << endl; 
				DtSala s;							
				list<DtSala> ls = contCineFuncion->listarSala(c);							
				for (std::list<DtSala>::iterator it=ls.begin(); it != ls.end(); ++it){
					s = *it;
					cout << s.getId() << endl; 					
				}
				cin >> salaSeleccionada;
				for (std::list<DtSala>::iterator it=ls.begin(); it != ls.end(); ++it){
					s = *it;
					if (s.getId() == salaSeleccionada )	{
						contCineFuncion->SeleccionarSala(s);
						break;						
					}																								
				}
				int dia,mes, anio,hora,minutos;
				cout << "Seleccione fecha de funcion " << endl; 
				cout << "dia " << endl; 
				cin >> dia;
				cout << "mes " << endl; 
				cin >> mes;
				cout << "anio " << endl; 
				cin >> anio;	
				DtFecha dtFecha = DtFecha(dia,mes,anio);
				
				cout << "Seleccione hora de funcion " << endl; 
				cout << "hora " << endl; 
				cin >> hora;
				cout << "minutos " << endl; 
				cin >> minutos;
				DtHorario dtHorario = DtHorario(hora,minutos);

				contCineFuncion->agregarFuncion(DtFuncion(0,dtFecha,dtHorario));
				
				
			}else
				cout << "No es admin " << endl; 

				
				
		}else if (comando == 4){//Crear Reserva

			
		}else if (comando == 5){//Puntuar Película
			Fabrica* f = Fabrica::getInstancia();
			IControladorPelicula* contPelicula = f->getIControladorPelicula();
			int peliculaSeleccionada=0, cont=0, aux=0, puntaje=0;
			cout << "Seleccione pelicula " << endl; 
			DtPelicula p;
			list<DtPelicula> lp = contPelicula->listarPelicula();
			for (std::list<DtPelicula>::iterator it=lp.begin(); it != lp.end(); ++it){
				cont++;
				p = *it;
				cout << cont << " - "<< p.getTitulo() << endl; 					
			}
			cin >> peliculaSeleccionada;
			cont = 0;
			for (std::list<DtPelicula>::iterator it=lp.begin(); it != lp.end(); ++it){
				cont++;
				if (cont == peliculaSeleccionada ){					
					p = *it;					
					break;	
				}
			}
			contPelicula->seleccionarPelicula(p);
			if(contPelicula->usuarioPuntuoPelicula()){
				cout << "Puntaje anterior: " << contPelicula->mostrarPuntaje() << endl;
				cout << "Desea modificar puntaje? Si=1 No=2 " << endl; 
				cin >> aux;
				if(aux==1){
					cout << "Ingrese puntaje: " << endl; 
					cin >> puntaje;
					contPelicula->agregarPuntaje(DtPuntaje(puntaje));
				}else
					break;
			}else{
				cout << "Ingrese puntaje: " << endl; 
				cin >> puntaje;
				contPelicula->agregarPuntaje(puntaje);
			}
		}else if (comando == 6){//Comentar Película
		
		
		}else if (comando == 7){//Eliminar Película		
		
		
		}else if (comando == 8){//Ver Información de Película				
		
		
		}else if (comando == 9){//Ver Comentarios y Puntajes de Películas
		
		
		}else if (comando == 10){//Cargar datos
			
								
		}else if (comando ==0 )
		
		
		
			return(0);
					
	}
}
