#include "Punto.hpp"

class Elipse : public Punto{
	protected:
	float a,b;
	
	public:
	Elipse (float x1, float y1, float a1, float b1);
	void setA(float a1);
	void setB(float b1);
	float getA() const;
	float getB() const;
};