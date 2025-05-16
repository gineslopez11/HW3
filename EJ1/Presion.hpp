#pragma once
#include "MedicionBase.hpp"

class Presion : public MedicionBase {
	public:
	float presionEstatica;
	float presionDinamica;

	Presion(float presionE, float presionD, float tiempoM);
	Presion(const Presion& other);
	void serializar(ofstream& out) const override;
	void deserializar(ifstream& in) override;
	void imprimir() const override;
};