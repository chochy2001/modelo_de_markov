//
// Created by jorge on 5/21/23.
//

#ifndef MODELO_DE_MARKOV_CADENA_DE_MARKOV_H
#define MODELO_DE_MARKOV_CADENA_DE_MARKOV_H

#include <map>
#include <random>

class CadenaDeMarkov {
private:
    std::map<char, std::map<char, double>> transiciones;
    std::default_random_engine generador;
    const double epsilon = 0.0001;

public:
    void agregar_transicion(char estado, const std::map<char, double>& probabilidades);
    [[maybe_unused]] char siguiente_estado(char estado_actual);
    std::string generar_cadena(char estado_inicial, int longitud);
};


#endif //MODELO_DE_MARKOV_CADENA_DE_MARKOV_H
