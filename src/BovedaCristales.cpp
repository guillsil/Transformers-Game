#include "BovedaCristales.hpp"

#include <ostream>
#include <fstream>

const std::string ERROR_CRISTALES_VACIO = "ERROR:: Bóveda vacía , no hay nada para mostrar";
const std::string ERROR_LIMITE_DE_CRISTALES_EXCEDIDO = "ERROR:: Se alcanzo el limite de cristales que se puede almacenar";
const std::string ERROR_NO_SE_PUDO_ABRIR_ARCHIVO = "ERROR:: La ruta suministrada no es Correcta. Por favor intentalo nuevamente. ";
const std::string DIRECTORIO_BASE = "archivos";



BovedaCristales::BovedaCristales(): cristales(TAMANIO_MAXIMO_DE_CRISTALES) {
}

void BovedaCristales::almacenar_cristal(Cristal cristal_nuevo) {
    if (cristales.tamanio() < TAMANIO_MAXIMO_DE_CRISTALES) {
        /*if (cristal_mas_poderoso.obtener_poder() < cristal_nuevo.obtener_poder()) {
            cristal_mas_poderoso = cristal_nuevo;
        }
        cristales.alta(cristal_nuevo);
        */

        size_t posicion = 0;
        while (posicion < cristales.tamanio() && cristales[posicion].obtener_poder() > cristal_nuevo.obtener_poder()) {
            posicion++;
        }
        cristales.alta(cristal_nuevo, posicion);
        /*
        if (cristal_nuevo.obtener_poder() > cristal_mas_poderoso.obtener_poder()) {
            cristal_mas_poderoso = cristal_nuevo;
        }
        */
    }else {
        throw ExcepcionBovedaCristales(ERROR_LIMITE_DE_CRISTALES_EXCEDIDO);
    }
}


Cristal BovedaCristales::obtener_cristal(size_t posicion) {
    try {
       return cristales.baja(posicion);
    } catch (ExcepcionVector& e) {
        throw ExcepcionBovedaCristales(ERROR_CRISTALES_VACIO);
    }
}
void BovedaCristales::mostrar_cristales() {
    if (!cristales.vacio()) {
        for (size_t i = 0; i < cristales.tamanio(); i++) {
            cristales[i].mostrar();
            std::cout << std::endl;
        }
    }else {
        throw ExcepcionBovedaCristales(ERROR_CRISTALES_VACIO);
    }
}

bool BovedaCristales::esta_vacia() {
    return cristales.vacio();
}

size_t BovedaCristales::tamanio() {
    return cristales.tamanio();
}

Cristal BovedaCristales::obtener_y_eliminar_cristal_mas_poderoso() {
    try {
        Cristal cristal_mas_poderoso = cristales[0];
        cristales.baja(0);
        return cristal_mas_poderoso;
    } catch (ExcepcionVector& e) {
        throw ExcepcionBovedaCristales(ERROR_CRISTALES_VACIO);
    }
}

Cristal BovedaCristales::obtener_cristal_mas_poderoso() {
    return cristales[0];
}

void BovedaCristales::exportar_cristales(std::string ruta) {
    std::string ruta_completa = construir_ruta_completa(ruta);
    std::ofstream archivo_cristales(ruta_completa);
    if (!archivo_cristales) {
        throw ExcepcionBovedaCristales(ERROR_NO_SE_PUDO_ABRIR_ARCHIVO);
    }
    escribir_cristales_en_archivo(archivo_cristales);
    archivo_cristales.close();
}


std::string BovedaCristales::construir_ruta_completa(std::string &ruta) {
    try {
        if (ruta.find('/') == std::string::npos) {
            ruta = DIRECTORIO_BASE + "/" + ruta;
        } else {
            ruta = DIRECTORIO_BASE + "/" + ruta;
            crear_directorios(ruta);
        }
        return ruta;
    } catch (std::filesystem::filesystem_error& e) {
        throw ExcepcionBovedaCristales(e.what());
    }
}

void BovedaCristales::crear_directorios(const std::string &ruta) {
    std::filesystem::path directorios = std::filesystem::path(ruta).parent_path();
    create_directories(directorios);
}

void BovedaCristales::escribir_cristales_en_archivo(std::ofstream &archivo_cristales) {
    for (size_t i = 0; i < cristales.tamanio(); i++) {
        std::string nivel_rareza = cristales[i].convertir_rareza_a_string();
        size_t fuerza = cristales[i].obtener_fuerza();
        size_t defenza = cristales[i].obtener_defensa();
        size_t velocidad = cristales[i].obtener_velocidad();
        archivo_cristales << nivel_rareza << "," << fuerza << "," << defenza << "," <<velocidad << std::endl;
    }
}
