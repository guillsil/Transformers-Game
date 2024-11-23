#ifndef CONTROL_ARCHIVO_HPP
#define CONTROL_ARCHIVO_HPP
#include "TDAs/Vector.hpp"
#include "Transformers.hpp"
#include "DatosJugador.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

const std::string RUTA_ARCHIVO = "datos.csv";

class ExcepcionControlArchivo : public std::runtime_error {
public:
    ExcepcionControlArchivo(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionControlArchivo(): runtime_error("") {
    }
};

template<typename T>
class ControlArchivo {
    const std::string ERROR_NO_SE_PUDO_ABRIR_ARCHIVO = "ERROR:: La ruta suministrada no es Correcta. Por favor intentalo nuevamente. ";
    const int NUMERO_CREAR_TRANSFORMER = 7;
    const int NUMERO_CREAR_DATOS_JUGADOR = 3;
    std::string ruta;

    //Pre:
    //Post:
    Vector<std::string> dividir_linea(const std::string& linea, char delimitador);

    //Pre:
    //Post:
    Transformers crear_transformer(Vector<std::string>& elementos);

    //Pre:
    //Post:
    DatosJugador crear_datos_jugador(Vector<std::string>& elementos);
public:
    //Constructor
    ControlArchivo();

    //Constructor
    ControlArchivo(std::string ruta);
    
    //Precondiciones: Recibe un vector no vacio. Sino existe el archivo, lo crea. 
    //Postcondiciones: Guarda la informacion del vector de forma ordenada en el archivo RUTA_ARCHIVO.
    //                 Del primer indice al ultimo, agragandose al final de la informacion del archivo si existe.
    void guardar_en_archivo(Vector<T> vector_guardar);

    //Pre: Recibe un vector no vacio. Sino existe el archivo, lo crea.
    //Post:
    void sobreescribir_en_archivo(Vector<T> vector_guardar);

    //Pre:
    //Post:
    Vector<T> leer_archivo();
};

template <typename T>
ControlArchivo<T>::ControlArchivo(){
    this->ruta = RUTA_ARCHIVO;
    std::cout << "Abriendo archivo " << ruta << " ..." << std::endl; 
}

template <typename T>
ControlArchivo<T>::ControlArchivo(std::string ruta_archivo){
    this->ruta = ruta_archivo;
    std::cout << "Abriendo archivo " << ruta << " ..." << std::endl; 
}

template <typename T>
void ControlArchivo<T>::guardar_en_archivo(Vector<T> vector_guardar){
    std::ofstream miArchivo (ruta, std::ofstream::app);
    if (miArchivo.is_open()){
        size_t cantidad_datos = vector_guardar.tamanio();
        for(size_t i = 0; i < cantidad_datos; i++){
            miArchivo << vector_guardar.baja(0) << std::endl;
        }
        miArchivo.close();
    }else{
        throw ExcepcionControlArchivo(ERROR_NO_SE_PUDO_ABRIR_ARCHIVO);
    }
}

template <typename T>
void ControlArchivo<T>::sobreescribir_en_archivo(Vector<T> vector_guardar){
    std::ofstream miArchivo (ruta, std::ofstream::trunc);
    if (miArchivo.is_open()){
        size_t cantidad_datos = vector_guardar.tamanio();
        for(size_t i = 0; i < cantidad_datos; i++){
            miArchivo << vector_guardar.baja(0) << std::endl;
        }
        miArchivo.close();
    }else{
        throw ExcepcionControlArchivo(ERROR_NO_SE_PUDO_ABRIR_ARCHIVO);
    }
}

template <typename T>
Vector<T> ControlArchivo<T>::leer_archivo(){
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ExcepcionControlArchivo(ERROR_NO_SE_PUDO_ABRIR_ARCHIVO);
    }

    std::string linea;
    Vector<std::string> elementos;
    Vector<T> lista_nueva;
    while (std::getline(archivo, linea)) {
        elementos = dividir_linea(linea, ',');
        if (elementos.tamanio() == NUMERO_CREAR_TRANSFORMER){
            lista_nueva.alta(crear_transformer(elementos));
        } else if (elementos.tamanio() == NUMERO_CREAR_DATOS_JUGADOR){
            lista_nueva.alta(crear_datos_jugador(elementos));
        }
        //Faltaria hacer para la boveda de cristaless
    }

    archivo.close();
    return lista_nueva;
}

template <typename T>
Vector<std::string> ControlArchivo<T>::dividir_linea(const std::string& linea, char delimitador) {
    Vector<std::string> elementos;
    std::stringstream ss(linea);
    std::string item;
    while (std::getline(ss, item, delimitador)) {
        elementos.alta(item);
    }
    return elementos;
}

template <typename T>
Transformers ControlArchivo<T>::crear_transformer(Vector<std::string>& elementos){
    std::string nombre = elementos[0];
    int fuerza = std::stoi(elementos[1]);
    int defensa = std::stoi(elementos[2]);
    int velocidad = std::stoi(elementos[3]);
    std::string faccion = elementos[4];
    std::string vehiculo = elementos[5];
    bool transformado = pase_texto_bool_transformado(elementos[6]);
    return Transformers(nombre, fuerza, defensa, velocidad, faccion, vehiculo, transformado);
}

#endif

template <typename T>
DatosJugador ControlArchivo<T>::crear_datos_jugador(Vector<std::string>& elementos){
    std::string nombre = elementos[0];
    int puntaje = std::stoi(elementos[1]);
    // Hacer la parte de Personaje jugado
    return DatosJugador(nombre, puntaje /*, personaje*/);
}
