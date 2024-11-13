#ifndef COLA_HPP
#define COLA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"
#include "Pila.hpp"
const std::string ERROR_COLA_VACIA = "ERROR: La cola está vacia";

class ExcepcionCola : public std::runtime_error {
public:
    ExcepcionCola(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionCola(): runtime_error("") {
    }
};

template<typename T>
class Cola {
private:

    NodoLista<T>* primer_nodo;
    NodoLista<T>* ultimo_nodo;
    size_t cantidad_datos;

public:
    // Constructor.
    Cola();

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato);

    // Pre: La cola no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la cola.
    T baja();

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato de la cola.
    T primero();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la cola esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    Cola(const Cola& cola) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Cola& cola) = delete;

    // Destructor.
    ~Cola();
};

template<typename T>
Cola<T>::Cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void Cola<T>::alta(T dato) {
    NodoLista<T>* nodo_nuevo = new NodoLista<T>(dato);
    nodo_nuevo->cambiar_siguiente(nullptr);
    if(cantidad_datos == 0){
        primer_nodo = nodo_nuevo;
        ultimo_nodo = primer_nodo;
    }
    else{
        NodoLista<T>* nodo_anterior_ultimo = ultimo_nodo;
        ultimo_nodo = nodo_nuevo;
        nodo_anterior_ultimo->cambiar_siguiente(ultimo_nodo);
    }
    cantidad_datos++;
}

template<typename T>
T Cola<T>::baja() {
    if(vacio()){
        throw ExcepcionCola(ERROR_COLA_VACIA);
    }
    NodoLista<T>* nodo_eliminar = primer_nodo;
    T dato_eliminado  = nodo_eliminar->obtener_dato();
    primer_nodo = primer_nodo->obtener_siguiente();
    delete nodo_eliminar;
    cantidad_datos--;
    return dato_eliminado;
}

template<typename T>
T Cola<T>::primero() {
    if(vacio()){
        throw ExcepcionCola(ERROR_COLA_VACIA);
    }
    return primer_nodo->obtener_dato();
}

template<typename T>
size_t Cola<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Cola<T>::vacio() {
    return (cantidad_datos == 0);
}

template<typename T>
Cola<T>::~Cola() {
    NodoLista<T>* nodo_liberar;
    for (int i = 0; i < cantidad_datos; i++){
        nodo_liberar = primer_nodo->obtener_siguiente();
        delete primer_nodo;
        primer_nodo = nodo_liberar;
    }
}

#endif
