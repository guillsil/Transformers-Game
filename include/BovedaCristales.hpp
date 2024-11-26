#ifndef BOVEDACRISTALES_HPP
#define BOVEDACRISTALES_HPP

#include <Cristal.hpp>
#include <stdexcept>
#include <string>
#include "TDAs/Vector.hpp"
#include "ControlArchivo.hpp"
#include <filesystem>


const size_t TAMANIO_MAXIMO_DE_CRISTALES = 20;

class ExcepcionBovedaCristales : public std::runtime_error {
public:
    ExcepcionBovedaCristales(std::string mensaje): runtime_error(mensaje) {}

    ExcepcionBovedaCristales(): runtime_error("") {}

};

class BovedaCristales {
public:
    //Constructor
    //Pre: -
    //Post: Crea una Bóveda con un TAMANIO_MAXIMO_DE_CRISTALES.
    BovedaCristales();

    //Constructor con tamanio_inicial de la boveda
    //Pre: -
    //Post: Crea una Bóveda con un tamanio_inicial.
    BovedaCristales(size_t tamanio_inicial);

    //Pre: La cantidad de cristales almacenados debe ser menor a TAMANIO_MAXIMO_DE_CRISTALES
    //Post: Almacena en la bóveda el cristal suministrado.
    void almacenar_cristal(Cristal cristal_nuevo);

    //Pre: La bóveda no debe estar Vaciá.
    //Post: Muestra por consola los cristales almacenados.
    void mostrar_cristales();

    //Pre: La posición debe estar dentro del rango de elementos almacenados.
    //Post: Devuelve el cristal de la posición indicada y lo elimina de la bóveda.
    Cristal obtener_cristal(size_t posicion);

    //Pre: ruta debe ser no vació.
    //Post: Se crea o actuliza el archivo en la ruta suministrada.
    //• Si la ruta contiene solo un nombre, este se tomará como el nombre del archivo y se guardará en el DIRECTORIO_BASE.
    //• Si la ruta contiene un directorio y un archivo se guardará en el DIRECTORIO_BASE tanto el nuevo directorio junto a su archivo.
    //El archivo csv tendrá la información de todos los cristales almacenados con el siguiente formato:
    //Formato del archivo CSV: (Nivel de Rareza, Fuerza, Defensa, Velocidad)
    void exportar_cristales(std::string ruta);

    //Pre: -
    //Post: Devuelve true si la bóveda esta, vaciá y false en caso contrario.
    bool esta_vacia();

    //Pre: -
    //Post: Devuelve el tamaño de la bóveda.
    size_t tamanio();

    //Pre: -
    //Post: Elimina el Cristal en el inidice pasado.
    Cristal eliminar_cristal(const int &indice);

    //Pre: -
    //Post: Devuelve el Cristal más poderoso que se encuentra en la bóveda que siempre se encontrara en la primera posición de
    //la bóveda, ya que la bóveda está ordenada de manera descendente.
    Cristal obtener_cristal_mas_poderoso();

private:
    Vector<Cristal> cristales;

    size_t tamanio_inicial;

    Menu menu;

    //Pre: La ruta debe ser no vaciá.
    //Post: Completa la ruta, colocando la ruta suministrada dentro de la carpeta para añadir archivos llamada "archivos".
    std::string construir_ruta_completa(std::string& ruta);

    //Pre: La ruta debe ser no vaciá.
    //Post: Crea los directorios necesarios para almacenar el archivo en la ruta especificada.
    void crear_directorios(const std::string& ruta);
};

#endif
