//Alex Fariña 22/11/2024

#ifndef COMBATES_USUARIO_HPP
#define COMBATES_USUARIO_HPP
#include "Transformers.hpp"
#include "Vector.hpp"
#include "SimulacionCombate.hpp"
#include "GeneradorCombates.hpp"

class CombatesUsuario {
private:
    //Atributos
    size_t puntos_partida;
    SimulacionCombate simulacion_combate;
    GeneradorCombates generador_combate;

    //Metodos privados
    void establecer_puntaje_combate(Resultado_combate resultado_combate, bool esta_transformado);

    void realizar_enfrentamiento();

    void batalla_jefe_final();

    void batalla_generica();

    void encuentro_aliado();

    void gestion_generador_combate();

    void gestion_simulacion_batalla();

public:
    CombatesUsuario(Transformers& personaje_principal, Vector<Transformers>& transformers_secundarios);

    ~CombatesUsuario();

    void iniciar_partida_combates();

    size_t obtener_puntaje();
};

#endif