#include <iostream>
#include "Juego.hpp"
#include "Vector.hpp"


int main() {
    Juego juego;
    Menu menu;
    char opcion_menu;
    menu.limpiar_menu();
    while (juego.jugando()) {
        menu.mostrar_menu_principal();
        std::cin >> opcion_menu;
        juego.procesar_menu_principal(opcion_menu);
    }

    return 0;
}