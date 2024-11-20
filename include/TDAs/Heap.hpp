#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef>
#include <stdexcept>
#include "Vector.hpp"

const bool MAXIMA = true;
const bool MINIMA = false;
const std::string ERROR_ESTA_VACIO = "ERROR:: Esta vácio";

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
    bool operador;
    //Pre:
    //Post:
    T baja_recursiva(bool maxima, size_t indice, size_t hijo_izquierdo, size_t hijo_derecho);

    //Pre: -
    //Post: Se intercambia el elemento en la posición indice1 con el de la posición indice2.
    void intercambiar(size_t indice_1, size_t indice_2);

    //Pre: Índice debe estar en el rango 0 y tamaño de los datos.
    //Post: El elemento en la posición índice (Sube) hacia su posición correcta en el heap
    void subir(size_t indice);

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

template <typename T>
void Heap<T>::intercambiar(size_t indice_1, size_t indice_2){
    T aux = datos[indice_1];
    datos[indice_1] = datos[indice_2];
    datos[indice_2] = aux;
}

template <typename T>
void Heap<T>::subir(size_t indice){
    size_t padre = (indice - 1) / 2;
    if(operador){
        while (datos[indice] > datos[padre] && indice != 0){
            intercambiar(indice, padre);
            indice = padre;
            if(indice != 0) padre = (indice - 1) / 2;
        }
    }else{
        while (datos[indice] < datos[padre] && indice != 0){
            intercambiar(indice, padre);
            indice = padre;
            if(indice != 0) padre = (indice - 1) / 2;
        }
    }
}

template<typename T>
T Heap<T>::baja_recursiva(bool maxima, size_t indice, size_t hijo_izquierdo, size_t hijo_derecho){
    if(tamanio() == 1) return datos.baja();
    if(indice == 0){
        intercambiar(indice, tamanio() - 1);
    }
    if(hijo_izquierdo < tamanio() && hijo_izquierdo != tamanio() - 1){
        if(hijo_derecho < tamanio() && hijo_derecho != tamanio() - 1){
            if(datos[hijo_derecho] > datos[hijo_izquierdo]){
                if(maxima){
                    intercambiar(indice, hijo_derecho);
                    return baja_recursiva(maxima, hijo_derecho, hijo_derecho * 2 + 1, hijo_derecho * 2 + 2);
                }else{
                    intercambiar(indice, hijo_izquierdo);
                    return baja_recursiva(maxima, hijo_izquierdo, hijo_izquierdo * 2 + 1, hijo_izquierdo * 2 + 2);
                }
            }
        }
        intercambiar(indice, hijo_izquierdo);
        return baja_recursiva(maxima, hijo_izquierdo, hijo_izquierdo * 2 + 1, hijo_izquierdo * 2 + 2);
    }
    return datos.baja();
}



template<typename T>
Heap<T>::Heap() {
    operador = MAXIMA;
}

template<typename T>
Heap<T>::Heap(bool maxima) {
    operador = maxima;
}

template<typename T>
void Heap<T>::alta(T dato) {
    datos.alta(dato);
    if(tamanio() != 1){
        subir(tamanio() - 1);
    }
}

template<typename T>
T Heap<T>::baja() {
    if(vacio())
        throw ExcepcionHeap(ERROR_ESTA_VACIO);
    return baja_recursiva(operador, 0, 1, 2);
}

template<typename T>
T Heap<T>::primero() {
    if(vacio())
        throw ExcepcionHeap(ERROR_ESTA_VACIO);
    return datos[0];
}

template<typename T>
bool Heap<T>::vacio() {
    return datos.vacio();
}

template<typename T>
size_t Heap<T>::tamanio() {
    return datos.tamanio();
}

template<typename T>
Heap<T>::~Heap() {
}

#endif