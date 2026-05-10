#include <iostream>

class Punto {
protected:
	double x_ = 0.0;
	double y_ = 0.0;

public:
	Punto() = default;
	Punto(double x, double y) : x_(x), y_(y) {}
	Punto operator=(const Punto& p) {
		if (this != &p) { // evitar autoasignación
			this->x_ = p.x_;
			this->y_ = p.y_;
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const Punto& p) {
		os << "(" << p.x_ << ", " << p.y_ << ")";
		return os;
	};
};

class PuntoCol : public Punto {
	std::string color_;
public:
	PuntoCol() = default;
	PuntoCol(double x, double y, const std::string& color) :
		Punto(x, y), color_(color) {
	}
	PuntoCol(const Punto& p, std::string color) :
		Punto(p), color_(color) {
	}

	PuntoCol(std::string color_) : color_(color_) {}
	PuntoCol(const PuntoCol& pc) : Punto(pc),
		color_(pc.color_) {
	}

	PuntoCol& operator=(const PuntoCol& pc);

	friend std::ostream& operator<<(std::ostream& os, const PuntoCol& pc) {
		os << static_cast<const Punto&>(pc) << " color: " << pc.color_;
		return os;
	};
};

PuntoCol& PuntoCol::operator=(const PuntoCol& pc) {
	if (this != &pc) { // evitar autoasignación
		this->color_ = pc.color_;
		this->Punto::operator= (pc); // asignar la parte de Punto
	}
	return *this;
}

int main() {
	PuntoCol p1(1.0, 2.0, "rojo");

	std::cout << "PuntoCol p1: " << p1 << std::endl;
}