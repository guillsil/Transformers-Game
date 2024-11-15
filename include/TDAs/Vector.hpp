#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>
const std::string ERROR_VECTOR_VACIO = "VectorDinamico:: Vector Vacío.";
const std::string ERROR_INDICE_FUERA_DE_RANGO = "VectorDinamico:: Posición fuera de rango.";
const size_t TAMANIO_INICIAL_VECTOR = 20;


class ExcepcionVector : public std::runtime_error {
public:
    ExcepcionVector(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionVector(): runtime_error("") {
    }
};



template<typename T>
class Vector {
private:
    T* datos;
    size_t tamanio_logico; // cantidad_de_elementos
    size_t tamanio_fisico; // tamanio
    const size_t tamanio_inicial; // Constante donde se guardara el tamaño inicial del vector que el usurio ingresa. Si no ingresa el tamaño inicial el que ocupara su lugar será TAMANIO_INICIAL_VECTOR que por defecto es de 20.

    void redimensionar(const size_t &nuevo_tamanio);

public:
    // Constructor.
    Vector();

    //Constructor con atributo para un tamaño inicial.
    Vector(size_t tamanio_inicial);

    //Contructor con un inicializador.
    Vector(size_t tamanio_inicial, T inicializador);

    // Constructor de copia (ya implementado).
    Vector(const Vector& vector);

    // Destructor.
    ~Vector();

    // PRE: El índice debe ser menor que la cantidad de datos.
    // POST: Devuelve una referencia al dato indicado.
    T& operator[](size_t indice);

    // Operador de asignación (ya implementado).
    Vector& operator=(const Vector& vector);

    // PRE: -
    // POST: Agrega el dato al final del vector.
    void alta(T dato);

    // PRE: El índice debe ser menor o igual que la cantidad de datos.
    // POST: Agrega el dato en el índice indicado,
    // moviendo todos los elementos siguientes.
    // Ejemplo:
    //      >> 1 3 2 7 0
    // alta(9, 2);
    //      >> 1 3 9 2 7 0
    void alta(T dato, size_t indice);

    // PRE: El vector no puede estar vacío.
    // POST: Elimina el último dato y lo devuelve.
    T baja();

    // PRE: El índice debe ser menor que la cantidad de datos.
    // POST: Elimina el dato en la posición indicada,
    // moviendo todos los elementos siguientes, y lo devuelve.
    // Ejemplo:
    //      >> 1 3 2 7 0
    // baja(1);
    //      >> 1 2 7 0
    T baja(size_t indice);

    // PRE: -
    // POST: Devuelve true si el vector está vacío (es decir, si no hay datos).
    bool vacio();

    // PRE: -
    // POST: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    //Pre:-
    //Post: Imprime por consola los elementos del vector
    void mostrar();

    //Pre: -
    //Post: Elimina todos los elementos del vector, estableciendo su tamaño lógico en 0.
    void limpiar();

