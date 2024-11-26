//
// Created by guille on 9/17/24.
//

#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "Menu.hpp"
#include "BovedaCristales.hpp"
#include "FusionadorEnergon.hpp"
#include "Protagonista.hpp"
#include "AdminTransformers.hpp"
#include "TablaClasificacion.hpp"


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
    //Post: Devuelve True si el juego está en curso o false en caso contrario.
    bool jugando() const;


private:
    Protagonista protagonista;
    Menu menu;
    BovedaCristales boveda;
    FusionadorEnergon fusionador;
    bool juego_en_curso;
    std::string nombre_jugador;
    AdministradorTransformers administrador_transformers;
    TablaClasificacion tabla_clasificacion;

    //Pre: -
    //Post: El personaje elegido responde al mensaje recibido.
    void respuesta_personaje(const std::string &mensaje);

    //Pre: -
    //Post: El personaje elegido sugiere una fusion con basado en su estado actual.
    void manejar_sugerencia_personaje();

    //Pre: -
    //Post: Se envia el mensaje a respuesta_personaje para que el personaje pueda responder al mensaje.
    void manejar_opcion_escribir_mensaje();

    //Pre: -
    //Post: Cambia el estado del personaje seleccionado según la opción ingresada.
    void manejar_cambiar_estado();

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
    //Post: Muestra los cristales almacenados en la bóveda y si ocurre un error devuelve una excepción.
    void mostrar_boveda();

    //Pre: (ruta) debe ser una cadena no vacía.
    //Post:Exporta los cristales de la bóveda en la ruta proporcionada.
    void manejar_exportar_boveda(std::string &ruta);

    //Pre: -
    //Post: Muestra por consola el tamaño de la bóveda.
    void manejar_de_bodega_mostrar_tamanio();

    //Pre: -
    //Post: Equipa con un Crital al personaje.
    void manejar_equipar_un_cristal();

    //Pre: -
    //Post: Muestra la cantidad de Cristales equipados por el personaje.
    void mostrar_cantidad_cristales_equipados();

    //Pre: -
    //Post: Gestiona las opciones del menú de la bóveda (almacenar, mostrar, exportar cristales).
    void manejar_boveda();

    //Pre: (faccion) debe ser un entero válido (0 para AUTOBOTS, 1 para DECEPTICONS).
    //Post: Devuelve una cadena que representa la
    std::string convertir_faccion_string(const int &faccion);


    //Pre: -
    //Post: Solicita datos al usuario para crear un Transformer y lo agrega al administrador.
    void manejar_crear_transformers();

    //Pre: -
    //Post: Busca un Transformer por nombre. Muestra un mensaje indicando si fue encontrado o no.
    void manejar_buscar_transformers();

    //Pre: -
    //Post: Solicita un nombre y elimina el Transformer correspondiente del administrador.
    void manejar_eliminar_transformers();

    //Pre: -
    //Post: Solicita un nombre y transforma el Transformer correspondiente.
    void manejar_transformar();

    //Pre: -
    //Post: Muestra por terminal los personajes secundarios que se encuentren ene le archivo de transformers secundarios.
    void mostrar_transformers_secundarios();

    //Pre: -
    //Post: Solicita al usuario el nombre del Transformer y lo devuelve como una cadena.
    std::string solicitar_nombre_transformers();

    //Pre: (faccion) debe ser un valor comprendindo entre (0=AUTOBOTS y 1=DECEPTICONS)
    //Post:
    int solicitar_vehiculo(const int& faccion);

    //Pre: -
    //Post: Solicita al usuario que ingrese la faccion y lo devuelve.
    int solicitar_faccion();

    //Pre: -
    //Post: Devuelve una cadena que representa el tipo de vehículo correspondiente
    std::string convertir_vehiculo_string(const int& vehiculo);

    //Pre: Todos los parámetros deben ser válidos para crear un Transformer (nombre no vacío, fuerza, defensa, velocidad mayores a 0).
    //Post: Agrega un Transformer con las características especificadas al administrador de Transformers.
    void manejar_agregar_transformers(const std::string &nombre,const int &fuerza,const int &defensa,const int &velocidad,const std::string &faccion,const
                              std::string &vehiculo);

    //Pre: (nombre) no debe estar vacío. (tipo_vehiculo) debe ser un valor válido entre 0 y 3.
    //Post: Crea un Transformer y lo agrega al administrador según el tipo de vehículo especificado.
    void crear_transformers(std::string nombre, int tipo_vehiculo);

    //Pre: -
    //Post: Crea un Autobots en base nombre y tipo de vehículo.
    void manejar_crear_autobots(const std::string& nombre);

    //Pre: -
    //Post: Crea un Decepticons en base nombre y tipo de vehículo.
    void manejar_crear_decepticons(const std::string& nombre);


    //Pre: -
    //Post: Maneja el flujo del personaje hasta que el mismo decida salir.
    void manejar_flujo_juego_principal();

    //Pre: -
    //Post: Devuelve true si la entrada es alguno de estos valores (COMÚN, RARO, ÉPICO o LEGENDARIO), o false en caso contrario.
    bool verificar_entrada_del_cristal(const int &entrada);

    //Pre: -
    //Post: Permite al usuario gestionar opciones relacionadas con el Administrador de Transformers (crear, buscar, eliminar, etc.).
    void manejar_administrar_transformers();

    //Pre: -
    //Post: Maneja interacciones con el personaje, como enviar mensajes, modificar estado o recibir sugerencias.
    void manejar_interactuar_con_el_personaje();
};




#endif //JUEGO_HPP
