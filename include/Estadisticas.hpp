//
// Created by guille on 10/16/24.
//

#ifndef ESTADISTICAS_HPP
#define ESTADISTICAS_HPP
#include <iostream>
#include "Menu.hpp"


class Estadisticas {
public:
    //Constructor
    //Pre: -
    //Post: Inicializa las estadísticas de fuerza, defensa y velocidad con los valores Suministrados
    Estadisticas(const size_t &fuerza, const size_t &defensa, const size_t &velocidad);

    //Pre: -
    //Post: Aumenta las estadísticas de (fuerza, defensa, velocidad)
    void aplicar_bonificacion();

    //Pre: -
    //Post: Devuelve el valor de fuerza.
    size_t obtener_fuerza();

    //Pre: -
    //Post:Devuelve el valor de defensa.
    size_t obtener_defensa();

    //Pre: -
    //Post: Devuelve el valor de velocidad.
    size_t obtener_velocidad();

    //Pre: -
    //Post: Imprimé por consola las estadísticas (fuerza, defensa, velocidad)
    void mostrar();

private:
    size_t fuerza;
    size_t defensa;
    size_t velocidad;

    Menu menu;
};



#endif //ESTADISTICAS_HPP
