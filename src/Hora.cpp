//
// Created by Lucas on 11/2/2019.
//

#include <iostream>
#include "Hora.h"

Hora::Hora(string &horaRecebida){
    string buffer;
    int hor, min;

    buffer = horaRecebida;
    buffer.erase(2, 4);
    hor = stoi(buffer);


    buffer = horaRecebida;
    buffer.erase(0, 3);
    buffer.erase(2, 4);
    min = stoi(buffer);


    this->hora = hor;
    this->minuto = min;
}
Hora::Hora(){

}



int Hora::getHora() const {
    return hora;
}


int Hora::getMinuto() const {
    return minuto;
}




bool Hora::operator<=(Hora Hora) const {
    if (this->hora > Hora.hora) return false;
    if (this->hora < Hora.hora) return true;

    //se chega aqui, a hora e igual
    if (this->minuto > Hora.minuto) return false;
    if (this->minuto < Hora.minuto) return true;

    //se chega aqui, o segundo e igual
    return true;
}



bool Hora::operator==(Hora hora) const {

    if(this->getHora() == hora.getHora() && this->getMinuto() == hora.getMinuto())
        return true;
    else
        return false;

}