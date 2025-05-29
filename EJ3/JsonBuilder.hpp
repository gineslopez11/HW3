#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class JsonBuilder {
    private:
    ostringstream jsonStream;  
    bool firstKey = true;

    public:
    // Agrega un array de doubles al JSON
    void addData(const map<string, vector<double>>& datos) {
        for (const auto& [key, values] : datos) {
            if (!firstKey) jsonStream << ",\n";
            jsonStream << "    \"" << key << "\": [";
            for (size_t i = 0; i < values.size(); ++i) {
                if (i != 0) jsonStream << ", ";
                jsonStream << values[i];
            }
            jsonStream << "]";
            firstKey = false;
        }
    }

    // Agrega un array de strings al JSON (con comillas)
    void addData(const map<string, vector<string>>& datos) {
        for (const auto& [key, values] : datos) {
            if (!firstKey) jsonStream << ",\n";
            jsonStream << "    \"" << key << "\": [";
            for (size_t i = 0; i < values.size(); ++i) {
                if (i != 0) jsonStream << ", ";
                jsonStream << "\"" << values[i] << "\"";
            }
            jsonStream << "]";
            firstKey = false;
        }
    }

    // Agrega un array de arrays de ints al JSON (formato tipo matriz)
    void addData(const map<string, vector<vector<int>>>& datos) {
        for (const auto& [key, values] : datos) {
            if (!firstKey) jsonStream << ",\n";
            jsonStream << "    \"" << key << "\": [\n";
            for (size_t i = 0; i < values.size(); ++i) {
                if (i != 0) jsonStream << ",\n";
                jsonStream << "        [";
                for (size_t j = 0; j < values[i].size(); ++j) {
                    if (j != 0) jsonStream << ", ";
                    jsonStream << values[i][j];
                }
                jsonStream << "]";
            }
            jsonStream << "\n    ]";
            firstKey = false;
        }
    }

    // Devuelve el string JSON final
    string build() const {
        return "{\n" + jsonStream.str() + "\n}";
    }
};