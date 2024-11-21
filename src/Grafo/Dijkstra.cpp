#include "../../include/TDAs/Grafo/Dijkstra.hpp"
#include "../../include/TDAs/Matriz.hpp"
#include "../../include/TDAs/Vector.hpp"
#include "../../include/TDAs/Grafo/TuplaVerticeDistancia.hpp"
#include "../include/TDAs/Heap.hpp"


const int INICIALIZADOR_PADRE = 0;

Dijkstra::Dijkstra() {}

Vector<size_t> Dijkstra::calcular_camino_minimo(Matriz<bool>& matriz_adyacencia, Matriz<int>& matriz_pesos, size_t origen, size_t destino, size_t vertices) {

    Vector<size_t> distancias(vertices, INFINITO);
    Vector<bool> visitados(vertices, false);
    Vector<size_t> padre(vertices, INICIALIZADOR_PADRE);
    distancias[origen] = 0;

    Heap<TuplaVerticeDistancia> cola_prioridad;
    // std::priority_queue<TuplaVerticeDistancia> cola_prioridad;
    cola_prioridad.alta(TuplaVerticeDistancia(origen, 0));

    while (!cola_prioridad.vacio()) {
        TuplaVerticeDistancia actual = cola_prioridad.primero();
        cola_prioridad.baja();

        size_t vertice_actual = actual.obtener_vertice();

        if (visitados[vertice_actual]) continue;
        visitados[vertice_actual] = true;

        for (size_t v = 0; v < vertices; ++v) {
            if (matriz_adyacencia(vertice_actual, v) && !visitados[v]) {
                int nuevo_peso = matriz_pesos(vertice_actual, v);
                size_t nueva_distancia = distancias[vertice_actual] + nuevo_peso;
                if (nueva_distancia < distancias[v]) {
                    distancias[v] = nueva_distancia;
                    padre[v] = vertice_actual;
                    cola_prioridad.alta(TuplaVerticeDistancia(v, nueva_distancia));
                }
            }
        }
    }
    // Si el destino no es alcanzable, devolvemos un vector vacío
    if (distancias[destino] == INFINITO) {
        return Vector<size_t>();
    }
    return reconstruir_camino(padre, origen, destino);
}


Vector<size_t> Dijkstra::reconstruir_camino(Vector<size_t> &padre, size_t origen, size_t destino) {
    Vector<size_t> camino_minimo;
    if (padre[destino] == INICIALIZADOR_PADRE && destino != origen) {
        return camino_minimo;
    }

    while (destino != origen) {
        if (destino == origen) {
            camino_minimo.limpiar();
            return camino_minimo;
        }
        camino_minimo.alta(destino);
        destino = padre[destino];
    }
    camino_minimo.alta(origen);
    camino_minimo.invertir();
    return  camino_minimo;
}

Dijkstra::~Dijkstra() {}
