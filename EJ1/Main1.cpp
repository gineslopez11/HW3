#include "SaveFlight.hpp"

int main (){
	Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
	Presion presion(101.3f, 5.8f, 6.1f);

	posicion.imprimir();
	presion.imprimir();
	return 0;
}