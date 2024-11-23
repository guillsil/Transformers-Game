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
       throw ExcepcionAdministradorTransformers(MENSAJE_ERROR_VACIO); //Ver si no se hace un Excepcion solo para Admin_transf
    }
    size_t eliminado_posicion = buscar_transformer(nombre);
    if (eliminado_posicion == NO_ENCONTRADO){ //ver caso no encuentra el transformer posicion = -1
        throw ExcepcionAdministradorTransformers(MENSAJE_ERROR_NO_ENCONTRADO);   
    }
    return lista_transformers.baja(buscar_transformer(nombre)); 
}

size_t AdministradorTransformers::buscar_transformer(std::string nombre){
    if (lista_transformers.vacio()){
       throw ExcepcionAdministradorTransformers(MENSAJE_ERROR_VACIO); //Ver si no se hace un Excepcion solo para Admin_transf
    }
    size_t buscado = NO_ENCONTRADO; //si devuelve -1 no lo encontró
    bool encontrado = false;
    size_t indice = (lista_transformers.tamanio() - 1);
    //Recorre el vector de atras para adelante. Se pude cambiar si deseado.
    while(encontrado == false || indice < 0){
        if (lista_transformers[indice].obtener_nombre() == nombre){
            encontrado = true;
            buscado = indice;
        } else {
            indice = indice - 1;
        }
    }
    return buscado;
}

void AdministradorTransformers::mostrar_todos_transformers(){
    if (lista_transformers.vacio()){
        throw ExcepcionAdministradorTransformers(MENSAJE_ERROR_VACIO);
    }
    std::cout << std::endl;
    for (size_t i = 0; i < lista_transformers.tamanio(); i++){
        std::cout << "      " << (i+1) << ") " << (lista_transformers[i]) << std::endl;
        std::cout << std::endl;
    }
}

void AdministradorTransformers::transformar_transformer(std::string nombre){
    if(lista_transformers.vacio()){
        throw ExcepcionAdministradorTransformers(MENSAJE_ERROR_VACIO);
    }
    size_t indice_transformado = buscar_transformer(nombre);
    //ver caso no encuentra el transformer -1
    if (indice_transformado == NO_ENCONTRADO){
        throw ExcepcionAdministradorTransformers(MENSAJE_ERROR_NO_ENCONTRADO);
    } else {
        lista_transformers[indice_transformado].cambiar_forma();
    }
}

Transformers AdministradorTransformers::operator[](size_t indice){
    if (indice >= lista_transformers.tamanio()){
        throw ExcepcionAdministradorTransformers(MENSAJE_FUERA_RANGO);
    }
    return lista_transformers[indice];
}

AdministradorTransformers::~AdministradorTransformers(){
    control_archivo_transformers.sobreescribir_en_archivo(lista_transformers);
}
