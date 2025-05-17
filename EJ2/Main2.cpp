#include "ProcesadorFigura.hpp"

int main() {
    Circulo c(0.0f, 0.0f, 2.0f); 
	Elipse e(0.0f, 0.0f, 4.0f, 2.0f); 
	Rectangulo r(0.0f, 0.0f, 1.0f, 2.0f); 
	Punto p(0.0f, 0.0f); 
    
    float areaC = ProcesadorFigura<Circulo>::calcularArea(c);
    float areaE = ProcesadorFigura<Elipse>::calcularArea(e);
	float areaR = ProcesadorFigura<Rectangulo>::calcularArea(r);

	cout << "Área de la circulo: " << areaC << endl;
	cout << "Área de la elipse: " << areaE << endl;
	cout << "Área de la rectangulo: " << areaR << endl;
	
	float areaP = ProcesadorFigura<Punto>::calcularArea(p);
    
    return 0;
}