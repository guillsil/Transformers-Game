//Alex Fariña 22/11/2024

#include "../include/GeneradorCombates.hpp"

GeneradorCombates:: ~GeneradorCombates(){}

Grafo GeneradorCombates:: generar_mapa(Vector<Transformers>& transformers_en_mapa){
    size_t cantidad_transformers = transformers_en_mapa.tamanio();
    Grafo mapa_combates(cantidad_transformers);
    Transformers personaje_principal = transformers_en_mapa[0];   
    size_t vertice_actual = 0;
    size_t siguiente_vertice = 1;
    size_t ultimo_vertice = cantidad_transformers - 1;

    // Conectar el primer vértice al segundo nivel
    while (siguiente_vertice < min((size_t)4, cantidad_transformers)) {
        mapa_combates.agregar_arista(vertice_actual, siguiente_vertice, costo_avanzar(personaje_principal,transformers_en_mapa[siguiente_vertice]) );
        siguiente_vertice++;
    }
    // Conexion a niveles intermedios de hasta 3 vertices
    while (siguiente_vertice < ultimo_vertice) {
        size_t nivel_inicio = siguiente_vertice; //Proximo vertice a conectar
        size_t nivel_fin = min(siguiente_vertice + 3, ultimo_vertice);

        for (size_t i = vertice_actual + 1; i < nivel_inicio; ++i) {
            for (size_t j = nivel_inicio; j < nivel_fin; ++j) {
                mapa_combates.agregar_arista(i, j, costo_avanzar(personaje_principal,transformers_en_mapa[j]));
            }
        }

        vertice_actual = nivel_inicio - 1;
        siguiente_vertice = nivel_fin;
    }
    // Conectar los últimos vértices al vértice final
    for (size_t i = vertice_actual + 1; i < ultimo_vertice; ++i) {
        mapa_combates.agregar_arista(i, ultimo_vertice, costo_avanzar(personaje_principal,transformers_en_mapa[ultimo_vertice]));
    }

    return mapa_combates;
}

Transformers GeneradorCombates:: obtener_jefe_final(Transformers& personaje_principal){
    Transformers jefe_final;
    if(personaje_principal.obtener_nombre() == "Optimus Prime"){
        jefe_final = Transformers("Megatron",60,70,100,"Decepticons","Camion");
    }
    else {
        jefe_final = Transformers("Optimus Prime",70,90,50,"Autobots","Tanque");
    }
    return jefe_final;
}

int GeneradorCombates:: costo_avanzar(Transformers& transformer_origen, Transformers& transformer_destino){
    int costo_avance = 30; //Lo definimos como un encuentro aliado
    
    if(!(transformer_origen == transformer_destino)){
        int comparacion_poderes = transformer_destino.obtener_poder() - transformer_origen.obtener_poder();
        costo_avance = 50 + comparacion_poderes;
        if(costo_avance > 100){
            costo_avance = 100;
        }
        else if(costo_avance < 10){
            costo_avance = 10;
        }
    }

    return costo_avance;
}

GeneradorCombates:: GeneradorCombates(){};

GeneradorCombates:: GeneradorCombates(Transformers& personaje_principal, Vector<Transformers>& transformers_secundarios){
    transformers_en_mapa = transformers_secundarios;
    transformers_en_mapa.alta(personaje_principal, 0);
    transformers_en_mapa.alta(obtener_jefe_final(personaje_principal),transformers_en_mapa.tamanio());

    mapa_combates = generar_mapa(transformers_en_mapa);
    mapa_combates.usar_dijkstra();
    secuencia_minima_numerica = mapa_combates.obtener_camino_minimo(0,transformers_en_mapa.tamanio()-1);
}

Vector<Transformers> GeneradorCombates:: obtener_secuencia_minima(){
    if(secuencia_minima_transformers.tamanio() == 0){
        for(size_t i = 0; i < secuencia_minima_numerica.camino.tamanio(); i++){
            secuencia_minima_transformers.alta(transformers_en_mapa[secuencia_minima_numerica.camino[i]]);
        }
    }
    
    return secuencia_minima_transformers;
}

int GeneradorCombates:: costo_energon_secuencia(){
    return secuencia_minima_numerica.costo_total;
}

void GeneradorCombates:: mostrar_mapa_combates(){
    graficador.mostrar_mapa_combates(transformers_en_mapa);
}

void GeneradorCombates:: mostrar_secuencia_minima(){
    graficador.mostrar_secuencia(secuencia_minima_numerica.camino,
                                transformers_en_mapa[0],
                                transformers_en_mapa[transformers_en_mapa.tamanio()-1]);
}

GeneradorCombates& GeneradorCombates:: operator=(const GeneradorCombates& generador_combates){
    if(this != &generador_combates){
        mapa_combates = generador_combates.mapa_combates;
        secuencia_minima_numerica = generador_combates.secuencia_minima_numerica;
        secuencia_minima_transformers = generador_combates.secuencia_minima_transformers;
        transformers_en_mapa = generador_combates.transformers_en_mapa;
    }   
    return *this;
}
