//Alex Fariña 22/11/2024

#ifndef GENERADOR_COMBATES_HPP
#define GENERADOR_COMBATES_HPP

#include "Transformers.hpp"
#include "Vector.hpp"
#include "Grafo.hpp"

struct Secuencia_combates {
    Vector<Transformers> secuencia_combate;
    int total_energon_secuencia;
};

class GeneradorCombates {
    private:
        //Atributos
        Grafo mapa_combates;
        Secuencia_combates secuencia_minima; 
        Vector<Transformers> transformers_en_mapa; //Representa los vertices de mi grafo mapa_combates

        //Metodos privados
        Grafo generar_mapa(Vector<Transformers>& transformers_en_mapa);

        Secuencia_combates generar_secuencia_minima();

        Transformers obtener_jefe_final(Transformers& personaje_principal);

        int costo_avanzar(Transformers& transformer_origen, Transformers& transformer_destino);
    public:

        GeneradorCombates(Transformers& personaje_principal, Vector<Transformers>& transformers_secundarios);

        ~GeneradorCombates();

        Vector<Transformers> obtener_secuencia_minima();

        int costo_energon_secuencia();

        void mostrar_mapa_combates();

        void mostrar_secuencia_minima();

};

#endif