#include "SimulacionCombate.hpp"

SimulacionCombate:: SimulacionCombate(Vector<Transformers> secuencia_combate){
    this->secuencia_combate = secuencia_combate;
    personaje_principal = secuencia_combate[0];
    posicion_actual = 0;
}

SimulacionCombate:: ~SimulacionCombate(){};

Resultado_combate SimulacionCombate:: combatir(){
    Resultado_combate resultado_combate = EMPATE;
    if(!combatio){
        if(es_aliado()){
            resultado_combate = DERRROTA;
        }
        else{
            if(personaje_principal.es_mas_fuerte(secuencia_combate[posicion_actual])) resultado_combate = VICTORIA;
            else if(personaje_principal.es_mas_fuerte(secuencia_combate[posicion_actual])) resultado_combate = DERRROTA;
        }
    }

    return resultado_combate;
}

void SimulacionCombate:: avanzar(){
    posicion_actual++;
    combatio = false;
}

bool SimulacionCombate:: hay_avance(){
    return (posicion_actual + 1) < secuencia_combate.tamanio();
}

bool SimulacionCombate:: es_aliado(){
    return personaje_principal == secuencia_combate[posicion_actual];
}

void SimulacionCombate:: mostrar_recorrido() {
    
}