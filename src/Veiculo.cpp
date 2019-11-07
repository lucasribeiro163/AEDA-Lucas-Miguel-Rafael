//
// Created by Lucas on 11/2/2019.
//

#include "Veiculo.h"
#include "Data.h"


const vector<Data*> &Veiculo::getDisponiblidade() const {
    return disponiblidade;
}

void Veiculo::setDisponiblidade(const vector<Data*> &disponiblidade) {
    this->disponiblidade = disponiblidade;
}

int VeiculoPassageiros::getNrPassageiros() const{
    return nrPassageiros;
}

void VeiculoPassageiros::setNrPassageiros(int nrPassageiros){
    this->nrPassageiros = nrPassageiros;
}

double VeiculoComercial::getVolumeCarga() const{
    return volume_carga;
}

void VeiculoComercial::setVolumeCarga(double volumeCarga){
    this->volume_carga = volumeCarga;
}

double VeiculoComercial::getPesoCarga() const{
    return peso_carga;
}

void VeiculoComercial::setPesoCarga(double pesoCarga){
    this->peso_carga = pesoCarga;
}

bool VeiculoComercial::isRefrigeracao() const{
    return refrigeracao;
}

void VeiculoComercial::setRefrigeracao(bool &refrigeracao){
    this->refrigeracao = refrigeracao;
}




