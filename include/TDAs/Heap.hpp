#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef>
#include <stdexcept>
#include "Vector.hpp"

class ExcepcionHeap : public std::runtime_error {
public:
    ExcepcionHeap(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionHeap(): runtime_error("") {
    }
};

// El dato debe implementar el operator<() y el operator>().
template<typename T>
class Heap {
private:
    Vector<T> datos;

public:
    // Constructor default.
    Heap();

    // Constructor. El parámetro indica si el heap es de máxima o de mínima.
    // Si es de máxima, utiliza el operador >. Si es de mínima, utiliza el <.
    Heap(bool maxima);

    // Pre: -
    // Post: Agrega el dato al heap.
    void alta(T dato);

    // Pre: El heap no puede estar vacío.
    // Post: Elimina y devuelve el primer dato.
    T baja();

    // Pre: El heap no puede estar vacío.
    // Post: Devuelve el primer dato.
    T primero();

    // Pre: -
    // Post: Devuelve true si el heap está vacío.
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el heap.
    size_t tamanio();

    // Destructor.
    ~Heap();
};

template<typename T>
Heap<T>::Heap() {
}

template<typename T>
Heap<T>::Heap(bool maxima) {
}

template<typename T>
void Heap<T>::alta(T dato) {
}

template<typename T>
T Heap<T>::baja() {
}

template<typename T>
T Heap<T>::primero() {
}

template<typename T>
bool Heap<T>::vacio() {
}

template<typename T>
size_t Heap<T>::tamanio() {
}

template<typename T>
Heap<T>::~Heap() {
}

#endif
