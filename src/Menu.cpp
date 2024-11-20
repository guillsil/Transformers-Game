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
  ║                                 ╔═════════════════════════════════════════╗                                 ║
  ║                                 ║             Ingrese su nombre:          ║                                 ║
  ║                                 ╚═════════════════════════════════════════╝                                 ║
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
  ║                  ███╗   ███╗███████╗ ██████╗  █████╗ ████████╗██████╗  ██████╗ ███╗   ██╗                   ║
  ║                  ████╗ ████║██╔════╝██╔════╝ ██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗████╗  ██║                   ║
  ║                  ██╔████╔██║█████╗  ██║  ███╗███████║   ██║   ██████╔╝██║   ██║██╔██╗ ██║                   ║
  ║                  ██║╚██╔╝██║██╔══╝  ██║   ██║██╔══██║   ██║   ██╔══██╗██║   ██║██║╚██╗██║                   ║
  ║                  ██║ ╚═╝ ██║███████╗╚██████╔╝██║  ██║   ██║   ██║  ██║╚██████╔╝██║ ╚████║                   ║
  ║                  ╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝                   ║)";
const std::string OPTIMUS_ASCII = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║                           ██████╗ ██████╗ ████████╗██╗███╗   ███╗██╗   ██╗███████╗                          ║
  ║                          ██║   ██║██   █║    ██║   ██║██╔█  █╔██║██║   ██║██║                               ║
  ║                          ██║   ██║██████║    ██║   ██║██║████║██║██║   ██║███████╗                          ║
  ║                          ██║   ██║██╔═══╝    ██║   ██║██║╚██╔╝██║██║   ██║╚════██║                          ║
  ║                          ╚██████╔╝██║        ██║   ██║██║ ╚═╝ ██║╚██████╔╝███████║                          ║
  ║                           ╚═════╝ ╚═╝        ╚═╝   ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚══════╝                          ║)";

const std::string MENU_PERSONAJE_ASCII = R"(
  ║                                                                                                             ║
  ║                                             Selecciona una opción:                                          ║
  ║            ╔═══════════════════════════════════════════════════════════════════════════════════╗            ║
  ║            ║                                                                                   ║            ║
  ║            ║      [1] Escribir un mensaje                  [5] Administrar Transformers        ║            ║
  ║            ║                                                                                   ║            ║
  ║            ║      [2] Sugerir una fusión                   [6] Equipar con un Cristal          ║            ║
  ║            ║                                                                                   ║            ║
  ║            ║      [3] Modificar Estado                     [7] Bóveda                          ║            ║
  ║            ║                                                                                   ║            ║
  ║            ║      [4] Fusionar Cristales                   [8] Salir                           ║            ║
  ║            ║                                                                                   ║            ║
  ║            ╚═══════════════════════════════════════════════════════════════════════════════════╝            ║
  ║                                                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";


const std::string MENU_INGRESAR_MENSAJE = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                              ▄▌▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█            ─▀▀▀▀▀▀█▀▀▀▀▀▀──────▄▄                   ║
  ║                           ▄▄██▌█                      █            ───▄▀█▀▀█▀▀█▄▄▄▄▄▄▄▄▀▀                   ║
  ║                        ▄▄▄▌▐██▌█               AFIP   █            ─▄█▄▄█▄▄█▄▄█████▀▀▀───                   ║
  ║                        ███████▌█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█            █████████████▀──────                     ║
  ║                        ▀(0)▀▀▀▀▀▀▀(0)(0)▀▀▀▀▀▀▀▀▀▀▀▀(0)▀           ─▄▄█▄▄▄▄▄▄▄█▄▄──────                     ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                             Ingresa el mensaje:                                             ║
  ║                                                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
