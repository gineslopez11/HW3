#include "JsonBuilder.hpp"
#include "DataGenerator.hpp"
#include <iostream>

using namespace std;
int main() {
	
    JsonBuilder builder;

    // Datos de ejemplo (usando tu clase GenerarData)
    vector<double> doubles = {1.3, 2.1, 3.2};
    vector<string> strings = {"Hola", "Mundo"};
    vector<vector<int>> lists = {{1, 2}, {3, 4}};

    // Construye el JSON
    builder.addData("vec_doubles", doubles);
    builder.addData("palabras", strings);
    builder.addData("listas", lists);

    // Imprime el resultado
    cout << builder.build() << endl;

    return 0;
}