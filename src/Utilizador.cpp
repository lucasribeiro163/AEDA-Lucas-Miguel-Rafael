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
}
VisitanteRegistado::VisitanteRegistado(string nome, int nif, int id, Preferencia &preferencias, string password)
: preferencia(preferencias), Visitante(){
    this->nome = nome;
    this->nif = nif;
    this->setId(id);
    this->password = password;
    this->preferencia = preferencias;
}


const int &VisitanteRegistado::getNif() const {
    return nif;
}

void VisitanteRegistado::setNif(const int &nif) {
    this->nif = nif;
}

const string VisitanteRegistado::getPreferencias()const{
    return preferencias;
}
const Preferencia VisitanteRegistado::getPreferencia() const{
    return preferencia;
}

void VisitanteRegistado::setPreferencias(const string &preferencias){
    this->preferencias = preferencias;
}

const string VisitanteRegistado::getNome() const{
    return this->nome;
}

void VisitanteRegistado::setNome(const string &nome){
    this->nome = nome;
}

const string &VisitanteRegistado::getPassword() const {
    return password;
}

void VisitanteRegistado::setPassword(const string &password) {
    VisitanteRegistado::password = password;
}


Cliente::Cliente(string nome, int nif, Preferencia &preferencias, string password)
: VisitanteRegistado(nome, nif, preferencias, password), reservas(), historico()
{

}
Cliente::Cliente(string nome, int nif, int id, Preferencia &preferencias, string password)
        : VisitanteRegistado(nome, nif, preferencias, password), reservas{}, historico{}
{
    this->setId(id);
}


const vector<Reserva *> &Cliente::getReservas() const {
    return reservas;
}

void Cliente::addReservas(Reserva * r){

    reservas.push_back(r);

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


ClienteDono::ClienteDono(string nome, int nif, Preferencia &preferencias, string password)
        : Cliente(nome, nif, preferencias, password){}

ClienteDono::ClienteDono(string nome, int nif, int id, Preferencia &preferencias, string password)
        : Cliente(nome, nif, preferencias, password)
    {
    this->setId(id);
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


void ClienteDono::setVeiculos(const vector<Veiculo *> &veiculos) {
    this->veiculos = veiculos;
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
