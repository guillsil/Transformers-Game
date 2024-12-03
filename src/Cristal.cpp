#include "Cristal.hpp"
#include <iostream>

const size_t FUERZA_INICIAL_COMUN = 15;
const size_t DEFENSA_INICIAL_COMUN = 15;
const size_t VELOCIDAD_INICIAL_COMUN = 15;
//const int MAX_ESTADISTICA_COMUN = 25; Simbólicamente es este el máximo que puede alcanzar las estadísticas para este nivel de rareza

const size_t FUERZA_INICIAL_RARO = 40;
const size_t DEFENSA_INICIAL_RARO = 40;
const size_t VELOCIDAD_INICIAL_RARO = 40;
// MAX_ESTADISTICA_RARO = 50; Simbólicamente es este el máximo que puede alcanzar las estadísticas para este nivel de rareza

const size_t FUERZA_INICIAL_EPICO = 65;
const size_t DEFENSA_INICIAL_EPICO = 65;
const size_t VELOCIDAD_INICIAL_EPICO = 65;
// MAX_ESTADISTICA_EPICO = 75; Simbólicamente es este el máximo que puede alcanzar las estadísticas para este nivel de rareza

const size_t FUERZA_INICIAL_LEGENDARIO = 90;
const size_t DEFENSA_INICIAL_LEGENDARIO = 90;
const size_t VELOCIDAD_INICIAL_LEGENDARIO = 90;
// MAX_ESTADISTICA_LEGENDARIO = 100; Simbólicamente es este el máximo que puede alcanzar las estadísticas para este nivel de rareza

const std::string COMUN_CADENA = "común";
const std::string RARO_CADENA = "raro";
const std::string EPICO_CADENA = "épico";
const std::string LEGENDARIO_CADENA = "legendario";
const std::string DESCONOCIDO_CADENA = "desconocida";

const int PROBABILIDAD_EXITO_COMUN_A_RARO = 50;
const int PROBABILIDAD_EXITO_RARO_A_EPICO = 30;
const int PROBABILIDAD_EXITO_EPICO_A_LEGENDARIO = 10;
const int PROBABILIDAD_EXITO_INVALIDA = 0;

const int FUERZA_INICIAL_INVALIDA = 0;
const int DEFENSA_INICIAL_INVALIDA = 0;
const int VELOCIDAD_INICIAL_INVALIDA = 0;

Cristal::Cristal(): rareza(COMUN), estadisticas(FUERZA_INICIAL_COMUN, DEFENSA_INICIAL_COMUN, VELOCIDAD_INICIAL_COMUN){
}

Cristal::Cristal(Rareza rareza): rareza(rareza), estadisticas(inicializar_estadisticas()) {}

Cristal::Cristal(const Rareza &rareza, const bool &exito): rareza(rareza), estadisticas(inicializar_estadisticas()) {
    if (exito) {
        estadisticas.aplicar_bonificacion();
    }
}

bool Cristal::operator==(Rareza rareza) {
    return this-> rareza == rareza;
}

Rareza Cristal::obtener_rareza() {
    return this-> rareza;
}

size_t Cristal::obtener_fuerza() {
    return estadisticas.obtener_fuerza();
}

size_t Cristal::obtener_defensa() {
    return estadisticas.obtener_defensa();
}

size_t Cristal::obtener_velocidad() {
    return estadisticas.obtener_velocidad();
}

size_t Cristal::obtener_poder() {
    return estadisticas.obtener_poder();
}

std::string Cristal::convertir_rareza_a_string() {
    switch (rareza) {
        case COMUN:
            return COMUN_CADENA;
        case RARO:
            return RARO_CADENA;
        case EPICO:
            return EPICO_CADENA;
        case LEGENDARIO:
            return LEGENDARIO_CADENA;
        default: return DESCONOCIDO_CADENA;
    }
}

void Cristal::mostrar() {
    menu.mostrar_recuadro_superior();
    menu.mostrar_rareza(convertir_rareza_a_string());
    estadisticas.mostrar();
    menu.mostrar_recuadro_inferior();
}

int Cristal::obtener_porcentaje_exito() {
    switch (rareza) {
        case COMUN: return PROBABILIDAD_EXITO_COMUN_A_RARO;
        case RARO:  return PROBABILIDAD_EXITO_RARO_A_EPICO;
        case EPICO: return PROBABILIDAD_EXITO_EPICO_A_LEGENDARIO;
        default: return PROBABILIDAD_EXITO_INVALIDA;
    }
}

Estadisticas Cristal::inicializar_estadisticas() {
    switch (rareza) {
        case COMUN:
            return Estadisticas(FUERZA_INICIAL_COMUN, DEFENSA_INICIAL_COMUN, VELOCIDAD_INICIAL_COMUN);
        case RARO:
            return Estadisticas(FUERZA_INICIAL_RARO, DEFENSA_INICIAL_RARO, VELOCIDAD_INICIAL_RARO);
        case EPICO:
            return Estadisticas(FUERZA_INICIAL_EPICO, DEFENSA_INICIAL_EPICO, VELOCIDAD_INICIAL_EPICO);
        case LEGENDARIO:
            return Estadisticas(FUERZA_INICIAL_LEGENDARIO, DEFENSA_INICIAL_LEGENDARIO, VELOCIDAD_INICIAL_LEGENDARIO);
        default:
            return Estadisticas(FUERZA_INICIAL_INVALIDA, DEFENSA_INICIAL_INVALIDA, VELOCIDAD_INICIAL_INVALIDA);
    }
}

std::ostream &operator<<(std::ostream &os, const Cristal& cristal){
    switch (cristal.rareza) {
        case COMUN:
            os << COMUN_CADENA; break;
        case RARO:
            os << RARO_CADENA; break;
        case EPICO:
            os << EPICO_CADENA; break;
        case LEGENDARIO:
            os << LEGENDARIO_CADENA; break;
        default: 
            os << DESCONOCIDO_CADENA; break;
    }
    os << "," << cristal.estadisticas;
    return os;
}