    //Pre: -
    //Post: Invierte el orden de los elementos del vector.
    void invertir();
};

template<typename T>
void Vector<T>::redimensionar(const size_t &nuevo_tamanio) {
    T * nuevo_vector = new T[nuevo_tamanio];
    for (size_t i = 0; i < tamanio_logico; i++) {
        nuevo_vector[i] = datos[i];
    }
    delete[] datos;
    datos = nuevo_vector;
    tamanio_fisico = nuevo_tamanio;
}

template<typename T>
Vector<T>::Vector(): datos(new T[TAMANIO_INICIAL_VECTOR]), tamanio_logico(0), tamanio_fisico(TAMANIO_INICIAL_VECTOR),
                     tamanio_inicial(TAMANIO_INICIAL_VECTOR) {
}

template<typename T>
Vector<T>::Vector(size_t tamanio_inicial): datos(new T[tamanio_inicial]), tamanio_logico(0),
                                           tamanio_fisico(tamanio_inicial), tamanio_inicial(tamanio_inicial) {
}

template <typename T>
Vector<T>::Vector(size_t tamanio_inicial, T inicializador): datos(new T[tamanio_inicial]), tamanio_logico(tamanio_inicial), tamanio_fisico(tamanio_inicial*2), tamanio_inicial(tamanio_inicial) {
    for (size_t i = 0; i < tamanio_inicial; i++){
        datos[i] = inicializador;
    }
}

template<typename T>
void Vector<T>::alta(T dato) {
    if (tamanio_logico == tamanio_fisico) {
        redimensionar(tamanio_fisico + tamanio_fisico/2);
    }
    datos[tamanio_logico] = dato;
    tamanio_logico++;
}

template<typename T>
void Vector<T>::alta(T dato, size_t indice) {
    if (indice > tamanio_logico) {
        throw  ExcepcionVector(ERROR_INDICE_FUERA_DE_RANGO);
    }
    if (tamanio_logico == tamanio_fisico) {
        redimensionar(tamanio_fisico + tamanio_fisico/2);
    }
    for (size_t j = tamanio_logico; j > indice; j--) {
                datos[j] = datos[j - 1];
    }
    datos[indice] = dato;
    tamanio_logico++;
}

template<typename T>
T Vector<T>::baja() {
    if (tamanio_logico == 0) {
        throw ExcepcionVector(ERROR_VECTOR_VACIO);
    }
    T dato = datos[tamanio_logico-1];
    tamanio_logico--;
    if (tamanio_logico < tamanio_fisico/2 && tamanio_fisico > tamanio_inicial) {
        redimensionar(tamanio_fisico / 2);
    }
    return dato;
}

template<typename T>
T Vector<T>::baja(size_t indice) {
    if (indice >= tamanio_logico) {
        throw ExcepcionVector(ERROR_INDICE_FUERA_DE_RANGO);
    }
    T dato = datos[indice];
    for (size_t j = indice; j < tamanio_logico - 1; j++) {
        datos[j] = datos[j + 1];
    }
    tamanio_logico--;

    if (tamanio_logico < tamanio_fisico/2 && tamanio_fisico > tamanio_inicial) {
        redimensionar(tamanio_fisico / 2);
    }
    return dato;
}

template<typename T>
bool Vector<T>::vacio() {
    return tamanio_logico == 0;
}

template<typename T>
size_t Vector<T>::tamanio() {
    return tamanio_logico;
}

template<typename T>
void Vector<T>::mostrar() {
    if (tamanio_logico == 0) {
        throw ExcepcionVector(ERROR_VECTOR_VACIO);
    }
    for (size_t i = 0; i < tamanio_logico; i++) {
        std::cout << datos[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::limpiar(){
    tamanio_logico = 0;
    if (tamanio_fisico > tamanio_inicial){
        redimensionar(tamanio_inicial);
    }
}

template <typename T>
void Vector<T>::invertir(){
    if (tamanio_logico == 0){
        throw ExcepcionVector(ERROR_VECTOR_VACIO);
    }
    size_t i = 0;
    size_t j = tamanio_logico - 1;
    while (i < j){
        T temp = datos[i];
        datos[i] = datos[j];
        datos[j] = temp;
        i++;
        j--;
    }
}

template<typename T>
T& Vector<T>::operator[](size_t indice) {
    if (tamanio_logico == 0 || indice >= tamanio_logico || indice > tamanio_fisico) {
        throw ExcepcionVector(ERROR_INDICE_FUERA_DE_RANGO);
    }
    return datos[indice];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] datos;
}

// Ya implementado. No hace falta modificarlo.
template<typename T>
Vector<T>::Vector(const Vector& vector): tamanio_inicial(0) {
    datos = nullptr;
    tamanio_logico = vector.tamanio_logico;
    tamanio_fisico = vector.tamanio_fisico;
    if (tamanio_fisico) {
        datos = new T[tamanio_fisico];
        for (size_t i = 0; i < tamanio_logico; i++) {
            datos[i] = vector.datos[i];
        }
    }
}

// Ya implementado. No hace falta modificarlo.
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector) {
    if (this != &vector) {
        delete[] datos;
        datos = nullptr;
        tamanio_logico = vector.tamanio_logico;
        tamanio_fisico = vector.tamanio_fisico;
        if (tamanio_fisico) {
            datos = new T[tamanio_fisico];
            for (size_t i = 0; i < tamanio_logico; i++) {
                datos[i] = vector.datos[i];
            }
        }
    }
    return *this;
}

#endif
