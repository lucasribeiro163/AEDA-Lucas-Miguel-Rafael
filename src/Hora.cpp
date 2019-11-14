//
// Created by Lucas on 11/2/2019.
//

#include "Hora.h"

Hora::Hora(string &horaRecebida){
    string buffer;
    int hor, min, seg;

    buffer = horaRecebida;
    buffer.erase(2, 8);
    hor = stoi(buffer);

    buffer = horaRecebida;
    buffer.erase(0, 3);
    buffer.erase(2, 6);
    min = stoi(buffer);

    buffer=horaRecebida;
    buffer.erase(0, 6);
    seg = stoi(buffer);

    this->hora = hor;
    this->minuto = min;
    this->segundo = seg;
}

int Hora::getHora() const {
    return hora;
}

void Hora::setHora(int hora) {
    this->hora = hora;
}

int Hora::getMinuto() const {
    return minuto;
}

void Hora::setMinuto(int minuto) {
    this->minuto = minuto;
}

int Hora::getSegundo() const {
    return segundo;
}

void Hora::setSegundo(int segundo) {
    this->segundo = segundo;
}

bool Hora::operator<=(Hora Hora) {
    if (this->hora > Hora.hora) return false;
    if (this->hora < Hora.hora) return true;

    //se chega aqui, a hora e igual
    if (this->minuto > Hora.minuto) return false;
    if (this->minuto < Hora.minuto) return true;

    //se chega aqui, o minuto e igual
    if (this->segundo > Hora.segundo) return false;
    if (this->segundo < Hora.segundo) return true;

    //se chega aqui, o segundo e igual
    return true;
}
