//
// Created by guille on 9/17/24.
//

#include "Menu.hpp"
const std::string TRANSFORMERS_LOGO = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║   ████████╗██████╗   █████╗ ███╗   ██╗███████╗██████╗ ██████╗ ██████╗ ███╗   ███╗███████╗██████╗ ███████╗   ║
  ║   ╚══██╔══╝██╔══██╗ ██╔══██╗████╗  ██║██╔════╝██════╝██╔═══██║██╔══██╗████╗ ████║██╔════╝██╔══██╗██╔════╝   ║
  ║      ██║   ██████╔╝ ███████║██╔██╗ ██║███████╗██████╗██║   ██║██████╔╝██╔████╔██║█████╗  ██████╔╝███████╗   ║
  ║      ██║   ██╔══██╗ ██╔══██║██║╚██╗██║╚════██║██╔═══╝██║   ██║██╔══██╗██║╚██╔╝██║██╔══╝  ██╔══██╗╚════██║   ║
  ║      ██║   ██║  ██║ ██║  ██║██║ ╚████║███████║██║    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██║  ██║███████║   ║
  ║      ╚═╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝   ║
  ║                                                                                                             ║
  ║                      ████████╗██   ██╗███████╗     ███████╗ █████╗ ███╗   ███╗███████╗                      ║
  ║                         ██║   ██╔══██║██╔════╝     ██╔════╝██╔══██╗████╗ ████║██╔════╝                      ║
  ║                         ██║   ███████║█████╗       ███████╗███████║██╔████╔██║█████╗                        ║
  ║                         ██║   ██╔══██║██╔══╝       ██╚══██║██╔══██║██║╚██╔╝██║██╔══╝                        ║
  ║                         ██║   ██║  ██║███████╗     ███████║██║  ██║██║ ╚═╝ ██║███████╗                      ║
  ║                         ╚═╝   ╚═╝  ╚═╝╚══════╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝                      ║
  ║                                                                                                             ║)";
const std::string MENU_INICIAL = R"(
  ║                             ╔═════════════════════════════════════════╗                                     ║
  ║                             ║             Ingrese su nombre:          ║                                     ║
  ║                             ╚═════════════════════════════════════════╝                                     ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
const std::string MENU_PRINCIPAL = R"(
  ║                                       Selecciona una opción:                                                ║
  ║                             ╔═════════════════════════════════════════╗                                     ║
  ║                             ║                                         ║                                     ║
  ║                             ║   [1] Interactuar con (Megatron)        ║                                     ║
  ║                             ║                                         ║                                     ║
  ║                             ║   [2] Interactuar con (Optimus Prime)   ║                                     ║
  ║                             ║                                         ║                                     ║
  ║                             ║   [3] Salir                             ║                                     ║
  ║                             ║                                         ║                                     ║
  ║                             ╚═════════════════════════════════════════╝                                     ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
const std::string MEGATRON_ASCII = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║                    ███╗   ███╗███████╗ ██████╗  █████╗ ████████╗██████╗  ██████╗ ███╗   ██╗                 ║
  ║                    ████╗ ████║██╔════╝██╔════╝ ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗████╗  ██║                 ║
  ║                    ██╔████╔██║█████╗  ██║  ███╗███████║   ██║   ██████╔╝██║   ██║██╔██╗ ██║                 ║
  ║                    ██║╚██╔╝██║██╔══╝  ██║   ██║██╔══██║   ██║   ██╔══██╗██║   ██║██║╚██╗██║                 ║
  ║                    ██║ ╚═╝ ██║███████╗╚██████╔╝██║  ██║   ██║   ██║  ██║╚██████╔╝██║ ╚████║                 ║
  ║                    ╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝                 ║)";
