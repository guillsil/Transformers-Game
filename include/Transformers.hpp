#ifndef TRANSFORMERS_HPP
#define TRANSFORMERS_HPP

#include <iostream>
#include <string>

#include "TDAs/Vector.hpp"
#include "Estadisticas.hpp"

//Constantes que podrian ser globales para todo el tp
const std::string FACCION_AUTOBOTS = "Autobots";
const std::string FACCION_DECEPTICONS = "Decepticons";
const std::string VEHICULO_AUTO = "Auto";
const std::string VEHICULO_CAMION = "Camion";
const std::string VEHICULO_AVION = "Avion";
const std::string VEHICULO_TANQUE = "Tanque";
const int ESTADISTICAS_AUMENTO = 10;
const int ESTADISTICAS_REDUCCION = -10;
//Segun el tp, si las estadisticas cambian normal, mucho o totalmente;
const int CAMBIO_NORMAL = 2;
const int CAMBIO_MUCHO = 3;
const int CAMBIO_TOTALMENTE = 4;

//NOMBRE,FUERZA,DEFENSA,VELOCIDAD,FACCIÓN,VEHÍCULO,TRANSFORMADO


class Transformers {
private:
    std::string nombre, faccion, vehiculo;
    Estadisticas estadisticas;
    //int fuerza, defensa, velocidad;


    //Pre:
    //Post: Cambia la estadistica pasada por puntero segun el numero de cambio

    int calcular_bonificacion(int estadistica_base, int multiplicador, int indicador_aumento_reduccion);


    //Pre:
    //Post: Cambia las estadisticas dependiendo del vehiculo que es el transformer. Se usa luego de la transformacion.
    //Agregar mejor descripcion
    void chequeo_vehiculo(bool al_reves);

    //Pre:
    //Post: Chequea el estado de transformado del transformer pasado y devuele un string que contiene Si o No
    bool pase_texto_bool_transformado(std::string texto_transformado);

public:
    //Constructor auxiliar para que funcione el programa
    Transformers();

    //Constructor con todos los datos
    Transformers(std::string nombre, int fuerza, int defensa, int velocidad, std::string faccion, std::string vehiculo, bool transformado);
    
    //Constructor sin transformado
    Transformers(std::string nombre, int fuerza, int defensa, int velocidad, std::string faccion, std::string vehiculo);
    
    //Constructor para crear en el ControlArchivo
    Transformers(Vector<std::string>& elementos);

    //Pre: -
    //Post: Devuelve el nombre del transformer
    std::string obtener_nombre();

    //Pre: -
    //Post: Cambia el estado del transformado.
    void cambiar_forma();

    //Pre: -
    //Post: Devuelve la suma de las estadisticas
    size_t obtener_poder();

    //Pre: -
    //Post: Devuelve true si los transformers son de la misma faccion.
    bool operator==(const Transformers& otro_transformer);

    //Pre: -
    //Post: Copia un trasformer en otro transformer
    Transformers& operator=(const Transformers& otro_transformer);

    //Pre: -
    //Post: Devuelve true si los transformers son igual de fuertes. Condicion: 2 de sus estadisticas deben ser iguales.
    bool son_iguales_fuerza(Transformers otro_transformer);

    //Pre:
    //Post: Devuelve true si un transformer es más fuerte que el otro. Condicion: 2 de sus estadisticas deben ser mayores que el otro.
    bool es_mas_fuerte(Transformers otro_transformer);

    //Pre: -
    //Post: Muestra los datos de Transformers por terminal
    void mostrar();

    // Pre: -
    // Post: Carga la información al stream de salida.
    friend std::ostream& operator<<(std::ostream& os, const Transformers& transformer);

};

#endif