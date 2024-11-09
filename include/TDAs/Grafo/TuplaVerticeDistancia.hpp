//
// Created by guille on 03/11/24.
//

#ifndef TUPLAVERTICEDISTANCIA_HPP
#define TUPLAVERTICEDISTANCIA_HPP
#include "iostream"

class TuplaVerticeDistancia {
public:
    TuplaVerticeDistancia(size_t vertice, size_t distancia);

    bool operator<(const TuplaVerticeDistancia &otra) const;

    size_t obtener_vertice() const;

    size_t obtener_distancia() const;

private:
    size_t vertice;
    size_t distancia;
};

#endif //TUPLAVERTICEDISTANCIA_HPP
