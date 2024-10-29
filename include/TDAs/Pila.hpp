#ifndef PILA_HPP
#define PILA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"

class ExcepcionPila : public std::runtime_error {
public:
    ExcepcionPila(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionPila(): runtime_error("") {
    }
};

template<typename T>
class Pila {
private:
    NodoLista<T>* ultimo_nodo;
    size_t cantidad_datos;

public:
    // Constructor.
    Pila();

    // Pre: -
    // Post: Agrega el dato al final de la pila.
    void alta(T dato);

    // Pre: La pila no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la pila.
    T baja();

    // Pre: La pila no puede estar vacía.
    // Post: Devuelve el primer dato de la pila.
    T primero();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la pila.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la pila esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    Pila(const Pila& pila) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Pila& pila) = delete;

    // Destructor.
    ~Pila();
};

template<typename T>
Pila<T>::Pila() {
}

template<typename T>
void Pila<T>::alta(T dato) {
}

template<typename T>
T Pila<T>::baja() {
}

template<typename T>
T Pila<T>::primero() {
}

template<typename T>
size_t Pila<T>::tamanio() {
}

template<typename T>
bool Pila<T>::vacio() {
}

template<typename T>
Pila<T>::~Pila() {
}

#endif
