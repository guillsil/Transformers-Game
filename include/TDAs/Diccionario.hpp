#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoDiccionario.hpp"
#include "Vector.hpp"


const int PREORDER = 0;
const int POSTORDER = 1;
const int INORDER = 2;

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
    //Post: Calcula el ancho
    void ancho_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T>& vector, int nivel, int nivel_actual);
    
    int obtenerAltura(NodoDiccionario<Clave, T>* nodo);
    
    //Post: Da de alta un dato
    void alta_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave, T dato);
    
    //Post: Busca un dato y dependiendo de que tenga que hacer, lo elimina o solo lo obtiene
    T& busqueda_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave);

    T baja_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave);
    
    //Post: Ordena al arbol puede ser tanto PRE - POST - IN ORDER
    void orden_recursivo(Vector<T>& vector, NodoDiccionario<Clave, T>* nodo, int tipo_orden);
    
    //Post: Calcula el inmediato sucesor de un elemento del arbol
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
    return baja_recursiva(raiz, clave);
}

template<typename Clave, typename T>
T& Diccionario<Clave, T>::operator[](Clave clave) {
    return busqueda_recursiva(raiz, clave);
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::inorder() {
    Vector<T> vec;
    if(!vacio())
        orden_recursivo(vec, raiz, INORDER);
    return vec;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::preorder() {
    Vector<T> vec;
    if(!vacio())
        orden_recursivo(vec, raiz, PREORDER);
    return vec;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::postorder() {
    Vector<T> vec;
    if(!vacio())
        orden_recursivo(vec, raiz, POSTORDER);
    return vec;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::ancho() {
    Vector<T> vector;
    int altura = obtenerAltura(raiz);
    for(int i = 1; i <= altura + 1; i++){
        ancho_recursivo(raiz, vector, 1, i);
    }
    return vector;
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
T& Diccionario<Clave, T>::busqueda_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave){
    if(nodo->obtener_clave() == clave){
        T &dato = nodo->obtener_dato();
        return dato;
    }
    if(nodo->obtener_clave() > clave){
        if(nodo->obtener_hijo_izquierdo())
            return busqueda_recursiva(nodo->obtener_hijo_izquierdo(), clave);
        else
            throw ExcepcionDiccionario("La clave no existe");
    }
    if(nodo->obtener_clave() < clave){
        if(nodo->obtener_hijo_derecho())
            return busqueda_recursiva(nodo->obtener_hijo_derecho(), clave);
        else
            throw ExcepcionDiccionario("La clave no existe");
    }
}

template<typename Clave, typename T>
T Diccionario<Clave, T>::baja_recursiva(NodoDiccionario<Clave, T>* nodo, Clave clave){
    if(nodo->obtener_clave() == clave){
        NodoDiccionario<Clave, T>* sucesor = inmediato_sucesor(nodo, clave);
        if (sucesor == nodo){
            T dato = nodo->obtener_dato();
            NodoDiccionario<Clave, T>* padre = nodo->obtener_padre();
            if(padre->obtener_hijo_derecho() == nodo) padre->cambiar_hijo_derecho(nullptr);
            if(padre->obtener_hijo_izquierdo() == nodo) padre->cambiar_hijo_izquierdo(nullptr);
            delete nodo;
            return dato;
        }else{
            nodo->cambiar_clave(sucesor->obtener_clave());
            nodo->cambiar_dato(sucesor->obtener_dato());
            return baja_recursiva(sucesor, sucesor->obtener_clave());
        }
    }
    if(nodo->obtener_clave() > clave){
        if(nodo->obtener_hijo_izquierdo())
            return baja_recursiva(nodo->obtener_hijo_izquierdo(), clave);
        else
            throw ExcepcionDiccionario("La clave no existe");
    }
    if(nodo->obtener_clave() < clave){
        if(nodo->obtener_hijo_derecho())
            return baja_recursiva(nodo->obtener_hijo_derecho(), clave);
        else
            throw ExcepcionDiccionario("La clave no existe");
    }
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::orden_recursivo(Vector<T>& vector, NodoDiccionario<Clave, T>* nodo, int tipo_orden){
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
    if(nodo->obtener_clave() == clave){
        if(nodo->obtener_hijo_derecho())
            return inmediato_sucesor(nodo->obtener_hijo_derecho(), clave);
        else 
            return nodo;
    }
    if(nodo->obtener_hijo_izquierdo())
        return inmediato_sucesor(nodo->obtener_hijo_izquierdo(), clave);
    return nodo;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::ancho_recursivo(NodoDiccionario<Clave, T>* nodo, Vector<T>& vector, int nivel, int nivel_actual){
    if(nivel == nivel_actual){
        vector.alta(nodo->obtener_dato());
    }
    if(nivel < nivel_actual){
        if(nodo->obtener_hijo_izquierdo())
            ancho_recursivo(nodo->obtener_hijo_izquierdo(), vector, nivel + 1, nivel_actual);
        if(nodo->obtener_hijo_derecho())
            ancho_recursivo(nodo->obtener_hijo_derecho(), vector, nivel + 1, nivel_actual);
    }
}

template<typename Clave, typename T>
int Diccionario<Clave, T>::obtenerAltura(NodoDiccionario<Clave, T>* nodo) {
    if(!nodo)
        return -1;
    return std::max(obtenerAltura(nodo->obtener_hijo_izquierdo()), obtenerAltura(nodo->obtener_hijo_derecho())) + 1;
}

#endif
