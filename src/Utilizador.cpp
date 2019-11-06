//
// Created by Lucas on 11/2/2019.
//

#include "Utilizador.h"
#include "Veiculo.h"

const string &Cliente::getNif() const {
    return nif;
}

void Cliente::setNif(const string &nif) {
    Cliente::nif = nif;
}

const int &Cliente::getTipo() const {
    return tipo;
}

void Cliente::setTipo(const int &tipo) {
    Cliente::tipo = tipo;
}

string Visitant::getId() const {
    return id;
}

void Visitant::setId(string id) {
    Visitant::id = id;
}

const vector<Veiculo *> &ClienteDono::getVeiculos() const {
    return veiculos;
}

void ClienteDono::setVeiculos(const vector<Veiculo *> &veiculos) {
    ClienteDono::veiculos = veiculos;
}

const vector<Reserva *> &ClienteBasico::getReservas() const {
    return reservas;
}

void ClienteBasico::setReservas(const vector<Reserva *> &reservas) {
    ClienteBasico::reservas = reservas;
}

const vector<Reserva *> &ClienteBasico::getHistorico() const {
    return historico;
}

void ClienteBasico::setHistorico(const vector<Reserva *> &historico) {
    ClienteBasico::historico = historico;
}
