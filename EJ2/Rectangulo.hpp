#include "Punto.hpp"

class Rectangulo : public Punto {
	protected:
	float ancho,largo;
	
	public:
	Rectangulo (float x1, float y1, float anch, float lar);
	void setAncho(float anch);
	void setLargo(float lar);
	float getAncho() const;
	float getLargo() const;
};