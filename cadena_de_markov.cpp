//Programa Realizado por Alejandro Rodriguez Larios y Jorge Salgado Miranda

// Incluimos el archivo de cabecera de nuestra clase CadenaDeMarkov.
#include "cadena_de_markov.h"
#include <numeric>
#include <algorithm>

// Método para agregar transiciones a un estado en nuestra Cadena de Markov.
void CadenaDeMarkov::agregar_transicion(char estado, const std::map<char, double>& probabilidades) {
    // Calculamos la suma de las probabilidades de transición.
    double sum = std::accumulate(probabilidades.begin(), probabilidades.end(), 0.0,
                                 [](double value, const std::map<char, double>::value_type& p) { return value + p.second; });

    // Si la suma de las probabilidades no es 1 (permitiendo una pequeña tolerancia), lanzamos una excepción.
    if(std::abs(sum - 1.0) > epsilon) {
        throw std::invalid_argument("Error: Las probabilidades de transición no suman 1.");
    }

    // Si las probabilidades suman 1, entonces asignamos estas probabilidades de transición al estado dado.
    transiciones[estado] = probabilidades;
}

// Método para obtener el siguiente estado dado un estado actual.
char CadenaDeMarkov::siguiente_estado(char estado_actual) {
    // Obtenemos las transiciones para el estado actual.
    std::map<char, double> trans = transiciones[estado_actual];
    double Suma_de_los_pesos = 0;
    // Calculamos la suma de los pesos de las transiciones.
    for(auto& tr : trans) {
        Suma_de_los_pesos += tr.second;
    }
    // Creamos una distribución uniforme con rango [0, Suma_de_los_pesos].
    std::uniform_real_distribution<double> distribucion(0.0, Suma_de_los_pesos);
    // Generamos un número aleatorio en el rango de nuestra distribución.
    double rnd = distribucion(generador);
    // Vamos restando este número por las probabilidades de transición hasta que sea menor que una de ellas.
    // Esa será la transición elegida.
    for (auto& tr : trans) {
        if (rnd < tr.second)
            return tr.first;
        rnd -= tr.second;
    }
    // Si no es posible realizar una transición, devolvemos el estado actual.
    return estado_actual;
}

// Método para generar una cadena de Markov de una cierta longitud, comenzando desde un estado inicial.
std::string CadenaDeMarkov::generar_cadena(char estado_inicial, int longitud) {
    // Creamos una cadena de la longitud deseada, inicialmente llena de espacios.
    std::string cadena(longitud, ' ');
    // El primer estado será nuestro estado inicial.
    cadena[0] = estado_inicial;
    // Para cada siguiente estado en la cadena, utilizamos nuestro método `siguiente_estado` para determinar
    // el próximo estado basado en las probabilidades de transición del estado actual.
    for (int i = 1; i < longitud; ++i) {
        cadena[i] = siguiente_estado(cadena[i - 1]);
    }
    // Devolvemos la cadena generada.
    return cadena;
}
