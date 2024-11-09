#ifndef TP1_2C2024_OPTIMUS_PRIME_HPP
#define TP1_2C2024_OPTIMUS_PRIME_HPP
#include <string>

#include "Utilidades.hpp"

//Estados de Animos.
const std::string OPTIMUS_ANIMO_SERENO = "sereno";
const std::string OPTIMUS_ANIMO_DETERMINADO = "determinado";
const std::string OPTIMUS_ANIMO_ENFURECIDO = "enfurecido";

//Palabras Claves.
const std::string CONTIENE_MEGATRONS = "megatron";
const std::string CONTIENE_DESEPTICONS = "decepticons";
const std::string CONTIENE_AUTOBOTS = "autobots";
const std::string CONTIENE_CYBERTRON = "cybertron";

//Respuestas a Estado Sereno.
const std::string SERENO_RESPUESTA_GENERICA = "En que puedo ayudarte, humano?";
const std::string SERENO_RESPUESTA_MEGATRON = "La paz siempre es nuestra prioridad, pero no dudaremos en defendernos.";
const std::string SERENO_RESPUESTA_DECEPTICONS = "La paz siempre es nuestra prioridad, pero no dudaremos en defendernos.";
const std::string SERENO_RESPUESTA_AUTOBOTS = "Los Autobots estan aqui para proteger a todos los seres vivos.";
const std::string SERENO_RESPUESTA_CYBERTRON = "Cybertron es nuestro hogar, pero nuestra mision esta aqui.";

//Respuestas a Estado Determinado.
const std::string DETERMINADO_RESPUESTA_GENERICA = "Nuestra lucha es por la libertad de todos los seres.";
const std::string DETERMINADO_RESPUESTA_MEGATRON = "Megatron sera detenido. No hay alternativa.";
const std::string DETERMINADO_RESPUESTA_DECEPTICONS = "Megatron sera detenido. No hay alternativa.";
const std::string DETERMINADO_RESPUESTA_AUTOBOTS = "Los Autobots son la luz en medio de la oscuridad.";
const std::string DETERMINADO_RESPUESTA_CYBERTRON = "Cybertron sobrevivira, como lo hemos hecho antes.";

//Respuestas a Estado Enfurecido.
const std::string ENFURECIDO_RESPUESTA_GENERICA_1 = "No tengo tiempo para estas trivialidades.";
const std::string ENFURECIDO_RESPUESTA_GENERICA_2 = "La batalla es inminente. Preparate.";

//Sujerencia de Fusión según un estado de ánimo.
const std::string SERENO_SUGERENCIA_FUSION = "Te recomiendo fusionar cristales comunes para comenzar a mejorar tu arsenal.";
const std::string DETERMINADO_SUGERENCIA_FUSION = "Te sugiero fusionar cristales raros para prepararte para la batalla.";
const std::string ENFURECIDO_SUGERENCIA_FUSION = "Fusiona cristales de alto riesgo para obtener una ventaja decisiva.";

enum EstadoDeAnimo {
    SERENO,
    DETERMINADO,
    ENFURECIDO
};

class OptimusPrime {
public:
    OptimusPrime();
    //Pre:-
    //Post: Optimus responde según su estado de ánimo (Sereno-Determinado-Enfurecido) y del contenido del mensaje.
    void responder(std::string mensaje);
    //Pre:-
    //Post: Sugiere una función según el estado de ánimo en el cual se encuentre Optimus (Sereno-Determinado-Enfurecido).
    void sugerir_fusion();
    //Pre: El ánimo debe ser uno de estos (Sereno-Determinado-Enfurecido).
    //Post: Modifica el estado de ánimo de Optimus según lo especificado.
    void cambiar_animo(std::string animo);

private:
    Utilidades utilidades;
    int estado_de_animo;
};

#endif
