#include "AdminTransformers.hpp"

AdministradorTransformers::AdministradorTransformers(): lista_transformers(), control_archivo_transformers(RUTA_ARCHIVO_TRANSFORMERS){
    lista_transformers = control_archivo_transformers.leer_archivo();
}

void AdministradorTransformers::agregar_transformer(std::string nombre, int fuerza, int defensa, int velocidad, std::string faccion, std::string vehiculo){
    Transformers nuevo_transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo);
    lista_transformers.alta(nuevo_transformer);
}

Transformers AdministradorTransformers::eliminar_transformer(std::string nombre){
    if (lista_transformers.vacio()){
       throw ExcepcionAdministradorTransformers(ERROR_LISTA_TRANSFORMERS_VACIO); //Ver si no se hace un Excepcion solo para Admin_transf
    }
    size_t eliminado_posicion = buscar_transformer(nombre);
    if (eliminado_posicion == NO_ENCONTRADO){ //ver caso no encuentra el transformer posicion = -1
        throw ExcepcionAdministradorTransformers(ERROR_TRANSFORMER_NO_ENCONTRADO);   
    }
    return lista_transformers.baja(buscar_transformer(nombre)); 
}

size_t AdministradorTransformers::buscar_transformer(std::string nombre){
    if (lista_transformers.vacio()){
       throw ExcepcionAdministradorTransformers(ERROR_LISTA_TRANSFORMERS_VACIO); //Ver si no se hace un Excepcion solo para Admin_transf
    }
    size_t buscado = (lista_transformers.tamanio() + 1); //si no lo encuentra generea un fuera de rango
    bool encontrado = false;
    size_t indice = 0;
    while((encontrado == false) && (indice < lista_transformers.tamanio())){
        //std::cout << indice << std::endl;
        if (lista_transformers[indice].obtener_nombre() == nombre){
            encontrado = true;
            buscado = indice;
        } else {
            indice = indice + 1;
        }
    }
    if (encontrado == false){
        buscado = NO_ENCONTRADO;
    }
    return buscado;
}

void AdministradorTransformers::mostrar_todos_transformers(){
    //std::cout << "-- NOMBRE, FUERZA, DEFENZA, VELOCIDAD, FACCION, VEHICULO, TRANSFOMADO" << std::endl;
    std::cout << std::endl;
    std::cout << "  Lista de Transformers Secundarios" << std::endl;
    for (size_t i = 0; i < lista_transformers.tamanio(); i++){
        menu.mostrar_recuadro_superior();
        std::cout << "      " << (i+1) << ") ";
        (lista_transformers[i]).mostrar();
        menu.mostrar_recuadro_inferior();
    }
}

Vector<Transformers>& AdministradorTransformers::obtener_transformers_secundarios(){
    return lista_transformers;
}

void AdministradorTransformers::transformar_transformer(std::string nombre){
    if(lista_transformers.vacio()){
        throw ExcepcionAdministradorTransformers(ERROR_LISTA_TRANSFORMERS_VACIO);
    }
    size_t indice_transformado = buscar_transformer(nombre);
    //ver caso no encuentra el transformer -1
    if (indice_transformado == NO_ENCONTRADO){
        throw ExcepcionAdministradorTransformers(ERROR_TRANSFORMER_NO_ENCONTRADO);
    } else {
        lista_transformers[indice_transformado].cambiar_forma();
        menu.mostrar_recuadro_superior();
        lista_transformers[indice_transformado].mostrar();
        menu.mostrar_recuadro_inferior();
    }
}

Transformers AdministradorTransformers::operator[](size_t indice){
    if (indice >= lista_transformers.tamanio()){
        throw ExcepcionAdministradorTransformers(ERROR_INDICE_FUERA_DE_RANGO);
    }
    return lista_transformers[indice];
}

AdministradorTransformers::~AdministradorTransformers(){
    control_archivo_transformers.sobreescribir_en_archivo(lista_transformers);
}
