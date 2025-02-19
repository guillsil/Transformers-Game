cmake_minimum_required(VERSION 3.22)
project(AYED_TPG_2C2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

add_compile_options(-Wall -Werror -Wconversion)

include_directories(include)
include_directories(include/TDAs)
include_directories(include/TDAs/Grafo)

# Tienen que agregar acá todos los archivos que necesiten compilar, con el siguiente formato:
#   directorio/archivo1.cpp
#   directorio/archivo2.cpp
#   ...
set(ARCHIVOS_FUENTE
        include/TDAs/Vector.hpp
        include/TDAs/Cola.hpp
        include/TDAs/Pila.hpp
        include/TDAs/Lista.hpp
        include/TDAs/NodoLista.hpp
        include/TDAs/Diccionario.hpp
        include/TDAs/NodoDiccionario.hpp
        include/TDAs/Heap.hpp
        include/TDAs/Matriz.hpp

        include/TDAs/Grafo/CaminoMinimo.hpp
        include/TDAs/Grafo/Dijkstra.hpp
        include/TDAs/Grafo/FloydWarshall.hpp
        include/TDAs/Grafo/Grafo.hpp

        src/Grafo/Dijkstra.cpp
        src/Grafo/FloydWarshall.cpp
        src/Grafo/Grafo.cpp

        src/Megatron.cpp
        src/OptimusPrime.cpp
        src/ManejadorDeRespuestas.cpp
        src/ManejadorDePalabrasClaves.cpp
        src/ManejadorDeMensajes.cpp

        src/GeneradorAleatorio.cpp
        src/FusionadorEnergon.cpp
        src/Cristal.cpp
        src/BovedaCristales.cpp
        src/Juego.cpp
        src/Menu.cpp
        src/Utilidades.cpp

        src/Estadisticas.cpp
        src/Grafo/TuplaVerticeDistancia.cpp

        src/Protagonista.cpp

        src/GraficadorCombates.cpp
        src/SimulacionCombate.cpp
        src/GeneradorCombates.cpp
        src/CombatesUsuario.cpp

        include/ControlArchivo.hpp
        src/Transformers.cpp
        src/AdminTransformers.cpp
        src/DatosJugador.cpp
        src/TablaClasificacion.cpp
)

add_executable(AYED_TPG_2C2024
        ${ARCHIVOS_FUENTE}
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

add_subdirectory(tests)

target_sources(TP_TESTS PRIVATE ${ARCHIVOS_FUENTE})