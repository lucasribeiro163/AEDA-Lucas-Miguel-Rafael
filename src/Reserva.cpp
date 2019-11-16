//
// Created by Lucas on 11/2/2019.
//

#include <iostream>
#include "Reserva.h"

Reserva::Reserva(Data &dataInicio, Data &dataFim, int preco, bool concretizacao, int veiculoId) :
        dataInicio(dataInicio), dataFim(dataFim)
{
    this->dataInicio = dataInicio;
    this->dataFim = dataFim;
    this->preco = preco;
    this->concretizacao = concretizacao;
    this->veiculoId = veiculoId;
}

Data &Reserva::getDataInicio(){
    return dataInicio;
}

void Reserva::setDataInicio(const Data &dataInicio){
    this->dataInicio = dataInicio;
}

Data &Reserva::getDataFim(){
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


void Reserva::print() {

    cout << "Fim: "  << this->getDataFim().getDia() << '/' << this->getDataFim().getMes() << '/' << this->getDataFim().getAno() << '/' << this->getDataFim().getHora().getHora()
         << "\nInicio: "  << this->getDataInicio().getDia() << '/' << this->getDataInicio().getMes() << '/' << this->getDataInicio().getAno() << '/' << this->getDataInicio().getHora().getHora() << endl;

}


bool Reserva::operator==(Reserva r){

    //completar, tem de ser mais que a data para ser igual

    if(this->getDataFim() == r.getDataFim() && this->getDataInicio() == r.getDataInicio())
        return true;
    else
        return false;


}

int Reserva::getVeiculoId() const {
    return veiculoId;
}

void Reserva::setVeiculoId(int veiculoId) {
    Reserva::veiculoId = veiculoId;
}

