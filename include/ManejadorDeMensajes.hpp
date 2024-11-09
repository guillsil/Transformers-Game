//
// Created by guille on 9/13/24.
//

#ifndef MANEJADORDEMENSAJES_HPP
#define MANEJADORDEMENSAJES_HPP
#include "ManejadorDePalabrasClaves.hpp"
#include "ManejadorDeRespuestas.hpp"

enum TipoDeRespuesta {
    POR_PALABRA_CLAVE,
    ALEATOREAMENTE
};

class ManejadorDeMensajes {

public:
    ManejadorDeMensajes(ManejadorDePalabrasClaves& manejador_palabras, ManejadorDeRespuestas& manejador_respuestas);
    //Pre:-
    //Post:Busca en el mensaje si hay alguna coincidencia con las palabras claves.
    void procesar_mensajes(const std::string& mensaje);
    //Pre: Tipo debe ser un valor válido de TipoDeRespuesta.
    //Post: Muestra la respuesta correspondiente, según el TipoDeRespuesta.
    void mostrar_mensajes(TipoDeRespuesta tipo);

private:
    ManejadorDePalabrasClaves& manejador_palabras;
    ManejadorDeRespuestas& manejador_respuestas;
    int primera_palabra_clave_hallada;
};


#endif //MANEJADORDEMENSAJES_HPP
