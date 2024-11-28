#include "Transformers.hpp"

Transformers::Transformers(std::string nombre, int fuerza, int defensa, int velocidad,
                           std::string faccion, std::string vehiculo, bool transformado): estadisticas(fuerza, defensa, velocidad){
    this->nombre = nombre;
    this->faccion = faccion;
    this->vehiculo = vehiculo;
    this->transformado = transformado;
}

Transformers::Transformers(std::string nombre, int fuerza, int defensa, int velocidad,
                           std::string faccion, std::string vehiculo): estadisticas(fuerza, defensa, velocidad){
    this->nombre = nombre;
    this->faccion = faccion;
    this->vehiculo = vehiculo;
    this->transformado = false;
}

Transformers::Transformers(Vector<std::string>& elementos): estadisticas( std::stoi(elementos[1]), std::stoi(elementos[2]), std::stoi(elementos[3])){
    this->nombre = elementos[0];
    this->faccion = elementos[4];
    this->vehiculo = elementos[5];
    this->transformado = pase_texto_bool_transformado(elementos[6]);
}

Transformers::Transformers(): estadisticas(5,5,5){
    this->nombre = "Sparkling";
    this->faccion = FACCION_AUTOBOTS;
    this->vehiculo = VEHICULO_AUTO;
    this->transformado = false;  
}

std::string Transformers::obtener_nombre(){
    return this->nombre;
}

size_t Transformers::obtener_poder(){
    return estadisticas.obtener_poder();
}

void Transformers::cambiar_forma(){
    bool cambiar = transformado;
    if (cambiar){ //Si el estado anterior a transformado es true, pasa a ser false; 
        this->transformado = false;
    } else { //Si el estado anterior a transformado es false, pasa a true.
        this->transformado = true;
    }
    //Se hace el cambio de estadisticas
    if (this->transformado){ //Si es true, esta transformado se realiza el cambio de estadisticas (al_reves = false)
        chequeo_vehiculo(false);
    } else { //Entonces no esta transformado no se deshace el cambio de estadisticas (al_reves = true)
        chequeo_vehiculo(true);
    }
}

Transformers& Transformers::operator=(const Transformers &otro_transformer){
    if (this != &otro_transformer){
        this->nombre = otro_transformer.nombre;
        this->estadisticas = otro_transformer.estadisticas;
        this->faccion = otro_transformer.faccion;
        this->vehiculo = otro_transformer.vehiculo;
        this->transformado = otro_transformer.transformado;
    }
    return *this;
}

bool Transformers::operator==(const Transformers &otro_transformer){
    bool facciones_iguales = false;
    if (this->faccion == otro_transformer.faccion){
        facciones_iguales = true;
    }
    return facciones_iguales;
}

bool Transformers::son_iguales_fuerza(Transformers otro_transformer){
    bool transformers_iguales = false;
    int contador_estaditicas_iguales = 0;

    if (this->estadisticas.obtener_fuerza() == otro_transformer.estadisticas.obtener_fuerza()) {contador_estaditicas_iguales++;  /*std::cout << "Fuerza igual "; */}
    if (this->estadisticas.obtener_defensa() == otro_transformer.estadisticas.obtener_defensa()) {contador_estaditicas_iguales++; /*std::cout << "Defensa igual ";*/}
    if (this->estadisticas.obtener_velocidad() == otro_transformer.estadisticas.obtener_velocidad()) {contador_estaditicas_iguales++; /*std::cout << "Velocidad igual ";*/}
    
    if (contador_estaditicas_iguales >= 2){
        transformers_iguales = true;
    }
    return transformers_iguales;
}

