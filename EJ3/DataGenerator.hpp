#pragma once
#include <vector>
#include <string>
#include <map>
#include <type_traits>

using namespace std;

template <typename T>
class GenerarData {
private:
    map<string, vector<T>> datos;

public:
    // Guarda doubles en "vec_doubles" y strings en "palabras"
    void AddValue(const T& valor) {
        if constexpr (is_same_v<T, double>) {
            datos["vec_doubles"].push_back(valor);
        } else if constexpr (is_same_v<T, string>) {
            datos["palabras"].push_back(valor);
        }
    }

    map<string, vector<T>> getData() const {
        return datos;
    }
};

// Especialización para int: guarda pares de ints en "listas"
template <>
class GenerarData<int> {
private:
    vector<int> intTemporales;
    map<string, vector<vector<int>>> datos;

public:
    // Junta los ints de a pares antes de guardarlos
    void AddValue(int valor) {
        intTemporales.push_back(valor);
        if (intTemporales.size() == 2) {
            datos["listas"].push_back(intTemporales);
            intTemporales.clear();
        }
    }

    map<string, vector<vector<int>>> getData() const {
        return datos;
    }
};