const std::string OPTIMUS_ASCII = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║                             ██████╗ ██████╗ ████████╗██╗███╗   ███╗██╗   ██╗███████╗                        ║
  ║                            ██║   ██║██   █║    ██║   ██║██╔█  █╔██║██║   ██║██║                             ║
  ║                            ██║   ██║██████║    ██║   ██║██║████║██║██║   ██║███████╗                        ║
  ║                            ██║   ██║██╔═══╝    ██║   ██║██║╚██╔╝██║██║   ██║╚════██║                        ║
  ║                            ╚██████╔╝██║        ██║   ██║██║ ╚═╝ ██║╚██████╔╝███████║                        ║
  ║                             ╚═════╝ ╚═╝        ╚═╝   ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚══════╝                        ║)";

const std::string MENU_PERSONAJE_ASCII = R"(
  ║                                                                                                             ║
  ║                                             Selecciona una opción:                                          ║
  ║                                         ╔════════════════════════════╗                                      ║
  ║                                         ║                            ║                                      ║
  ║                                         ║   [1] Escribir un mensaje  ║                                      ║
  ║                                         ║                            ║                                      ║
  ║                                         ║   [2] Sugerir una fusión   ║                                      ║
  ║                                         ║                            ║                                      ║
  ║                                         ║   [3] Modificar Estado     ║                                      ║
  ║                                         ║                            ║                                      ║
  ║                                         ║   [4] Fusionar Cristales   ║                                      ║
  ║                                         ║                            ║                                      ║
  ║                                         ║   [5] Bóveda               ║                                      ║
  ║                                         ║                            ║                                      ║
  ║                                         ║   [6] Salir                ║                                      ║
  ║                                         ║                            ║                                      ║
  ║                                         ╚════════════════════════════╝                                      ║
  ║                                                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";


const std::string MENU_INGRESAR_MENSAJE = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                              ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█            ─▀▀▀▀▀▀█▀▀▀▀▀▀──────▄▄                   ║
  ║                           ▄▄██▌█                      █            ───▄▀█▀▀█▀▀█▄▄▄▄▄▄▄▄▀▀                   ║
  ║                        ▄▄▄▌▐██▌█               elliug █            ─▄█▄▄█▄▄█▄▄█████▀▀▀───                   ║
  ║                        ███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█            █████████████▀──────                     ║
  ║                        ▀(0)▀▀▀▀▀▀▀(0)(0)▀▀▀▀▀▀▀▀▀▀▀▀(0)▀           ─▄▄█▄▄▄▄▄▄▄█▄▄──────                     ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                                 Ingresa el mensaje:                                         ║
  ║                                                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
const std::string MENU_INGRESAR_ESTADO = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                          ─▀▀▀▀▀▀█▀▀▀▀▀▀──────▄▄                 ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█                  ║
  ║                        ───▄▀█▀▀█▀▀█▄▄▄▄▄▄▄▄▀▀                ▄▄██▌█                      █                  ║
  ║                        ─▄█▄▄█▄▄█▄▄█████▀▀▀───             ▄▄▄▌▐██▌█               elliug █                  ║
  ║                         ██████████████▀──────             ███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█                  ║
  ║                          ─▄▄█▄▄▄▄▄▄▄█▄▄──────             ▀(0)▀▀▀▀▀▀▀(0)(0)▀▀▀▀▀▀▀▀▀▀▀▀(0)▀                 ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                                                                                             ║)";
const std::string MENU_INGRESAR_ESTADO_OPTIMUS = R"(
  ║                                                Estados de Intención :                                       ║
  ║                                        ╔══════════════════════════════════╗                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║        [1]  Sereno               ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║        [2]  Determinado          ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║        [3]  Enfurecido           ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ╚══════════════════════════════════╝                                 ║
  ║                                                                                                             ║)";
const std::string MENU_INGRESAR_ESTADO_MEGATRON = R"(
  ║                                               Estados de Intención :                                        ║
  ║                                         ╔═════════════════════════════════╗                                 ║
  ║                                         ║                                 ║                                 ║
  ║                                         ║        [1]  Desprecio           ║                                 ║
  ║                                         ║                                 ║                                 ║
  ║                                         ║        [2]  Manipulación        ║                                 ║
  ║                                         ║                                 ║                                 ║
  ║                                         ║        [3]  Amenaza             ║                                 ║
  ║                                         ║                                 ║                                 ║
  ║                                         ╚═════════════════════════════════╝                                 ║
  ║                                                                                                             ║)";

