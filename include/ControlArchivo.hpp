#ifndef CONTROL_ARCHIVO_HPP
#define CONTROL_ARCHIVO_HPP
#include "TDAs/Vector.hpp"
#include "Transformers.hpp"
#include "DatosJugador.hpp"
#include "Cristal.hpp"
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
    const size_t NUMERO_CREAR_TRANSFORMER = 7;
    const size_t NUMERO_CREAR_DATOS_JUGADOR = 3;
    std::string ruta;

    //Pre: linea y delimitador deben ser distintos de null(vacio)
    //Post: Separa el string linea por donde pasa el char delimitador indicando, lo devuelve como TDA Vector clase string.
    Vector<std::string> dividir_linea(const std::string& linea, char delimitador);
public:
    //Constructor
    ControlArchivo();

    //Constructor
    ControlArchivo(std::string ruta);
    
    //Pre: Recibe un vector no vacio. Sino existe el archivo, lo crea.
    //Post: Guarda la informacion del vector de forma ordenada en el archivo indicado por atributo ruta.
    //      Del primer indice al ultimo, desde el principio del archivo. Si exite información previa, borra y escribe sobre ella.
    void sobreescribir_en_archivo(Vector<T> vector_guardar);

    //Pre: Atributo std::string ruta de ControlArchivo debe apuntar a un archivo existente.
    //     La clase T indicada debe tener un constructor T(Vector<std::string>& arg).
    //Post: Extrae la informacion existente en el archivo indicado por el atributo ruta. Esta se extrae linea por linea
    //      y se la devuelve como un vector T donde T es la clase del Template.
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
        if (elementos.vacio() != true){
            lista_nueva.alta(T(elementos));
        }
    }

    archivo.close();
    return lista_nueva;
}

template <typename T>
Vector<std::string> ControlArchivo<T>::dividir_linea(const std::string& linea, char delimitador) {
    Vector<std::string> elementos;
    std::stringstream ss(linea);
    std::string item;
    if(linea != ""){
        while (std::getline(ss, item, delimitador)) {
            elementos.alta(item);
        }
    }
    return elementos;
}


#endif