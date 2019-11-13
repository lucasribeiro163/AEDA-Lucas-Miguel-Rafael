//
// Created by Lucas on 11/2/2019.
//

#include <ostream>
#include <iostream>
#include "Veiculo.h"
#include "Data.h"

using namespace std;

Veiculo::Veiculo(string marca, string modelo, int ano, int clientId){
    this->marca = marca;
    this->modelo = modelo;
    this->ano = ano;
    this->clientId = clientId;
}

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

int Veiculo::getAno()const{
    return this->ano;
}

void Veiculo::setAno(int &ano){
    this->ano = ano;
}

const vector<Data*> &Veiculo::getDisponiblidade() const {
    return disponiblidade;
}

void Veiculo::setDisponiblidade(const vector<Data*> &disponiblidade) {
    this->disponiblidade = disponiblidade;
}

int Veiculo::getClientId() const{
    return this->clientId;
}

void Veiculo::setClientId(int &id){
    this->clientId = clientId;
}

void Veiculo::print()const{
    cout << "Marca: " << marca << endl
    << "Modelo: " << modelo << endl
    << "Ano: " << ano << endl;
}

VeiculoPassageiros::VeiculoPassageiros(string marca, string modelo, int ano, int clientId, int nrPassageiros)
        : Veiculo(marca, modelo, ano, clientId){
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
                                   bool refrigeracao)
        : Veiculo(marca, modelo, ano, clientId) {
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
