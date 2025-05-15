#include "Presion.hpp"
#include "Posicion.hpp"

class SaveFlightData{
	public:
	Posicion posicion;
	Presion presion;

	SaveFlightData(Posicion pos, Presion pres);
	void serializar(ofstream& out) const;
	void deserializar(ifstream& in);
};