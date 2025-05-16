#pragma once
#include <iostream>
using namespace std;

class Punto {
	protected:
	float x,y;

	public:
	Punto (float x1, float y1);
	void setX(float x1);
	void setY(float y1);
	float getX() const;
	float getY() const;
};