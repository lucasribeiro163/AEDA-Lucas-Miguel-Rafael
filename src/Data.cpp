//
// Created by Lucas on 11/2/2019.
//

#include "Data.h"

int Data::getAno() const {
    return ano;
}

void Data::setAno(int ano) {
    this->ano = ano;
}

int Data::getMes() const {
    return mes;
}

void Data::setMes(int mes) {
    this->mes = mes;
}

int Data::getDia() const {
    return dia;
}

void Data::setDia(int dia) {
    this->dia = dia;
}

bool Data::operator<=(Data data) {
    if(this->ano > data.ano) return false;
    if(this->ano < data.ano) return true;

    //se chega aqui, o ano e igual
    if(this->mes > data.mes) return false;
    if(this->mes < data.mes) return true;

    //se chega aqui, o mes e igual
    if(this->dia > data.dia) return false;
    if(this->dia < data.dia) return true;

    //se chega aqui, o dia e igual
    return (this->hora<=data.hora);
}

