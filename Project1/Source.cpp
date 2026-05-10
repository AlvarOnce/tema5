#include <iostream>

class Mamifero {
protected:
	float peso_ = 100.0f;
public:
	Mamifero() = default;
	Mamifero(float peso) : peso_(peso) {}
	float peso() const { return peso_; }
	void set_peso(float peso) { peso_ = peso; }
};

class Perro : public Mamifero {
public:
	Perro() = default;
	Perro(float peso) : Mamifero(peso) {}
};

class Caniche : public Perro {
public:
	Caniche() = default;
	Caniche(float peso) : Perro(peso) {}
};

int main() {
	Caniche c;
	c.set_peso(12.5f);
	std::cout << "El peso del caniche es: " << c.peso() << " kg" << std::endl;
	
	Perro p(20.0f);
	std::cout << "El peso del perro es: " << p.peso() << " kg" << std::endl;
	
	return 0;
}