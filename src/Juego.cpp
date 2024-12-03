//
// Created by guille on 9/17/24.
//

#include "Juego.hpp"
#include "CombatesUsuario.hpp"

const std::string MENSAJE_ESTADO_MODIFICADO_CORRECTAMENTE = "Se Modifico Correctamente el estado" ;
const std::string MENSAJE_TRANSFORMERS_CREADO_CORRECTAMENTE = "Se creo Correctamente el Transformers";
const std::string MENSAJE_ELIMINADADO_CORRECTAMENTE ="Se Elimino Correctamente el Transformers" ;
const std::string MENSAJE_TRANSFORMERS_ENCONTRADO = "Se encontro al Transformers";
const std::string MENSAJE_TRANSFORMERS_NO_ENCONTRADO = "No se encontro al Transformers";
const std::string ERROR_ENTRADA_INVALIDA = "Error: Entrada Inválida. Intente nuevamente.";
const std::string ERROR_LIMITE_EN_BOVEDA_EXCEDIDO = "Error: Limite en la Bóveda alcanzado";


const std::string MENSAJE_EQUIPADO_CON_EXITO = "Se Equipo con éxito el cristal mas Fuerte.";
const std::string MENSAJE_ALMACENADO_CON_EXITO = "Se almaceno con éxito el cristal.";
const std::string MENSAJE_ARCHIVO_CREADO_CORRECTAMENTE = "Se ha generado con éxito el archivo con la ruta suministrada.";
const std::string CANTIDAD_CRISTALES_ALMACENADOS = "Cantidad de Cristales Almacenados: ";
const std::string MENSAJE_CRISTAL_OBTENIDO = "EL cristal obtenido es: ";

const int POSICION_CRISTAL_MAS_PODEROSO = 0;

const int AUTO_FUERZA_INCIAL = 50;
const int AUTO_DEFENSA_INCIAL = 60;
const int AUTO_VELOCIDAD_INCIAL = 100;

const int CAMION_FUERZA_INCIAL = 120;
const int CAMION_DEFENSA_INCIAL = 80;
const int CAMION_VELOCIDAD_INCIAL = 60;

const int AVION_FUERZA_INCIAL = 60;
const int AVION_DEFENSA_INCIAL = 50;
const int AVION_VELOCIDAD_INCIAL = 100;

const int TANQUE_FUERZA_INCIAL = 90;
const int TANQUE_DEFENSA_INCIAL = 110;
const int TANQUE_VELOCIDAD_INCIAL = 30;

enum Faccion {
    AUTOBOTS,
    DECEPTICONS
};
enum Vehiculos{
    AUTO,
    CAMION,
    AVION,
    TANQUE
};


Juego::Juego(): protagonista(PERSONAJE_INVALIDO), juego_en_curso(true) {
    Cristal cristal_regalo(COMUN);
    boveda.almacenar_cristal(cristal_regalo);
}


