//
// Created by Lucas on 11/2/2019.
//

#include "Utilizador.h"

const string &Ciente::getNif() const {
    return nif;
}

void Ciente::setNif(const string &nif) {
    Ciente::nif = nif;
}

int Ciente::getTipo() const {
    return tipo;
}

void Ciente::setTipo(int tipo) {
    Ciente::tipo = tipo;
}

const string &Visitant::getId() const {
    return id;
}

void Visitant::setId(const string &id) {
    Visitant::id = id;
}

const vector<Veiculo *> &CienteDono::getVeiculos() const {
    return veiculos;
}

void CienteDono::setVeiculos(const vector<Veiculo *> &veiculos) {
    CienteDono::veiculos = veiculos;
}

const vector<Reserva *> &CienteBasico::getReservas() const {
    return reservas;
}

void CienteBasico::setReservas(const vector<Reserva *> &reservas) {
    CienteBasico::reservas = reservas;
}

const vector<Reserva *> &CienteBasico::getHistorico() const {
    return historico;
}

void CienteBasico::setHistorico(const vector<Reserva *> &historico) {
    CienteBasico::historico = historico;
}
