//
// Created by guille on 11/20/24.
//

#ifndef PROTAGONISTA_HPP
#define PROTAGONISTA_HPP

#include <BovedaCristales.hpp>
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "Transformers.hpp"

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
    //Post: Devuelve el transformer que esta usando el Protagonista
    Transformers obtener_transformer_principal();

    //Pre: -
    //Post: Equipa un cristal en la boveda del personaje a lo sumo solo podrá tener 7 cristales equipados.
    void equipar_cristal(Cristal cristal);

    //Pre:
    //Post: Muestra los cristales con el que se encuentra equipados el Protagonista.
    void ver_cristales_equipados();

    //Pre:-
    //Post: Devuelve la cantidad de Cristales equipados.
    size_t obtener_cantidad_cristales_equipados();

private:
    OptimusPrime optimus;
    Megatron megatron;
    Personaje personaje_jugando;
    BovedaCristales cristales_equipados;
    Transformers transformer_principal;

    //Pre: -
    //Post: Devuelve el estado en formato cadena teniendo en cuenta el índice suministrado.
    std::string obtener_estado(const char &indice);
};


#endif //PROTAGONISTA_HPP