void Juego::procesar_menu_principal(const char& opcion_menu, const std::string &nombre) {
    nombre_jugador = nombre;
    switch (opcion_menu) {
        case OPCION_1:
            menu.limpiar_menu();
            protagonista = Personaje(MEGATRON);
            manejar_flujo_juego_principal();
            break;
        case OPCION_2:
            menu.limpiar_menu();
            protagonista = Personaje(OPTIMUS_PRIME);
            manejar_flujo_juego_principal();
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
    protagonista.obtener_respuesta(mensaje);
    menu.mostrar_recuadro_inferior();
}


void Juego::manejar_sugerencia_personaje() {
    menu.limpiar_menu();
    menu.mostrar_recuadro_superior();
    protagonista.obtener_sugerencia();
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

void Juego::manejar_cambiar_estado(){
    menu.limpiar_menu();
    char indice_estado;
    menu.mostrar_menu_estado(protagonista.obtener_personaje());
    std::cin >> indice_estado;
    try {
        protagonista.actualizar_estado(indice_estado);
        menu.limpiar_y_mostrar_mensaje(MENSAJE_ESTADO_MODIFICADO_CORRECTAMENTE);
    } catch (ExcepcionProtagonista& e) {
        menu.mostrar_mensaje(e.what());
    }
}

void Juego::fusionador_de_cristales(const int &entrada_1, const int &entrada_2) {
    try {
        Cristal cristal_1(static_cast<Rareza>(entrada_1));
        Cristal cristal_2(static_cast<Rareza>(entrada_2));
        Cristal cristal_resultante;
        cristal_resultante = fusionador.fusionar(cristal_1, cristal_2);
        boveda.almacenar_cristal(cristal_resultante);
        menu.limpiar_y_mostrar_mensaje(MENSAJE_CRISTAL_OBTENIDO + cristal_resultante.convertir_rareza_a_string());
    } catch (ExcepcionFusionadorEnergon& e) {
        menu.limpiar_y_mostrar_mensaje(e.what());
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
        } else {
            menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
        }
    } else {
        menu.limpiar_y_mostrar_mensaje(ERROR_LIMITE_EN_BOVEDA_EXCEDIDO);
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
            menu.limpiar_y_mostrar_mensaje(MENSAJE_ALMACENADO_CON_EXITO);
        } catch (ExcepcionBovedaCristales& e) {
            menu.limpiar_y_mostrar_mensaje(e.what());
        }
    } else {
        menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

void Juego::mostrar_boveda() {
    menu.limpiar_menu();
    try {
        boveda.mostrar_cristales();
    } catch (ExcepcionBovedaCristales& e) {
        menu.mostrar_mensaje(e.what());
    }
}

void Juego::manejar_exportar_boveda(std::string &ruta) {
    menu.limpiar_menu();
    try {
        menu.mostrar_menu_exportar_archivo();
        std::cin >> ruta;
        boveda.exportar_cristales(ruta);
        menu.limpiar_y_mostrar_mensaje(MENSAJE_ARCHIVO_CREADO_CORRECTAMENTE);
    } catch (ExcepcionBovedaCristales& e) {
        menu.limpiar_y_mostrar_mensaje(e.what());
    }
}

void Juego::manejar_de_bodega_mostrar_tamanio() {
    menu.limpiar_menu();
    try{
        menu.mostrar_mensaje(CANTIDAD_CRISTALES_ALMACENADOS + std::to_string(boveda.tamanio()));
    } catch (ExcepcionBovedaCristales& e){
        menu.mostrar_mensaje(e.what());
    }
}

void Juego::manejar_equipar_un_cristal(){
    menu.limpiar_menu();
    try{
        protagonista.equipar_cristal(boveda.eliminar_cristal(POSICION_CRISTAL_MAS_PODEROSO));
        menu.mostrar_mensaje(MENSAJE_EQUIPADO_CON_EXITO);
    } catch (ExcepcionProtagonista& e){
        menu.mostrar_mensaje(e.what());
    }
}

void Juego::mostrar_cantidad_cristales_equipados(){
    menu.limpiar_menu();
    try{
        protagonista.ver_cristales_equipados();
    } catch (ExcepcionBovedaCristales& e){
        menu.mostrar_mensaje(e.what());
    }
}

void Juego::manejar_boveda() {
    menu.limpiar_menu();
    char opcion;
    bool continuar = true;
    std::string ruta;
    menu.menu_abriendo_boveda();
    while (continuar) {
        menu.mostrar_menu_boveda();
        std::cin >> opcion;
        switch (opcion) {
            case OPCION_1:
                manejar_de_almacenamiento_de_cristales();
                break;
            case OPCION_2:
                mostrar_boveda();
                break;
            case OPCION_3:
                manejar_exportar_boveda(ruta);
                break;
            case OPCION_4:
                manejar_de_bodega_mostrar_tamanio();
                break;
            case OPCION_5:
                menu.limpiar_y_mostrar_mensaje(CANTIDAD_CRISTALES_ALMACENADOS + std::to_string(protagonista.obtener_cantidad_cristales_equipados()));
                break;
            case OPCION_6:
                menu.limpiar_menu();
                boveda.obtener_cristal_mas_poderoso().mostrar();
                break;
            case OPCION_7:
                manejar_equipar_un_cristal();
                break;
            case OPCION_8:
                mostrar_cantidad_cristales_equipados();
                break;
             case OPCION_9:
                continuar = false;
                menu.limpiar_menu();
                menu.menu_cerranco_boveda();
                break;
            default:
                menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
        }
    }
}

std::string Juego::convertir_faccion_string(const int &faccion) {
    if (faccion == 0) { return FACCION_AUTOBOTS;}
    return FACCION_DECEPTICONS;
}

std::string Juego::solicitar_nombre_transformers(){
    std::string nombre_transformers;
    menu.limpiar_menu();
    menu.menu_ingregar_nombre_transformers();
    std::cin >> nombre_transformers;
    return nombre_transformers;
}

int Juego::solicitar_vehiculo(const int &faccion){
    int tipo_vihiculo;
    menu.limpiar_menu();
    menu.menu_escoger_vehiculo(faccion);
    std::cin >> tipo_vihiculo;
    return tipo_vihiculo;
}

int Juego::solicitar_faccion(){
    int faccion;
    menu.limpiar_menu();
    menu.menu_escoger_faccion();
    std::cin >> faccion;
    return faccion;
}

std::string Juego::convertir_vehiculo_string(const int &vehiculo){
    switch (vehiculo) {
        case 0:
            return VEHICULO_AUTO;
        case 1:
            return VEHICULO_CAMION;
        case 2:
            return VEHICULO_AVION;
        case 3:
            return VEHICULO_TANQUE;
        default:
            menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
            return "";
    }
}

void Juego::manejar_agregar_transformers(const std::string &nombre,const int &fuerza,const int &defensa,const int &velocidad,const std::string &faccion,const
                              std::string &vehiculo) {
    try{
        administrador_transformers.agregar_transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo);
    } catch (ExcepcionAdministradorTransformers& e){
        menu.limpiar_y_mostrar_mensaje(e.what());
    }
}


void Juego::crear_transformers(const std::string &nombre, const int &tipo_vehiculo){
    switch (tipo_vehiculo){
    case AUTO:
        manejar_agregar_transformers(nombre, calcular_estadistica(AUTO_FUERZA_INCIAL), calcular_estadistica(AUTO_DEFENSA_INCIAL), calcular_estadistica(AUTO_VELOCIDAD_INCIAL), convertir_faccion_string(AUTOBOTS), convertir_vehiculo_string(tipo_vehiculo));
        break;
    case CAMION:
        manejar_agregar_transformers(nombre, calcular_estadistica(CAMION_FUERZA_INCIAL), calcular_estadistica(CAMION_DEFENSA_INCIAL), calcular_estadistica(CAMION_VELOCIDAD_INCIAL), convertir_faccion_string(AUTOBOTS), convertir_vehiculo_string(tipo_vehiculo));
        break;
    case AVION:
        manejar_agregar_transformers(nombre, calcular_estadistica(AVION_FUERZA_INCIAL), calcular_estadistica(AVION_DEFENSA_INCIAL), calcular_estadistica(AVION_VELOCIDAD_INCIAL), convertir_faccion_string(DECEPTICONS), convertir_vehiculo_string(tipo_vehiculo));
        break;
    case TANQUE:
        manejar_agregar_transformers(nombre, calcular_estadistica(TANQUE_FUERZA_INCIAL), calcular_estadistica(TANQUE_DEFENSA_INCIAL), calcular_estadistica(TANQUE_VELOCIDAD_INCIAL), convertir_faccion_string(DECEPTICONS), convertir_vehiculo_string(tipo_vehiculo));
        break;
    default:
        menu.mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

void Juego::manejar_crear_autobots(const std::string &nombre){
    int tipo_vehiculo = solicitar_vehiculo(AUTOBOTS);
    if (tipo_vehiculo == AUTO || tipo_vehiculo == CAMION){
        crear_transformers(nombre, tipo_vehiculo);
        menu.limpiar_y_mostrar_mensaje(MENSAJE_TRANSFORMERS_CREADO_CORRECTAMENTE);
    } else {
        menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

void Juego::manejar_crear_decepticons(const std::string &nombre){
    int tipo_vehiculo = solicitar_vehiculo(DECEPTICONS);
    if (tipo_vehiculo == AVION || tipo_vehiculo == TANQUE){
        crear_transformers(nombre, tipo_vehiculo);
        menu.limpiar_y_mostrar_mensaje(MENSAJE_TRANSFORMERS_CREADO_CORRECTAMENTE);
    } else {
        menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

void Juego::manejar_crear_transformers(){
    menu.limpiar_menu();
    std::string nombre = solicitar_nombre_transformers();
    int faccion = solicitar_faccion();
    if (faccion == AUTOBOTS){
        manejar_crear_autobots(nombre);
    } else if (faccion == DECEPTICONS){
        manejar_crear_decepticons(nombre);
    } else{
        menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
    }
}

void Juego::manejar_buscar_transformers(){
    menu.limpiar_menu();
    const std::string nombre = solicitar_nombre_transformers();
    try {
        if (administrador_transformers.buscar_transformer(nombre) != BUSCAR_TRANSFORMER_NO_ENCONTRADO){
            menu.limpiar_menu();
            menu.menu_transformers_encontrado();
        } else {
            menu.limpiar_menu();
            menu.menu_transformers_no_encontrado();
        }
    } catch (ExcepcionAdministradorTransformers& e){
        menu.limpiar_y_mostrar_mensaje(e.what());
    }
}

void Juego::manejar_eliminar_transformers(){
    menu.limpiar_menu();
    const std::string nombre_transformers = solicitar_nombre_transformers();
    try {
        administrador_transformers.eliminar_transformer(nombre_transformers);
        menu.limpiar_y_mostrar_mensaje(MENSAJE_ELIMINADADO_CORRECTAMENTE);
    } catch (ExcepcionAdministradorTransformers& e){
        menu.limpiar_y_mostrar_mensaje(e.what());
    }
}

void Juego::manejar_transformar(){
    menu.limpiar_menu();
    std::string nombre_transformers = solicitar_nombre_transformers();
    try {
        administrador_transformers.transformar_transformer(nombre_transformers);
    } catch (ExcepcionAdministradorTransformers& e){
        menu.limpiar_y_mostrar_mensaje(e.what());
    }
}

void Juego::mostrar_transformers_secundarios(){
    menu.limpiar_menu();
    administrador_transformers.mostrar_todos_transformers();
}

void Juego::manejar_administrar_transformers(){
    bool continuar = true;
    char opcion_menu;
    while (continuar) {
        menu.mostrar_menu_administrador_transformers();
        std::cin >> opcion_menu;
        switch (opcion_menu) {
            case OPCION_1: //crear un transformers
                manejar_crear_transformers();
                break;
            case OPCION_2: // mostrar todos los transformers
                mostrar_transformers_secundarios();
                break;
            case OPCION_3: //Buscar un Transformer por nombre
                menu.limpiar_menu();
                manejar_buscar_transformers();
                break;
            case OPCION_4: // Eliminar un Transformer por nombre
                menu.limpiar_menu();
                manejar_eliminar_transformers();
                break;
            case OPCION_5: // Transformar un Transformer
                manejar_transformar();
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

void Juego::manejar_interactuar_con_el_personaje(){
    menu.limpiar_menu();
    bool continuar = true;
    char opcion_menu;
    while (continuar){
        menu.menu_interactuar_con_personaje(protagonista.obtener_personaje());
        std::cin >> opcion_menu;
        switch (opcion_menu) {
            case OPCION_1:
                manejar_opcion_escribir_mensaje();
                break;
            case OPCION_2:
                manejar_sugerencia_personaje();
                break;
            case OPCION_3:
                manejar_cambiar_estado();
                break;
            case OPCION_4:
                menu.limpiar_menu();
                continuar = false;
                break;
            default:
                menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
        }
    }
}

void Juego::mostrar_tabla_clasificacion(){
    menu.limpiar_menu();
    menu.mostrar_recuadro_superior();
    tabla_clasificacion.mostrar_top10_jugadores();
    menu.mostrar_recuadro_inferior();
}

void Juego::manejar_combate(){
    menu.limpiar_menu();
    if (protagonista.obtener_personaje() == MEGATRON){
        Transformers megatron(TEXTO_MEGATRON, 80, 90, 100, convertir_faccion_string(DECEPTICONS), convertir_vehiculo_string(AVION));
        CombatesUsuario combates_usuario(megatron, administrador_transformers.obtener_transformers_secundarios());
        combates_usuario.iniciar_partida_combates();
        if(combates_usuario.get_termino()){
            tabla_clasificacion.agregar_jugador(nombre_jugador, (int)combates_usuario.obtener_puntaje(), protagonista.obtener_personaje());
        }
    }else{
        Transformers optimus(TEXTO_OPTIMUS_PRIME, 80, 100, 70, convertir_faccion_string(AUTOBOTS), convertir_vehiculo_string(CAMION));
        CombatesUsuario combates_usuario(optimus, administrador_transformers.obtener_transformers_secundarios());
        combates_usuario.iniciar_partida_combates();
        if(combates_usuario.get_termino()){
            tabla_clasificacion.agregar_jugador(nombre_jugador, (int)combates_usuario.obtener_puntaje(), protagonista.obtener_personaje());
        }
    }
    
}

void Juego::manejar_flujo_juego_principal() {
    bool continuar = true;
    char opcion_menu;
    while (continuar) {
        menu.mostrar_menu_personaje(protagonista.obtener_personaje());
        std::cin >> opcion_menu;
        switch (opcion_menu) {
            case OPCION_1: // Interactuar con el personaje
                manejar_interactuar_con_el_personaje();
               break;
            case OPCION_2: // Fusionador
                manejar_fusionar_de_cristales();
                break;
            case OPCION_3: // Bóveda
                manejar_boveda();
                break;
            case OPCION_4: // Administrador
                menu.limpiar_menu();
                manejar_administrar_transformers();
                break;
        case OPCION_5: // Simulacion de Batalla
                manejar_combate();
                break;
            case OPCION_6: // Tabla Clasificación
                mostrar_tabla_clasificacion();
                break;
             case OPCION_7:
                menu.limpiar_menu();
                continuar = false;
            default:
                menu.limpiar_y_mostrar_mensaje(ERROR_ENTRADA_INVALIDA);
        }
    }
}

bool Juego::verificar_entrada_del_cristal(const int &entrada) {
    return entrada == COMUN || entrada == RARO || entrada == EPICO;
}

int Juego::calcular_estadistica(const int &estadistica_base){
    Utilidades generador;
    int cantidad_estadistica_extra = 10*(generador.generar_numero_aleatorio(1,3));
    int suma_resta = generador.generar_numero_aleatorio(1,2);
    if (suma_resta == 2){ //Si es igual a 2, lo tomamos como que debe restarse se multiplicará x -1
        cantidad_estadistica_extra = (-1) * cantidad_estadistica_extra;
    }
    return estadistica_base + cantidad_estadistica_extra;
}