const std::string MENU_INGRESAR_ESTADO = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                            ____                     _____________         _____________                     ║
  ║                       ____//_]|________        ____//__][__][___|    ____//__][______||                     ║
  ║                      (o _ |  -|   _  o|       (o  _|  -|     _ o|   (o _ |  -|   _   o|                     ║
  ║                       `(_)-------(_)--'        `-(_)--------(_)-'    `(_)-------(_)---'                     ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                                                                                             ║)";
const std::string MENU_INGRESAR_ESTADO_OPTIMUS = R"(
  ║                                           Estados de Intención :                                            ║
  ║                                    ╔══════════════════════════════════╗                                     ║
  ║                                    ║                                  ║                                     ║
  ║                                    ║        [1]  Sereno               ║                                     ║
  ║                                    ║                                  ║                                     ║
  ║                                    ║        [2]  Determinado          ║                                     ║
  ║                                    ║                                  ║                                     ║
  ║                                    ║        [3]  Enfurecido           ║                                     ║
  ║                                    ║                                  ║                                     ║
  ║                                    ╚══════════════════════════════════╝                                     ║
  ║                                                                                                             ║)";
const std::string MENU_INGRESAR_ESTADO_MEGATRON = R"(
  ║                                           Estados de Intención :                                            ║
  ║                                     ╔═════════════════════════════════╗                                     ║
  ║                                     ║                                 ║                                     ║
  ║                                     ║        [1]  Desprecio           ║                                     ║
  ║                                     ║                                 ║                                     ║
  ║                                     ║        [2]  Manipulación        ║                                     ║
  ║                                     ║                                 ║                                     ║
  ║                                     ║        [3]  Amenaza             ║                                     ║
  ║                                     ║                                 ║                                     ║
  ║                                     ╚═════════════════════════════════╝                                     ║
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
  ║               ██████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗ █████╗ ███████╗  ██████╗ ██████╗               ║
  ║               ██════╝██║   ██║██╔════╝██║██╔═══██║████╗  ██║██╔══██╗██║   ██║██║   ██║██╔══██╗              ║
  ║               ██████╗██║   ██║███████╗██║██║   ██║██╔██╗ ██║███████║██║   ██║██║   ██║██████╔╝              ║
  ║               ██╔═══╝██║   ██║╚════██║██║██║   ██║██║╚██╗██║██╔══██║██║   ██║██║   ██║██╔══██╗              ║
  ║               ██║    ╚██████╔╝███████║██║╚██████╔╝██║ ╚████║██║  ██║███████╔╝╚██████╔╝██║  ██║              ║
  ║               ╚═╝     ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝              ║
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║                                                                                                             ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                  Ingresa los cristales que deseas fusionar:                                 ║
  ║                                                                                                             ║
  ║                                     0-Cómun       1-Raro        2-Epico                                     ║
  ║                                                                                                             ║
  ║                      (Debe ingresar el indice correspondiente a cada nivel de cristal)                      ║
  ║                         (Por ejemplo si ingresa 0, corresponde a un cristal Cómun)                          ║
  ║                                                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝)";
const std::string BOVEDA= R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                                             //                                                              ║
  ║                              ██████╗ ██████╗ ██╗   ██╗███████╗███████╗  █████╗                              ║
  ║                              ██   █║██║   ██║██║   ██║██╔════╝██║   ██║██╔══██╗                             ║
  ║                              ██████╝██║   ██║██║   ██║█████╗  ██║   ██║███████║                             ║
  ║                              ██═══█║██║   ██║ ██  ██║ ██╔══╝  ██║   ██║██╔══██║                             ║
  ║                              ██████║╚██████╔╝  ████╔╝ ███████╗███████╔╝██║  ██║                             ║
  ║                              ╚═════╝ ╚═════╝     ╚═╝  ╚══════╝ ╚═════╝ ╚═╝  ╚═╝                             ║)";
