#include "Protagonista.hpp"

const std::string ESTADO_INVALIDO;
const std::string ERROR_ESTADO_INCORRECTO = "Error:: Estado Ínvalido. Intente nuevamente.";
const std::string ERROR_ALCANZO_EL_LIMITE_CRISTALES_EQUIPADOS = "Error:: Alcanzo el limite de cristales equipados ( que es 7 por defecto)";
const size_t TAMANIO_MAXIMO_CRISTALES_EQUIPADOS = 7;


Protagonista::Protagonista(Personaje personaje): cristales_equipados(TAMANIO_MAXIMO_CRISTALES_EQUIPADOS) {
    this->personaje_jugando = personaje;
}

void Protagonista::obtener_respuesta(const std::string &mensaje) {
    if (personaje_jugando == MEGATRON) {    megatron.responder(mensaje);
    }else { optimus.responder(mensaje);}
}

std::string Protagonista::obtener_estado(const char &indice) {
    if (personaje_jugando == MEGATRON) {
        switch (indice) {
            case OPCION_1:
                return  MEGATRON_INTENCION_DESPRECIO;
            case OPCION_2:
                return MEGATRON_INTENCION_MANIPULACION;
            case OPCION_3:
                return MEGATRON_INTENCION_AMENAZA;
            default:
                return ESTADO_INVALIDO;
        }
    }
    switch (indice) {
        case OPCION_1:
            return OPTIMUS_ANIMO_SERENO;
        case OPCION_2:
            return OPTIMUS_ANIMO_DETERMINADO;
        case OPCION_3:
            return OPTIMUS_ANIMO_ENFURECIDO;
        default:
            return  ESTADO_INVALIDO;
    }
}

void Protagonista::obtener_sugerencia() {
    if (personaje_jugando == MEGATRON){ megatron.sugerir_fusion();
    }else { optimus.sugerir_fusion();}
}

void Protagonista::actualizar_estado(const char &indice) {
    if (indice == OPCION_1 || indice == OPCION_2 || indice == OPCION_3) {
        if (personaje_jugando == MEGATRON) {    megatron.cambiar_intencion(obtener_estado(indice));
        }else { optimus.cambiar_animo(obtener_estado(indice));}
    }else {
        throw ExcepcionProtagonista(ERROR_ESTADO_INCORRECTO);
    }
}

Personaje Protagonista::obtener_personaje() { return personaje_jugando;}

void Protagonista::equipar_cristal(Cristal cristal) {
    try{
        cristales_equipados.almacenar_cristal(cristal);
    }catch (ExcepcionBovedaCristales& e){
        throw ExcepcionProtagonista(ERROR_ALCANZO_EL_LIMITE_CRISTALES_EQUIPADOS);
    }
}

void Protagonista::ver_cristales_equipados(){
    try{
        cristales_equipados.mostrar_cristales();
    }catch (ExcepcionVector & e){
        throw ExcepcionProtagonista(e.what());
    }
}

size_t Protagonista::obtener_cantidad_cristales_equipados(){
    return cristales_equipados.tamanio();
}
