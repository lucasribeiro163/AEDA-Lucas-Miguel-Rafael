//
// Created by Lucas on 11/2/2019.
//

#include <iostream>
#include "Data.h"


using namespace std;

Data::Data(string data, string hora) : hora(hora) {
    string buffer;
    int ano, mes, dia;

    buffer = data;
    buffer.erase(2, 8);
    dia = stoi(buffer);


    buffer = data;
    buffer.erase(0, 3);
    buffer.erase(2, 6);
    mes = stoi(buffer);



    buffer=data;
    buffer.erase(0, 6);
    ano = stoi(buffer);


    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
}

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

Hora &Data::getHora(){
    return hora;
}

void Data::setHora(Hora &hora){
    this->hora = hora;
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
    if(this->hora.getHora() > data.hora.getHora() ) return false;
    if(this->hora.getHora()  < data.hora.getHora() ) return true;

    //se chega aqui, o hora e igual
    if(this->hora.getMinuto() > data.hora.getMinuto() ) return false;
    if(this->hora.getMinuto()  < data.hora.getMinuto() ) return true;

    return true;

    //se chega aqui, o dia e igual
    //return (this->hora<=data.hora);
}


bool Data::operator==(Data data){

    if(this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() == data.getDia() && this->getHora() == data.getHora())
        return true;
    else
        return false;



}

