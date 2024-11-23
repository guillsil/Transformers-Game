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

    cout << "¿Combatir transformado? [y]/[n]: ";
    cin >> respuesta;
    while(respuesta != 'y' && respuesta != 'n'){
        cout << "¿Combatir transformado? [y]/[n]: ";
        cin >> respuesta;
    }
    if(respuesta == 'y') {
        transformado = true;
        cout << "\nPelearas transformado -10 pts" << endl;;
    }
    resultado_combate = simulacion_combate.combatir(transformado);
    establecer_puntaje_combate(resultado_combate, transformado);
    switch (resultado_combate) {
    case VICTORIA:
        cout << "VICTORIA, felicidades!! +50 pts" << endl;
        break;
    case DERRROTA:
        cout << "DERRORA :(, suerte para la proxima -50 pts" << endl;
        break;
    default:
        cout << "EMPATE, tus puntos se mantendran iguales" << endl;
        break;
    }
    cout << "PUNTAJE ACTUAL: " << puntos_partida << endl;
    
}

void CombatesUsuario::batalla_jefe_final(){
    cout << "\n\tCOMBATE FINAL" << endl;
    cout << "TE ENFRENTARAS A " << simulacion_combate.nombre_encuentro_actual() << endl;
    cout << "\n\tCARACTERISTICAS DEL COMBATE" << endl;
    cout << "--Este enfrentamiento a diferencia del resto, se hara 3 veces" << endl
    <<  "--Entre cada enfrentamiento tendras la posibilidad de transformarte" << endl
    << "--" + simulacion_combate.nombre_encuentro_actual() + "tambien tendra la posibilidad de transformarse" << endl;

    for (size_t i = 0; i < 3; i++) {
        realizar_enfrentamiento();
    }
}

void CombatesUsuario::batalla_generica(){
    cout << "Te has topado con " << simulacion_combate.nombre_encuentro_actual() << endl
    << "Tendras que enfrentarlo..." << endl;
    realizar_enfrentamiento();
}

void CombatesUsuario::encuentro_aliado(){
    cout << "Mira con quien te encontraste, " + simulacion_combate.nombre_encuentro_actual() 
    +", un aliado!!" << endl;
    cout << "Obtuviste +25 pts" << endl;
    puntos_partida += 25;
}

void CombatesUsuario::gestion_simulacion_batalla(){

    cout << "\tBienvenido al campo de battalla" << endl;
    cout << "Preparate para un serie de combates que te llevaran al enfrentamiento final..." << endl 
    << "Estos son los encuentros que debes realizar:" << endl;
    generador_combate.mostrar_secuencia_minima();
    cout << "\nComencemos!!" << endl;

    while(simulacion_combate.hay_avance()){
        cout << "PRESIONE UNA TECLA PARA AVANZAR AL SIGUIENTE ENCUENTRO...";
        getchar();
        simulacion_combate.avanzar();
        if(simulacion_combate.es_aliado()){
            encuentro_aliado();
            cout << "Continuemos con el siguiente encuentro!!" << endl;
        }
        else if(!simulacion_combate.hay_avance()){
            batalla_jefe_final();
            cout << "Este fue el combate final..." << endl;
        }
        else {
            batalla_generica();
            cout << "Continuemos con el siguiente encuentro!!" << endl;
        }
    }

    cout << "\n\tPartida finalizada" << endl;
    cout << "PUNTAJE FINAL: " << puntos_partida << endl;
    cout << "PRESIONE UNA TECLA PARA SALIR..." << endl;
    getchar();
}

void CombatesUsuario::gestion_generador_combate(){
    cout << "Con tu personaje principal y los transformers almacenados, se genero un mapa de posibles \ncombates que desencadenaran siempre a una Batalla final" <<
    endl << "A continuacion el mapa de combates:" << endl;
    generador_combate.mostrar_mapa_combates();
    cout << "\nCon este mapa podremos obtener el recorrido con menos gasto de energon a la batalla final" << endl;
    cout << "PRESIONE UNA TECLA PARA OBTENER EL CAMINO QUE GASTARA MENOS ENERGON..." << endl;
    getchar();
    generador_combate.mostrar_secuencia_minima();
    cout << "El gasto total de este camino es: " << generador_combate.costo_energon_secuencia() << " ENERGON" << endl;
}

void CombatesUsuario:: iniciar_partida_combates(){
    cout << "\n\tBIENVENIDO A LA BATALLA FINAL" << endl;
    gestion_generador_combate();
    cout << "Emocionante ese mapa, eh, pero mas emocionante sera empezar el proceso de combates en el campo de batalla!!" << endl;
    cout << "PRESIONA UNA TECLA PARA CONTINUAR AL CAMPO DE BATALLA..." << endl;
    gestion_simulacion_batalla();
}

size_t CombatesUsuario::obtener_puntaje(){
    return puntos_partida;
}