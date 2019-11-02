//
// Created by Lucas on 11/2/2019.
//

#include "Hora.h"

int Hora::getHora() const {
    return hora;
}

void Hora::setHora(int hora) {
    Hora::hora = hora;
}

int Hora::getMinuto() const {
    return minuto;
}

void Hora::setMinuto(int minuto) {
    Hora::minuto = minuto;
}

int Hora::getSegundo() const {
    return segundo;
}

void Hora::setSegundo(int segundo) {
    Hora::segundo = segundo;
}
