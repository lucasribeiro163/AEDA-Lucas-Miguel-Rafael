//
// Created by Lucas on 11/2/2019.
//

#include <ostream>
#include <iostream>
#include "Veiculo.h"
#include "Data.h"

using namespace std;

Veiculo::Veiculo(string marca, string modelo, int ano, int clientId, double priceHour, Data manutencao){
    this->marca = marca;
    this->modelo = modelo;
    this->ano = ano;
    this->clientId = clientId;
    this->id = this->nrVeiculos++;
    this->priceHour = priceHour;
    this->manutencao = manutencao;
}

int Veiculo::nrVeiculos = 1;

string Veiculo::getMarca()const{
    return this->marca;
}

void Veiculo::setMarca(string &marca){
    this->marca = marca;
}

string Veiculo::getModelo()const{
    return this->modelo;
}

void Veiculo::setModelo(string &modelo){
    this->modelo = modelo;
}

int Veiculo::getId() const {

    return id;

}

int Veiculo::getAno()const{
    return this->ano;
}

void Veiculo::setAno(int &ano){
    this->ano = ano;
}

const vector<Reserva*> &Veiculo::getReservas() const{
    return reservas;
}

void Veiculo::addReserva(Reserva *reserva){
    this->reservas.push_back(reserva);
}

int Veiculo::getClientId() const{
    return this->clientId;
}

void Veiculo::setManutencao(Data manutencao) {
    this->manutencao = manutencao;
}


void Veiculo::print()const{
    cout << "Id: " << id << endl << "Marca: " << marca << endl
    << "Modelo: " << modelo << endl
    << "Ano: " << ano << endl
    << "Hourly Rate: " << priceHour << endl
    << "Next maintenance: ";
    manutencao.printData();
    cout << " ";
    manutencao.printHour();
    cout << endl;
}

double Veiculo::getPriceHour() const {
    return priceHour;
}
Data Veiculo::getManutencao() const {
    return manutencao;
}

bool Veiculo::operator<(const Veiculo &v1) const {
    if(this->manutencao == v1.getManutencao())
        return !this->id < v1.getId();
    else if( this->manutencao <= v1.getManutencao())
        return false;
    return true;

}


VeiculoPassageiros::VeiculoPassageiros(string marca, string modelo, int ano, int clientId, int nrPassageiros, double priceHour, Data manutencao)
        : Veiculo(marca, modelo, ano, clientId, priceHour, manutencao){
    this->nrPassageiros = nrPassageiros;
};

int VeiculoPassageiros::getNrPassageiros() const{
    return nrPassageiros;
}

void VeiculoPassageiros::setNrPassageiros(int nrPassageiros){
    this->nrPassageiros = nrPassageiros;
}

void VeiculoPassageiros::print()const{
    Veiculo::print();
    cout << "Nr passageiros: " << nrPassageiros << endl;
}

VeiculoComercial::VeiculoComercial(string marca, string modelo, int ano, int clientId, double volume_carga, double peso_carga,
                                   bool refrigeracao, double priceHour, Data manutencao)
        : Veiculo(marca, modelo, ano, clientId, priceHour,manutencao) {
    this->volume_carga = volume_carga;
    this->peso_carga = peso_carga;
    this->refrigeracao = refrigeracao;
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

bool VeiculoComercial::hasRefrigeracao() const{
    return refrigeracao;
}

void VeiculoComercial::setRefrigeracao(bool &refrigeracao){
    this->refrigeracao = refrigeracao;
}

void VeiculoComercial::print() const{
    Veiculo::print();
    cout << "Volume carga: " << volume_carga << endl
    << "Peso carga: " << peso_carga << endl;
    if(hasRefrigeracao()){
        cout << "Tem refrigeracao" << endl;
    }
}