bool Transformers::es_mas_fuerte(Transformers otro_transformer){
    bool transformer_actual_es_mas_fuerte = false;
    int contador_estadidicas_mas_altas = 0;

    if (this->estadisticas.obtener_fuerza() > otro_transformer.estadisticas.obtener_fuerza()) {contador_estadidicas_mas_altas++; /*std::cout << "Fuerza superior ";*/}
    if (this->estadisticas.obtener_defensa() > otro_transformer.estadisticas.obtener_defensa()) {contador_estadidicas_mas_altas++; /*std::cout << "Defensa superior ";*/}
    if (this->estadisticas.obtener_velocidad() > otro_transformer.estadisticas.obtener_velocidad()) {contador_estadidicas_mas_altas++; /*std::cout << "Velocidad superior "*/ }
    
    if (contador_estadidicas_mas_altas >= 2){
        transformer_actual_es_mas_fuerte = true;
    }
    return transformer_actual_es_mas_fuerte;
}

int Transformers::calcular_bonificacion(int estadistica_base, int multiplicador, int indicador_aumento_reduccion){
    return estadistica_base*multiplicador*indicador_aumento_reduccion;
}

void Transformers::chequeo_vehiculo(bool al_reves){
    //El caso normal = incremento = 1;
    int interruptor_incremento_reduccion = 1;
    if (al_reves == true){
        //El caso al reves = reduccion = -1
        interruptor_incremento_reduccion = -1;
    } 
    //Estructura de la suma: Estaditica_a_cambiar = estadistica_a_cambiar + (1 ó -1)*(aumento/reduccion base * multiplicador)
    if (this->faccion == FACCION_AUTOBOTS){
        if(this->vehiculo == VEHICULO_AUTO){ // F- D- V++
            this-> estadisticas.aplicar_bonificacion_distintas(
                calcular_bonificacion(ESTADISTICAS_REDUCCION,CAMBIO_NORMAL,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_REDUCCION,CAMBIO_NORMAL,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_AUMENTO,CAMBIO_MUCHO,interruptor_incremento_reduccion));
        } else { //Caso Camion // F+ D+ V-
        this-> estadisticas.aplicar_bonificacion_distintas(
                calcular_bonificacion(ESTADISTICAS_AUMENTO,CAMBIO_NORMAL,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_AUMENTO,CAMBIO_NORMAL,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_REDUCCION,CAMBIO_NORMAL,interruptor_incremento_reduccion));
        }
    } else { //Caso Decepticons
        if (this->vehiculo == VEHICULO_AVION){ // F++ D--- V++
        this-> estadisticas.aplicar_bonificacion_distintas(
                calcular_bonificacion(ESTADISTICAS_AUMENTO,CAMBIO_MUCHO,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_REDUCCION,CAMBIO_TOTALMENTE,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_AUMENTO,CAMBIO_MUCHO,interruptor_incremento_reduccion));
        } else { //Caso tanque // F++ D++ V---
        this-> estadisticas.aplicar_bonificacion_distintas(
                calcular_bonificacion(ESTADISTICAS_AUMENTO,CAMBIO_MUCHO,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_AUMENTO,CAMBIO_MUCHO,interruptor_incremento_reduccion),
                calcular_bonificacion(ESTADISTICAS_REDUCCION,CAMBIO_TOTALMENTE,interruptor_incremento_reduccion));
        }
    }
}

bool Transformers::pase_texto_bool_transformado(std::string texto_transformado){
    bool estado_actual;
    if (texto_transformado == "Si"){
        estado_actual = true;
    } else {
        estado_actual = false;
    }
    return estado_actual;
}

void Transformers::mostrar(){
    std::cout << "  Nombre del Transformer: " << nombre;
    std::cout << "  Faccion: " << faccion;
    std::cout << "  Vehiculo: " << vehiculo; 
    std::cout << "  Transformado: ";
    if (transformado){
        std::cout << "Si";
    } else {
        std::cout << "No";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    estadisticas.mostrar();
}

std::ostream &operator<<(std::ostream &os, const Transformers &transformer){
    os << transformer.nombre
        << "," << transformer.estadisticas
        << "," << transformer.faccion
        << "," << transformer.vehiculo
        << ",";
    
    if (transformer.transformado){
        os << "Si";
    } else {
        os << "No";
    }            
    return os;
}
