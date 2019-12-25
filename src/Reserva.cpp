//
// Created by Lucas on 11/2/2019.
//

#include <iostream>
#include "Reserva.h"

Reserva::Reserva(Data &dataInicio, Data &dataFim, double preco, bool concretizacao, int veiculoId, Contract contrato) :
        dataInicio(dataInicio), dataFim(dataFim), contrato(contrato)
{
    this->dataInicio = dataInicio;
    this->dataFim = dataFim;
    this->preco = preco;
    this->concretizacao = concretizacao;
    this->veiculoId = veiculoId;
}

const Contract &Reserva::getContrato() const {
    return contrato;
}

Data &Reserva::getDataInicio(){
    return dataInicio;
}


Data &Reserva::getDataFim(){
    return dataFim;
}


const double Reserva::getPreco(){
    return preco;
}



bool Reserva::isConcretizacao() const {
    return concretizacao;
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


