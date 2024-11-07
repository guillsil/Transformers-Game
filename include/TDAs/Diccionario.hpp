#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoDiccionario.hpp"
#include "Vector.hpp"

const bool BAJA = true;
const bool BUSQUEDA = false;
const int PREORDER = 0;
const int POSTORDER = 0;
const int INORDER = 0;

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

    int calcular_altura(NodoDiccionario<Clave, T>* nodo);
    Vector<T> ancho_recursivo(NodoDiccionario<Clave, T>* nodo);
    void obtener_nodos_nivel(NodoDiccionario<Clave, T>* nodo, int nivel, Vector<T>& resultado);
    void alta_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave, T dato);
    T busqueda_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave, bool que_hacer);
    void orden_recursivo(Vector<T> vector, NodoDiccionario<Clave, T>* nodo, int tipo_orden);
    NodoDiccionario<Clave, T>* inmediato_sucesor(NodoDiccionario<Clave, T>* nodo, Clave clave);
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
    // Post: Devuelve el total inorder.
    Vector<T> inorder();

    // Pre: -
    // Post: Devuelve el total preorder.
    Vector<T> preorder();

    // Pre: -
    // Post: Devuelve el total postorder.
    Vector<T> postorder();

    // Pre: -
    // Post: Devuelve el total en ancho (por niveles).
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
    raiz = 0;
    cantidad_datos = 0;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::alta(Clave clave, T dato){
    if(raiz)
        alta_recursiva(raiz, clave, dato);
    else
        raiz = new NodoDiccionario<Clave, T>(clave, dato);
    cantidad_datos++;
}

template<typename Clave, typename T>
T Diccionario<Clave, T>::baja(Clave clave) {
    return busqueda_recursiva(raiz, clave, BAJA);
}

template<typename Clave, typename T>
T& Diccionario<Clave, T>::operator[](Clave clave) {
    T valor_buscado = busqueda_recursiva(raiz, clave, BUSQUEDA); 
    return valor_buscado;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::inorder() {
    Vector<T> vec;
    orden_recursivo(vec, raiz, INORDER);
    return vec;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::preorder() {
    Vector<T> vec;
    orden_recursivo(vec, raiz, PREORDER);
    return vec;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::postorder() {
    Vector<T> vec;
    orden_recursivo(vec, raiz, POSTORDER);
    return vec;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::ancho() {
    Vector<T> vec;
    if(raiz){
        vec = ancho_recursivo(raiz);
    }
    return vec;
}

template<typename Clave, typename T>
std::size_t Diccionario<Clave, T>::tamanio() {
    return cantidad_datos;
}

template<typename Clave, typename T>
bool Diccionario<Clave, T>::vacio() {
    return (raiz == 0);
}

template<typename Clave, typename T>
Diccionario<Clave, T>::~Diccionario() {
    delete raiz;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::alta_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave, T dato){
    if(nodo->obtener_clave() == clave)
        throw ExcepcionDiccionario("La clave existe");
    if(nodo->obtener_clave() > clave){
        if(nodo->obtener_hijo_izquierdo())
            alta_recursiva(nodo->obtener_hijo_izquierdo(), clave, dato);
        else
            nodo->cambiar_hijo_izquierdo(new NodoDiccionario<Clave, T>(clave, dato, nodo, 0, 0));
    }
    if(nodo->obtener_clave() < clave){
        if(nodo->obtener_hijo_derecho())
            alta_recursiva(nodo->obtener_hijo_derecho(), clave, dato);
        else
            nodo->cambiar_hijo_derecho(new NodoDiccionario<Clave, T>(clave, dato, nodo, 0, 0));
    }
}

template<typename Clave, typename T>
T Diccionario<Clave, T>::busqueda_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave, bool que_hacer){
    if(nodo->obtener_clave() == clave){
        T dato = nodo->obtener_dato();
        if(que_hacer){
            NodoDiccionario<Clave, T>* aux = inmediato_sucesor(nodo, clave);
            nodo->cambiar_clave(aux->obtener_clave());
            nodo->cambiar_dato(aux->obtener_dato());
            delete aux;
            cantidad_datos--;
        }
        return dato;
    }
    if(nodo->obtener_clave() > clave){
        if(nodo->obtener_hijo_izquierdo())
            return busqueda_recursiva(nodo->obtener_hijo_izquierdo(), clave, que_hacer);
        else
            throw ExcepcionDiccionario("La clave no existe");
    }
    if(nodo->obtener_clave() < clave){
        if(nodo->obtener_hijo_derecho())
            return busqueda_recursiva(nodo->obtener_hijo_derecho(), clave, que_hacer);
        else
            throw ExcepcionDiccionario("La clave no existe");
    }
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::orden_recursivo(Vector<T> vector, NodoDiccionario<Clave, T>* nodo, int tipo_orden){
    if(tipo_orden == PREORDER)
        vector.alta(nodo->obtener_dato());
    if(nodo->obtener_hijo_izquierdo())
        orden_recursivo(vector, nodo->obtener_hijo_izquierdo(), tipo_orden);
    if(tipo_orden == INORDER)
        vector.alta(nodo->obtener_dato());
    if(nodo->obtener_hijo_derecho())
        orden_recursivo(vector, nodo->obtener_hijo_derecho(), tipo_orden);
    if(tipo_orden == POSTORDER)
        vector.alta(nodo->obtener_dato());
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>* Diccionario<Clave, T>::inmediato_sucesor(NodoDiccionario<Clave, T>* nodo, Clave clave){
    if(nodo->obtener_clave() == clave)
        return inmediato_sucesor(nodo->obtener_hijo_derecho(), clave);
    if(nodo->obtener_hijo_izquierdo())
        return inmediato_sucesor(nodo->obtener_hijo_izquierdo(), clave);
    else
        return nodo;
}

template<typename Clave, typename T>
int Diccionario<Clave, T>::calcular_altura(NodoDiccionario<Clave, T>* nodo) {
    int altura_izquierda = calcular_altura(nodo->obtener_hijo_izquierdo());
    int altura_derecha = calcular_altura(nodo->obtener_hijo_derecho());
    return (altura_izquierda < altura_derecha)? altura_derecha + 1:altura_izquierda + 1;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::ancho_recursivo(NodoDiccionario<Clave, T>* nodo){
    Vector<T> resultado;
    int altura = calcular_altura(nodo);
    for (int i = 0; i < altura; i++) {
        obtener_nodos_nivel(nodo, i, resultado);
    }
    return resultado;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::obtener_nodos_nivel(NodoDiccionario<Clave, T>* nodo, int nivel, Vector<T>& resultado){
    if (nivel == 1) {
        resultado.alta(nodo->obtener_dato());
    } else if (nivel > 1) {
        obtener_nodos_nivel(nodo->obtener_hijo_izquierdo(), nivel - 1, resultado);
        obtener_nodos_nivel(nodo->obtener_hijo_derecho(), nivel - 1, resultado);
    }
}
#endif
