#ifndef MEGATRON_HPP
#define MEGATRON_HPP

#include <string>

class Megatron {
public:
    Megatron();

    void responder(std::string mensaje);

    void sugerir_fusion();

    void cambiar_intencion(std::string intencion);
};

#endif
