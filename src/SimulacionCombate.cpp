//Alex Fariña 21/11/2024

#include "SimulacionCombate.hpp"
#include "Utilidades.hpp"

SimulacionCombate:: SimulacionCombate(){};

SimulacionCombate:: SimulacionCombate(Vector<Transformers> secuencia_combate){
    this->secuencia_combate = secuencia_combate;
    personaje_principal = secuencia_combate[0];
    jefe_final = secuencia_combate[secuencia_combate.tamanio()-1];
    posicion_actual = 0;
}

SimulacionCombate:: ~SimulacionCombate(){};

Resultado_combate SimulacionCombate:: combatir(bool transformado){
    Resultado_combate resultado_combate = EMPATE;
    if(transformado) personaje_principal.cambiar_forma();
    
    if(posicion_actual == (secuencia_combate.tamanio() - 1)){
        Utilidades utilidad;
        int valor_jefe_transformado = utilidad.generar_numero_aleatorio(0,1);
        if(valor_jefe_transformado == 1) jefe_final.cambiar_forma();
        
        if(personaje_principal.es_mas_fuerte(jefe_final)) resultado_combate = VICTORIA;
        else if(jefe_final.es_mas_fuerte(personaje_principal)) resultado_combate = DERRROTA;
        
        if(valor_jefe_transformado == 1) jefe_final.cambiar_forma();
    }
    else {
        if(personaje_principal.es_mas_fuerte(secuencia_combate[posicion_actual])) resultado_combate = VICTORIA;
        else if(secuencia_combate[posicion_actual].es_mas_fuerte(personaje_principal)) resultado_combate = DERRROTA;
    }
    
    if(transformado) personaje_principal.cambiar_forma();

    return resultado_combate;
}

void SimulacionCombate:: avanzar(){
    posicion_actual++;
}

bool SimulacionCombate:: hay_avance(){
    return (posicion_actual + 1) < secuencia_combate.tamanio();
}

bool SimulacionCombate:: es_aliado(){
    return personaje_principal == secuencia_combate[posicion_actual];
}

Transformers& SimulacionCombate:: transformer_encuentro_actual(){
    return secuencia_combate[posicion_actual];
}

void SimulacionCombate:: reiniciar_avance(){
    posicion_actual = 0;
}

SimulacionCombate& SimulacionCombate:: operator=(const SimulacionCombate& simulacion_combate){
    if(this != &simulacion_combate){
        secuencia_combate = simulacion_combate.secuencia_combate;
        personaje_principal = simulacion_combate.personaje_principal;
        posicion_actual = 0;
    }
    return *this;
}