//
// Created by migue on 11/13/2019.
//

#include "Preferencia.h"


Preferencia::Preferencia(int precoMax, int anoMax, int nrPass){
    this->precoMax = precoMax;
    this->anoMax = anoMax;
    this->nrPass = nrPass;
}
Preferencia::Preferencia(int precoMax, int anoMax, float peso_carga, float volume, bool refrigeracao){
    this->precoMax = precoMax;
    this->anoMax = anoMax;
    this->peso_carga = peso_carga;
    this->volume = volume;
    this->refrigeracao = refrigeracao;
}

int Preferencia::getPrecoMax() const{
    return precoMax;
}
void Preferencia::setPrecoMax(int &preco){
    this->precoMax = preco;
}

int Preferencia::getAnoMax() const{
    return anoMax;
}
void Preferencia::setaAnoMax(int &ano){
    this->anoMax = ano;
}

int Preferencia::getNrPass() const{
    return nrPass;
}
void Preferencia::setNrPass(int &nrPass){
    this->nrPass = nrPass;
}

float Preferencia::getPeso_carga() const{
    return peso_carga;
}
void Preferencia::setPeso_carga(float &peso_carga){
    this->peso_carga = peso_carga;
}

float Preferencia::getVolume() const{
    return volume;
}
void Preferencia::setVolume(float &volume){
    this->volume = volume;
}

bool Preferencia::getRefrigeracao() const{
    return refrigeracao;
}
void Preferencia::setRefrigeracao(bool &refrigeracao){
    this->refrigeracao = refrigeracao;
}