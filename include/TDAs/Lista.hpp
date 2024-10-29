#ifndef LISTA_HPP
#define LISTA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"

class ExcepcionLista : public std::runtime_error {
public:
    ExcepcionLista(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionLista(): runtime_error("") {
    }
};

// La lista es 0-indexed (es decir, la primera posición es 0).
template<typename T>
class Lista {
private:
    NodoLista<T>* primer_nodo;
    NodoLista<T>* ultimo_nodo;
    NodoLista<T>* cursor;
    size_t cantidad_datos;

public:
    // Constructor.
    Lista();

    // Pre: -
    // Post: Agrega el dato al principio de la lista.
    void alta_principio(T dato);

    // Pre: -
    // Post: Agrega el dato al final de la lista.
    void alta_final(T dato);

    // Pre: La lista no puede estar vacía.
    // Post: Elimina el primer dato y lo devuelve.
    T baja_primero();

    // Pre: La lista no puede estar vacía.
    // Post: Elimina el último dato y lo devuelve.
    T baja_ultimo();

    // Pre: La posición debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada.
    // Ejemplo:
    //      >> 8 5 2 7 1
    // insertar(9, 2);
    //      >> 8 5 9 2 7 1
    void insertar(T dato, size_t posicion);

    // Pre: La posición debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada y lo devuelve.
    // Ejemplo:
    //      >> 8 5 2 7 1
    // eliminar(3);
    //      >> 8 5 2 1
    T eliminar(size_t posicion);

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve una referencia al primer dato de la lista.
    T& primero();

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve una referencia al último dato de la lista.
    T& ultimo();

    // Pre: -
    // Post: Reinicia el cursor al principio o al final de la lista, según lo indicado.
    void reiniciar_cursor(bool principio);

    // Pre: Se debe poder avanzar (es decir, el cursor debe apuntar a un nodo siguiente).
    // Post: Avanza el cursor al nodo siguiente del actual.
    void avanzar();

    // Pre: Se debe poder retroceder (es decir, el cursor debe apuntar a un nodo anterior).
    // Post: Retrocede el cursor al nodo anterior del actual.
    void retroceder();

    // Pre: El cursor debe apuntar a un nodo válido.
    // Post: Devuelve una referencia al dato actual (cursor).
    T& elemento();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la lista esta vacía (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    Lista(const Lista& lista) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Lista& lista) = delete;

    // Destructor.
    ~Lista();
};

template<typename T>
Lista<T>::Lista() {
}

template<typename T>
void Lista<T>::alta_principio(T dato) {
}

template<typename T>
void Lista<T>::alta_final(T dato) {
}

template<typename T>
T Lista<T>::baja_primero() {
}

template<typename T>
T Lista<T>::baja_ultimo() {
}

template<typename T>
void Lista<T>::insertar(T dato, size_t posicion) {
}

template<typename T>
T Lista<T>::eliminar(size_t posicion) {
}

template<typename T>
T& Lista<T>::primero() {
}

template<typename T>
T& Lista<T>::ultimo() {
}

template<typename T>
void Lista<T>::reiniciar_cursor(bool principio) {
}

template<typename T>
void Lista<T>::avanzar() {
}

template<typename T>
void Lista<T>::retroceder() {
}

template<typename T>
T& Lista<T>::elemento() {
}

template<typename T>
size_t Lista<T>::tamanio() {
}

template<typename T>
bool Lista<T>::vacio() {
}

template<typename T>
Lista<T>::~Lista() {
}

#endif
