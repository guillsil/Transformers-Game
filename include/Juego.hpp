//
// Created by guille on 9/17/24.
//

#ifndef JUEGO_HPP
#define JUEGO_HPP
#include "Menu.hpp"
#include "Utilidades.hpp"
#include "BovedaCristales.hpp"
#include "FusionadorEnergon.hpp"
#include "Personaje.hpp"


class Juego {
public:
    //Constructor
    //El juego inicialmente te regala un cristal del Tipo Común con las estadísticas mínimas para que puedas empezar a jugar.
    Juego();
    /*
    Pre: (opcion_menu) debe ser un caracter válido entre '1' y '4'.
    Post:
    Si la opción es '1' o '2' se selecciona el personaje correspondiente.
    Si la opción es '3' se sale del juego
    Si no ingresa ninguna de las opciones anteriores se vuelve a pedir que ingrese una opción.
    */
    void procesar_menu_principal(const char &opcion_menu, const std::string &nombre);

    //Pre: -
    //Post: Devuelve TRue si el juego está en curso o false en caso contrario.
    bool jugando() const;


private:
    Personaje personaje;
    Menu menu;
    Utilidades utilidades;
    BovedaCristales boveda;
    FusionadorEnergon fusionador;
    bool juego_en_curso;
    std::string nombre_jugador;

    //Pre: -
    //Post: El personaje elegido responde al mensaje recibido.
    void respuesta_personaje(const std::string &mensaje);


    //Pre: -
    //Post: El personaje elegido sugiere una fusion con basado en su estado actual.
    void manejar_sugerencia_personaje();

    //Pre: -
    //Post: Se envia el mensaje a respuesta_personaje para que el personaje pueda responder al mensaje.
    void manejar_opcion_escribir_mensaje();

    //Pre: entrada_1 y entrada_2 deben ser entradas válidas para la rareza de un cristal.
    //Por ejemplo deben ser 0, 1, 2, 3.
    //Post:Fusiona dos cristales y almacena el cristal resultante en la bóveda.
    void fusionador_de_cristales(const int &entrada_1, const int &entrada_2);

    //Pre: -
    //Post: Fusiona cristales con base en la entrada del usuario.
    void manejar_fusionar_de_cristales();

    //Pre: -
    //Post: Solicita al usuario un cristal y lo almacena en la bóveda. Muestra un mensaje de éxito o error.
    void manejar_de_almacenamiento_de_cristales();

    //Pre: -
    //Post: Muestra los cristales almacenados en la bóveda y si ocurre un error devuelve una excepcion.
    void manejar_mostrar_boveda();

    //Pre: (ruta) debe ser una cadena no vacia.
    //Post:Exporta los cristales de la bóveda en la ruta proporcionada.
    void manejar_exportar_boveda(std::string &ruta);

    //Pre: -
    //Post: Muestra por consola el tamaño de la bóveda.
    void manejar_de_bodega_mostrar_tamanio();

    //Pre: -
    //Post: Gestiona las opciones del menú de la bóveda (almacenar, mostrar, exportar cristales).
    void manejar_de_bodega();

    //Pre: -
    //Post: Maneja el flujo del personaje hasta que el mismo decida salir.
    void interactuar_con_personaje();

    //Pre: -
    //Post: Devuelve true si la entrada es alguno de estos valores (COMÚN, RARO, ÉPICO o LEGENDARIO), o false en caso contrario.
    bool verificar_entrada_del_cristal(const int &entrada);
};




#endif //JUEGO_HPP
