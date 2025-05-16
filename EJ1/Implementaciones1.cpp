#include "SaveFlight.hpp"
#include <fstream>  

//Implementacion MedicionBase:
MedicionBase::MedicionBase(float tiempoM) : tiempoMedicion(make_unique<float>(tiempoM)){}
float MedicionBase::getTiempo() const { return *tiempoMedicion; }

//Implementacion Presion
Presion::Presion(float presionE, float presionD, float tiempoM) : presionEstatica(presionE), presionDinamica(presionD), MedicionBase(tiempoM){
	    if (presionE < 0 || presionD < 0) throw std::invalid_argument("Las presiones no pueden ser negativas");
}
Presion::Presion(const Presion& other) : presionEstatica(other.presionEstatica), presionDinamica(other.presionDinamica), MedicionBase(other.getTiempo()){
	if (other.presionEstatica < 0 || other.presionDinamica < 0) throw std::invalid_argument("Las presiones no pueden ser negativas");
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
	cout<<"Presion Estatica: "<<presionEstatica<<", Presion Dinamica: "<<presionDinamica<<", Tiempo: "<<*tiempoMedicion<<endl;
};

//Implementacion Posicion
Posicion::Posicion(float lat, float lon, float alt, float tiempoM) : latitud(lat), longitud(lon), altitud(alt), MedicionBase(tiempoM){}
Posicion::Posicion(const Posicion& other) : latitud(other.latitud), longitud(other.longitud), altitud(other.altitud), MedicionBase(other.getTiempo()){}
void Posicion::serializar(ofstream& out) const{
	    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    	out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
		out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));

    	float tiempo = this->getTiempo(); 
    	out.write(reinterpret_cast<const char*>(&tiempo), sizeof(float));
}
void Posicion::deserializar(ifstream& in){
	    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    	in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
		in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
    
    	float tiempo = this->getTiempo(); 
    	in.read(reinterpret_cast<char*>(&tiempo), sizeof(float));
}
void Posicion::imprimir() const{
	cout<<"Longitud: "<<longitud<<", Latitud: "<<latitud<<", Altitud: "<<altitud<<", Tiempo: "<<*tiempoMedicion<<endl;
};

//Implementacion SaveFlightData
SaveFlightData::SaveFlightData(const Posicion& pos, const Presion& pres) : posicion(pos), presion(pres){}
void SaveFlightData::serializar(ofstream& out) const{
		posicion.serializar(out);
		presion.serializar(out);

}
void SaveFlightData::deserializar(ifstream& in){
		posicion.deserializar(in);
		presion.deserializar(in);
}

