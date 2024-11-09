//
// Created by guille on 9/18/24.
//

#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP
#include <iostream>


class Utilidades {
public:
    //Pre: La cadena debe ser no (vaciá).
    //Post: Transforma todos los caracteres de la cadena a minuscula.
    void convertir_a_minuscula(std::string &cadena);
    //Pre: Él (inicio) debe ser menor que (fin).
    //Post: Devuelve un número aleatorio entre él (inicio) y (fin).
    int generar_numero_aleatorio(const int &inicio, const int &fin);
    //Pre: La (cantidad) debe ser menor que (max).
    //Post: El elemento es agregado al arreglo siempre y cuando haya espacio. Devuelve False si no se pudo agregar el elemento.
    //NOTA: El número se genera en tipo double y luego se castea a entero. Si no hago esto no se genera tan aleatoriamente el número.
    bool agregar_elemento_a_arreglo(std::string arreglo[], int &cantidad,const int &max, const std::string &elemento);
};
#endif //UTILIDADES_HPP
