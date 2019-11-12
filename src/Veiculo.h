//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_VEICULO_H
#define UNTITLED_VEICULO_H

#include <vector>
#include <string>
#include "Data.h"

using namespace std;

class Veiculo {

    string marca, modelo;
    int ano;

    vector<Data*> disponiblidade;
public:

    virtual const vector<Data*> &getDisponiblidade() const;

    virtual void setDisponiblidade(const vector<Data*> &disponiblidade);

    virtual string getMarca()const;

    virtual void setMarca(string &marca);

    virtual string getModelo()const;

    virtual string setModelo(string &modelo);

    virtual int getAno()const;

    virtual void setAno(int &ano);

};


class VeiculoPassageiros{

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

    void setRefrigeracao(bool &refrigeracao);


};

#endif //UNTITLED_VEICULO_H
