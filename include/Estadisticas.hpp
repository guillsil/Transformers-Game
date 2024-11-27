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
    //Post: Devuelve el valor del poder.
    size_t obtener_poder();

    //Pre: -
    //Post: Actualiza el poder total
    void actualizar_poder();

    //Pre: Los numeros pueden ser positivos o negativos. Depende de si se desea sumar o restar;
    //Post: Suma las bonoficaciones pasadas a las estadisticas preexistentes
    void aplicar_bonificacion_distintas(int bono_fuerza, int bono_defensa, int bono_velocidad);

    //Pre:
    //Post: Copia las otras estadisticas en las estadisticas que llama al operador;
    Estadisticas& operator=(const Estadisticas &otras_estadisticas);

    //Pre: -
    //Post: Imprimé por consola las estadísticas (fuerza, defensa, velocidad)
    void mostrar();

    // Pre: -
    // Post: Carga la información al stream de salida.
    friend std::ostream& operator<<(std::ostream& os, const Estadisticas& estadisticas);


private:
    size_t fuerza;
    size_t defensa;
    size_t velocidad;
    size_t poder;
    Menu menu;
};



#endif //ESTADISTICAS_HPP
