//
// Created by guille on 9/17/24.
//

#include "Juego.hpp"

const std::string ESTADO_INVALIDO;

const std::string ERROR_ENTRADA_INVALIDA = "Error: Entrada Inválida. Intente nuevamente.";
const std::string ERROR_BOVEDA_VACIA = "Error: La bóveda esta vaciá.";
const std::string ERROR_LIMITE_EN_BOVEDA_EXCEDIDO = "Error: Limite en la Bóveda alcanzado";

const std::string MENSAJE_ESTADO_MODIFICADO_CORRECTAMENTE = "Se Modifico Correctamente el estado" ;
const std::string MENSAJE_ALMACENADO_CON_EXITO = "Se almaceno con éxito el cristal.";
const std::string MENSAJE_ARCHIVO_CREADO_CORRECTAMENTE = "Se ha generado con éxito el archivo con la ruta suministrada.";
const std::string CANTIDAD_CRISTALES_ALMACENADOS = "Cantidad de Cristales Almacenados: ";
const std::string MENSAJE_CRISTAL_OBTENIDO = "EL cristal obtenido es: ";

Juego::Juego(): personaje_seleccionado(PERSONAJE_INVALIDO), juego_en_curso(true), indice_estado('0') {}


void Juego::procesar_menu_principal(const char& opcion_menu, const std::string &nombre) {
    nombre_jugador = nombre;
    switch (opcion_menu) {
        case OPCION_1:
            menu.limpiar_menu();
            personaje_seleccionado = MEGATRON;
            interactuar_con_personaje();
        break;
        case OPCION_2:
            menu.limpiar_menu();
            personaje_seleccionado = OPTIMUS_PRIME;
            interactuar_con_personaje();
        break;
        case OPCION_3:
            juego_en_curso = false;
        break;
        default:
            menu.limpiar_menu();
            menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

bool Juego::jugando() const {
    return juego_en_curso;
}

void Juego::respuesta_personaje(const std::string &mensaje) {
    menu.limpiar_menu();
    menu.mostrar_recuadro_superior();
    if (personaje_seleccionado == MEGATRON) {megatron.responder(mensaje);
    }else {optimus.responder(mensaje);}
    menu.mostrar_recuadro_inferior();
}

void Juego::obtener_estado_personaje() {
    if (personaje_seleccionado == MEGATRON) {
        switch (indice_estado) {
            case OPCION_1:  estado_personaje = MEGATRON_INTENCION_DESPRECIO;
            case OPCION_2:  estado_personaje = MEGATRON_INTENCION_MANIPULACION;
            case OPCION_3:  estado_personaje = MEGATRON_INTENCION_AMENAZA;
            default: estado_personaje = ESTADO_INVALIDO;
        }
   }
    switch (indice_estado) {
        case OPCION_1:  estado_personaje = OPTIMUS_ANIMO_SERENO;
        case OPCION_2:  estado_personaje = OPTIMUS_ANIMO_DETERMINADO;
        case OPCION_3:  estado_personaje = OPTIMUS_ANIMO_ENFURECIDO;
        default: estado_personaje = ESTADO_INVALIDO;
    }
}

void Juego::actualizar_estado_personaje() {
    menu.limpiar_menu();
    obtener_estado_personaje();
    if (indice_estado) {
        if (personaje_seleccionado == MEGATRON) {
            megatron.cambiar_intencion(estado_personaje);
        }else {
            optimus.cambiar_animo(estado_personaje);
        }
        menu.mostrar_mensaje(MENSAJE_ESTADO_MODIFICADO_CORRECTAMENTE);
    }else {
        menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

void Juego::manejar_sugerencia_personaje() {
    menu.limpiar_menu();
    menu.mostrar_recuadro_superior();
    if (personaje_seleccionado == MEGATRON) { megatron.sugerir_fusion();
    }else {optimus.sugerir_fusion();}
    menu.mostrar_recuadro_inferior();
}

void Juego::manejar_opcion_escribir_mensaje() {
    std::string mensaje;
    menu.limpiar_menu();
    menu.mostrar_menu_ingresar_mensaje();
    std::cin.ignore();
    std::getline(std::cin ,mensaje);
    respuesta_personaje(mensaje);
}
void Juego::fusionador_de_cristales(const int &entrada_1, const int &entrada_2) {
    try {
        Cristal cristal_1(static_cast<Rareza>(entrada_1));
        Cristal cristal_2(static_cast<Rareza>(entrada_2));
        Cristal cristal_resultante;
        cristal_resultante = fusionador.fusionar(cristal_1, cristal_2);
        boveda.almacenar_cristal(cristal_resultante);
        menu.limpiar_menu();
        menu.mostrar_mensaje(MENSAJE_CRISTAL_OBTENIDO + cristal_resultante.convertir_rareza_a_string());
    } catch (ExcepcionFusionadorEnergon& e) {
        menu.mostrar_mensaje(e.what());
    }
}

void Juego::manejar_fusionar_de_cristales() {
    menu.limpiar_menu();
    if (boveda.tamanio() < TAMANIO_MAXIMO_DE_CRISTALES) {
        int entrada_1;
        int entrada_2;
        menu.mostrar_menu_fusionar_cristales();
        menu.mostrar_ingresar_cristal(1);
        std::cin >> entrada_1;
        menu.mostrar_ingresar_cristal(2);
        std::cin >> entrada_2;
        if (verificar_entrada_del_cristal(entrada_1) && verificar_entrada_del_cristal(entrada_2)) {
            fusionador_de_cristales(entrada_1, entrada_2);
        }else {
            menu.limpiar_menu();
            menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
        }
    }else {
        menu.limpiar_menu();
        menu.mostrar_mensaje(ERROR_LIMITE_EN_BOVEDA_EXCEDIDO);
    }
}

void Juego::manejar_de_almacenamiento_de_cristales() {
    menu.limpiar_menu();
    menu.mostrar_menu_almacenar_cristal();
    int entrada;
    std::cin >> entrada;
    if (verificar_entrada_del_cristal(entrada) || entrada == LEGENDARIO) {
        try {
            Cristal cristal(static_cast<Rareza>(entrada));
            boveda.almacenar_cristal(cristal);
            menu.limpiar_menu();
            menu.mostrar_mensaje(MENSAJE_ALMACENADO_CON_EXITO);
        } catch (ExcepcionBovedaCristales& e) {
            menu.mostrar_mensaje(e.what());
        }
    }else {
        menu.limpiar_menu();
        menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

void Juego::manejar_mostrar_boveda() {
    menu.limpiar_menu();
    try {
        boveda.mostrar_cristales();
    } catch (ExcepcionBovedaCristales& e) {
        menu.mostrar_mensaje(e.what());
    }
}

void Juego::manejar_exportar_boveda(std::string &ruta) {
    menu.limpiar_menu();
    if (boveda.esta_vacia()) {
        menu.mostrar_mensaje(ERROR_BOVEDA_VACIA);
    }else {
        try {
            menu.mostrar_menu_exportar_archivo();
            std::cin >> ruta;
            boveda.exportar_cristales(ruta);
            menu.limpiar_menu();
            menu.mostrar_mensaje(MENSAJE_ARCHIVO_CREADO_CORRECTAMENTE);
        } catch (ExcepcionBovedaCristales& e) {
            menu.limpiar_menu();
            menu.mostrar_mensaje(e.what());
        }
    }
}

void Juego::manejar_de_bodega_mostrar_tamanio() {
    menu.limpiar_menu();
    if (!boveda.esta_vacia()) {
        menu.mostrar_mensaje(CANTIDAD_CRISTALES_ALMACENADOS + std::to_string(boveda.tamanio()));
    }else {
        menu.mostrar_mensaje(ERROR_BOVEDA_VACIA);
    }
}

void Juego::manejar_de_bodega() {
    menu.limpiar_menu();
    char opcion;
    bool continuar = true;
    std::string ruta;
    while (continuar) {
        menu.mostrar_menu_boveda();
        std::cin >> opcion;
        switch (opcion) {
            case OPCION_1:
                manejar_de_almacenamiento_de_cristales();
                break;
            case OPCION_2:
                manejar_mostrar_boveda();
                break;
            case OPCION_3:
                manejar_exportar_boveda(ruta);
                break;
            case OPCION_4:
                manejar_de_bodega_mostrar_tamanio();
                break;
            case OPCION_5:
                continuar = false;
                menu.limpiar_menu();
            default:
                menu.limpiar_menu();
                menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
        }
    }
}




void Juego::interactuar_con_personaje() {
    bool continuar = true;
    char opcion_menu;
    while (continuar) {
        menu.mostrar_menu_personaje(personaje_seleccionado);
        std::cin >> opcion_menu;
        switch (opcion_menu) {
            case OPCION_1:
                manejar_opcion_escribir_mensaje();
                break;
            case OPCION_2:
                manejar_sugerencia_personaje();
                break;
            case OPCION_3:
                menu.limpiar_menu();
                menu.mostrar_menu_estado(personaje_seleccionado);
                std::cin >> indice_estado;
                actualizar_estado_personaje();
                break;
            case OPCION_4: // Fusionador
                manejar_fusionar_de_cristales();
                break;
            case OPCION_5: // Boveda
                manejar_de_bodega();
                break;
            case OPCION_6:
                menu.limpiar_menu();
                continuar = false;
                break;
            default:
                menu.limpiar_menu();
                menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
        }
    }
}



bool Juego::verificar_entrada_del_cristal(const int &entrada) {
    return entrada == COMUN || entrada == RARO || entrada == EPICO;
}

