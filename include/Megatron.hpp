#ifndef TP1_2C2024_MEGATRON_HPP
#define TP1_2C2024_MEGATRON_HPP
#include <string>
#include "Utilidades.hpp"

//Estados de Intención.
const std::string MEGATRON_INTENCION_DESPRECIO = "desprecio";
const std::string MEGATRON_INTENCION_MANIPULACION = "manipulacion";
const std::string MEGATRON_INTENCION_AMENAZA = "amenaza";

//Palabras Claves.
const std::string CONTIENE_OPTIMUS_PRIME = "optimus prime";
const std::string CONTIENE_AUTOBOTS_MEGATRON = "autobots";
const std::string CONTIENE_CYBERTRON_MEGATRON = "cybertron";
const std::string CONTIENE_PODER = "poder";
const std::string CONTIENE_ALIADO = "aliado";
const std::string CONTIENE_FUERZA = "fuerza";

//Respuestas a Intención Desprecio.
const std::string DESPRECIO_RESPUESTA_GENERICA = "Eres insignificante.";
const std::string DESPRECIO_RESPUESTA_OPTIMUS_PRIME = "Esos debiles seran aplastados bajo mi yugo.";
const std::string DESPRECIO_RESPUESTA_AUTOBOTS = "Esos debiles seran aplastados bajo mi yugo.";
const std::string DESPRECIO_RESPUESTA_CYBERTRON = "Cybertron sera mio, a cualquier costo.";

//Respuestas a Intencion Manipulación.
const std::string MANIPULACION_RESPUESTA_GENERICA = "Puedo darte lo que buscas, si estas dispuesto a arrodillarte.";
const std::string MANIPULACION_RESPUESTA_PODER = "Unete a mi, y juntos gobernaremos este universo.";
const std::string MANIPULACION_RESPUESTA_ALIADO = "Unete a mi, y juntos gobernaremos este universo.";
const std::string MANIPULACION_RESPUESTA_FUERZA = "Solo el mas fuerte merece sobrevivir.";

//Respuestas a Intencion Amenaza.
const std::string AMENAZA_RESPUESTA_GENERICA_1 = "Atrevete a desafiarme, y conoceras el verdadero terror.";
const std::string AMENAZA_RESPUESTA_GENERICA_2 = "No hay lugar para los debiles en mi imperio.";

//Sugerencia de Fusión según la Intención.
const std::string DESPRECIO_SUGERENCIA_FUSION = "Fusiona cristales comunes para mejorar tus capacidades basicas.";
const std::string MANIPULACION_SUGERENCIA_FUSION = "Fusiona cristales raros para obtener un poder significativo.";
const std::string AMENAZA_SUGERENCIA_FUSION = "Realiza fusiones arriesgadas para obtener una ventaja poderosa.";

enum EstadosDeIntencion {
    DESPRECIO,
    MANIPULACION,
    AMENAZA
};

class Megatron {
public:
    Megatron();
    //Pre:-
    //Post: Megatron responde según su estado de intención (Desprecio-Manipulación-Amenaza) y del contenido del mensaje.
    void responder(std::string mensaje);
    //Pre:-
    //Post: Sugiere una función según el estado de intención en el cual se encuentre Megatron (Desprecio-Manipulación-Amenaza).
    void sugerir_fusion();
    //Pre: La intensión debe ser una de estas (Desprecio-Manipulación-Amenaza).
    //Post: Modifica el estado de intención de Megatron según lo especificado.
    void cambiar_intencion(std::string intencion);

private:
    Utilidades utilidades;
    int estado_de_intencion;
};

#endif
