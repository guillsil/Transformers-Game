#include "TablaClasificacion.hpp"

TablaClasificacion::TablaClasificacion(): lista_jugadores(), control_archivo_tabla(RUTA_ARCHIVO_CLASIFICACION){
    //Importar archivo csv
    lista_jugadores = control_archivo_tabla.leer_archivo();
}

void TablaClasificacion::mostrar_top10_jugadores(){
    if (lista_jugadores.vacio()){
        throw ExcepcionTablaClasificacion(ERROR_TABLA_VACIO);
    } else {
        size_t numero_jugadores_mostrados = lista_jugadores.tamanio();
        if (lista_jugadores.tamanio() > 10){
            numero_jugadores_mostrados = 10;
        }
        std::cout << "-- NOMBRE JUGADOR, PUNTAJE, PERSONAJE USADO" << std::endl;
        for (size_t i = 0; i < numero_jugadores_mostrados; i++){
            std::cout << (i + 1) << ") " << lista_jugadores[i] << std::endl;
        }
    }
}

void TablaClasificacion::agregar_jugador(DatosJugador jugador_nuevo){
    //Modularizar == que almacenar en boveda
    size_t posicion = 0;
    while (posicion < lista_jugadores.tamanio() && lista_jugadores[posicion].obtener_puntaje() > jugador_nuevo.obtener_puntaje()) {
        posicion++;
    }
    lista_jugadores.alta(jugador_nuevo, posicion);
}

void TablaClasificacion::agregar_jugador(std::string nombre_jugador, int puntaje, Personaje personaje_usado){
    DatosJugador nuevo(nombre_jugador, puntaje, personaje_usado);
    size_t posicion = 0;
    while (posicion < lista_jugadores.tamanio() && lista_jugadores[posicion].obtener_puntaje() > nuevo.obtener_puntaje()) {
        posicion++;
    }
    lista_jugadores.alta(nuevo, posicion);   
}

TablaClasificacion::~TablaClasificacion(){
    //Exportar archivo csv
    control_archivo_tabla.sobreescribir_en_archivo(lista_jugadores);
}