const std::string MENU_BOVEDA= R"(
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                             Bóveda de Almacenamiento                                        ║
  ║                                                                                                             ║
  ║          ╔═══════════════════════════════════════════════════════════════════════════════════════╗          ║
  ║          ║                                                                                       ║          ║
  ║          ║              [1]  Almacenar un Cristal           [4]  Cantidad Cristales              ║          ║
  ║          ║                                                                                       ║          ║
  ║          ║              [2]  Mostrar Cristales              [5]  Mostrar Crista con Mayor Poder  ║          ║
  ║          ║                                                                                       ║          ║
  ║          ║              [3]  Exportar Cristales             [6]  Salir                           ║          ║
  ║          ║                                                                                       ║          ║
  ║          ╚═══════════════════════════════════════════════════════════════════════════════════════╝          ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string ADMINISTRADOR_TRANSFORMERS = R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║    █████╗ ███████╗ ███╗   ███╗██╗███╗   ██╗██╗███████╗████████╗██████╗  █████╗ ███████╗  ██████╗ ██████╗    ║
  ║   ██╔══██╗██║   ██║████╗ ████║██║████╗  ██║██║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██║   ██║██╔═══██║██╔══██╗   ║
  ║   ███████║██║   ██║██╔████╔██║██║██╔██╗ ██║██║███████╗   ██║   ██████╔╝███████║██║   ██║██║   ██║██████╔╝   ║
  ║   ██╔══██║██║   ██║██║╚██╔╝██║██║██║╚██╗██║██║╚════██║   ██║   ██╔══██╗██╔══██║██║   ██║██║   ██║██╔══██╗   ║
  ║   ██║  ██║███████╔╝██║ ╚═╝ ██║██║██║ ╚████║██║███████║   ██║   ██║  ██║██║  ██║███████╔╝╚██████╔╝██║  ██║   ║
  ║   ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝   ║
  ║   ████████╗██████╗   █████╗ ███╗   ██╗███████╗██████╗ ██████╗ ██████╗ ███╗   ███╗███████╗██████╗ ███████╗   ║
  ║   ╚══██╔══╝██╔══██╗ ██╔══██╗████╗  ██║██╔════╝██════╝██╔═══██║██╔══██╗████╗ ████║██╔════╝██╔══██╗██╔════╝   ║
  ║      ██║   ██████╔╝ ███████║██╔██╗ ██║███████╗██████╗██║   ██║██████╔╝██╔████╔██║█████╗  ██████╔╝███████╗   ║
  ║      ██║   ██╔══██╗ ██╔══██║██║╚██╗██║╚════██║██╔═══╝██║   ██║██╔══██╗██║╚██╔╝██║██╔══╝  ██╔══██╗╚════██║   ║
  ║      ██║   ██║  ██║ ██║  ██║██║ ╚████║███████║██║    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗██║  ██║███████║   ║
  ║      ╚═╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝   ║
  ║                                                                                                             ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                  Administrador de Transformers Secundarios                                  ║
  ║                                                                                                             ║
  ║          ╔═══════════════════════════════════════════════════════════════════════════════════════╗          ║
  ║          ║                                                                                       ║          ║
  ║          ║  [1]  Agregar un nuevo Transformer           [4]  Eliminar un Transformer por nombre  ║          ║
  ║          ║                                                                                       ║          ║
  ║          ║  [2]  Mostrar todos los Transformers         [5]  Transformar un Transformer          ║          ║
  ║          ║                                                                                       ║          ║
  ║          ║  [3]  Buscar un Transformer por nombre       [6]  Salir                               ║          ║
  ║          ║                                                                                       ║          ║
  ║          ╚═══════════════════════════════════════════════════════════════════════════════════════╝          ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string MENU_ESCOGER_NOMBRE_TRANSFORMERS= R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║        888                                   .d888                                                          ║
  ║        888                                  d88P"                                                           ║
  ║        888                                  888                                                             ║
  ║        888888888d888 8888b. 88888b. .d8888b 888888 .d88b. 888d88888888b.d88b.  .d88b. 888d888.d8888b        ║
  ║        888   888P"      "88b888 "88b88K     888   d88""88b888P"  888 "888 "88bd8P  Y8b888P"  88K            ║
  ║        888   888    .d888888888  888"Y8888b.888   888  888888    888  888  88888888888888    "Y8888b.       ║
  ║        Y88b. 888    888  888888  888     X88888   Y88..88P888    888  888  888Y8b.    888         X88       ║
  ║         "Y888888    "Y888888888  888 88888P'888    "Y88P" 888    888  888  888 "Y8888 888     88888P'       ║
  ║                                                                                                             ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║              ╔════════════════════════════════════════════════════════════════════════════════╗             ║
  ║              ║                                                                                ║             ║
  ║              ║                      Ingrese el Nombre del Transformers.                       ║             ║
  ║              ║                                                                                ║             ║
  ║              ╚════════════════════════════════════════════════════════════════════════════════╝             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string MENU_ESCOGER_FACCION= R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                 ╚╝                                          ║
  ║                             ██████╗ █████╗ ██████╗██████╗██╗ ██████╗ ███╗   ██╗                             ║
  ║                             ██════╝██╔══██╗██╔═══╝██╔═══╝██║██╔═══██║████╗  ██║                             ║
  ║                             ██████╗███████║██║    ██║    ██║██║   ██║██╔██╗ ██║                             ║
  ║                             ██╔═══╝██╔══██║██║    ██║    ██║██║   ██║██║╚██╗██║                             ║
  ║                             ██║    ██║  ██║██████╗██████╗██║╚██████╔╝██║ ╚████║                             ║
  ║                             ╚═╝    ╚═╝  ╚═╝╚═════╝╚═════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝                             ║
  ║                                                                                                             ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                    Escoge la facción de su Transformers.                                    ║
  ║                                                                                                             ║
  ║              ╔════════════════════════════════════════════════════════════════════════════════╗             ║
  ║              ║                                                                                ║             ║
  ║              ║                      [0] Autobots      [1] Decepticons                         ║             ║
  ║              ║                                                                                ║             ║
  ║              ╚════════════════════════════════════════════════════════════════════════════════╝             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";

