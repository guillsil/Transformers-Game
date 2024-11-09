#ifndef CRISTAL_HPP
#define CRISTAL_HPP
#include <Estadisticas.hpp>
#include <string>
#include "Menu.hpp"

enum Rareza {
    COMUN,
    RARO,
    EPICO,
    LEGENDARIO,
};

class Cristal {
public:
    //Constructor
    //Pre: -
    //Post: Se crea un cristal con la rareza por default que es COMUN junto a sus estadísticas.
    Cristal();

    //Constructor que recibe un atributo de Rareza
    //Pre:-
    //Post:
    Cristal(Rareza rareza);

    //Constructor que recibe un atributo de Rareza y un booleno (exito)
    //Pre: -
    //Post: Crea un cristal con la rareza suministrada y completa las estadísticas según el valor de (exit)
    //Si es True: lo completa aplicando una bonificación de (10 puntos) en las mismas.
    //Si es False: lo completa con valores por default.
    Cristal(const Rareza &rareza, const bool &exito);

    // Operador para comprobar si dos cristales tienen la misma rareza.
    //Pre:-
    //Post: Devuelve True si la rareza del cristal es igual a la suministrada.
    bool operator==(Rareza rareza);

    //Pre: -
    //Post: Devuelve la rareza del cristal.
    Rareza obtener_rareza();

    //Pre: -
    //Post: Devuelve la estadística de fuerza que tiene el cristal.
    size_t obtener_fuerza();

    //Pre: -
    //Post: Devuelve la estadística de Defensa que tiene el cristal.
    size_t obtener_defensa();

    //Pre: -
    //Post: Devuelve la estadística de Velocidad que tiene el cristal.
    size_t obtener_velocidad();

    //Pre: -
    //Post: Devuelve la rareza del cristal como una cadena.
    std::string convertir_rareza_a_string();

    //Pre: -
    //Post: Devuelve el poder de un cristal que es la suma de sus Estadísticas es decir es la suma entre la fuerza, velocidad y defensa.
    size_t obtener_poder();

    //Pre: -
    //Post: Imprime tanto la rareza del cristal así como sus estadísticas por consola.
    void mostrar();

    //Pre: Si la rareza es LEGENDARIA, no se podrá fusionar a uno de mejor nivel por tal motivo, si la rareza del cristal es Legendaria se devolverá la PROBABILIDAD_EXITO_INVALIDA.
    //Post: Devuelve el porcentaje de éxito que tiene el cristal para poder fusionar a uno de mejor nivel.
    int obtener_porcentaje_exito();

private:
    //Rareza del Cristal
    Rareza rareza;

    Menu menu;

    //Estadistica de un cristal
    Estadisticas estadisticas;

    //Pre: -
    //Post: Completa las estadísticas del cristal según su rareza.
    //Comun: (FUERZA_INICIAL_COMUN, DEFENSA_INICIAL_COMUN, VELOCIDAD_INICIAL_COMUN)
    //Raro: (FUERZA_INICIAL_RARO, DEFENSA_INICIAL_RARO, VELOCIDAD_INICIAL_RARO)
    //Epico:(FUERZA_INICIAL_EPICO, DEFENSA_INICIAL_EPICO, VELOCIDAD_INICIAL_EPICO)
    //Legendario: (FUERZA_INICIAL_LEGENDARIO, DEFENSA_INICIAL_LEGENDARIO, VELOCIDAD_INICIAL_LEGENDARIO)
    //EstadisticaInvalida: (FUERZA_INICIAL_INVALIDA, DEFENSA_INICIAL_INVALIDA, VELOCIDAD_INICIAL_INVALIDA) (NUNCA ENTRARA AQUÍ , POR LO CUAL NO HARE UNA VERIFICACIÓN YA QUE , SI A LA HORA DE CREAR UN CRISTAL NO SE LE PASA UN VALOR CORRECTO DE RAREZA NO SE SE PODRÁ CREAR DIRECTAMENTE.)
    Estadisticas inicializar_estadisticas();
};

#endif
