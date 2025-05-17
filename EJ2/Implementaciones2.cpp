#include "ProcesadorFigura.hpp"

//Implementacion Punto
Punto::Punto(float x1, float y1) : x(x1), y(y1){}
void Punto::setX(float x1) { x = x1;}
void Punto::setY(float y1) { y = y1;}
float Punto::getX() const{ return x; }
float Punto::getY() const{ return y; }

//Implementacion Circulo
Circulo::Circulo(float x1, float y1, float r) : Punto(x1,y1), radio(r){}
void Circulo::setR(float r) { radio = r;}
float Circulo::getR() const{ return radio; }

//Implementacion Elipse
Elipse::Elipse(float x1, float y1, float a1, float b1) : Punto(x1,y1), a(a1), b(b1){}
void Elipse::setA(float a1) { a = a1;}
void Elipse::setB(float b1) { b = b1;}
float Elipse::getA() const{ return a; }
float Elipse::getB() const{ return b; }

//Implementacion Rectangulo
Rectangulo::Rectangulo(float x1, float y1, float anch, float lar) : Punto(x1,y1), ancho(anch), largo(lar){}
void Rectangulo::setAncho(float anch) { ancho = anch;}
void Rectangulo::setLargo(float lar) { largo = lar;}
float Rectangulo::getAncho() const{ return ancho; }
float Rectangulo::getLargo() const{ return largo; }
