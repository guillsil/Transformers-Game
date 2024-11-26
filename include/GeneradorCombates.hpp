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
        Camino secuencia_minima_numerica; 
        Vector<Transformers> transformers_en_mapa; //Representa los vertices que tendra mi grafo mapa_combates
        Vector<Transformers> secuencia_minima_transformers;
    
        //Metodos privados
        //pre: 
        //El vector debe contener en la primera posicion el personaje principal y en la ultima el jefe final
        //post:
        //Crea un mapa en base al vector de transformers ingresado
        //El mapa se genera respetando el orden de la lista, siendo el primer elemento el personaje principal y el ultimo el jefe final
        //El avance desde el principio es siempre hacia adelante
        //Por cada avance siempre se tendra la posibilidad de avanzar hasta a tres transformers diferentes
        //El encuentro final no permite mas avances
        Grafo generar_mapa(Vector<Transformers>& transformers_en_mapa);

        //pre: 
        //post:
        //Devuelve la contra cara del personaje principal, que seria el jefe final
        //Si personaje_principal es Optimus Prime devuelve Megatron
        //Si personaje_principal es  Megatron devuelve Optimus Prime
        Transformers obtener_jefe_final(Transformers& personaje_principal);

        //Pre:-
        //Post:
        //Compara la faccion y/o poder del transformer destino con el del personaje principal
        //Si la faccion es la misma devuelve 30
        //Si la faccion es distinta
        //--Si sus poderes son iguales, devuelve 50.
        //--Si el poder del personaje principal es mayor, devuelve un numero entre 10 y 49, a mayor diferencia de poder, menor el numero
        //--Si el poder del personaje principal es menor, devuelve un numero entre 51 y 100 a mayor diferencia de poder, mayor el numero
        int costo_avanzar(Transformers& transformer_origen, Transformers& transformer_destino);
    public:
        //Constructores

        GeneradorCombates(); //Diseñado a fin de porder usar el operador de asignacion

        //pre:
        //El personaje principal debe ser "Optimus Prime" o "Megatron"
        //post:
        //Constructor
        GeneradorCombates(Transformers& personaje_principal, Vector<Transformers>& transformers_secundarios);

        //Destructor
        ~GeneradorCombates();

        //pre:-
        //post:
        //Devuelve la secuencia de combates con menor gasto de energon
        Vector<Transformers> obtener_secuencia_minima();

        //pre:-
        //post:
        //Devuelve el costo total de energon de la secuencia de combates minima
        int costo_energon_secuencia();

        //pre:-
        //post:
        //Muestra por pantalla todos los posibles caminos para llegar desde el personaje principal hasta el
        //el ultimo transformer que representaria el ultimo encuentro y jefe final
        //Se muestra a su vez el costo de energon entre cada 
        void mostrar_mapa_combates();

        //pre:-
        //post:
        //Muestra por pantalla la secuencia de combates de menor costo energon obtenida
        void mostrar_secuencia_minima();

        //Operador de asignacion
        GeneradorCombates& operator=(const GeneradorCombates& generador_combates);

};

#endif