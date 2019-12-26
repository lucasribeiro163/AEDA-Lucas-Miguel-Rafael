//
// Created by Lucas on 11/2/2019.
//

#include <iostream>
#include "Data.h"

using namespace std;


Data::Data(){

}
Data::Data(int ano, int mes, int dia, Hora hora): hora(hora) {

    this->ano = ano;
    this->mes = mes;
    this->dia = dia;

}


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

Hora Data::getHora() const{
    return hora;
}

void Data::setHora(Hora &hora){
    this->hora = hora;
}

Data Data::getDifference(Data dataFim){

    int dia = dataFim.getDia() - this->getDia();
    int mes = dataFim.getMes() - this->getMes();
    int ano = dataFim.getAno() - this->getAno();


    Data res(ano, mes,dia, this->getHora());

    return res;

}


int Data::hoursBetween(Data d) {


    int res = 0;

    if(d.getAno() - this->getAno() > 1)
        res += (d.getAno() - this->getAno()) * 8760;

    if(d.getAno() - this->getAno() == 1)
        res += ((12 -d.getMes()) + this->getMes()) * 720;
    else if(d.getMes() - this->getMes() > 1)
        res += (d.getMes() - this->getMes()) * 720;

    if(d.getMes() - this->getMes() == 1)
        res += ((30 - d.getDia()) + this->getDia()) *24;
    else if(d.getDia() - this->getDia() > 1)
        res += (d.getDia() - this->getDia()) * 24;

    if(d.getDia() - this->getDia() == 1)
        res += (24-d.getHora().getHora()) + this->getHora().getHora();
    else
        res += d.getHora().getHora() - this->getHora().getHora();


    return res;

}



bool Data::operator<=(Data data)const {
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


bool Data::operator==(Data data) const {

    return this->getAno() == data.getAno() && this->getMes() == data.getMes() && this->getDia() == data.getDia() &&
           this->getHora() == data.getHora();
}

void Data::printData() const {
    if(this->getDia() < 10)
        cout << "0" << this->getDia();
    else cout << this->getDia();
    cout << "/";

    if(this->getMes() < 10)
        cout << "0" << this->getMes();
    else cout << this->getMes();
    cout << "/" << this->getAno();
}

void Data::printHour() const {
    if(this->getHora().getHora() < 10)
        cout << "0" << this->getHora().getHora();
    else cout << this->getHora().getHora();

    cout << ":";

    if(this->getHora().getMinuto() < 10)
        cout << "0" << this->getHora().getMinuto();
    else cout << this->getHora().getMinuto();
}

