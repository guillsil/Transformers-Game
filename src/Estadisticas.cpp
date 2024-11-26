//
// Created by guille on 10/16/24.
//

#include "../include/Estadisticas.hpp"
const int FACTOR_BONIFICACION = 10;


Estadisticas::Estadisticas(const size_t &fuerza, const size_t &defensa, const size_t &velocidad) {
    this->fuerza = fuerza;
    this->defensa = defensa;
    this->velocidad = velocidad;
    this->poder = fuerza + defensa + velocidad;
}

void Estadisticas::aplicar_bonificacion() {
    fuerza += FACTOR_BONIFICACION;
    defensa += FACTOR_BONIFICACION;
    velocidad += FACTOR_BONIFICACION;
    poder += FACTOR_BONIFICACION * 3;
}

size_t Estadisticas::obtener_fuerza() {return fuerza;}

size_t Estadisticas::obtener_defensa() {return defensa;}

size_t Estadisticas::obtener_velocidad() {return velocidad;}

size_t Estadisticas::obtener_poder() { return poder;}

Estadisticas& Estadisticas::operator=(const Estadisticas &otras_estadisticas){
    this-> fuerza = otras_estadisticas.fuerza;
    this-> defensa = otras_estadisticas.defensa;
    this-> velocidad = otras_estadisticas.velocidad;
    this-> poder = fuerza + defensa + velocidad;
}

void Estadisticas::mostrar() {
    menu.mostrar_estadisticas(std::to_string(fuerza), std::to_string(defensa), std::to_string(velocidad));
}

std::ostream &operator<<(std::ostream &os, const Estadisticas &estadisticas){
    os << estadisticas.fuerza 
       << "," << estadisticas.defensa
       << "," << estadisticas.velocidad;
    return os;
}
