#include "MedicionBase.hpp"

class Presion : public MedicionBase {
	public:
	float presionEstatica;
	float presionDinamica;

	Presion(float presionE, float presionD, float tiempoM);
	void serializar(ofstream& out) const override;
	void deserializar(ifstream& in) override;
	void imprimir() const override;
};