//Programa Realizado por Alejandro Rodriguez Larios y Jorge Salgado Miranda

// Esta es la definición de la guarda de inclusión, que evita la inclusión múltiple
// del mismo archivo de encabezado que podría causar problemas.
#ifndef MODELO_DE_MARKOV_CADENA_DE_MARKOV_H

// Definimos el identificador único de la guarda de inclusión.
#define MODELO_DE_MARKOV_CADENA_DE_MARKOV_H

// Incluimos la biblioteca de mapas y generadores aleatorios de C++.
#include <map>
#include <random>

// Definimos la clase CadenaDeMarkov.
class CadenaDeMarkov {
    // Variables privadas de la clase.
private:
    // Mapa que contiene las transiciones entre estados.
    // Cada estado (clave del mapa exterior) tiene asociado un mapa
    // con los estados a los que puede transicionar (claves del mapa interior)
    // y sus respectivas probabilidades (valores del mapa interior).
    std::map<char, std::map<char, double>> transiciones;

    // Motor de generación de números aleatorios, necesario para elegir el próximo estado.
    std::default_random_engine generador;

    // Epsilon es una pequeña constante que usamos para comparar doubles con cierta tolerancia.
    const double epsilon = 0.0001;

    // Métodos públicos de la clase.
public:
    // Método para agregar transiciones a un estado.
    // El primer argumento es el estado, el segundo es un mapa con los estados de destino y sus probabilidades.
    void agregar_transicion(char estado, const std::map<char, double>& probabilidades);

    // Método que dado un estado actual, retorna el siguiente estado en la cadena de Markov.
    char siguiente_estado(char estado_actual);

    // Método que genera una cadena de la cadena de Markov, dado un estado inicial y una longitud.
    std::string generar_cadena(char estado_inicial, int longitud);
};

// Final de la definición de la guarda de inclusión.
#endif //MODELO_DE_MARKOV_CADENA_DE_MARKOV_H
