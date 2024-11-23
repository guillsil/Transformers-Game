#include "DatosJugador.hpp"

DatosJugador::DatosJugador(std::string nombre_jugador, int puntaje/*, Protagonista o Personaje personaje_usado */){
    this->nombre_jugador = nombre_jugador;
    this->puntaje = puntaje;
}

// void DatosJugador::actualizar_puntaje(int nuevo_puntaje){
//     this->puntaje = nuevo_puntaje;
// }

std::ostream &operator<<(std::ostream &os, const DatosJugador &datos_jugador) {
    os << datos_jugador.nombre_jugador
    << "," << datos_jugador.puntaje /*
    << "," << datos_jugador.personje_usado */;            
    return os;
}
