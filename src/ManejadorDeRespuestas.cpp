//
// Created by guille on 9/13/24.
//

#include "ManejadorDeRespuestas.hpp"

const std::string ERROR_LIMITE_MAX_ALCANZADO = "Error, no se pudo agregar el elemento, Limite Max alcanzado";
const std::string ERROR_RESPUESTAS_NO_DISPONIBLES = "Error, No hay respuetas randoms Disponible";

ManejadorDeRespuestas::ManejadorDeRespuestas() {
    cantidad_respuestas = 0;
    cantidad_respuestas_random = 0;
}

void ManejadorDeRespuestas::agregar_respuesta(const std::string& respuesta) {
    if (cantidad_respuestas >= MAX_RESPUESTAS) {
        throw std::overflow_error(ERROR_LIMITE_MAX_ALCANZADO);
    }
    bool resultado = utilidades.agregar_elemento_a_arreglo(respuestas, cantidad_respuestas, MAX_RESPUESTAS, respuesta);
    if (!resultado) {
        throw std::overflow_error(ERROR_LIMITE_MAX_ALCANZADO);
    }
}

void ManejadorDeRespuestas::agregar_respuesta_random(const std::string& respuesta) {
    if (cantidad_respuestas_random >= MAX_RESPUESTAS) {
        throw std::overflow_error(ERROR_LIMITE_MAX_ALCANZADO);
    }
    utilidades.agregar_elemento_a_arreglo(respuestas_random, cantidad_respuestas_random, MAX_RESPUESTAS, respuesta);
}

std::string ManejadorDeRespuestas::obtener_respuesta_por_indice(const int &indice) {
    if (cantidad_respuestas > 0) {
        return respuestas[indice];
    }
    throw std::runtime_error(ERROR_RESPUESTAS_NO_DISPONIBLES);
}

std::string ManejadorDeRespuestas::obtener_respuesta_random() {
    if (cantidad_respuestas_random > 0) {
        const int indice_aleatorio = utilidades.generar_numero_aleatorio(0, cantidad_respuestas_random);
        return  respuestas_random[indice_aleatorio];
    }
    throw std::runtime_error(ERROR_RESPUESTAS_NO_DISPONIBLES);
}
