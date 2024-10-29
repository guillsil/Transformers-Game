#ifndef COLA_HPP
#define COLA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"

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
}

template<typename T>
void Cola<T>::alta(T dato) {
}

template<typename T>
T Cola<T>::baja() {
}

template<typename T>
T Cola<T>::primero() {
}

template<typename T>
size_t Cola<T>::tamanio() {
}

template<typename T>
bool Cola<T>::vacio() {
}

template<typename T>
Cola<T>::~Cola() {
}

#endif
