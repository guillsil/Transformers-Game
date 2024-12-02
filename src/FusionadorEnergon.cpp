#include "FusionadorEnergon.hpp"

const std::string ERROR_DISTINTO_NIVEL_DE_CRISTAL = "Error: Los cristales no son del mismo nivel.";

const std::string ERROR_FUSION_PROHIBIDA = "Error: No se pueden fusionar cristales Legendarios ya que es el nivel máximo.";

const std::string ERROR_RETROCESO_DE_RAREZA_INVALIDA = "Error: No se pueden fusionar cristales Legendarios ya que es el nivel máximo.";

const int NUMERO_DE_FALLOS_CONSECUTIVOS_PARA_EXITO = 3;

const int RAREZA_NO_VALIDA = -1;

const int BONIFICACION_EXTRA_POR_FUSION_EXITOSA = 5;
const int BONIFICACION_EXTRA_POR_FUSION_FALLIDA = 5;
const int BONIFICACION_BASE = 10;
const int BONIFICACION_MAXIMA = 40;


FusionadorEnergon::FusionadorEnergon(): ultima_rareza(RAREZA_NO_VALIDA), probabilidad_bonificacion(BONIFICACION_BASE) {
    for (int & fallos_consecutivo : fallos_consecutivos) {
        fallos_consecutivo = 0;
    }
}

Cristal FusionadorEnergon::fusionar(Cristal cristal_1, Cristal cristal_2) {
    return fusionar_cristales(cristal_1, cristal_2, nullptr);
}

Cristal FusionadorEnergon::fusionar(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio& generador) {
    return fusionar_cristales(cristal_1, cristal_2, &generador);
}

Cristal FusionadorEnergon::fusionar_cristales(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio *generador=nullptr) {
    verificar_rarezas_iguales(cristal_1, cristal_2);
    verificar_fusion_prohibida(cristal_1.obtener_rareza());
    Rareza rareza_actual = cristal_1.obtener_rareza();
    int rareza_resultante = 0;
    int porcentaje_exito = cristal_1.obtener_porcentaje_exito();

    if (verificar_exito_de_fusion(rareza_actual, porcentaje_exito, generador)) {
        rareza_resultante = obtener_proxima_rareza(rareza_actual);
        resetear_fallos_por_nivel(rareza_actual);
        if (probabilidad_bonificacion <= BONIFICACION_MAXIMA) {
            probabilidad_bonificacion += BONIFICACION_EXTRA_POR_FUSION_EXITOSA;
        }else {
            probabilidad_bonificacion = BONIFICACION_BASE;
        }
    }else {
        fallos_consecutivos[rareza_actual]++;
        if (probabilidad_bonificacion >= BONIFICACION_BASE) {
            probabilidad_bonificacion -= BONIFICACION_EXTRA_POR_FUSION_EXITOSA;
        }else {
            probabilidad_bonificacion = BONIFICACION_BASE;
        }
        rareza_resultante = obtener_rareza_anterior(rareza_actual);
    }
    ultima_rareza = rareza_actual;
    return Cristal(static_cast<Rareza>(rareza_resultante), dar_bonificacion(probabilidad_bonificacion));
}

void FusionadorEnergon::verificar_rarezas_iguales(Cristal &cristal_1, Cristal &cristal_2) {
    if (!(cristal_1.obtener_rareza() == cristal_2.obtener_rareza())) {
        throw ExcepcionFusionadorEnergon(ERROR_DISTINTO_NIVEL_DE_CRISTAL);
    }
}

bool FusionadorEnergon::verificar_exito_de_fusion(const Rareza &rareza_actual, const int &porcentaje_exito,
    GeneradorAleatorio *generador) {
    if (fallos_consecutivos[rareza_actual] >= NUMERO_DE_FALLOS_CONSECUTIVOS_PARA_EXITO){
        return  true;
    }
    if (generador != nullptr){
        return generador-> generar_chance_porcentual(porcentaje_exito);
    }
    GeneradorAleatorio generador_aleatorio;
    return  generador_aleatorio.generar_chance_porcentual(porcentaje_exito);
}

void FusionadorEnergon::verificar_fusion_prohibida(const Rareza &rareza) {
    if (rareza == LEGENDARIO) {
        throw ExcepcionFusionadorEnergon(ERROR_FUSION_PROHIBIDA);
    }
}

int FusionadorEnergon::obtener_proxima_rareza(const Rareza &rareza) {
    switch (rareza) {
        case COMUN:
            return RARO;
        case RARO:
            return EPICO;
        case EPICO:
            return LEGENDARIO;
        default:
            throw ExcepcionFusionadorEnergon(ERROR_FUSION_PROHIBIDA);
    }
}

int FusionadorEnergon::obtener_rareza_anterior(const Rareza &rareza) {
    switch (rareza) {
        case COMUN:
            return COMUN;
        case RARO:
            return COMUN;
        case EPICO:
            return RARO;
        case LEGENDARIO:
            return EPICO;
        default:
            throw ExcepcionFusionadorEnergon(ERROR_RETROCESO_DE_RAREZA_INVALIDA);
    }
}

void FusionadorEnergon::resetear_fallos_por_nivel(const Rareza &rareza) {
    if (rareza != ultima_rareza && ultima_rareza != -1) {
        for (int & fallos_consecutivo : fallos_consecutivos) {
            fallos_consecutivo = 0;
        }
    }
}

bool FusionadorEnergon::dar_bonificacion(const int &probabilidad_bonificacion) {
    return generador_bonificacion.generar_chance_porcentual(probabilidad_bonificacion);
}


