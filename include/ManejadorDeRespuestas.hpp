//
// Created by guille on 9/13/24.
//

#ifndef MANEJADORDERESPUESTAS_HPP
#define MANEJADORDERESPUESTAS_HPP
#include <iostream>

#include "Utilidades.hpp"

const int MAX_RESPUESTAS = 10;


class ManejadorDeRespuestas {

public:
  ManejadorDeRespuestas();

  //Pre: respuesta debe ser una cadena válida y el número total de respuestas ingresadas debe ser inferior a MAX_RESPUESTAS
  //Post: Almacena la respuesta ingresada.
  void agregar_respuesta(const std::string& respuesta);

  //Pre: respuesta_random debe ser una cadena válida y el número total de respuestas randoms ingresadas debe ser inferior a MAX_RESPUESTAS
  //Post: Almacena la respuesta random ingresada.
  void agregar_respuesta_random(const std::string& respuesta_random);

  //Pre: El índice debe ser válido es decir estar entre 0 y cantidad respuestas.
  //Post: Devuelve la respuesta correspondiente según el índice
  std::string obtener_respuesta_por_indice(const int &indice);

  //Pre: Almenos debe contener una respuesta random ingresada.
  //Post: Devuelve al azar una respuesta random.
  std::string obtener_respuesta_random();

private:
  Utilidades utilidades;
  std::string respuestas[MAX_RESPUESTAS];
  std::string respuestas_random[MAX_RESPUESTAS];
  int cantidad_respuestas;
  int cantidad_respuestas_random;
};



#endif //MANEJADORDERESPUESTAS_HPP
