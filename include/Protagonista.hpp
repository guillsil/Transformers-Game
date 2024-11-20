//
// Created by guille on 11/20/24.
//

#ifndef PROTAGONISTA_HPP
#define PROTAGONISTA_HPP

#include <BovedaCristales.hpp>
#include "OptimusPrime.hpp"
#include "Megatron.hpp"

class ExcepcionProtagonista : public std::runtime_error {
public:
    ExcepcionProtagonista(std::string mensaje): runtime_error(mensaje) {}

    ExcepcionProtagonista(): runtime_error("") {}

};

class Protagonista {
public:
    //Pre:
    //Post: Se crea una instancia del Objeto Personaje con el Protagonista enviado
    Protagonista(Personaje personaje);

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
    Personaje obtener_personaje();

    //Pre: -
    //Post: Equipa un cristal en la boveda del personaje a lo sumo solo podrá tener 20 cristales equipados.
    void equipar_cristal(Cristal cristal);

private:
    OptimusPrime optimus;
    Megatron megatron;
    Personaje personaje_jugando;
    char indice_estado;
    std::string estado_personaje;
    BovedaCristales cristales_equipados;

    //Pre: -
    //Post: Actualiza el estado_personaje según el índice de estado del mismo.
    void obtener_estados();
};


#endif //PROTAGONISTA_HPP
