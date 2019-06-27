#include <cstdlib>
#include <iostream>
#include "Fabrica.h"
#include "IControladorUsuario.h"
#include "IControladorPelicula.h"
#include "IControladorCineFuncion.h"
#include "IControladorReserva.h"
#include <list>
#include <map>
#include "DtReserva.h"
#include "DtCredito.h"
#include "DtDebito.h"

using namespace std;
map<string, float> financieras;
list<DtSala> listaDtSalas;

void agregarFuncion(){
	Fabrica* f = Fabrica::getInstancia();
	IControladorPelicula* contPelicula = f->getIControladorPelicula();
	IControladorCineFuncion* contCineFuncion= f->getIControladorCineFuncion();
	contPelicula->seleccionarPelicula(DtPelicula("Esjubi du","sinosis Esjubi du","www.BosterEsjubi.jpg",0));
	contCineFuncion->SeleccionarCine(DtCine(1,DtDireccion("calle1",1111)));
	contCineFuncion->SeleccionarSala(DtSala(1,10));
	DtHorario dtHorario = DtHorario(11,10);
	DtFecha dtFecha = DtFecha(6,6,2018);
	contCineFuncion->agregarFuncion(DtFuncion(0,dtFecha,dtHorario));
	///segunda funcion
	//contPelicula->seleccionarPelicula(DtPelicula("Madris","sinosis Madris","www.BosterMadris.jpg",0));
	contCineFuncion->SeleccionarCine(DtCine(2,DtDireccion()));
	contCineFuncion->SeleccionarSala(DtSala(2,0));
	dtHorario = DtHorario(8,30);
	dtFecha = DtFecha(26,8,2019);
	contCineFuncion->agregarFuncion(DtFuncion(0,dtFecha,dtHorario));
}
void agregarFinanciera(){
	financieras["Pronto"] = 10;
	financieras["Fucac"]  = 5;
	financieras["MegaFinanzas"]  = 0;
}

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
	contPelicula->agregarPelicula(DtPelicula("Esjubi du","sinosis Esjubi du","www.BosterEsjubi.jpg",0));
	contPelicula->agregarPelicula(DtPelicula("Madris","sinosis Madris","www.BosterMadris.jpg",0));
	contPelicula->agregarPelicula(DtPelicula("dragonbol seta","sinosisMadris dragonbol seta","www.dragonbol.jpg",0));
}

