#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoDiccionario.hpp"
#include "Vector.hpp"

class ExcepcionDiccionario : public std::runtime_error {
public:
    ExcepcionDiccionario(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionDiccionario(): runtime_error("") {
    }
};

// La clave debe implementar el operator<() y el operator==().
// Las claves menores a la clave de la raíz iran al subárbol izquierdo,
// mientras que las mayores iran al derecho.
template<typename Clave, typename T>
class Diccionario {
private:
    NodoDiccionario<Clave, T>* raiz;
    std::size_t cantidad_datos;

public:
    // Constructor.
    Diccionario();

    // Pre: La clave no puede existir en el diccionario.
    // Post: Agrega el dato asociado a la clave al diccionario. Si no hay datos, crea una nueva raíz.
    void alta(Clave clave, T dato);

    // Pre: La clave debe existir en el diccionario.
    // Post: Elimina el dato asociado a la clave del diccionario y lo devuelve.
    // NOTA: El caso de baja con dos hijos se resuelve con sucesor inmediato. Se puede hacer swap del dato.
    T baja(Clave clave);

    // Pre: La clave debe existir en el diccionario.
    // Post: Devuelve una referencia al valor asociado a la clave.
    T& operator[](Clave clave);

    // Pre: -
    // Post: Devuelve el recorrido inorder.
    Vector<T> inorder();

    // Pre: -
    // Post: Devuelve el recorrido preorder.
    Vector<T> preorder();

    // Pre: -
    // Post: Devuelve el recorrido postorder.
    Vector<T> postorder();

    // Pre: -
    // Post: Devuelve el recorrido en ancho (por niveles).
    Vector<T> ancho();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el diccionario.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el diccionario está vacío.
    bool vacio();

    // El constructor de copia está deshabilitado.
    Diccionario(const Diccionario& diccionario) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Diccionario& diccionario) = delete;

    // Destructor.
    ~Diccionario();
};

template<typename Clave, typename T>
Diccionario<Clave, T>::Diccionario() {
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::alta(Clave clave, T dato) {
}

template<typename Clave, typename T>
T Diccionario<Clave, T>::baja(Clave clave) {
}

template<typename Clave, typename T>
T& Diccionario<Clave, T>::operator[](Clave clave) {
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::inorder() {
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::preorder() {
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::postorder() {
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::ancho() {
}

template<typename Clave, typename T>
std::size_t Diccionario<Clave, T>::tamanio() {
}

template<typename Clave, typename T>
bool Diccionario<Clave, T>::vacio() {
}

template<typename Clave, typename T>
Diccionario<Clave, T>::~Diccionario() {
}

#endif
