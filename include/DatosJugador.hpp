#ifndef DATOSJUGADOR_HPP
#define DATOSJUGADOR_HPP
#include <iostream>
#include <string>
#include "Menu.hpp" //Preguntar si se puede cambiar a DatosJugador

class ExcepcionDatosJugador : public std::runtime_error {
public:
    ExcepcionDatosJugador(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionDatosJugador(): runtime_error("") {
    }
};

const std::string TEXTO_MEGATRON = "Megatron";
const std::string TEXTO_OPTIMUS_PRIME = "Optimus Prime";
const std::string ERROR_PERSONAJE_INVALIDO = "ERROR:: Personaje principal invalido";

class DatosJugador {
private:
    std::string nombre_jugador;
    int puntaje;
    Personaje personaje_usado;

    //Pre:
    //Post:
    Personaje obtener_personaje_desde_texto(std::string nombre_personaje);

    //Pre:
    //Post:
    std::string obtener_personaje_usado();
public:
    //Constructor para error vector;
    DatosJugador();

    //Constructor
    DatosJugador(std::string nombre_jugador, int puntaje, Personaje personaje_usado);

    //Constructor para archivo
    DatosJugador(std::string nombre_jugador, int puntaje, std::string nombre_personaje);

    //Constructor para salvar un error en control archivo
    DatosJugador(std::string nombre, int f, int d, int v, std::string faccion, std::string vehiculo, std::string transformado);

    //Pre:
    //Post: Devuelve el puntaje del jugador
    int obtener_puntaje();

    // Pre: -
    // Post: Carga la información al stream de salida.
    friend std::ostream& operator<<(std::ostream& os, const DatosJugador& datos_jugador);

    //~DatosJugador();
};

#endif