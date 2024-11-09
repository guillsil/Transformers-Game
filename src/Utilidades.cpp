//
// Created by guille on 9/18/24.
//
#include <random>
#include "Utilidades.hpp"

void Utilidades::convertir_a_minuscula(std::string &cadena) {
    for (char& caracter : cadena) {
        caracter = static_cast<char>(std::tolower(static_cast<unsigned char>(caracter)));
    }
}

int Utilidades::generar_numero_aleatorio(const int &inicio,const int &fin) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(inicio, fin);
    return static_cast<int>(dis(gen));
}

bool Utilidades::agregar_elemento_a_arreglo(std::string arreglo[], int &cantidad, const int &max, const std::string &elemento) {
    if (cantidad < max) {
        arreglo[cantidad] = elemento;
        cantidad++;
        return true;
    }
    return false;
}
