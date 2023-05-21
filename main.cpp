// Incluimos el archivo de cabecera de nuestra clase CadenaDeMarkov.
#include "cadena_de_markov.h"
#include <iostream>

// Punto de entrada principal del programa.
int main() {
    try {
        // Creamos una instancia de nuestra clase CadenaDeMarkov.
        CadenaDeMarkov cadena;

        // Agregamos las transiciones de cada estado en nuestra cadena de Markov.
        // Para el estado 'A', puede ir al estado 'B' con una probabilidad de 0.2,
        // al estado 'C' con una probabilidad de 0.5, y al estado 'D' con una probabilidad de 0.3.
        cadena.agregar_transicion('A', {{'B', 0.2},
                                        {'C', 0.5},
                                        {'D', 0.3}});
        // Similarmente, agregamos transiciones para los estados 'B', 'C', y 'D'.
        cadena.agregar_transicion('B', {{'A', 0.1},
                                        {'C', 0.2},
                                        {'D', 0.7}});
        cadena.agregar_transicion('C', {{'A', 0.4},
                                        {'B', 0.6},
                                        {'D', 0.0}});
        cadena.agregar_transicion('D', {{'A', 0.3},
                                        {'B', 0.5},
                                        {'C', 0.2}});

        // Generamos una cadena utilizando nuestro modelo de Markov, empezando desde el estado 'A'
        // y con una longitud de 10 estados. Esto significa que la cadena generada tendrá 10 estados,
        // cada uno elegido basado en las probabilidades de transición que especificamos anteriormente.
        std::string secuencia_de_cadena = cadena.generar_cadena('A', 10);

        // Imprimimos la cadena generada a la salida estándar.
        std::cout << secuencia_de_cadena << std::endl;
    } catch (const std::invalid_argument& e) {
        // Si las probabilidades de transición no suman 1, se lanza una excepción.
        // Capturamos esa excepción aquí y mostramos su mensaje.
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    // Devolvemos 0 para indicar que el programa terminó exitosamente.
    return 0;
}
