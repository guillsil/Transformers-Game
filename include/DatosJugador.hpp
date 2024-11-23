#ifndef DATOSJUGADOR_HPP
#define DATOSJUGADOR_HPP
#include <iostream>
#include <string>
//#include donde esté el enum personaje

class DatosJugador {
private:
    std::string nombre_jugador;
    int puntaje;
    //Personaje personaje_usado; //(o es mejor usar protagonista?) Protagonista personaje_usado;
public:
    //Constructor
    DatosJugador(std::string nombre_jugador, int puntaje/*, Protagonista o Personaje personaje_usado */);

    // //No se si es necesario aún
    // void actualizar_puntaje(int nuevo_puntaje);

    // Pre: -
    // Post: Carga la información al stream de salida.
    friend std::ostream& operator<<(std::ostream& os, const DatosJugador& datos_jugador);

    //~DatosJugador();
};

#endif