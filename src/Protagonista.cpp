#include "Protagonista.hpp"

const std::string ESTADO_INVALIDO;
const std::string ERROR_ESTADO_INCORRECTO = "Error:: Estado Ínvalido. Intente nuevamente.";
const std::string ERROR_BOVEDA_CRISTALES_EQUIPADOS_VACIA = "Error:: La Bóveda de Cristales Equipados esta vaciá";
const std::string ERROR_ALCANZO_EL_LIMITE_CRISTALES_EQUIPADOS = "Error:: Alcanzo el limite de cristales equipados(TAMANIO_MAXIMO_CRISTALES_EQUIPADOS = 7)";
const size_t TAMANIO_MAXIMO_CRISTALES_EQUIPADOS = 7;


Protagonista::Protagonista(Personaje personaje): indice_estado('0'), cristales_equipados(TAMANIO_MAXIMO_CRISTALES_EQUIPADOS) {
    this->personaje_jugando = personaje;
}

void Protagonista::obtener_respuesta(const std::string &mensaje) {
    if (personaje_jugando == MEGATRON) {
        megatron.responder(mensaje);
    }else {
        optimus.responder(mensaje);
    }
}

void Protagonista::obtener_estados() {
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

void Protagonista::obtener_sugerencia() {
    if (personaje_jugando == MEGATRON){
        megatron.sugerir_fusion();
    }else {
        optimus.sugerir_fusion();
    }
}

void Protagonista::actualizar_estado(const char &indice) {
    indice_estado = indice;
    obtener_estados();
    if (indice_estado == '1' || indice_estado == '2' || indice_estado == '3') {
        if (personaje_jugando == MEGATRON) {
            megatron.cambiar_intencion(estado_personaje);
        }else {
            optimus.cambiar_animo(estado_personaje);
        }
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
        throw ExcepcionProtagonista(ERROR_BOVEDA_CRISTALES_EQUIPADOS_VACIA);
    }
}

size_t Protagonista::obtener_cantidad_cristales_equipados(){
    return cristales_equipados.tamanio();
}
