//
// Created by guille on 09/11/24.
//

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include <BovedaCristales.hpp>

#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "Menu.hpp"

class ExcepcionPersonaje : public std::runtime_error {
public:
    ExcepcionPersonaje(std::string mensaje): runtime_error(mensaje) {}

    ExcepcionPersonaje(): runtime_error("") {}

};

class Personaje {
public:
    //Pre:
    //Post: Se crea una instancia del Objeto Personaje con el Protagonista enviado
    Personaje(Protagonista personaje);

    //Pre: -
    //Post: Se genera una respuesta adecuada al mensaje, basada en el personaje actual y su estado.
    void obtener_respuesta(const std::string &mensaje);

    //Pre: -
    //Post: Se genera una sugerencia adecuada para el personaje actual, basada en su estado y objetivos.
    void obtener_sugerencia();

    //Pre: El parámetro indice es un carácter válido que representa un estado del personaje.
    //Post: Se actualiza el estado del personaje.
    void actualizar_estado(const char &indice);

    //Pre: -
    //Post: Devuelve el personaje que está siendo jugable actualmente.
    Protagonista obtener_personaje();

    //Pre: -
    //Post: Equipa un cristal en la boveda del personaje a lo sumo solo podrá tener 20 cristales equipados.
    void equipar_cristal(Cristal cristal);

private:
    OptimusPrime optimus;
    Megatron megatron;
    Protagonista personaje_jugando;
    char indice_estado;
    std::string estado_personaje;
    BovedaCristales cristales_equipados;

    //Pre: -
    //Post: Actualiza el estado_personaje según el índice de estado del mismo.
    void obtener_estados();
};



#endif //PERSONAJE_HPP
