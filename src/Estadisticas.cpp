//
// Created by guille on 10/16/24.
//

#include "../include/Estadisticas.hpp"
const int FACTOR_BONIFICACION = 10;


Estadisticas::Estadisticas(const size_t &fuerza, const size_t &defensa, const size_t &velocidad) {
    this->fuerza = fuerza;
    this->defensa = defensa;
    this->velocidad = velocidad;
    actualizar_poder();
}

void Estadisticas::aplicar_bonificacion() {
    fuerza += FACTOR_BONIFICACION;
    defensa += FACTOR_BONIFICACION;
    velocidad += FACTOR_BONIFICACION;
    poder += FACTOR_BONIFICACION * 3;
}

void Estadisticas::aplicar_bonificacion_distintas(int bono_fuerza, int bono_defensa, int bono_velocidad){
    this->fuerza = fuerza + bono_fuerza;
    this->defensa = defensa + bono_defensa;
    this->velocidad = velocidad + bono_velocidad; 
    actualizar_poder();
}

size_t Estadisticas::obtener_fuerza() {return fuerza;}

size_t Estadisticas::obtener_defensa() {return defensa;}

size_t Estadisticas::obtener_velocidad() {return velocidad;}

size_t Estadisticas::obtener_poder() { return poder;}

void Estadisticas::actualizar_poder(){
    this-> poder = fuerza + defensa + velocidad;  
}

Estadisticas& Estadisticas::operator=(const Estadisticas &otras_estadisticas){
    if (this != &otras_estadisticas){
        this-> fuerza = otras_estadisticas.fuerza;
        this-> defensa = otras_estadisticas.defensa;
        this-> velocidad = otras_estadisticas.velocidad;
        actualizar_poder();
    }    
    return *this;
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
