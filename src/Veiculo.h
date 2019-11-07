//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_VEICULO_H
#define UNTITLED_VEICULO_H

#include <vector>
#include "Data.h"

using namespace std;

class Veiculo {

    vector<Data*> disponiblidade;

public:

    const vector<Data*> &getDisponiblidade() const;

    void setDisponiblidade(const vector<Data*> &disponiblidade);

};


class VeiculoPassageiro{

    int nrPassageiros;

public:

    int getNrPassageiros() const;
    void setNrPassageiros(int nrPassageiros);

};


class VeiculoComercial{

    double volume_carga;
    double peso_carga;
    bool refrigeracao;

public:

    double getVolumeCarga() const;

    void setVolumeCarga(double volumeCarga);

    double getPesoCarga() const;

    void setPesoCarga(double pesoCarga);

    bool isRefrigeracao() const;

    void setRefrigeracao(bool refrigeracao);


};











#endif //UNTITLED_VEICULO_H
