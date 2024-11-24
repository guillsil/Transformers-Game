//Alex Fariña 22/11/2024

#ifndef COMBATES_USUARIO_HPP
#define COMBATES_USUARIO_HPP
#include "Transformers.hpp"
#include "Vector.hpp"
#include "SimulacionCombate.hpp"
#include "GeneradorCombates.hpp"

class CombatesUsuario {
private:
    //Atributos
    size_t puntos_partida;
    SimulacionCombate simulacion_combate;
    GeneradorCombates generador_combate;

    //Metodos privados

    //Pre:-
    //Post:
    //Segun el resultado_combate y esta_transformado suma y/o resta puntos a puntos_partida
    void establecer_puntaje_combate(Resultado_combate resultado_combate, bool esta_transformado);

    //pre:-
    //post:
    //Maneja la parte repetitiva en los combates:
    //--Solicitud de si el personaje_principal estara o no transformado
    //--Mostrando el resultado del enfrentamiento y los puntos obtenidos/perdidos
    void realizar_enfrentamiento();

    //pre: 
    //debemos encontrarnos en el ultimo encuentro de simulacion_combate
    //post:
    //Se encarga de la interacion con el usuario en la batalla final (ultimo encuentro)
    void batalla_jefe_final();

    //pre: 
    //debemos encontrarnos en un encuentro distinto al ultimo en simulacion_combate
    //post:
    //Se encarga de la interacion con el usuario en las batallas dentro de los encuentros intermedios con transformers enemigos
    void batalla_generica();

    //pre:-
    //post:
    //Se encarga de la interaccion con el usuario al toparse con un transformer de la misma faccion que su personaje principal
    void encuentro_aliado();

    //pre:-
    //post:
    //Se encarga de la interaccion con el usuario y el generador de combates
    //Mostrando el mapa de posibles recorridos
    //Mostrando el la secuencia de menor gasto y el peso de esta
    void gestion_generador_combate();

    //Pre:-
    //Post:
    //Se encarga de la interaccion entre el usuario y el proceso de encuentros y combates 
    //establecidos en la secuencia de combates minima
    void gestion_simulacion_batalla();

public:
    //pre:
    //El personaje principal debe ser "Optimus Prime" o "Megatron"
    //post:
    //Constructor
    CombatesUsuario(Transformers& personaje_principal, Vector<Transformers>& transformers_secundarios);

    //Destructor
    ~CombatesUsuario();

    //Pre:-
    //Post:
    //Realiza la interacion con el usuario al proceso de combates: mapa de combates, secuencia minima, y proceso e interacion de batallas.
    void iniciar_partida_combates();

    //pre:-
    //post:
    //Devuelve el puntaje, si no se llama previamente a iniciar_partida_combates() siempre devolvera 0
    //Si se llama a iniciar_partida_combates() devolvera el puntaje obtenido en la partida
    size_t obtener_puntaje();
};

#endif