const std::string PARTE_SUPERIOR_RECUADRO = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
    )";
const std::string PARTE_INFERIOR_RECUADRO = R"(
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
const std::string MENU_FUSIONAR_CRISTALES = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║                ██████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗ █████╗ ███████╗  ██████╗ ██████╗              ║
  ║                ██════╝██║   ██║██╔════╝██║██╔═══██║████╗  ██║██╔══██╗██║   ██║██║   ██║██╔══██╗             ║
  ║                ██████╗██║   ██║███████╗██║██║   ██║██╔██╗ ██║███████║██║   ██║██║   ██║██████╔╝             ║
  ║                ██╔═══╝██║   ██║╚════██║██║██║   ██║██║╚██╗██║██╔══██║██║   ██║██║   ██║██╔══██╗             ║
  ║                ██║    ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║██║  ██║███████╔╝╚██████╔╝██║  ██║             ║
  ║                ╚═╝     ╚═════╝╚══════╝╚═╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝             ║
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                   Ingresa los cristales que deseas fusionar:                                ║
  ║                                                                                                             ║
  ║                                        0-Cómun       1-Raro        2-Epico                                  ║
  ║                                                                                                             ║
  ║                         (Debe ingresar el indice correspondiente a cada nivel de cristal)                   ║
  ║                            (Por ejemplo si ingresa 0, corresponde a un cristal Cómun)                       ║
  ║                                                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝)";
const std::string BOVEDA= R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                                             //                                                              ║
  ║                                 ██████╗ ██████╗ ██╗   ██╗███████╗███████╗  █████╗                           ║
  ║                                 ██   █║██║   ██║██║   ██║██╔════╝██║   ██║██╔══██╗                          ║
  ║                                 ██████╝██║   ██║██║   ██║█████╗  ██║   ██║███████║                          ║
  ║                                 ██═══█║██║   ██║ ██  ██║ ██╔══╝  ██║   ██║██╔══██║                          ║
  ║                                 ██████║╚██████╔╝  ████╔╝ ███████╗███████╔╝██║  ██║                          ║
  ║                                 ╚═════╝ ╚═════╝     ╚═╝  ╚══════╝ ╚═════╝ ╚═╝  ╚═╝                          ║)";
const std::string MENU_BOVEDA= R"(
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                             Bóveda de Almacenamiento                                        ║
  ║                                                                                                             ║
  ║                                        ╔══════════════════════════════════╗                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║   [1]  Almacenar un Cristal      ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║   [2]  Mostrar Cristales         ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║   [3]  Exportar Cristales        ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║   [4]  Cantidad Cristales        ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ║   [5]  Salir                     ║                                 ║
  ║                                        ║                                  ║                                 ║
  ║                                        ╚══════════════════════════════════╝                                 ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string MENU_INGRESAR_CRISTALES_BOVEDA= R"(
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                               Ingrese el Cristal que deseá almacenar en la bóveda.                          ║
  ║                                                                                                             ║
  ║              ╔════════════════════════════════════════════════════════════════════════════════╗             ║
  ║              ║                                                                                ║             ║
  ║              ║              0-Común       1-Raro      2-Épico     3-Legendario                ║             ║
  ║              ║                                                                                ║             ║
  ║              ╚════════════════════════════════════════════════════════════════════════════════╝             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string MENU_INGRESAR_RUTA_ARCHIVO= R"(
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                          Ingrese la ruta en la cual quieres exportar el archivo:                            ║
  ║                                                                                                             ║
  ║              ╔════════════════════════════════════════════════════════════════════════════════╗             ║
  ║              ║  Recuerda que solo podes ingresar ya sea el nombre del archivo, Por ejemplo:   ║             ║
  ║              ║  •Ingrese la ruta: pepe -> entonces se creara un archivo llamado pepe en el    ║             ║
  ║              ║  directorio raíz llamado /archivos.                                            ║             ║
  ║              ║  También podrás ingresar con una ruta y el nombre del archivo, Por ejemplo:    ║             ║
  ║              ║  •Ingrese la ruta: /pepe/quiere_aprobar.csv  -> entonces se guardara este      ║             ║
  ║              ║   directorio con el archivo en el directorio raíz llamado /archivos            ║             ║
  ║              ╚════════════════════════════════════════════════════════════════════════════════╝             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string SIMBOLO_INGRESAR_MENSAJE = "-: ";

