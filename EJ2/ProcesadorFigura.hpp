#include "Circulo.hpp"
#include "Elipse.hpp"
#include "Rectangulo.hpp"
#include <stdexcept>
#include <cmath> 

template<typename T>
class ProcesadorFigura {
	public:
	static float calcularArea(const T&) {
		throw runtime_error("No se puede calcular area de la figura");
	}
};

template<>
class ProcesadorFigura<Circulo> {
	public:
	static float calcularArea(const Circulo& c) {
		return M_PI * c.getR() * c.getR();
	}
};

template<>
class ProcesadorFigura<Elipse> {
	public:
	static float calcularArea(const Elipse& e) {
		return M_PI * e.getA() * e.getB();
	}
};

template<>
class ProcesadorFigura<Rectangulo> {
	public:
	static float calcularArea(const Rectangulo& r) {
		return r.getAncho() * r.getLargo();
	}
};