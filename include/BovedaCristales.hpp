#ifndef BOVEDACRISTALES_HPP
#define BOVEDACRISTALES_HPP

#include <Cristal.hpp>
#include <stdexcept>
#include <string>

class ExcepcionBovedaCristales : public std::runtime_error {
public:
    ExcepcionBovedaCristales(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionBovedaCristales(): runtime_error("") {
    }
};

class BovedaCristales {
public:
    void almacenar_cristal(Cristal cristal_nuevo);

    void mostrar_cristales();

    Cristal obtener_cristal(size_t posicion);

    void exportar_cristales(std::string ruta);
};

#endif
