#ifndef FUSIONADORENERGON_HPP
#define FUSIONADORENERGON_HPP

#include "GeneradorAleatorio.hpp"
#include "Cristal.hpp"
#include <stdexcept>

class ExcepcionFusionadorEnergon : public std::runtime_error {
public:
    ExcepcionFusionadorEnergon(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionFusionadorEnergon(): runtime_error("") {
    }
};

class FusionadorEnergon {
public:
    FusionadorEnergon();

    Cristal fusionar(Cristal cristal_1, Cristal cristal_2);

    Cristal fusionar(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio& generador);
};

#endif
