#include "DatosJugador.hpp"

DatosJugador::DatosJugador(){
    this-> nombre_jugador = "ERROR";
    this-> puntaje = 0;
    this-> personaje_usado = PERSONAJE_INVALIDO;
}

DatosJugador::DatosJugador(std::string nombre_jugador, int puntaje, Personaje personaje_usado){
    this->nombre_jugador = nombre_jugador;
    this->puntaje = puntaje;
    this->personaje_usado = personaje_usado;
}

DatosJugador::DatosJugador(Vector<std::string>& elementos){
    this-> nombre_jugador = elementos[0];
    this-> puntaje = std::stoi(elementos[1]);
    this-> personaje_usado = obtener_personaje_desde_texto(elementos[2]);
}

Personaje DatosJugador::obtener_personaje_desde_texto(std::string nombre_personaje){
    Personaje auxiliar = PERSONAJE_INVALIDO;
    if (nombre_personaje == TEXTO_MEGATRON){
        auxiliar = MEGATRON;
    } else if (nombre_personaje == TEXTO_OPTIMUS_PRIME) {
        auxiliar = OPTIMUS_PRIME;
    }
    return auxiliar;
}

int DatosJugador::obtener_puntaje() {
    return puntaje;
}

std::string DatosJugador::obtener_personaje_usado() {
    std::string nombre_personaje = "personaje invalido";
    switch (personaje_usado) {
        case MEGATRON:
            nombre_personaje = TEXTO_MEGATRON;
            break;
        case OPTIMUS_PRIME:
            nombre_personaje = TEXTO_OPTIMUS_PRIME;
            break;
        case PERSONAJE_INVALIDO:
            throw ExcepcionDatosJugador(ERROR_PERSONAJE_INVALIDO);
            break;
    }
    return nombre_personaje;
}

std::ostream &operator<<(std::ostream &os, const DatosJugador &datos_jugador) {
    os << datos_jugador.nombre_jugador
    << "," << datos_jugador.puntaje 
    << ",";
    //Problema con const -> Duplicado de codigo no se encontró solución 
    std::string nombre_personaje = "personaje invalido";
    switch (datos_jugador.personaje_usado) {
        case MEGATRON:
            nombre_personaje = TEXTO_MEGATRON;
            break;
        case OPTIMUS_PRIME:
            nombre_personaje = TEXTO_OPTIMUS_PRIME;
            break;
        case PERSONAJE_INVALIDO:
            throw ExcepcionDatosJugador(ERROR_PERSONAJE_INVALIDO);
            break;
    }
    os << nombre_personaje;

    return os;
}
