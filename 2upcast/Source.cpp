#include <iostream>
//#include <Windows.h> // para SetConsoleCP y SetConsoleOutputCP y poner acentos en la consola de Windows
#include <locale.h> // para setlocale y usar el español en la consola

using namespace std;

class Guerrero{
public:
	void pelea() { // todos los guerreros saben pelear
		cout << "¡Pelea mamón ñoño!" << endl;
	}
};

class Mago : public Guerrero {
	int mana_ = 100; // los magos tienen maná
public:
	void hechiza(){ // los magos saben hechizar
		cout << "¡Hechiza!" << endl;
	} // los magos también saben pelear, heredan el método pelea() de Guerrero
	
};
int main() {
	//SetConsoleCP(1252);
	//SetConsoleOutputCP(1252); // para usar acentos en la consola de Windows

	setlocale(LC_ALL, "spanish"); // para usar el español en la consola

	Guerrero g;
	Mago m;
	g.pelea(); // vínculo estático
	m.hechiza(); // vínculo estático
	m.pelea(); // vínculo estático con método base
	// el compilador sabe exactamente a qué
	// función llamar en tiempo de compilación

	Guerrero* pg = &m; // UPCAST: un Mago es un Guerrero
	pg->pelea(); // el mago pelea según el guerrero
	// pg->hechiza(); // INCORRECTO, hechiza() no es accesible
	// debido a la resolución de la llamada
	// por vínculo estático, el compilador solo ve el tipo Guerrero* y no sabe que pg apunta a un Mago
	// por lo tanto, no puede llamar a hechiza() a través de pg

	Guerrero g2 = m; // SLICING: se pierde la parte de Mago, solo queda la parte de Guerrero

};