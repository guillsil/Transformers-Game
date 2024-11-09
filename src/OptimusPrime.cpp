#include "OptimusPrime.hpp"
#include <iostream>
#include "ManejadorDeMensajes.hpp"
#include "ManejadorDeRespuestas.hpp"
#include "ManejadorDePalabrasClaves.hpp"

OptimusPrime::OptimusPrime() {
    estado_de_animo = SERENO;
}

void OptimusPrime::responder(std::string mensaje) {
    utilidades.convertir_a_minuscula(mensaje);
    ManejadorDePalabrasClaves palabras_claves;
    ManejadorDeRespuestas respuestas;
    ManejadorDeMensajes controlador_de_mensajes(palabras_claves, respuestas);

    palabras_claves.agregar_palabras_clave(CONTIENE_MEGATRONS);
    palabras_claves.agregar_palabras_clave(CONTIENE_DESEPTICONS);
    palabras_claves.agregar_palabras_clave(CONTIENE_AUTOBOTS);
    palabras_claves.agregar_palabras_clave(CONTIENE_CYBERTRON);
    respuestas.agregar_respuesta_random(ENFURECIDO_RESPUESTA_GENERICA_1);
    respuestas.agregar_respuesta_random(ENFURECIDO_RESPUESTA_GENERICA_2);

    controlador_de_mensajes.procesar_mensajes(mensaje);
    if (estado_de_animo == SERENO) {
        respuestas.agregar_respuesta(SERENO_RESPUESTA_GENERICA);
        respuestas.agregar_respuesta(SERENO_RESPUESTA_MEGATRON);
        respuestas.agregar_respuesta(SERENO_RESPUESTA_DECEPTICONS);
        respuestas.agregar_respuesta(SERENO_RESPUESTA_AUTOBOTS);
        respuestas.agregar_respuesta(SERENO_RESPUESTA_CYBERTRON);
        controlador_de_mensajes.mostrar_mensajes(POR_PALABRA_CLAVE);
    }else if (estado_de_animo == DETERMINADO) {
        respuestas.agregar_respuesta(DETERMINADO_RESPUESTA_GENERICA);
        respuestas.agregar_respuesta(DETERMINADO_RESPUESTA_MEGATRON);
        respuestas.agregar_respuesta(DETERMINADO_RESPUESTA_DECEPTICONS);
        respuestas.agregar_respuesta(DETERMINADO_RESPUESTA_AUTOBOTS);
        respuestas.agregar_respuesta(DETERMINADO_RESPUESTA_CYBERTRON);
        controlador_de_mensajes.mostrar_mensajes(POR_PALABRA_CLAVE);
    }else {
        controlador_de_mensajes.mostrar_mensajes(ALEATOREAMENTE);
    }
}

void OptimusPrime::sugerir_fusion() {
    if (estado_de_animo == SERENO) {
        std::cout <<SERENO_SUGERENCIA_FUSION;
    }else if (estado_de_animo == DETERMINADO) {
        std::cout << DETERMINADO_SUGERENCIA_FUSION;
    }else {
        std::cout << ENFURECIDO_SUGERENCIA_FUSION;
    }
}

void OptimusPrime::cambiar_animo(std::string animo) {
    utilidades.convertir_a_minuscula(animo);
    if (animo == OPTIMUS_ANIMO_SERENO) {
        estado_de_animo = SERENO;
    }else if (animo == OPTIMUS_ANIMO_DETERMINADO) {
        estado_de_animo = DETERMINADO;
    }else {
        estado_de_animo = ENFURECIDO;
    }
}