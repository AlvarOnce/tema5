#include <iostream>

using namespace std;

class Guerrero{
public:
	void pelea() { // todos los guerreros saben pelear
		cout << "¡Pelea!" << endl;
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
	Guerrero g;
	Mago m;
	g.pelea(); // vínculo estático
	m.hechiza(); // vínculo estático
	m.pelea(); // vínculo estático con método base
	// el compilador sabe exactamente a qué
	// función llamar en tiempo de compilación

	Guerrero* pg = &m; // upcasting: un Mago es un Guerrero
	pg->pelea(); // el mago pelea según el guerrero
	// pg->hechiza(); // INCORRECTO, hechiza() no es accesible
	// debido a la resolución de la llamada
	// por vínculo estático

	Guerrero g2 = m; // slicing, se pierde la parte de Mago, solo queda la parte de Guerrero

};