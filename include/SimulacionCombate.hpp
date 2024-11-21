#ifndef SIMULACION_COMBATE_HPP
#define SIMULACION_COMBATE_HPP

#include "transformers.hpp"
#include "Vector.hpp"

enum Resultado_combate {
    VICTORIA,
    DERRROTA,
    EMPATE
};

class SimulacionCombate {
    private:
        //Atributos
        Vector<Transformers> secuencia_combate; 
        Transformers personaje_principal;
        size_t posicion_actual;
        bool combatio;
        
    public:
        //Constructor
        SimulacionCombate(Vector<Transformers> secuencia_combate);
        
        //Destructor
        ~SimulacionCombate();
        
        //pre:-
        //post:
        //Hara la comparacion de fuerza entre el personaje_principal y el transformer en posicion_actual:
        //  Si personaje_principal es mas fuerte, devuelve VICTORIA
        //  Si el transformer en posicion_actual es mas fuerte, devuelve DERROTA
        //  Si tienen igual fuerza, devuelve EMPATE
        //Si combatio == true el resultado del combate siempre sera EMPATE
        //Si intenta combatir un transformer_aliado, el resultado siempre sera DERROTA
        Resultado_combate combatir();

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
        //Muestra por pantalla el recorrido del personaje_principal 
        void mostrar_recorrido();

};


#endif