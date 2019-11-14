//
// Created by Lucas on 11/2/2019.
//

#include "Reserva.h"

Reserva::Reserva(Data &dataInicio, Data &dataFim, int preco, bool concretizacao) :
        dataInicio(dataInicio), dataFim(dataFim)
{
    this->dataInicio = dataInicio;
    this->dataFim = dataFim;
    this->preco = preco;
    this->concretizacao = concretizacao;
}

const Data &Reserva::getDataInicio() const{
    return dataInicio;
}

void Reserva::setDataInicio(const Data &dataInicio){
    this->dataInicio = dataInicio;
}

const Data &Reserva::getDataFim() const{
    return dataFim;
}

void Reserva::setDataFim(const Data &dataFim){
    this->dataFim = dataFim;
}

const int Reserva::getPreco(){
    return preco;
}

const void Reserva::setPreco(int &preco){
    this->preco = preco;
}


bool Reserva::isConcretizacao() const {
    return concretizacao;
}

void Reserva::setConcretizacao(const bool concretizacao) {
    Reserva::concretizacao = concretizacao;
}
