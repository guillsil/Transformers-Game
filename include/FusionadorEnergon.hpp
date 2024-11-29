#ifndef FUSIONADORENERGON_HPP
#define FUSIONADORENERGON_HPP

#include "GeneradorAleatorio.hpp"
#include "Cristal.hpp"
#include <stdexcept>

class ExcepcionFusionadorEnergon : public std::runtime_error {
public:
    ExcepcionFusionadorEnergon(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionFusionadorEnergon(): runtime_error("") {
    }
};

class FusionadorEnergon {
public:
    //Constructor
    //Pre: -
    //Post: Inicializa al objeto con fallos_consecutivos en ceros, la ultima_rareza como RAREZA_PROHIBIDA.
    FusionadorEnergon();

    //Pre: Los cristales deben ser del mismo nivel de rareza y los cristales del tipo LEGENDARIO no se pueden fusionar.
    //Post: Devuelve un nuevo cristal, que puede ser de mayor, menor o igual rareza a la del cristal, dependiendo del exito que tenga la fusión.
    //Si fallas 3 fusiones consecutivas, la proxima tendra el exito asegurado.
    Cristal fusionar(Cristal cristal_1, Cristal cristal_2);

    //Pre: Los cristales deben ser del mismo nivel de rareza y los cristales del tipo LEGENDARIO no se pueden fusionar.
    //Post: Devuelve un nuevo cristal, que puede ser de mayor, menor o igual rareza a la del cristal, dependiendo lo que devuelva el generador.
    //Si fallas 3 fusiones consecutivas, la proxima tendra el exito asegurado.
    Cristal fusionar(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio& generador);

private:
    int fallos_consecutivos[4];
    int ultima_rareza;
    int probabilidad_bonificacion;

    //Generador que permite consultar si se da la bonificación extra o no.
    GeneradorAleatorio generador_bonificacion;

    //Pre: Los cristales deben ser del mismo nivel de rareza y los cristales del tipo LEGENDARIO no se pueden fusionar.
    //Post: Devuelve un nuevo cristal, que puede ser de mayor, menor o igual rareza a la del cristal, dependiendo lo que devuelva el generador.
    //Si fallas 3 fusiones consecutivas, la proxima tendra el exito asegurado.
    Cristal fusionar_cristales(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio *generador);

    //Pre: -
    //Post: Lanza una excepcion si los cristales tienen distintas rarezas.
    void verificar_rarezas_iguales(Cristal &cristal_1, Cristal &cristal_2);

    //Pre: -
    //Post: Devuelve true si la fusion es exitosa o false en caso contrario.
    bool verificar_exito_de_fusion(const Rareza &rareza_actual, const int &porcentaje_exito, GeneradorAleatorio *generador);

    //Pre: -
    //Post: Si la rareza es LEGENDARIO lanza una excepcion.
    void verificar_fusion_prohibida(const Rareza &rareza);

    //Pre: La rareza no puede ser LEGENDARIA
    //Post: Devuelve la siguiente rareza según lo siguiente:
    /*
    Común a Raro
    Raro a Épico:
    Épico a Legendario
     */
    int obtener_proxima_rareza(const Rareza &rareza);

    //Pre: -
    //Post: Devuelve la rareza anteriror según lo siguiente:
    /*
    Común | Común
    Raro | Común:
    Épico | Raro
    Legendario | Epico
     */
    int obtener_rareza_anterior(const Rareza &rareza);

    //Pre: -
    //Post: Los fallos se resetean si la rareza es distinta de la ultima_rareza fusionada.
    void resetear_fallos_por_nivel(const Rareza &rareza);

    //Pre: La probabilidad_bonificacion debe ser menor que 100 siempre.
    //Post: Devuelve True si se otorga una bonificacion al nuevo cristal, false en caso contrario.
    bool dar_bonificacion(const int &probabilidad_bonificacion);

};

#endif
