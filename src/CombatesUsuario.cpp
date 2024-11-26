//Alex Fariña 22/11/2024

#include "CombatesUsuario.hpp"
#include "Utilidades.hpp"
#include <iostream>

using namespace std;

CombatesUsuario::CombatesUsuario(Transformers& personaje_principal, Vector<Transformers>& transformers_secundarios){
    generador_combate = GeneradorCombates(personaje_principal, transformers_secundarios);
    simulacion_combate = SimulacionCombate(generador_combate.obtener_secuencia_minima());
    puntos_partida = 0;
}

CombatesUsuario::~CombatesUsuario(){}

void CombatesUsuario::establecer_puntaje_combate(Resultado_combate resultado_combate, bool esta_transformado){
    size_t cant_restar = (esta_transformado) ? 10 : 0;
    switch (resultado_combate) {
    case VICTORIA:
        puntos_partida += (50 - cant_restar);
        break;
    case DERRROTA:
        cant_restar += 50;
        puntos_partida -= (puntos_partida < cant_restar) ? puntos_partida : cant_restar; 
        break;
    default:
        break;
    }
}

void CombatesUsuario:: realizar_enfrentamiento(){
    char respuesta;
    bool transformado = false;
    Resultado_combate resultado_combate;

    cout << COMBATIR_TRANSFORMADO;
    cin >> respuesta;
    while(respuesta != 'y' && respuesta != 'n'){
        cout << COMBATIR_TRANSFORMADO;
        cin >> respuesta;
    }
    if(respuesta == 'y') {
        transformado = true;
        cout << TRANSFORMADO_PTS << endl;;
    }
    resultado_combate = simulacion_combate.combatir(transformado);
    establecer_puntaje_combate(resultado_combate, transformado);
    switch (resultado_combate) {
    case VICTORIA:
        cout << VICTORIA_MENSAJE << endl;
        break;
    case DERRROTA:
        cout << DERROTA_MENSAJE << endl;
        break;
    default:
        cout << EMPATE_MENSAJE << endl;
        break;
    }
    cout << "PUNTAJE ACTUAL: " << puntos_partida << endl;
    
}

void CombatesUsuario::batalla_jefe_final(){
    cout << COMBATE_FINAL_INTRO << simulacion_combate.nombre_encuentro_actual() << endl;
    cout << CARACTERISTICAS_COMBATE_FINAL << endl;

    for (size_t i = 0; i < 3; i++) {
        realizar_enfrentamiento();
    }
}

void CombatesUsuario::batalla_generica(){
    cout << ENEMIGO_ENCUENTRO << simulacion_combate.nombre_encuentro_actual() << endl;
    realizar_enfrentamiento();
}

void CombatesUsuario::encuentro_aliado(){
    cout << simulacion_combate.nombre_encuentro_actual() + "?";
    cout << ALIADO_ENCUENTRO << endl;
    puntos_partida += 25;
}

void CombatesUsuario::gestion_simulacion_batalla(){

    cout << BIENVENIDA_CAMPO_BATALLA << endl;
    cout << PREPARACION_SERIE_COMBATES << endl 
    << "Estos son los encuentros que debes realizar:" << endl;
    generador_combate.mostrar_secuencia_minima();
    cout << "\n\tComencemos!!" << endl;

    while(simulacion_combate.hay_avance()){
        cout << PRESIONE_TECLA_AVANZAR;
        getchar();
        simulacion_combate.avanzar();
        if(simulacion_combate.es_aliado()){
            encuentro_aliado();
            cout << CONTINUAR_ENCUENTROS << endl;
        }
        else if(!simulacion_combate.hay_avance()){
            batalla_jefe_final();
        }
        else {
            batalla_generica();
            cout << CONTINUAR_ENCUENTROS << endl;
        }
    }

    cout << PUNTUACION_FINAL << puntos_partida << endl;
    cout << SALIDA << endl;
    getchar();
}

void CombatesUsuario::gestion_generador_combate(){
    cout << PRESENTACION_MAPA_COMBATES << endl;
    generador_combate.mostrar_mapa_combates();
    cout << OBTENER_SECUENCIA_MINIMA << endl;
    getchar();
    generador_combate.mostrar_secuencia_minima();
    cout << "El gasto total de este camino es: " << generador_combate.costo_energon_secuencia() << " ENERGON" << endl;
}

void CombatesUsuario:: iniciar_partida_combates(){
    cout << BIENVENIDA_BATALLA_FINAL << endl;
    gestion_generador_combate();
    cout << EMOCION_MAPA << endl;
    cout << PRESIONE_TECLA_CAMPO_BATALLA << endl;
    gestion_simulacion_batalla();
}

size_t CombatesUsuario::obtener_puntaje(){
    return puntos_partida;
}