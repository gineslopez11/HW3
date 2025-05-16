#pragma once
#include "Presion.hpp"
#include "Posicion.hpp"

class SaveFlightData{
	public:
	Posicion posicion;
	Presion presion;

	SaveFlightData(const Posicion& pos,const Presion& pres);
	void serializar(ofstream& out) const;
	void deserializar(ifstream& in);
};