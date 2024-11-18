[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/SOoPfuVL)
# AYED - TPG 2c2024
### SILVA GUILLERMO ANDRES - 109777 - RIVERO ARDISSONE, CANDELA BELÉN - 110339 - NARVÁEZ YAGUANA, GABRIEL ALEJANDRO - 111432 - ROJAS CALIZAYA, KEVIN EDGARDO - 109948 - FARIÑA GONCALVES, ALEX JAVIER  - 112438
<p align="center">
   <img src="image/Banner.png" alt="TP1: Interacción con Transformers"><br>
</p>


## Compilación

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

```bash
g++ -I include main.cpp src/*.cpp -o main
```

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

## Justificación de la Selección de Estructuras de Datos y Algoritmos.

* ### Cola de Prioridad en el Algoritmo de Camino Mínimo de Dijkstra
  #### ¿Por qué una cola de prioridad?
  * Eficiencia: Encuentra el siguiente nodo a explorar rápidamente.
  * Orden: Mantiene los nodos ordenados por distancia.
  * Optimización: Evita explorar caminos que claramente son más largos.
  * En pocas palabras: En Dijkstra, nos asegura encontrar el camino más corto de manera eficiente, reduciendo la complejidad a O((a + v)log(v)).

* ### Funcionalidad para Mostrar el cristal con mayor Poder
  Para poder mostrar el cristal con mayor poder lo que se decide es ir almacenando en la bóveda los cristales de manera ordenada y asi el obtener el cristal de mayor poder tendrá un costo de O(1), esto porque se ordena de manera descendente lo que permite que el cristal con mayor poder este en la primera posición de la bóveda.
* ### Funcionalidad para Equipar con un Cristal al Personaje



## Aclaraciones Adicionales

* ### Parametro Poder
  El parámetro de poder de un cristal se representa mediante la suma de las estadísticas de un cristal es decir es la suma entre la fuerza, defensa y velociad.





## Imagenes del juego
### Menu de Nuevas Funcionalidades (Fusiondor - Boveda)
| Menu Bóveda                                                               | Menu Fusionador                                                               |
|---------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| <img src="image/menu_boveda.png" alt="TP1: Interacción con Transformers"> | <img src="image/menu_fusionador.png" alt="TP1: Interacción con Transformers"> |
### Menus de la Bóveda
| Menu Bóveda para Almacenar                                                          | Menu Bóveda para Exportar                                                          |
|-------------------------------------------------------------------------------------|------------------------------------------------------------------------------------|
| <img src="image/menu_boveda_almacenar.png" alt="TP1: Interacción con Transformers"> | <img src="image/menu_boveda_exportar.png" alt="TP1: Interacción con Transformers"> |
### Menu de Personajes
| Menu Personaje Optimus                                                     | Menu Personaje Megatron                                                     |
|----------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| <img src="image/menu_optimus.png" alt="TP1: Interacción con Transformers"> | <img src="image/menu_megatron.png" alt="TP1: Interacción con Transformers"> |

### Menu para elegir el estado
| Elegir Estados para Optimus                                                         | Elegir Estados para Megatron                                                          |
|-------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|
| <img src="image/menu_modificar_estado.png" alt="TP1: Interacción con Transformers"> | <img src="image/menu_modificar_estado_2.png" alt="TP1: Interacción con Transformers"> |


### Respuestas que se da a distintos cambios
| Sugerir Fusion                                                                           | Respuesta a mensaje                                                                |
|------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------|
| <img src="image/respuesta_fusion.png" alt="TP1: Interacción con Transformers">           | <img src="image/respuesta_mensaje.png" alt="TP1: Interacción con Transformers">    |
| Modificar Estado                                                                         | Resultado de Fusionar                                                              |
| <img src="image/respuesta_modificar_estado.png" alt="TP1: Interacción con Transformers"> | <img src="image/respuesta_fusionador.png" alt="TP1: Interacción con Transformers"> |




