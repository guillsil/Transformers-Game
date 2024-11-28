//
// Created by guille on 9/17/24.
//

#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <chrono>
#include <thread>
const char OPCION_1 = '1';
const char OPCION_2 = '2';
const char OPCION_3 = '3';
const char OPCION_4 = '4';
const char OPCION_5 = '5';
const char OPCION_6 = '6';
const char OPCION_7 = '7';
const char OPCION_8 = '8';
const char OPCION_9 = '9';

enum Personaje {
    MEGATRON,
    OPTIMUS_PRIME,
    PERSONAJE_INVALIDO
};


class Menu {
public:
    //Pre: Menu debe haber sido correctamente inicializado.
    //Post: Se muestra por consola el menu principal del juego.
    void mostrar_menu_principal(const std::string &nombre);

    //Pre: personaje_elejido debe ser válido entre MEGATRON=0 u OPTIMUS=1.
    //Post: Se muestra por consola el menu principal del personaje.
    void mostrar_menu_personaje(const int &personaje_elejido);

    //Pre: Menu debe haber sido correctamente inicializado.
    //Post: Muestra por consola el menu para que el usuario pueda ingresar el mensaje.
    void mostrar_menu_ingresar_mensaje();

    //Pre: Pre: personaje_elejido debe ser válido entre MEGATRON=0 u OPTIMUS=1.
    //Post: Se muestra por consola el menu para que el usuario pueda elegir el usuario del personaje.
    void mostrar_menu_estado(const int &personaje_elejido);

    //Pre:-
    //Post: Se muestra por consola la parte superior del recuadro del menu.
    void mostrar_recuadro_superior();

    //Pre:-
    //Post: Se muestra por consola la parte inferior del recuadro del menu.
    void mostrar_recuadro_inferior ();

    //Pre: El sistema operativo debe ser linux, ya que el comando que se usa es "clear".
    //Post: Se limpia el texto de la consola.
    void limpiar_menu();

    //Pre: -
    //Post: Se muestra por consola el mensaje dentro de un recuadro de menu.
    void mostrar_mensaje(const std::string &mensaje);

    //Pre: -
    //Post: Muestra por consola el menu del Fusionador.
    void mostrar_menu_fusionar_cristales();

    //Pre: -
    //Post: Muestra por consola el menu de la bóveda.
    void mostrar_menu_boveda();

    //Pre: -
    //Post: Muestra por consola el menu de Almacenar Cristal.
    void mostrar_menu_almacenar_cristal();

    //Pre: -
    //Post: Muestra por consola el menu de exportar un Cristal.
    void mostrar_menu_exportar_archivo();

    //Pre: -
    //Post: Muestra por consola el mensaje para que el usuario pueda ingresar el cristal para fusionar.
    void mostrar_ingresar_cristal(const int &cristal);

    //Pre: Las estadísticas (fuerza, defensa y velocidad) deben ser enteros menores que 100.
    //Post: Imprime por consola las estadisticas de un cristal
    void mostrar_estadisticas(const std::string &fuerza, const std::string &defensa, const std::string &velocidad);

    //Pre: rareza debe ser una cadena no vaciá y alguno de los siguientes valores (común, raro, épico, legendario).
    //Post: Muestra por consola la rareza de un cristial.
    void mostrar_rareza(const std::string &rareza);

    //Pre: -
    //Post: Imprime por consola el menu inicial del juego en el cual se pide al usuario que ingrese su nombre.
    void mostrar_menu_inicial();

    //Pre: -
    //Post: Muestra por consola el menú del Administrador de Transformers
    void mostrar_menu_administrador_transformers();

    //Pre: -
    //Post: Imprime por la terminal el menú para que el usuario pueda escoger la facción.
    void menu_escoger_faccion();

    //Pre: (faccion) solo puede ser (0=Autobots, 1=Decepticons)
    //Post: Muestra por la terminal el menú para que el usuario pueda escoger el tipo de vehículo.
    void menu_escoger_vehiculo(const int& faccion);

    //Pre:-
    //Post: Imprime por consola el menú para ingresar el nombre del transformers.
    void menu_ingregar_nombre_transformers();

    //Pre: (personaje_elejido) solo puede adquirir estos dos valores (MEGATRON=0 Y OPTIMUS=1)
    //Post: Muestra por consola el menú para interactuar con el personaje según el personaje elejido
    void menu_interactuar_con_personaje(const int &personaje_elejido);

    //Pre: -
    //Post: Limpia la terminal y muestra un mensaje con recuadro por terminal.
    void limpiar_y_mostrar_mensaje(const std::string& mensaje);
    void menu_transformers_encontrado();
    void menu_transformers_no_encontrado();
};



#endif //MENU_HPP