//
// Created by Lucas on 11/2/2019.
//

#include "Veiculo.h"
#include "Data.h"

double VeiculoComercial::getVolumeCarga() const {
    return volume_carga;
}

void VeiculoComercial::setVolumeCarga(double volumeCarga) {
    volume_carga = volumeCarga;
}

double VeiculoComercial::getPesoCarga() const {
    return peso_carga;
}

void VeiculoComercial::setPesoCarga(double pesoCarga) {
    peso_carga = pesoCarga;
}

bool VeiculoComercial::isRefrigeracao() const {
    return refrigeracao;
}

void VeiculoComercial::setRefrigeracao(bool refrigeracao) {
    VeiculoComercial::refrigeracao = refrigeracao;
}

const vector<Data*> &Veiculo::getDisponiblidade() const {
    return disponiblidade;
}

void Veiculo::setDisponiblidade(const vector<Data*> &disponiblidade) {
    Veiculo::disponiblidade = disponiblidade;
}
