//
// Created by guille on 9/13/24.
//

#ifndef MANEJADORDEPALABRASCLAVES_HPP
#define MANEJADORDEPALABRASCLAVES_HPP
#include <iostream>
#include "Utilidades.hpp"

const int MAX_PALABRAS_CLAVES= 10;

class ManejadorDePalabrasClaves {

  public:
    ManejadorDePalabrasClaves();
    //Pre: palabra debe ser una cadena válida y el número total de palabras claves ingresadas debe ser inferior a MAX_PALABRAS_CLAVES
    //Post: Almacena la palabra clave.
    void agregar_palabras_clave(const std::string& palabra);

    //Pre:-
    //Post: Devuelve el índice en el que se encuentra la palabra clave dentro de la cadena o -1 si no tiene ninguna aparición.
    int buscar_palabras_clave(const std::string& cadena);

   private:
    Utilidades utilidades;
    std::string palabras_claves[MAX_PALABRAS_CLAVES];
    int cantidad_palabras_claves;
};


#endif //MANEJADORDEPALABRASCLAVES_HPP
