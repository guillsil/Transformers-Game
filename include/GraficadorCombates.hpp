#ifndef GRAFICADOR_COMBATES_HPP
#define GRAFICADOR_COMBATES_HPP
#include <string>
#include "Transformers.hpp"
#include "TDAs/Vector.hpp"
using namespace std;

const string union_unica = R"(                ░      
                ░      
                ░      
                ░      
                ░     
                ░)";
const string union_tres_tres = R"(        ░               ░
  ░░     ░░    ░░░    ░░     ░░
  ░ ░      ░  ░ ░ ░  ░      ░ ░
  ░  ░      ░░  ░  ░░      ░  ░
  ░   ░     ░░  ░  ░░     ░   ░
  ░    ░   ░  ░ ░ ░  ░   ░    ░
  ░     ░ ░    ░░░    ░ ░     ░
  ░      ░     ░░░     ░      ░
  ░     ░ ░   ░ ░ ░   ░ ░     ░
  ░    ░   ░ ░  ░  ░ ░   ░    ░
  ░   ░     ░   ░   ░     ░   ░
  ░  ░     ░ ░  ░  ░ ░     ░  ░
  ░ ░     ░   ░ ░ ░   ░     ░ ░
  ░░     ░     ░░░     ░     ░░
  ░     ░       ░       ░     ░)";
const string union_uno_tres = R"(
               ░░░      
              ░ ░ ░     
             ░  ░  ░    
            ░   ░   ░   
          ░░    ░    ░  
        ░░      ░     ░░ )";
const string union_uno_dos = R"(               ░░      
              ░ ░      
             ░  ░      
            ░   ░      
          ░░    ░     
        ░░      ░)";
const string union_tres_uno = R"(       ░        ░        ░
        ░       ░       ░ 
         ░      ░      ░  
          ░     ░     ░   
           ░    ░    ░    
            ░   ░   ░     
             ░  ░  ░      
              ░ ░ ░)";
const string union_tres_dos = R"(                        ░
  ░░           ░░     ░░     ░
  ░ ░         ░ ░    ░      ░ 
  ░  ░       ░  ░   ░      ░  
  ░   ░     ░   ░  ░      ░   
  ░    ░   ░    ░ ░      ░    
  ░     ░ ░     ░░      ░     
  ░      ░     ░░      ░      
  ░     ░ ░   ░ ░     ░      
  ░    ░   ░ ░  ░    ░      
  ░   ░     ░   ░   ░        
  ░  ░     ░ ░  ░  ░         
  ░ ░     ░   ░ ░ ░        
  ░░     ░     ░░░           
  ░     ░       ░)";
const string union_dos_uno = R"(       ░        ░        
        ░       ░        
         ░      ░        
          ░     ░        
           ░    ░        
            ░   ░        
             ░  ░        
              ░ ░ )";

class GraficadorCombates {  
    private:
        //Metodos privados

        //pre: 
        //los valores deben ser como maximo de 3 cifras, a partir de ahi el grafico se rompe
        //post:
        //Grafica por pantalla 2 vertices
        //En el interior del primero figura valor1
        //En el interior del segundo figura valor2
        void vertices_dobles(size_t valor1, size_t valor2);

        //pre: 
        //los valores deben ser como maximo de 3 cifras, a partir de ahi el grafico se rompe
        //post:
        //Grafica por pantalla 3 vertices
        //En el interior del primero figura valor1
        //En el interior del segundo figura valor2
        //En el interior del tercero figura valor3
        void vertices_triples(size_t valor1, size_t valor2, size_t valor3);

        //Pre:
        //valor debe tener como maximo 7 caracteres, a partir de ahi el grafico se rompe
        //Post:
        //Grafica por pantalla 1 vertice medio con valor en su interior
        void vertice_individual(string valor);

        //Pre:
        //Valor debe ser como maximo de 3 cifras, a partir de ahi el grafico se rompe
        //Post:
        //sobrecarga del metodo vertice_individual que admite un valor numerico
        //Grafica por pantalla 1 vertice medio con valor en su interior
        void vertice_individual(size_t valor);

        //pre:-
        //post:
        //Muestra en el medio el peso de ir desde p_principal hasta t_destino
        void pesos_aristas(Transformers& p_principal, Transformers& t_destino);
        //pre:-
        //post:
        //Muestra ordenado por ordenadamente el peso de ir desde p_principal hasta t_destino1 y t_destino2
        void pesos_aristas(Transformers& p_principal, Transformers& t_destino1, Transformers& t_destino2);
        //pre:-
        //post:
        //Muestra ordenado por ordenadamente el peso de ir desde p_principal hasta t_destino1, t_destino2 y t_destino3
        void pesos_aristas(Transformers& p_principal, Transformers& t_destino1, Transformers& t_destino2, Transformers& t_destino3);

        //pre:
        //Nombre debe ser "Optimus Prime" o Megatron
        //post:
        //Devuelve el nombre en una version acotada
        // "Optimus Prime" --> OP
        // "Megatron" --> M
        string acotar_nombre(string nombre);

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
        //Constructor
        GraficadorCombates();

        //Destructor
        ~GraficadorCombates();

        //pre:
        //transformers_en_mapa debe contener: 
        //Al primer elemento como el personaje pricipal
        //Al ultimo elemento como jefe final
        //A los elementos medios como transformers secundarios 
        //post:
        //Grafica por pantalla un mapa con niveles medios de hasta 3 transformers secundarios
        //El primer y ultimo nivel son de vertices unicos con el nombre acotado del 
        //p_principal y jefe final respectivamente
        void mostrar_mapa_combates(Vector<Transformers>& transformers_en_mapa);

        //pre:
        //secuencia debe representar un camino, donde del primero voy al segundo, del segundo al tercero, etc
        //El primero y ultimo elemento debe representar el personaje principal y jefe final respectivamente
        //post:
        //Grafica por pantalla la secuencia mediante vertices y conexiones
        //Se reemplaza el primer y ultimo numero por los nombres acotados del personaje principal y jefe final respectivamente
        void mostrar_secuencia(Vector<size_t>& secuencia, Transformers& p_principal, Transformers& j_final);
};

#endif