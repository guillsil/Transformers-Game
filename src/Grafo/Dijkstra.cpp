#include "../../include/TDAs/Grafo/Dijkstra.hpp"
#include "../../include/TDAs/Vector.hpp"
#include "../../include/TDAs/Matriz.hpp"
#include "../../include/TDAs/Grafo/TuplaVerticeDistancia.hpp"
#include <iostream>
#include <queue>

const int INICIALIZADOR_PADRE = 0;

Dijkstra::Dijkstra() {}

Vector<size_t> Dijkstra::calcular_camino_minimo(Matriz<bool>& matriz_adyacencia, Matriz<int>& matriz_pesos, size_t origen, size_t destino, size_t vertices) {

    Vector<size_t> distancias(vertices, INFINITO);
    Vector<bool> visitados(vertices, false);
    Vector<size_t> padre(vertices, INICIALIZADOR_PADRE);
    distancias[origen] = 0;
    std::priority_queue<TuplaVerticeDistancia> cola_prioridad;
    cola_prioridad.push(TuplaVerticeDistancia(origen, 0));

    while (!cola_prioridad.empty()) {
        TuplaVerticeDistancia actual = cola_prioridad.top();
        cola_prioridad.pop();

        int vertice_actual = static_cast<int>(actual.obtener_vertice());

        if (visitados[vertice_actual]) continue;
        visitados[vertice_actual] = true;

        for (size_t v = 0; v < vertices; ++v) {
            if (matriz_adyacencia(vertice_actual, v) && !visitados[v]) {
                int nuevo_peso = matriz_pesos(vertice_actual, v);
                size_t nueva_distancia = distancias[vertice_actual] + nuevo_peso;
                if (nueva_distancia < distancias[v]) {
                    distancias[v] = nueva_distancia;
                    padre[v] = vertice_actual;
                    cola_prioridad.push(TuplaVerticeDistancia(v, nueva_distancia));
                }
            }
        }
    }
    return reconstruir_camino(padre, origen, destino);
}

Vector<size_t> Dijkstra::reconstruir_camino(Vector<size_t> &padre, size_t origen, size_t destino) {
    Vector<size_t> camino_minimo;
    if (padre[destino] == INICIALIZADOR_PADRE) {  return camino_minimo;}

    for (size_t v = destino; v != INICIALIZADOR_PADRE; v = padre[v]) {
        if (v == origen) {
            camino_minimo.limpiar();
            return camino_minimo;
        }
        camino_minimo.alta(v);
    }
    camino_minimo.alta(origen);
    camino_minimo.invertir();
    return  camino_minimo;
}

Dijkstra::~Dijkstra() {}
