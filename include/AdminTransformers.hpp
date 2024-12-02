#ifndef ADMIN_TRANSFORMERS_HPP
#define ADMIN_TRANSFORMERS_HPP

#include <iostream>
#include <string>
#include "TDAs/Vector.hpp"
#include "Transformers.hpp"
#include "ControlArchivo.hpp"

const size_t BUSCAR_TRANSFORMER_NO_ENCONTRADO = -1;

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
    const std::string ERROR_TRANSFORMER_NO_ENCONTRADO = "RESULTADO:: No se encontró el transformer buscado";
    const std::string ERROR_LISTA_TRANSFORMERS_VACIO = "ERROR:: No hay Transformers secundarios para controlar";
    const std::string ERROR_INDICE_FUERA_DE_RANGO = "ERROR:: Posición fuera de rango.";

    Vector<Transformers> lista_transformers;
    ControlArchivo<Transformers> control_archivo_transformers;
    Menu menu;
public:
    //Constructor
    AdministradorTransformers();

    //Pre: -
    //Post: Agrega un nuevo transformer a vector lista_transformers
    void agregar_transformer(std::string nombre, int fuerza, int defensa, int velocidad, std::string faccion, std::string vehiculo);
    
    //Pre: El vector lista_transformers no debe estar vacio
    //Post: Elimina un transformer segun el nombre
    //Ver si se devuelve y se elimina x pantalla o que se hace, usar buscar y operador [] para mejor rendimiento
    Transformers eliminar_transformer(std::string nombre);
    
    //Pre: -
    //Post: Buscar un transformer segun el nombre, devuelve su posicion en lista_transformers.
    // Si no lo encuentra devuelve un numero fuera de rango
    size_t buscar_transformer(std::string nombre);
    
    //Pre: -
    //Post: Muestra a todos los transformers de la lista_transformer por terminal
    void mostrar_todos_transformers();

    //Pre: -
    //Post: Devuelve la lista_transformers
    Vector<Transformers>& obtener_transformers_secundarios();

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