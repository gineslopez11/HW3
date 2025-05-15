#include "IMediciones.hpp"
#include <memory>

class MedicionBase : public IMediciones{
	protected: 
	unique_ptr<float> tiempoMedicion;

	public:
	MedicionBase (float tiempoM);
	float getTiempo() const;
	virtual void imprimir() const = 0;
	virtual void serializar(ofstream& out) const = 0;
	virtual void deserializar(ifstream& in) = 0;

};