//Alex Fariña 21/11/2024

#ifndef SIMULACION_COMBATE_HPP
#define SIMULACION_COMBATE_HPP

#include "Transformers.hpp"
#include "Vector.hpp"

enum Resultado_combate {
    VICTORIA,
    DERRROTA,
    EMPATE
};

class SimulacionCombate {
    private:

        Vector<Transformers> secuencia_combate; 
        Transformers personaje_principal;
        Transformers jefe_final;
        size_t posicion_actual;
        
    public:
        //Constructores
        SimulacionCombate(); //Diseñado a fin de porder usar el operador de asignacion

        SimulacionCombate(Vector<Transformers> secuencia_combate);

        //Destructor
        ~SimulacionCombate();
        
        //pre: El transformer en el encuentro actual no debe ser de la misma faccion
        //post:
        //Hara la comparacion de fuerza entre el personaje_principal y el transformer en posicion_actual:
        //  Si personaje_principal es mas fuerte, devuelve VICTORIA
        //  Si el transformer en posicion_actual es mas fuerte, devuelve DERROTA
        //  Si tienen igual fuerza, devuelve EMPATe
        //El combate con el jefe_final (ultimo encuentro) genera un numero aleatorio que 
        //determina si el jefe final estara transformado para el combate
        Resultado_combate combatir(bool transformado);

        //pre: 
        //Posicion_actual + 1 debe ser una posicion valida
        //post:
        //Avanza hasta el siguiente encuentro de la secuencia de combates
        void avanzar();

        //pre:-
        //post:
        //Devuelve true si es posible avanzar a una posicion valida
        bool hay_avance();

        //pre:-
        //post:
        //Devuelve true si el transformer en posicion_actual es de la misma faccion que personaje_principal
        //Caso contrario devuelve false
        bool es_aliado();
        
        //pre:
        //post:
        //Muestra por pantalla el recorrido del personaje_principal hasta el encuentro actual
        void mostrar_recorrido();

        //Pre:-
        //Post:
        //Devuleve el nombre del transformer que se encuentra en posicion_actual dentro de la secuencia de combates
        std:: string nombre_encuentro_actual();

        //Operador de asignacion
        SimulacionCombate& operator=(const SimulacionCombate& simulacion_combate);

};


#endif