void Menu::mostrar_menu_principal(const std::string &nombre) {
    mostrar_mensaje("Bienvenido " + nombre + " ¡prepárate para esta aventura!");
    std::cout << TRANSFORMERS_LOGO;
    std::cout << MENU_PRINCIPAL << std::endl;
    std::cout<<SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::mostrar_menu_personaje(const int &personaje_elejido) {
    if (personaje_elejido == MEGATRON) {
        std::cout << MEGATRON_ASCII;
    }else {
        std::cout << OPTIMUS_ASCII;
    }
    std::cout << MENU_PERSONAJE_ASCII;
    std::cout<<SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::mostrar_menu_estado(const int &personaje_elejido) {
    std::cout << MENU_INGRESAR_ESTADO;
    if (personaje_elejido == MEGATRON) {
        std::cout << MENU_INGRESAR_ESTADO_MEGATRON;
    }else {
        std::cout << MENU_INGRESAR_ESTADO_OPTIMUS;
    }
    std::cout << PARTE_INFERIOR_RECUADRO;
    std::cout<<SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::mostrar_menu_ingresar_mensaje() {
    std::cout << MENU_INGRESAR_MENSAJE;
    std::cout<<SIMBOLO_INGRESAR_MENSAJE;
}



void Menu::mostrar_recuadro_superior() {
    std::cout << PARTE_SUPERIOR_RECUADRO;
}

void Menu::mostrar_recuadro_inferior() {
    std::cout << PARTE_INFERIOR_RECUADRO;
}

void Menu::limpiar_menu() {
    system("clear");
}

void Menu::mostrar_mensaje(const std::string &mensaje) {
    std::cout << PARTE_SUPERIOR_RECUADRO;
    std::cout << mensaje;
    std::cout << PARTE_INFERIOR_RECUADRO;
}

void Menu::mostrar_menu_fusionar_cristales() {
    std::cout << MENU_FUSIONAR_CRISTALES << std::endl;
}


void Menu::mostrar_menu_boveda() {
    std::cout << BOVEDA;
    std::cout << MENU_BOVEDA;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::mostrar_menu_almacenar_cristal() {
    std::cout << BOVEDA;
    std::cout << MENU_INGRESAR_CRISTALES_BOVEDA;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::mostrar_menu_exportar_archivo() {
    std::cout << BOVEDA;
    std::cout << MENU_INGRESAR_RUTA_ARCHIVO;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::mostrar_ingresar_cristal(const int &cristal) {
    std::cout << PARTE_SUPERIOR_RECUADRO;
    std::cout << "Cristal " << cristal;
    std::cout << PARTE_INFERIOR_RECUADRO;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::mostrar_estadisticas(const std::string &fuerza, const std::string &defensa, const std::string &velocidad) {
    std::cout << "                Fuerza: " << fuerza << "                    Defensa: " << defensa << "                      Velocidad: " << velocidad << std::endl;
    std::cout << PARTE_INFERIOR_RECUADRO;
}

void Menu::mostrar_rareza(const std::string &rareza) {
    std::cout << PARTE_SUPERIOR_RECUADRO;
    std::cout << "Rareza: " << rareza << std::endl;
}

void Menu::mostrar_menu_inicial() {
    std::cout << TRANSFORMERS_LOGO;
    std::cout << MENU_INICIAL;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}


