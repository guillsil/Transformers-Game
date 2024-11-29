//Alex Fariña 22/11/2024

#ifndef COMBATES_USUARIO_HPP
#define COMBATES_USUARIO_HPP
#include "Transformers.hpp"
#include "TDAs/Vector.hpp"
#include "SimulacionCombate.hpp"
#include "GeneradorCombates.hpp"
#include <string>
using namespace std;

const string BIENVENIDA_CAMPO_BATALLA = "\tBienvenido al campo de batalla";
const string BIENVENIDA_BATALLA_FINAL = "\n\tBIENVENIDO A LA BATALLA FINAL";
const string PREPARACION_SERIE_COMBATES = "Preparate para un serie de combates que te llevaran al enfrentamiento final...";
const string PRESIONE_TECLA_AVANZAR = "PRESIONE UNA TECLA PARA AVANZAR AL SIGUIENTE ENCUENTRO...";
const string PRESIONE_TECLA_CAMPO_BATALLA = "PRESIONA UNA TECLA PARA DIRIGIRTE AL CAMPO DE BATALLA...";
const string PUNTUACION_FINAL = "\n\tPartida finalizada\nPUNTAJE FINAL: ";
const string SALIDA = "PRESIONE UNA TECLA PARA SALIR...";
const string COMBATE_FINAL_INTRO = "\n\tCOMBATE FINAL\nTE ENFRENTARAS A ";
const string CARACTERISTICAS_COMBATE_FINAL = "\n\tCARACTERISTICAS DEL COMBATE\n--Este enfrentamiento a diferencia del resto, se hara 3 veces\n--Entre cada enfrentamiento tendras la posibilidad de transformarte\n--En esta instancia, tu enemigo tambien tendra la posibilidad de transformarse\n";
const string ALIADO_ENCUENTRO = "Mira con quien te encontraste, un aliado!!\nObtuviste +25 pts";
const string ENEMIGO_ENCUENTRO = "Oh no! un enemigo!\nTendras que enfrentar a ";
const string PRESENTACION_MAPA_COMBATES = "Con tu personaje principal y los transformers almacenados, se genero un mapa de posibles \ncombates que desencadenaran siempre a una Batalla final.\nA continuacion el mapa de combates:";
const string EMOCION_MAPA = "Emocionante ese mapa, eh, pero mas emocionante sera empezar el proceso de combates en el campo de batalla!!";
const string TRANSFORMADO_PTS = "\nPelearas transformado -10 pts";
const string COMBATIR_TRANSFORMADO = "¿Combatir transformado? [y]/[n]: ";
const string COMBATIR_TRANSFORMADO_ERROR = "Entrada invalida. ¿Combatir transformado? [y]/[n]: ";
const string VICTORIA_MENSAJE = "VICTORIA, felicidades!! +50 pts";
const string DERROTA_MENSAJE = "DERRROTA :(, suerte para la proxima -50 pts";
const string EMPATE_MENSAJE = "EMPATE, tus puntos se mantendran iguales";
const string CONTINUAR_ENCUENTROS = "Continuemos con el siguiente encuentro!!";
const string OBTENER_SECUENCIA_MINIMA = "\nCon este mapa podremos obtener el recorrido con menos gasto de energon a la batalla final\nPRESIONE UNA TECLA PARA OBTENER EL CAMINO QUE GASTARA MENOS ENERGON...";

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
    //Devuelve el puntaje final de la partida, si no se llama previamente a iniciar_partida_combates() siempre devolvera 0
    //Si se llama a iniciar_partida_combates() devolvera el puntaje obtenido en la partida
    size_t obtener_puntaje();
};

#endif