#ifndef TABLACLASIFICACION_HPP
#define TABLACLASIFICACION_HPP
#include <iostream>
#include <string>
#include "ControlArchivo.hpp"
#include "TDAs/Vector.hpp"
#include "DatosJugador.hpp"

class ExcepcionTablaClasificacion : public std::runtime_error {
public:
    ExcepcionTablaClasificacion(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionTablaClasificacion(): runtime_error("") {
    }
};

class TablaClasificacion{
private:
    const std::string ERROR_TABLA_VACIO = "ERROR:: Tabla de Clasificaciones vacía , no hay nada para mostrar";
    const std::string RUTA_ARCHIVO_CLASIFICACION = "TablaDeClasificacion.csv";
    const int MAXIMO_MOSTRAR_JUGADORES = 10;
    Vector<DatosJugador> lista_jugadores;
    ControlArchivo<DatosJugador> control_archivo_tabla;
public:
    //Constructor
    TablaClasificacion();

    //Pre:
    //Post: Muestra por terminal los 10 jugadores de mayor puntaje, ordenados de mayor a menor. 
    //      De haber menos de 10 jugadores, muestra los que hay.
    void mostrar_top10_jugadores();

    //Pre: Se asume que el DatosJugador está bien generado
    //Post: A traves de insersion ordenada, se agrega un DatosJugador nuevo a la lista_jugadores
    void agregar_jugador(DatosJugador jugador_nuevo);

    //Pre: -
    //Post: A traves de insersion ordenada, se agrega un DatosJugador nuevo a la lista_jugadores
    void agregar_jugador(std::string nombre_jugador, int puntaje, Personaje personaje_usado);

    //Destructor
    ~TablaClasificacion();
};

#endif