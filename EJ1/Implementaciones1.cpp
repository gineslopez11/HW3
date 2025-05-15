#include "SaveFlight.hpp"
#include <fstream>  

//Implementacion MedicionBase:
MedicionBase::MedicionBase(float tiempoM) : tiempoMedicion(make_unique<float>(tiempoM)){}
float MedicionBase::getTiempo() const { return *tiempoMedicion; }

//Implementacion Presion
Presion::Presion(float presionE, float presionD, float tiempoM) : presionEstatica(presionE), presionDinamica(presionD), MedicionBase(tiempoM){
	    if (presionE < 0 || presionD < 0) throw std::invalid_argument("Las presiones no pueden ser negativas");
}
void Presion::serializar(ofstream& out) const{
	    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
    	out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
    
    	float tiempo = this->getTiempo(); 
    	out.write(reinterpret_cast<const char*>(&tiempo), sizeof(float));
}
void Presion::deserializar(ifstream& in){
	    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
    	in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
    
    	float tiempo = this->getTiempo(); 
    	in.read(reinterpret_cast<char*>(&tiempo), sizeof(float));
}
void Presion::imprimir() const{

};

//Implementacion Posicion

