#include "Punto.hpp"

class Circulo : public Punto{
	protected:
	float radio;
	
	public:
	Circulo (float x1, float y1, float r);
	void setR(float r);
	float getR() const;

};