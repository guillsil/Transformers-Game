//
// Created by guille on 9/13/24.
//

#include "ManejadorDeMensajes.hpp"


ManejadorDeMensajes::ManejadorDeMensajes(ManejadorDePalabrasClaves& manejador_palabras,
    ManejadorDeRespuestas& manejador_respuestas): manejador_palabras(manejador_palabras), manejador_respuestas(manejador_respuestas), primera_palabra_clave_hallada(-1) {}

void ManejadorDeMensajes::procesar_mensajes(const std::string &mensaje) {
    primera_palabra_clave_hallada = manejador_palabras.buscar_palabras_clave(mensaje);
}

void ManejadorDeMensajes::mostrar_mensajes(const TipoDeRespuesta tipo) {
    switch (tipo) {
        case POR_PALABRA_CLAVE:
            if (primera_palabra_clave_hallada < 0) {
                std::cout << manejador_respuestas.obtener_respuesta_por_indice(0);

            } else {
                std::cout << manejador_respuestas.obtener_respuesta_por_indice(primera_palabra_clave_hallada+1);;
            }
            break;
        case ALEATOREAMENTE:
            std::cout << manejador_respuestas.obtener_respuesta_random();
    }
}
