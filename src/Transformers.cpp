#include "Transformers.hpp"

Transformers::Transformers(std::string nombre, int fuerza, int defensa, int velocidad,
                           std::string faccion, std::string vehiculo, bool transformado){
    this->nombre = nombre;
    this->fuerza = fuerza;
    this->defensa = defensa;
    this->velocidad = velocidad;
    this->faccion = faccion;
    this->vehiculo = vehiculo;
    this->transformado = transformado;
}

Transformers::Transformers(std::string nombre, int fuerza, int defensa, int velocidad,
                           std::string faccion, std::string vehiculo){
    this->nombre = nombre;
    this->fuerza = fuerza;
    this->defensa = defensa;
    this->velocidad = velocidad;
    this->faccion = faccion;
    this->vehiculo = vehiculo;
    this->transformado = false;
}

Transformers::Transformers(std::string nombre, int fuerza, int defensa, int velocidad, std::string faccion, std::string vehiculo, std::string transformado){
    this->nombre = nombre;
    this->fuerza = fuerza;
    this->defensa = defensa;
    this->velocidad = velocidad;
    this->faccion = faccion;
    this->vehiculo = vehiculo;
    this->transformado = pase_texto_bool_transformado(transformado);
}

Transformers::Transformers(std::string jugador, int puntaje, std::string personaje) {
    this->nombre = "Sparkling";
    this->fuerza = 5; this->defensa = 5; this->velocidad = 5;
    this->faccion = FACCION_AUTOBOTS;
    this->vehiculo = VEHICULO_AUTO;
    this->transformado = false;
}

Transformers::Transformers(){
    this->nombre = "Sparkling";
    this->fuerza = 5; this->defensa = 5; this->velocidad = 5;
    this->faccion = FACCION_AUTOBOTS;
    this->vehiculo = VEHICULO_AUTO;
    this->transformado = false;  
}

std::string Transformers::obtener_nombre(){
    return this->nombre;
}

int Transformers::obtener_poder(){
    //implementar con estadisticas
    return fuerza + defensa + velocidad;
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
        this->fuerza = otro_transformer.fuerza;
        this->defensa = otro_transformer.defensa;
        this->velocidad = otro_transformer.velocidad;
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

    if (this->fuerza == otro_transformer.fuerza) {contador_estaditicas_iguales++;  /*std::cout << "Fuerza igual "; */}
    if (this->defensa == otro_transformer.defensa) {contador_estaditicas_iguales++; /*std::cout << "Defensa igual ";*/}
    if (this->velocidad == otro_transformer.velocidad) {contador_estaditicas_iguales++; /*std::cout << "Velocidad igual ";*/}
    
    if (contador_estaditicas_iguales >= 2){
        transformers_iguales = true;
    }
    return transformers_iguales;
}

bool Transformers::es_mas_fuerte(Transformers otro_transformer){
    bool transformer_actual_es_mas_fuerte = false;
    int contador_estadidicas_mas_altas = 0;

    if (this->fuerza > otro_transformer.fuerza) {contador_estadidicas_mas_altas++; /*std::cout << "Fuerza superior ";*/}
    if (this->defensa > otro_transformer.defensa) {contador_estadidicas_mas_altas++; /*std::cout << "Defensa superior ";*/}
    if (this->velocidad > otro_transformer.velocidad) {contador_estadidicas_mas_altas++; /*std::cout << "Velocidad superior "*/ }
    
    if (contador_estadidicas_mas_altas >= 2){
        transformer_actual_es_mas_fuerte = true;
    }
    return transformer_actual_es_mas_fuerte;
}

//Cambiar para poder usar como modulacion para cambio de estadisticas
int Transformers::cambiar_estadisticas(int estadistica_base, int multiplicador, int indicador_aumento_reduccion){
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
            this->fuerza = fuerza + interruptor_incremento_reduccion*(ESTADISTICAS_REDUCCION* CAMBIO_NORMAL);
            this->defensa = defensa + interruptor_incremento_reduccion*(ESTADISTICAS_REDUCCION* CAMBIO_NORMAL);
            this->velocidad = velocidad + interruptor_incremento_reduccion*(ESTADISTICAS_AUMENTO* CAMBIO_MUCHO);
        } else { //Caso Camion // F+ D+ V-
            this->fuerza = fuerza + interruptor_incremento_reduccion*(ESTADISTICAS_AUMENTO* CAMBIO_NORMAL);
            this->defensa = defensa + interruptor_incremento_reduccion*(ESTADISTICAS_AUMENTO* CAMBIO_NORMAL);
            this->velocidad = velocidad + interruptor_incremento_reduccion*(ESTADISTICAS_REDUCCION* CAMBIO_NORMAL);
        }
    } else { //Caso Decepticons
        if (this->vehiculo == VEHICULO_AVION){ // F++ D--- V++
            this->fuerza = fuerza + interruptor_incremento_reduccion*(ESTADISTICAS_AUMENTO* CAMBIO_MUCHO);
            this->defensa = defensa + interruptor_incremento_reduccion*(ESTADISTICAS_REDUCCION* CAMBIO_TOTALMENTE);
            this->velocidad = velocidad + interruptor_incremento_reduccion*(ESTADISTICAS_AUMENTO* CAMBIO_MUCHO);
        } else { //Caso tanque // F++ D++ V---
            this->fuerza = fuerza + interruptor_incremento_reduccion*(ESTADISTICAS_AUMENTO* CAMBIO_MUCHO);
            this->defensa = defensa + interruptor_incremento_reduccion*(ESTADISTICAS_AUMENTO* CAMBIO_MUCHO);
            this->velocidad = velocidad + interruptor_incremento_reduccion*(ESTADISTICAS_REDUCCION* CAMBIO_TOTALMENTE);
        }
    }
}

//No se si es necesario para el constructor al sacarlos de csv probablemente
bool Transformers::pase_texto_bool_transformado(std::string texto_transformado){
    bool estado_actual;
    if (texto_transformado == "Si"){
        estado_actual = true;
    } else {
        estado_actual = false;
    }
    return estado_actual;
}

std::ostream &operator<<(std::ostream &os, const Transformers &transformer){
    os << transformer.nombre
        << "," << transformer.fuerza
        << "," << transformer.defensa
        << "," << transformer.velocidad
        << "," << transformer.faccion
        << "," << transformer.vehiculo
        << ",";
    
    if (transformer.transformado){
        os << "Si";
    } else {
        os << "No";
    }
    // problema llamando a la funcion chequear_transformado debido a que transformer es CONST
    // std::string palabra_transformado = transformer.chequear_transformado();
    // os << ", Trasformado: " << ;
            
    return os;
}
