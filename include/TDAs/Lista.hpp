#ifndef LISTA_HPP
#define LISTA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"

const std::string  ERROR_LISTA_VACIA = "ERROR: La lista esta vacia";
const std::string ERROR_RANGO_POSICION = "ERROR: Posicion fuera del rango de la lista";
const std::string ERROR_CURSOR_AVANZAR = "ERROR: No es posible seguir avanzando";
const std::string ERROR_CURSOR_RETROCEDER = "ERROR: No es posible seguir retrocediendo";

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

    //Metodo privado

    //Pre: La posición debe ser menor o igual que la cantidad de datos.
    //Post: devuelve el nodo en esa posicion de la lista
    NodoLista<T>* obtener_nodo(size_t posicion);

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
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cursor = nullptr;
    cantidad_datos = 0;

}

template<typename T>
void Lista<T>::alta_principio(T dato) {
    NodoLista<T>* nuevo_nodo = new NodoLista<T>(dato);
    if(vacio()){
        primer_nodo = nuevo_nodo;
        primer_nodo->cambiar_siguiente(nullptr);
        primer_nodo->cambiar_anterior(nullptr);

        ultimo_nodo = primer_nodo;
        cursor = primer_nodo;
    }
    else {
        nuevo_nodo->cambiar_anterior(nullptr);
        nuevo_nodo->cambiar_siguiente(primer_nodo);
        primer_nodo->cambiar_anterior(nuevo_nodo);
        primer_nodo = nuevo_nodo;

    }
    cantidad_datos++;
}

template<typename T>
void Lista<T>::alta_final(T dato) {
    NodoLista<T>* nuevo_nodo = new NodoLista<T>(dato);
    if(vacio()){
        primer_nodo = nuevo_nodo;
        primer_nodo->cambiar_siguiente(nullptr);
        primer_nodo->cambiar_anterior(nullptr);

        ultimo_nodo = primer_nodo;
        cursor = primer_nodo;
    }
    else {
        nuevo_nodo->cambiar_anterior(ultimo_nodo);
        nuevo_nodo->cambiar_siguiente(nullptr);
        ultimo_nodo->cambiar_siguiente(nuevo_nodo);
        ultimo_nodo = nuevo_nodo;
    }
    cantidad_datos++;

}

template<typename T>
T Lista<T>::baja_primero() {

    if(vacio()){
        throw ExcepcionLista(ERROR_LISTA_VACIA);
    }

    NodoLista<T>* nodo_eliminar = primer_nodo;
    T dato_eliminado = nodo_eliminar->obtener_dato();

    primer_nodo = primer_nodo->obtener_siguiente();
    primer_nodo->cambiar_anterior(nullptr);

    delete nodo_eliminar;
    cantidad_datos--;
    return dato_eliminado;
}

template<typename T>
T Lista<T>::baja_ultimo() {
    if(vacio()){
        throw ExcepcionLista(ERROR_LISTA_VACIA);
    }

    NodoLista<T>* nodo_eliminar = ultimo_nodo;
    T dato_eliminado = nodo_eliminar->obtener_dato();

    ultimo_nodo = ultimo_nodo->obtener_anterior();
    ultimo_nodo->cambiar_siguiente(nullptr);

    delete nodo_eliminar;
    cantidad_datos--;
    return dato_eliminado;
}

template<typename T>
NodoLista<T>* Lista<T>::obtener_nodo(size_t posicion){
    if(posicion > cantidad_datos){
        throw ExcepcionLista(ERROR_RANGO_POSICION);
    }

    NodoLista<T>* nodo_en_pos;
    if(posicion <= (cantidad_datos/2)){
        nodo_en_pos = primer_nodo;
        for (size_t i = 0; i < posicion; i++){
            nodo_en_pos = nodo_en_pos->obtener_siguiente();
        }
    }
    else if(posicion == cantidad_datos){
        nodo_en_pos = nullptr;
    }
    else {
        nodo_en_pos = ultimo_nodo;
        for (size_t i = (cantidad_datos-1); i > posicion; i--){
            nodo_en_pos = nodo_en_pos->obtener_anterior();
        }
    }
    return nodo_en_pos;
}

template<typename T>
void Lista<T>::insertar(T dato, size_t posicion) {
    if(posicion > cantidad_datos){
        throw ExcepcionLista(ERROR_RANGO_POSICION);
    }

    if(posicion == 0){
        alta_principio(dato);
    }
    else if(posicion == cantidad_datos){
        alta_final(dato);
    }
    else{
        NodoLista<T>* nodo_nuevo = new NodoLista<T>(dato);
        NodoLista<T>* anterior = obtener_nodo(posicion-1);
        nodo_nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        nodo_nuevo->cambiar_anterior(anterior);
        anterior->cambiar_siguiente(nodo_nuevo);
        cantidad_datos++;
    }
}

template<typename T>
T Lista<T>::eliminar(size_t posicion) {
    if(posicion >= cantidad_datos){
        throw ExcepcionLista(ERROR_RANGO_POSICION);
    }

    T dato_eliminado;
    if(posicion == 0){
        dato_eliminado = baja_primero();
    }
    else if(posicion == (cantidad_datos - 1)){
        dato_eliminado = baja_ultimo();
    }
    else {
        NodoLista<T>* nodo_eliminar = obtener_nodo(posicion);

        dato_eliminado = nodo_eliminar->obtener_dato();
        nodo_eliminar->obtener_siguiente()->cambiar_anterior(nodo_eliminar->obtener_anterior());
        nodo_eliminar->obtener_anterior()->cambiar_siguiente(nodo_eliminar->obtener_siguiente());
        delete nodo_eliminar;
        cantidad_datos--;
    }
    return dato_eliminado;
}

template<typename T>
T& Lista<T>::primero() {
    if(vacio()){
        throw ExcepcionLista(ERROR_LISTA_VACIA);
    }
    return primer_nodo->obtener_referencia_dato();
}

template<typename T>
T& Lista<T>::ultimo() {
    if(vacio()){
        throw ExcepcionLista(ERROR_LISTA_VACIA);
    }
    return ultimo_nodo->obtener_referencia_dato();
}

template<typename T>
void Lista<T>::reiniciar_cursor(bool principio) {
    if(principio){
        cursor = primer_nodo;
    }
    else {
        cursor = ultimo_nodo;
    }
}

template<typename T>
void Lista<T>::avanzar() {
    if(!cursor->obtener_siguiente()){
        throw ExcepcionLista(ERROR_CURSOR_AVANZAR);
    }
    cursor = cursor->obtener_siguiente();
}

template<typename T>
void Lista<T>::retroceder() {
    if(!cursor->obtener_anterior()){
        throw ExcepcionLista(ERROR_CURSOR_RETROCEDER);
    }
    cursor = cursor->obtener_anterior();
}

template<typename T>
T& Lista<T>::elemento() {
    if(vacio()){
        throw ExcepcionLista(ERROR_LISTA_VACIA);
    }
    return cursor->obtener_referencia_dato();
}

template<typename T>
size_t Lista<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Lista<T>::vacio() {
    return (cantidad_datos == 0);
}

template<typename T>
Lista<T>::~Lista() {
    NodoLista<T>* nodo_liberar = primer_nodo;
    while (nodo_liberar != nullptr) {
        NodoLista<T>* nodo_siguiente = nodo_liberar->obtener_siguiente();
        delete nodo_liberar;
        nodo_liberar = nodo_siguiente;
    }
}
#endif