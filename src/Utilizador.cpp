//
// Created by Lucas on 11/2/2019.
//

#include "Utilizador.h"
#include "Veiculo.h"

const int &VisitanteRegistado::getNif() const {
    return nif;
}

void VisitanteRegistado::setNif(const int &nif) {
    this->nif = nif;
}

int VisitanteRegistado::getId() const {
    return id;
}

void VisitanteRegistado::setId(int id) {
    this->id = id;
}

const int VisitanteRegistado::getPreferencias()const{
    return preferencias;
}

const vector<Veiculo *> &ClienteDono::getVeiculos() const {
    return veiculos;
}

void ClienteDono::setVeiculos(const vector<Veiculo *> &veiculos) {
    this->veiculos = veiculos;
}

const vector<Reserva *> &Cliente::getReservas() const {
    return reservas;
}

void Cliente::setReservas(const vector<Reserva *> &reservas) {
    this->reservas = reservas;
}

const vector<Reserva *> &Cliente::getHistorico() const {
    return historico;
}

void Cliente::setHistorico(const vector<Reserva *> &historico) {
    this->historico = historico;
}

void Cliente::addToHistorico(Reserva &reserva) {
    Reserva *reservaPtr;
    reservaPtr=&reserva;
    historico.push_back(reservaPtr);
}

void ClienteDono::addVeiculo(Veiculo &veiculo) {
    Veiculo *veiculoPtr;
    veiculoPtr = &veiculo;
    veiculos.push_back(veiculoPtr);

}
