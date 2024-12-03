//Alex Fariña 22/11/2024

#ifndef COMBATES_USUARIO_HPP
#define COMBATES_USUARIO_HPP
#include "Transformers.hpp"
#include "TDAs/Vector.hpp"
#include "SimulacionCombate.hpp"
#include "GeneradorCombates.hpp"
#include "TablaClasificacion.hpp"
#include <string>
using namespace std;

//comentarios combate
const string comentario_combate_1 = "  ¡Comienza la batalla! 🔥\n";
const string comentario_combate_2 = "  PUM!! 💥 ¡Primer golpe demoledor!\n";
const string comentario_combate_3 = "  Uhh... GOLPE BAJO... 😬\n";
const string comentario_combate_4 = "  ¡Uh, justo en chasis! ¡Eso tuvo que doler! 😱\n";
const string comentario_combate_5 = "  ¡Increíble! ¡Contraataca con un golpe de tuercas!\n";
const string comentario_combate_6 = "  ¡Esquiva con agilidad de un F1!\n";
const string comentario_combate_7 = "  ¡Cuidado! ¡Está preparando su ataque especial! ¡VAMOS A MORIR TODOS! 😨\n";
const string comentario_combate_8 = "  ¡¡BAM!! ¡Qué golpe final! ¡Increíble desempeño! 🎇\n";
const string comentario_combate_9 = "  ¡La batalla ha terminado!\n";

//Presion de teclas
const string PRESIONE_TECLA_CONTINUAR = "  PRESIONE UNA TECLA PARA CONTINUAR...";
const string PRESIONE_TECLA_COMBATE_FINAL = "  HAS LLEGADO AL ULTIMO ENCUENTRO\nPRESIONA UNA TECLA PARA INICIARLO...";
const string PRESIONE_TECLA_RESULTADO_COMBATE = "  PRESIONE ENTER PARA VER EL RESULTADO DEL COMBATE...";

//Partida
const string PUNTUACION_FINAL = "\n\tPartida finalizada\nPUNTAJE FINAL: ";
const string SALIDA = "PRESIONE UNA TECLA PARA SALIR...";
const string ALIADO_ENCUENTRO = "Mira con quien te encontraste, un aliado!!\nObtuviste +25 pts\n";
const string ENEMIGO_ENCUENTRO = "\t\t\t\t\tOh no! un enemigo!\n\t\t\t\t\tTendras que enfrentar a ";
const string TRANSFORMADO_PTS = "\n  Pelearas transformado -10 pts";

class CombatesUsuario {
private:
    //Atributos
    size_t puntos_partida;
    SimulacionCombate simulacion_combate;
    GeneradorCombates generador_combate;
    bool termino_torneo;
    Menu menu;

    //Metodos privados

    //Pre:-
    //Post:
    //Segun el resultado_combate y esta_transformado suma y/o resta puntos a puntos_partida
    void establecer_puntaje_combate(Resultado_combate& resultado_combate, bool esta_transformado);

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

    //Pre:-
    //Post:
    //Se encarga de la interaccion entre el usuario y el proceso de encuentros y combates 
    //establecidos en la secuencia de combates minima
    void gestion_simulacion_batalla();

    //Pre:-
    //Post:
    //Muestra una secuencia de oraciones que simulan comentarios y sonidos de una batalla
    void efectos_combate();

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

    bool get_termino();
};

#endif