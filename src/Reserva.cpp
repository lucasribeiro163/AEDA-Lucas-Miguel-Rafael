//
// Created by Lucas on 11/2/2019.
//

#include "Reserva.h"

const Data &Reserva::getData() const {
    return data;
}

void Reserva::setData(const Data &data) {
    Reserva::data = data;
}

const Veiculo &Reserva::getVeiculo() const {
    return veiculo;
}

void Reserva::setVeiculo(const Veiculo &veiculo) {
    Reserva::veiculo = veiculo;
}

const Transacao &Reserva::getPagamento() const {
    return pagamento;
}

void Reserva::setPagamento(const Transacao &pagamento) {
    Reserva::pagamento = pagamento;
}

bool Reserva::isConcretizacao() const {
    return concretizacao;
}

void Reserva::setConcretizacao(const bool concretizacao) {
    Reserva::concretizacao = concretizacao;
}
