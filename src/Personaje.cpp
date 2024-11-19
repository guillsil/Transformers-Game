//
// Created by guille on 09/11/24.
//

#include "Personaje.hpp"

const std::string ESTADO_INVALIDO;
const std::string ERROR_ESTADO_INCORRECTO = "Error: Estado Ínvalido. Intente nuevamente.";
const size_t TAMANIO_MAXIMO_CRISTALES_EQUIPADOS = 7;

Personaje::Personaje(Protagonista personaje): indice_estado('0'), cristales_equipados(TAMANIO_MAXIMO_CRISTALES_EQUIPADOS) {
  this->personaje_jugando = personaje;
}


void Personaje::obtener_respuesta(const std::string &mensaje) {
    if (personaje_jugando == MEGATRON) {
        megatron.responder(mensaje);
    }else {
        optimus.responder(mensaje);
    }
}

void Personaje::obtener_estados() {
    if (personaje_jugando == MEGATRON) {
        switch (indice_estado) {
            case OPCION_1:  estado_personaje = MEGATRON_INTENCION_DESPRECIO;
            case OPCION_2:  estado_personaje = MEGATRON_INTENCION_MANIPULACION;
            case OPCION_3:  estado_personaje = MEGATRON_INTENCION_AMENAZA;
            default: estado_personaje = ESTADO_INVALIDO;
        }
    }
    switch (indice_estado) {
        case OPCION_1:  estado_personaje = OPTIMUS_ANIMO_SERENO;
        case OPCION_2:  estado_personaje = OPTIMUS_ANIMO_DETERMINADO;
        case OPCION_3:  estado_personaje = OPTIMUS_ANIMO_ENFURECIDO;
        default: estado_personaje = ESTADO_INVALIDO;
    }
}

void Personaje::obtener_sugerencia() {
    if (personaje_jugando == MEGATRON){
        megatron.sugerir_fusion();
    }else {
        optimus.sugerir_fusion();
    }
}

void Personaje::actualizar_estado(const char &indice) {
    indice_estado = indice;
    obtener_estados();
    if (indice_estado == '1' || indice_estado == '2' || indice_estado == '3') {
        if (personaje_jugando == MEGATRON) {
            megatron.cambiar_intencion(estado_personaje);
        }else {
            optimus.cambiar_animo(estado_personaje);
        }
    }else {
        throw ExcepcionPersonaje(ERROR_ESTADO_INCORRECTO);
    }
}

Protagonista Personaje::obtener_personaje() { return personaje_jugando;}

void Personaje::equipar_cristal(Cristal cristal) {
    cristales_equipados.almacenar_cristal(cristal);
}
