#include "../../include/TDAs/Grafo/FloydWarshall.hpp"

const int INICIALIZADOR_PADRE = 0;

FloydWarshall::FloydWarshall() {
}

Vector<size_t> FloydWarshall::calcular_camino_minimo(Matriz<bool>& matriz_adyacencia, Matriz<int>& matriz_pesos, size_t origen, size_t destino, size_t vertices) {
    Matriz<int> distancias(vertices, INFINITO);
    Matriz<int> padre(vertices, INICIALIZADOR_PADRE);
    for (size_t i = 0; i < vertices; i++) {
        for (size_t j = 0; j < vertices; j++) {
            if (i == j) {
                distancias(i, j) = 0;
            }else {
                distancias(i, j) = matriz_pesos(i, j);
                padre(i, j) = static_cast<int>(i);

            }
        }
    }
    for (size_t k = 0; k < vertices; k++) {
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                int nueva_distancia = distancias(i, k) + distancias(k, j);
                if (nueva_distancia < distancias(i, j)) {
                    distancias(i, j) = nueva_distancia;
                    padre(i, j) = padre(k, j);
                }
            }
        }
    }
    return reconstruir_camino(padre, origen, destino);
}


FloydWarshall::~FloydWarshall() {
}

Vector<size_t> FloydWarshall::reconstruir_camino(Matriz<int> &padre, size_t origen, size_t destino) {
    Vector<size_t> camino_minimo;
    if (padre(origen, destino) == INICIALIZADOR_PADRE) {
        return camino_minimo;
    }

    while (destino != origen) {
        camino_minimo.alta(destino);
        destino = padre(origen, destino);
    }
    camino_minimo.alta(origen);

    // Invertimos el camino para obtener el orden correcto
    camino_minimo.invertir();
    return camino_minimo;
}
