#include "cadena_de_markov.h"
#include <iostream>

int main() {
    try {
        CadenaDeMarkov cadena;

        cadena.agregar_transicion('A', {{'B', 0.2},
                                        {'C', 0.5},
                                        {'D', 0.3}});
        cadena.agregar_transicion('B', {{'A', 0.1},
                                        {'C', 0.2},
                                        {'D', 0.7}});
        cadena.agregar_transicion('C', {{'A', 0.4},
                                        {'B', 0.6},
                                        {'D', 0.0}});
        cadena.agregar_transicion('D', {{'A', 0.3},
                                        {'B', 0.5},
                                        {'C', 0.2}});

        std::string secuencia_de_cadena = cadena.generar_cadena('A', 10);
        std::cout << secuencia_de_cadena << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }
    return 0;
}
