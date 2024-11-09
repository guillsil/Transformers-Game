#include <iostream>
#include "Juego.hpp"
#include "Vector.hpp"


int main() {
    char opcion_menu;
    std::string nombre_jugador;
    Juego juego;
    Menu menu;

    menu.limpiar_menu();
    menu.mostrar_menu_inicial();
    std::cin >> nombre_jugador;
    while (juego.jugando()) {
        menu.limpiar_menu();
        menu.mostrar_menu_principal(nombre_jugador);
        std::cin >> opcion_menu;
        juego.procesar_menu_principal(opcion_menu, nombre_jugador);
    }
    return 0;
}