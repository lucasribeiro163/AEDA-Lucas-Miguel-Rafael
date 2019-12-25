//
// Created by Lucas on 11/2/2019.
//

#include "Utilizador.h"
#include "Veiculo.h"
#include <iostream>


using namespace std;

Visitante::Visitante() {

    this->id = this->nrVisitantes++;

}

//Os carros da empresa levam clientId 0, sendo assim este comeca em 1
int Visitante::nrVisitantes = 1;

int Visitante::getId() {
    return this->id;
}
void Visitante::setId(int id){
    this->id = id;
}

void Visitante::resetID(int id) {
    nrVisitantes--;
    this->id = id;
}



VisitanteRegistado::VisitanteRegistado(string nome, int nif, Preferencia &preferencias, string password)
: preferencia(preferencias), Visitante(){
    this->nome = nome;
    this->nif = nif;
    this->password = password;
    this->type =0;
}
VisitanteRegistado::VisitanteRegistado(string nome, int nif, int id, Preferencia &preferencias, string password)
: preferencia(preferencias), Visitante(){
    this->nome = nome;
    this->nif = nif;
    this->setId(id);
    this->password = password;
    this->preferencia = preferencias;
    this->type = 0;
}


const int &VisitanteRegistado::getNif() const {
    return nif;
}


const string VisitanteRegistado::getPreferencias()const{
    return preferencias;
}
const Preferencia &VisitanteRegistado::getPreferencia() const{
    return preferencia;
}


const string VisitanteRegistado::getNome() const{
    return this->nome;
}


const string &VisitanteRegistado::getPassword() const {
    return password;
}

int VisitanteRegistado::getType() const {
    return type;
}

void VisitanteRegistado::setType(int type) {
    this->type = type;
}


Cliente::Cliente(string nome, int nif, Preferencia preferencias, string password)
: VisitanteRegistado(nome, nif, preferencias, password), reservas(), historico()
{
    this->setType(1);
}
Cliente::Cliente(string nome, int nif, int id, Preferencia preferencias, string password)
        : VisitanteRegistado(nome, nif, preferencias, password), reservas{}, historico{}
{
    this->setId(id);
    this->setType(1);
}


const vector<Reserva *> &Cliente::getReservas() const {
    return reservas;
}

void Cliente::addReservas(Reserva * r){

    reservas.push_back(r);

}


ClienteDono::ClienteDono(string nome, int nif, Preferencia preferencias, string password)
        : Cliente(nome, nif, preferencias, password){
    this->setType(2);
}

ClienteDono::ClienteDono(string nome, int nif, int id, Preferencia preferencias, string password)
        : Cliente(nome, nif, preferencias, password)
    {
    this->setId(id);
    this->setType(2);
    }



vector<Veiculo *>* ClienteDono::getVeiculos(){
    return &veiculos;
}

vector<VeiculoComercial *>* ClienteDono::getVeiculosComerciais() {
    return &veiculosComerciais;
}

vector<VeiculoPassageiros *>* ClienteDono::getVeiculosPassageiros() {
    return &veiculosPassageiros;

}



void ClienteDono::addVeiculo(Veiculo* veiculo) {

    veiculos.push_back(veiculo);

}

void ClienteDono::addVeiculoPassageiros(VeiculoPassageiros *veiculo) {

    veiculosPassageiros.push_back(veiculo);

}
void ClienteDono::addVeiculoComercial(VeiculoComercial *veiculo) {

    veiculosComerciais.push_back(veiculo);

}

void ClienteDono::printCars() {

    for(int i=0; i < this->veiculos.size(); i++){

        this->veiculos.at(i)->print();
        cout << "----------" << endl;

    }


}
