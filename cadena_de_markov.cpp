//
// Created by jorge on 5/21/23.
//

#include "cadena_de_markov.h"
#include <numeric>
#include <algorithm>

void CadenaDeMarkov::agregar_transicion(char estado, const std::map<char, double>& probabilidades) {
    double sum = std::accumulate(probabilidades.begin(), probabilidades.end(), 0.0,
                                 [](double value, const std::map<char, double>::value_type& p) { return value + p.second; });

    if(std::abs(sum - 1.0) > epsilon) {
        throw std::invalid_argument("Error: Las probabilidades de transición no suman 1.");
    }

    transiciones[estado] = probabilidades;
}

char CadenaDeMarkov::siguiente_estado(char estado_actual) {
    std::map<char, double> trans = transiciones[estado_actual];
    double Suma_de_los_pesos = 0;
    for(auto& tr : trans) {
        Suma_de_los_pesos += tr.second;
    }
    std::uniform_real_distribution<double> distribucion(0.0, Suma_de_los_pesos);
    double rnd = distribucion(generador);
    for (auto& tr : trans) {
        if (rnd < tr.second)
            return tr.first;
        rnd -= tr.second;
    }
    return estado_actual; // returns current state if no transition is possible
}

std::string CadenaDeMarkov::generar_cadena(char estado_inicial, int longitud) {
    std::string cadena(longitud, ' ');
    cadena[0] = estado_inicial;
    for (int i = 1; i < longitud; ++i) {
        cadena[i] = siguiente_estado(cadena[i - 1]);
    }
    return cadena;
}
