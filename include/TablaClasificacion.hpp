#ifndef TABLACLASIFICACION_HPP
#define TABLACLASIFICACION_HPP
#include <iostream>
#include <string>
#include "ControlArchivo.hpp"
#include "Vector.hpp"
#include "DatosJugador.hpp"
//#include donde esté el enum personaje

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
    TablaClasificacion(/* args */);

    //Pre:
    //Post:
    void mostrar_top10_jugadores();

    //Pre:
    //Post: Es una insersion ordenada.
    void agregar_jugador(DatosJugador jugador_nuevo);

    //Destructor
    ~TablaClasificacion();
};

#endif