#include "JsonBuilder.hpp"
#include "DataGenerator.hpp"
#include <iostream>

using namespace std;

int main() {
    JsonBuilder builder;

    GenerarData<double> generadorDoubles;
    GenerarData<string> generadorStrings;
    GenerarData<int> generadorInts;

    generadorDoubles.AddValue(1.3);
    generadorDoubles.AddValue(2.1);
    generadorDoubles.AddValue(3.2);

    generadorStrings.AddValue("Hola");
    generadorStrings.AddValue("Mundo");

    generadorInts.AddValue(1);
    generadorInts.AddValue(2);
    generadorInts.AddValue(3);
    generadorInts.AddValue(4);

    builder.addData(generadorDoubles.getData());
    builder.addData(generadorStrings.getData());
    builder.addData(generadorInts.getData());

    cout << builder.build() << endl;

    return 0;
}