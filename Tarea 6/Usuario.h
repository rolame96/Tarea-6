#ifndef Usuario_H
#define Usuario_H
#include <string>

using namespace std;

class Usuario
{
  private: 
		string nickname, password, urlFoto;
		bool admin;
  public:
        //constructor por defecto
        Usuario();
    	//constructor comun
        Usuario(string, string, string, bool);    
        //propiedades
        void setNickname(string);
        string getNickname();
        void setPassword(string);
        string getPassword();      
		void setUrlFoto(string);
        string getUrlFoto();      
        //operaciones
        bool esAdmin();
        //Destructor
        ~Usuario();
};

#endif
