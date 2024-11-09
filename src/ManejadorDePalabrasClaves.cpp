//
// Created by guille on 9/13/24.
//

#include "ManejadorDePalabrasClaves.hpp"

const std::string ERROR_LIMITE_MAX_ALCANZADO = "Error, no se pudo agregar el elemento, Limite Max alcanzado";

ManejadorDePalabrasClaves::ManejadorDePalabrasClaves() {
    cantidad_palabras_claves = 0;
}

void ManejadorDePalabrasClaves::agregar_palabras_clave(const std::string& palabra) {
    if (cantidad_palabras_claves >= MAX_PALABRAS_CLAVES) {
        throw std::overflow_error(ERROR_LIMITE_MAX_ALCANZADO);
    }
    utilidades.agregar_elemento_a_arreglo(palabras_claves, cantidad_palabras_claves, MAX_PALABRAS_CLAVES, palabra);
}


int ManejadorDePalabrasClaves::buscar_palabras_clave(const std::string& cadena) {
    for (int i = 0; i < cantidad_palabras_claves; i++)  {
        std::string::size_type posicion = cadena.find(palabras_claves[i]);
        if (posicion < cadena.length()) {return i;}
    }
    return -1;
}
