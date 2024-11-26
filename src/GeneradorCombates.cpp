//Alex Fariña 22/11/2024

#include "../include/GeneradorCombates.hpp"

Grafo GeneradorCombates:: generar_mapa(Vector<Transformers>& transformers_en_mapa){
    size_t cantidad_transformers = transformers_en_mapa.tamanio();
    Grafo mapa_combates(cantidad_transformers);
    bool primer_vertice_nivel = true;
    Transformers personaje_principal = transformers_en_mapa[0];
    for(size_t i = 0; i < cantidad_transformers-1; i++){
        size_t j = i;

        //Caso donde el vertice es el primero del grafo o el tercero de los niveles medios 
        if(i % 3 == 0){
           j++;
           primer_vertice_nivel = true;
        }
        //Caso donde mi vertice es el primero de un nivel medio
        else if(primer_vertice_nivel){
            j += 3;
            primer_vertice_nivel = false;
            
        }
        //Caso donde mi vertice sea el segundo de un nivel medio
        else {
            j += 2;
        }

        size_t vertice_limite = j + 3; //Solo queremos agregar la arista desde i hasta, como mucho, el ultimo vertice del siguiente nivel
        while(j <= vertice_limite && j < cantidad_transformers-1){
            mapa_combates.agregar_arista(i, j, costo_avanzar(personaje_principal, transformers_en_mapa[j]));
            j++;
        }
    }

    return mapa_combates;
}

Transformers GeneradorCombates:: obtener_jefe_final(Transformers& personaje_principal){
    Transformers jefe_final;
    if(personaje_principal.obtener_nombre() == "Optimus Prime"){
        jefe_final = Transformers("Optimus Prime",1,1,1,"Autobots","Camion");
    }
    else {
        jefe_final = Transformers("Megatron",1,1,1,"Decepticons","Tanque");
    }
    return jefe_final;
}

int GeneradorCombates:: costo_avanzar(Transformers& transformer_origen, Transformers& transformer_destino){
    int costo_avance = 30;
    
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

GeneradorCombates:: ~GeneradorCombates(){};

Vector<Transformers> GeneradorCombates:: obtener_secuencia_minima(){
    if(secuencia_minima_transformers.tamanio() > 0){
        for(size_t i = 0; i < secuencia_minima_numerica.camino.tamanio(); i++){
            secuencia_minima_transformers[i] = transformers_en_mapa[secuencia_minima_numerica.camino[i]];
        }
    }
    return secuencia_minima_transformers;
}

int GeneradorCombates:: costo_energon_secuencia(){
    return secuencia_minima_numerica.costo_total;
}

void GeneradorCombates:: mostrar_mapa_combates(){
    
}

void GeneradorCombates:: mostrar_secuencia_minima(){
    //A implementar
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
