#ifndef ADMIN_TRANSFORMERS_HPP
#define ADMIN_TRANSFORMERS_HPP

#include <iostream>
#include <string>
#include "TDAs/Vector.hpp"
#include "Transformers.hpp"
#include "ControlArchivo.hpp"

class ExcepcionAdministradorTransformers : public std::runtime_error {
public:
    ExcepcionAdministradorTransformers(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionAdministradorTransformers(): runtime_error("") {
    }
};

class AdministradorTransformers{
private:
    const std::string RUTA_ARCHIVO_TRANSFORMERS = "transformers.csv";
    const std::string MENSAJE_ERROR_NO_ENCONTRADO = "No se encontró el transformer buscado";
    const std::string MENSAJE_ERROR_VACIO = "No hay transformers para administrar.";
    const std::string MENSAJE_FUERA_RANGO = "Fuera de rango";
    const size_t NO_ENCONTRADO = -1;

    Vector<Transformers> lista_transformers;
    ControlArchivo<Transformers> control_archivo_transformers;
public:
    //Constructor
    AdministradorTransformers();

    //Pre:
    //Post: Agrega un nuevo transformer a vector lista_transformers
    void agregar_transformer(std::string nombre, int fuerza, int defensa, int velocidad, std::string faccion, std::string vehiculo);
    
    //Pre:
    //Post: Elimina un transformer segun el nombre
    //Ver si se devuelve y se elimina x pantalla o que se hace, usar buscar y operador [] para mejor rendimiento
    Transformers eliminar_transformer(std::string nombre);
    
    //Pre:
    //Post: Buscar un transformer segun el nombre, devuelve su posicion en lista_transformers. Si devuelve -1, no lo encontró;
    //Pensar que debe devolver (posicion? = size_t)
    size_t buscar_transformer(std::string nombre);
    
    //Pre:
    //Post: Muestra a todos los transformers de la lista_transformer por terminal
    void mostrar_todos_transformers();

    //Pre:
    //Post: Devuelve el trasformer en la posicion indice del vector lista_transformers
    Transformers operator[](size_t indice);

    //Pre:
    //Post: Cambia de forma al transformer al opuesto al que estaba.
    // Transformado = true -> false ó Transformado = false -> true
    void transformar_transformer(std::string nombre);

    //Destructor
    ~AdministradorTransformers();

};

#endif