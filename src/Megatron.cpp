#include "Megatron.hpp"
#include <iostream>
#include "ManejadorDeMensajes.hpp"
#include "ManejadorDeRespuestas.hpp"
#include "ManejadorDePalabrasClaves.hpp"

Megatron::Megatron() {
    estado_de_intencion = DESPRECIO;
}

void Megatron::responder(std::string mensaje) {
    utilidades.convertir_a_minuscula(mensaje);
    ManejadorDePalabrasClaves palabras_claves;
    ManejadorDeRespuestas respuestas;
    ManejadorDeMensajes controlador_de_mensajes(palabras_claves, respuestas);

    respuestas.agregar_respuesta_random(AMENAZA_RESPUESTA_GENERICA_1);
    respuestas.agregar_respuesta_random(AMENAZA_RESPUESTA_GENERICA_2);

    if (estado_de_intencion == DESPRECIO) {
        palabras_claves.agregar_palabras_clave(CONTIENE_OPTIMUS_PRIME);
        palabras_claves.agregar_palabras_clave(CONTIENE_AUTOBOTS_MEGATRON);
        palabras_claves.agregar_palabras_clave(CONTIENE_CYBERTRON_MEGATRON);


        respuestas.agregar_respuesta(DESPRECIO_RESPUESTA_GENERICA);
        respuestas.agregar_respuesta(DESPRECIO_RESPUESTA_OPTIMUS_PRIME);
        respuestas.agregar_respuesta(DESPRECIO_RESPUESTA_AUTOBOTS);
        respuestas.agregar_respuesta(DESPRECIO_RESPUESTA_CYBERTRON);

        controlador_de_mensajes.procesar_mensajes(mensaje);
        controlador_de_mensajes.mostrar_mensajes(POR_PALABRA_CLAVE);
    } else if (estado_de_intencion == MANIPULACION) {
        palabras_claves.agregar_palabras_clave(CONTIENE_PODER);
        palabras_claves.agregar_palabras_clave(CONTIENE_ALIADO);
        palabras_claves.agregar_palabras_clave(CONTIENE_FUERZA);

        respuestas.agregar_respuesta(MANIPULACION_RESPUESTA_GENERICA);
        respuestas.agregar_respuesta(MANIPULACION_RESPUESTA_PODER);
        respuestas.agregar_respuesta(MANIPULACION_RESPUESTA_ALIADO);
        respuestas.agregar_respuesta(MANIPULACION_RESPUESTA_FUERZA);

        controlador_de_mensajes.procesar_mensajes(mensaje);
        controlador_de_mensajes.mostrar_mensajes(POR_PALABRA_CLAVE);
    } else {
        controlador_de_mensajes.mostrar_mensajes(ALEATOREAMENTE);
    }
}

void Megatron::sugerir_fusion() {
    if (estado_de_intencion == DESPRECIO) {
        std::cout << DESPRECIO_SUGERENCIA_FUSION;
    } else if (estado_de_intencion == MANIPULACION) {
        std::cout << MANIPULACION_SUGERENCIA_FUSION;
    } else {
        std::cout << AMENAZA_SUGERENCIA_FUSION;
    }
}

void Megatron::cambiar_intencion(std::string intencion) {
    utilidades.convertir_a_minuscula(intencion);
    if (intencion == MEGATRON_INTENCION_DESPRECIO) {
        estado_de_intencion = DESPRECIO;
    } else if (intencion == MEGATRON_INTENCION_MANIPULACION) {
        estado_de_intencion = MANIPULACION;
    } else {
        estado_de_intencion = AMENAZA;
    }
}