void agregarCine(){
	
	Fabrica* f = Fabrica::getInstancia();
	IControladorCineFuncion* contCineFuncion= f->getIControladorCineFuncion();
	list<DtSala> ls;
	ls.push_back(DtSala(0,10));	
	ls.push_back(DtSala(0,537));	
	contCineFuncion->agregarCine(DtCine(0,DtDireccion("calle1",1111)),ls);	
	ls.push_back(DtSala(0,50));	
	ls.push_back(DtSala(0,5327));	
	contCineFuncion->agregarCine(DtCine(0,DtDireccion("calle2",1122)),ls);	
}
int main() {	
	agregarFinanciera();
	agregarUsuario();
	bool sesionOK = Fabrica::getInstancia()->getIControladorUsuario()->iniciarSesion("admin", "admin");
	agregarPelicula();
	agregarCine();
	agregarFuncion();
	
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
				cout << "No ok"<< endl; 
				
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
			Fabrica* f = Fabrica::getInstancia();
			IControladorPelicula* contPelicula = f->getIControladorPelicula();
			IControladorCineFuncion* contCineFuncion = f->getIControladorCineFuncion();
			IControladorReserva* contReserva = f->getIControladorReserva();
			int peliculaSeleccionada=0, cont=0, aux=0, puntaje=0;
			while(true){
				cout << "Seleccione pelicula o salir = 0" << endl; 
				DtPelicula p;
				list<DtPelicula> lp = contPelicula->listarPelicula();
				for (std::list<DtPelicula>::iterator it=lp.begin(); it != lp.end(); ++it){
					cont++;
					p = *it;
					cout << cont << " - "<< p.getTitulo() << endl; 					
				}
				cin >> peliculaSeleccionada;
				if(peliculaSeleccionada!=0){
					cont = 0;
					for (std::list<DtPelicula>::iterator it=lp.begin(); it != lp.end(); ++it){
						cont++;
						if (cont == peliculaSeleccionada ){					
							p = *it;					
							break;	
						}
					}
					contPelicula->seleccionarPelicula(p);
					DtPelicula dp = contPelicula->getDatosPeliculaSeleccionada();
					cout << "Poster: "<<dp.getPoster() <<endl;
					cout << "Sinopsis: "<<dp.getSinopsis() <<endl;
					cout << "Ver información adicional = 1, Cancelar = 0" << endl; 
					cin >> aux;
					if(aux == 1){
						list<DtCine> listaDtCine = contCineFuncion->listarCinePeliculaSeleccionada();
						DtCine dc;
						for (std::list<DtCine>::iterator it=listaDtCine.begin(); it != listaDtCine.end(); ++it){
							dc = *it;
							cout << dc; 	
						}
						aux=0;
						cout << "Seleccionar Cine o Cancelar = 0" << endl;
						cin >> aux; 
						if(aux != 0){
							contCineFuncion->SeleccionarCine(DtCine(aux,DtDireccion()));
							list<DtFuncion> listaDtFuncion = contCineFuncion->listarFuncionCineSeleccionadoPeliculaSeleccionada();
							aux=0;
							cout << "Seleccione funcion o elija otra pelicula = 0"<<endl;
							DtFuncion df;
							for (std::list<DtFuncion>::iterator it=listaDtFuncion.begin(); it != listaDtFuncion.end(); ++it){
								df = *it;
								cout << df << endl; 					
							}
							cin >> aux;
							if(aux!=0){
								int cantAsientos;
								contCineFuncion->SeleccionarFuncion(DtFuncion(aux,DtFecha(),DtHorario()));
								cout << "Ingrese cantidad de asientos: "<<endl;							
								cin >> cantAsientos;
								aux=0;
								cout << "Ingrese modo de pago, credito = 1, debito = 2"<<endl;
								cin >> aux;
								if(aux==1){
									string financiera;
									cout << "Ingrese financiera: "<<endl;
									map<string,float>::iterator it;
									for (it= financieras.begin(); it!=financieras.end(); ++it){
									  string clave = it->first;
									  float  valor = it->second;
									  cout << clave << " - Descuento: " << valor << "%" <<endl;
									}
									cin >> financiera;
									DtCredito dtr = DtCredito(financieras[financiera],financiera,0);
									contReserva->crearReserva(dtr);
								}else{
									string banco;
									cout << "Ingrese banco: "<<endl;
									cin >> banco;
									DtDebito dtd = DtDebito(banco,0);
									contReserva->crearReserva(dtd);
								}
								cout << "Costo de la reserva: "<< contReserva->mostrarCosto();
								aux=0;
								cout << "Confirmar = 1, Cancelar = 2"<<endl;
								cin >> aux;
								if(aux==1){
									contReserva->confirmarReserva();
									cout << "Reserva Ingresada "<<endl;
								}
								break;
							}
						}else
							break;
					}
				}
			}
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
				}
			}else{
				cout << "Ingrese puntaje: " << endl; 
				cin >> puntaje;
				contPelicula->agregarPuntaje(puntaje);
			}
			cout << "Puntaje ingresado." << endl;
		}else if (comando == 6){//Comentar Película
		
		
		}else if (comando == 7){//Eliminar Película		
		
		
		}else if (comando == 8){//Ver Información de Película				
		
		
		}else if (comando == 9){//Ver Comentarios y Puntajes de Películas
		
		
		}else if (comando == 10){//Cargar datos
			
								
		}else if (comando ==0 )
		
		
		
			return(0);
					
	}
}
