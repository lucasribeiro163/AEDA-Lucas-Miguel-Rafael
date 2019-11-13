//
// Created by Lucas on 11/2/2019.
//

#include "Transacao.h"

double Transacao::getValor() const {
    return valor;
}

void Transacao::setValor(double valor) {
    Transacao::valor = valor;
}

const Data &Transacao::getData() const {
    return data;
}

void Transacao::setData(const Data &data) {
    Transacao::data = data;
}

const Veiculo &Transacao::getVeiculo() const {
    return veiculo;
}

void Transacao::setVeiculo(const Veiculo &veiculo) {
    Transacao::veiculo = veiculo;
}
