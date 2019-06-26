#ifndef DtPuntaje_H
#define DtPuntaje_H

using namespace std;


class DtPuntaje{
	private:
		int puntos;
	public:
		DtPuntaje();
		DtPuntaje(int);
		int getPuntos();
		friend ostream& operator << (ostream&, const DtPuntaje&);
		~DtPuntaje();
};

#endif
