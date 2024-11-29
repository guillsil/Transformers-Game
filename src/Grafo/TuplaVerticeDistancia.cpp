#include "../../include/TDAs/Grafo/TuplaVerticeDistancia.hpp"


TuplaVerticeDistancia::TuplaVerticeDistancia(){
}

TuplaVerticeDistancia::TuplaVerticeDistancia(size_t vertice, size_t distancia) {
    this->vertice = vertice;
    this->distancia = distancia;
}

bool TuplaVerticeDistancia::operator>(const TuplaVerticeDistancia &otra) const {
    return distancia < otra.distancia;
}

bool TuplaVerticeDistancia::operator<(const TuplaVerticeDistancia &otra) const {
    return distancia > otra.distancia; // Menor distancia => Mayor prioridad
}



size_t TuplaVerticeDistancia::obtener_vertice() const { return vertice;}

size_t TuplaVerticeDistancia::obtener_distancia() const { return distancia;}
