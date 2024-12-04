//Alex Fariña 22/11/2024

#include "CombatesUsuario.hpp"
#include "Utilidades.hpp"
#include "Menu.hpp"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

CombatesUsuario::CombatesUsuario(Transformers& personaje_principal, Vector<Transformers>& transformers_secundarios){
    generador_combate = GeneradorCombates(personaje_principal, transformers_secundarios);
    simulacion_combate = SimulacionCombate(generador_combate.obtener_secuencia_minima());
    termino_torneo = false;
    puntos_partida = 0;
}

CombatesUsuario::~CombatesUsuario(){}

void CombatesUsuario::establecer_puntaje_combate(Resultado_combate& resultado_combate, bool esta_transformado){
    size_t cant_restar = (esta_transformado) ? PUNTOS_RESTADOS_ESTA_TRANSFORMADO : 0;
    switch (resultado_combate) {
    case VICTORIA:
        puntos_partida += (PUNTOS_GANAR_PERDER - cant_restar);
        break;
    case DERRROTA:
        cant_restar += PUNTOS_GANAR_PERDER;
        puntos_partida -= (puntos_partida < cant_restar) ? puntos_partida : cant_restar; 
        break;
    default:
        puntos_partida -= (puntos_partida < cant_restar) ? puntos_partida : cant_restar; 
        break;
    }
}

void CombatesUsuario:: efectos_combate(){
    int ms_pausar = 3000; //Cantidad en milisegundos a pausar entre cada comentario
    std::cout << comentario_combate_1;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_2;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_3;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_4;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_5;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_6;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_7;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_8;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_pausar));

    std::cout << comentario_combate_9;
}

void CombatesUsuario:: realizar_enfrentamiento(){
    size_t respuesta;
    bool transformado = false;
    Resultado_combate resultado_combate;
    menu.menu_estara_transformado();
    cin >> respuesta;
    while(respuesta != 1 && respuesta != 2){
        menu.menu_estara_transformado();
        cin >> respuesta;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(respuesta == 1) {
        transformado = true;
        cout << TRANSFORMADO_PTS << endl;;
    }
    efectos_combate();
    cout << PRESIONE_TECLA_RESULTADO_COMBATE;
    cin.get();
    resultado_combate = simulacion_combate.combatir(transformado);
    establecer_puntaje_combate(resultado_combate, transformado);
    switch (resultado_combate) {
    case VICTORIA:
        menu.mostrar_victoria_combate();
        break;
    case DERRROTA:
        menu.mostrar_derrota_combate();
        break;
    default:
        menu.mostrar_empate_combate();
        break;
    }
    cout << "PUNTAJE ACTUAL: " << puntos_partida << endl;
    cout << PRESIONE_TECLA_CONTINUAR;
    cin.get();
}

void CombatesUsuario::batalla_jefe_final(){
    cout << PRESIONE_TECLA_COMBATE_FINAL;
    cin.get();
    bool jefe_final_megatron = simulacion_combate.transformer_encuentro_actual().obtener_nombre() == "Megatron";
    menu.mostrar_vs_combate_final(jefe_final_megatron);
    cout << PRESIONE_TECLA_CONTINUAR;
    cin.get();
    system("clear");
    for (size_t i = 0; i < 3; i++) {
        system("clear");
        cout << "ENCUENTRO NUMERO " << i+1 << endl;
        realizar_enfrentamiento();
    }
    termino_torneo = true;
}

void CombatesUsuario::batalla_generica(){
    menu.mostrar_mensaje(ENEMIGO_ENCUENTRO + simulacion_combate.transformer_encuentro_actual().obtener_nombre());
    realizar_enfrentamiento();
}

void CombatesUsuario::encuentro_aliado(){
    menu.mostrar_mensaje("\t\t\t\t\t" + simulacion_combate.transformer_encuentro_actual().obtener_nombre() + "?\n" + ALIADO_ENCUENTRO);
    puntos_partida += 25;
    cout << PRESIONE_TECLA_CONTINUAR;
    cin.get();
}

void CombatesUsuario::gestion_simulacion_batalla(){
    simulacion_combate.reiniciar_avance();
    puntos_partida = 0;
    size_t opcion = 0;
    while(opcion < 1 || opcion > 3){
        menu.menu_combates();
        cin >> opcion;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(opcion != 3 && simulacion_combate.hay_avance()){
        switch (opcion) {
        case 1:
            generador_combate.mostrar_secuencia_minima();
            cout << "  EL GASTO TOTAL DE ESTE CAMINO ES: " << generador_combate.costo_energon_secuencia() << " ENERGON" << endl;
            cout << PRESIONE_TECLA_CONTINUAR;
            cin.get();
            break;
        case 2:
            simulacion_combate.avanzar();
            if(simulacion_combate.es_aliado()){
                encuentro_aliado();
            }
            else if(!simulacion_combate.hay_avance()){
                system("clear");
                batalla_jefe_final();
            }
            else {
                batalla_generica();
            }
            break;
        default:
            break;
        }
        if(simulacion_combate.hay_avance()){
            opcion = 0;
            while(opcion < 1 || opcion > 3){
                menu.menu_combates();
                cin >> opcion;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}

void CombatesUsuario:: iniciar_partida_combates(){
    size_t opcion = 0;
    while(opcion < 1 || opcion > 4){
        menu.menu_batalla_final(true);
        cin >> opcion;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(opcion != 4){
        switch (opcion) {
        case 1:
            generador_combate.mostrar_mapa_combates();
            cout << PRESIONE_TECLA_CONTINUAR;
            cin.get();
            break;
        case 2:
            generador_combate.mostrar_secuencia_minima();
            cout << "  EL GASTO TOTAL DE ESTE CAMINO ES: " << generador_combate.costo_energon_secuencia() << " ENERGON" << endl;
            cout << PRESIONE_TECLA_CONTINUAR;
            cin.get();
            break;
        case 3:
            gestion_simulacion_batalla();
            break;
        default:
            break;
        }
        opcion = 0;
        while(opcion < 1 || opcion > 4){
            menu.menu_batalla_final(false);
            cin >> opcion;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool CombatesUsuario::get_termino(){
    return termino_torneo;
}

size_t CombatesUsuario::obtener_puntaje(){
    return puntos_partida;
}