const std::string MENU_ESCOGER_VEHICULO= R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                             ,-----------------.                    ,-----------------.                      ║
  ║                            /,--------.--------.\                  /,--------.--------.\                     ║
  ║                           /:       '---' ,--.  :\                ::       '---'       ::                    ║
  ║                          (.'------------'----`-',)               ||__,-=-.____________||                    ║
  ║                        ,' \`.        $        ,'/ `.           ,( \.        &        ,/ ).                  ║
  ║                      ,'-.--. `.------^------.' .--,-`.       ,'-.-. `,------^------.' ,-,-`.                ║
  ║                     ((__)) |,'    ___|___    `.| ((__))     ((__))|\/    ___|___    \/|((__))               ║
  ║                     |`--' _|_________|_________|_ `--'|     |`--' |_________|_________| `--'|               ║
  ║                     | __,',--.__|____|____|__,--.`.__ |     | __,',-.__|____|____|__,-.`.__ |               ║
  ║                     ||__`_`--'._|____|____|__`--','__||     ||__`.`-'__|____|____|__`-','__||               ║
  ║                    (___          |  AFIP |          ___)   (___         |  AFIP |         ___)              ║
  ║                       |````|``---'-------'---``|````|         |```|-----'-------'-----|```|                 ║
  ║                       '----'                   '----'         '---'                   '---'                 ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                             Escoge el Vehículo.                                             ║
  ║                                                                                                             ║
  ║              ╔════════════════════════════════════════════════════════════════════════════════╗             ║
  ║              ║                                                                                ║             ║
  ║              ║                           [0] Auto        [1] Camión                            ║             ║
  ║              ║                                                                                ║             ║
  ║              ╚════════════════════════════════════════════════════════════════════════════════╝             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string MENU_ESCOGER_AERONAVE= R"(
  ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
  ║                                                                                                             ║
  ║                                                .     .-/,\-.     ,                                          ║
  ║                                                 \ .-'//,M,\\`-. /                                           ║
  ║                                                .-' .'/,MMM,\`. `-.                                          ║
  ║                                           _.-"^\  / /       \ \  /^"-._                                     ║
  ║                                          /,MMMM".' /  .-|-.  \ '."MMMM,\                                    ║
  ║                            ________,,,/_,MMMM"/  /.-"  |  "-.\  \"MMMM,_\,,,_________                       ║
  ║               -=========================='===^==^==^=====^==='=============================-                ║
  ║                             ``^^^"""""""||\""""""""""""||\""""""""""""/||""""""""^^^``                      ║
  ║                                         ||             ||_)            ||                                   ║
  ║                                         ||,            (|             ,||                                   ║
  ║                                         db|            d8b            |db                                   ║
  ║                                         YP             Y8P             YP                                   ║
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                                             Escoge la Aeronave.                                             ║
  ║                                                                                                             ║
  ║              ╔════════════════════════════════════════════════════════════════════════════════╗             ║
  ║              ║                                                                                ║             ║
  ║              ║                          [0] Avion                [2] Tanque                   ║             ║
  ║              ║                                                                                ║             ║
  ║              ╚════════════════════════════════════════════════════════════════════════════════╝             ║
  ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
const std::string MENU_INGRESAR_CRISTALES_BOVEDA= R"(
  ║ ════════════════════════════════════════════════════════════════════════════════════════════════════════════║
  ║                                                                                                             ║
  ║                            Ingrese el Cristal que deseá almacenar en la bóveda.                             ║
  ║                                                                                                             ║
  ║              ╔════════════════════════════════════════════════════════════════════════════════╗             ║
  ║              ║                                                                                ║             ║
  ║              ║           [0] Común       [0] Raro      [0] Épico     [0] Legendario           ║             ║
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
  ║              ║                                                                                ║             ║
  ║              ║  Recuerda que solo podes ingresar ya sea el nombre del archivo, Por ejemplo:   ║             ║
  ║              ║                                                                                ║             ║
  ║              ║  •Ingrese la ruta: pepe -> entonces se creara un archivo llamado pepe en el    ║             ║
  ║              ║  directorio raíz llamado /archivos.                                            ║             ║
  ║              ║  También podrás ingresar con una ruta y el nombre del archivo, Por ejemplo:    ║             ║
  ║              ║                                                                                ║             ║
  ║              ║  •Ingrese la ruta: /pepe/quiere_aprobar.csv  -> entonces se guardara este      ║             ║
  ║              ║   directorio con el archivo en el directorio raíz llamado /archivos            ║             ║
  ║              ║                                                                                ║             ║
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

void Menu::mostrar_menu_administrador_transformers(){
    std::cout << ADMINISTRADOR_TRANSFORMERS;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::menu_escoger_faccion(){
    std::cout << MENU_ESCOGER_FACCION;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}


void Menu::menu_escoger_vehiculo(){
    std::cout << MENU_ESCOGER_VEHICULO;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::menu_escoger_aeronave(){
    std::cout << MENU_ESCOGER_AERONAVE;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}

void Menu::menu_ingregar_nombre_transformers(){
    std::cout << MENU_ESCOGER_NOMBRE_TRANSFORMERS;
    std::cout << SIMBOLO_INGRESAR_MENSAJE;
}