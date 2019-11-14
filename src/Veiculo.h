//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_VEICULO_H
#define UNTITLED_VEICULO_H

#include <vector>
#include <string>
#include "Data.h"
#include "Reserva.h"

using namespace std;

class Veiculo {

    string marca, modelo;
    int ano, clientId, veiculoId;

    vector<Reserva*> reservas;
public:

    Veiculo(string marca, string modelo, int ano, int clientId, int veiculoId);

    virtual const vector<Reserva*> &getReservas() const;

    virtual void addReserva(Reserva *reserva);

    virtual string getMarca()const;

    virtual void setMarca(string &marca);

    virtual string getModelo()const;

    virtual void setModelo(string &modelo);

    virtual int getAno()const;

    virtual void setAno(int &ano);

    virtual int getClientId() const;

    virtual void setClientId(int &id);

    virtual int getVeiculoId() const;

    virtual void setVeiculoId(int &id);

    virtual void print()const;

};


class VeiculoPassageiros : public Veiculo{

    int nrPassageiros;

public:

    VeiculoPassageiros(string marca, string modelo, int ano, int clientId, int VeiculoId, int nrPassageiros);
    int getNrPassageiros() const;
    void setNrPassageiros(int nrPassageiros);

    void print()const;
};


class VeiculoComercial : public Veiculo{

    double volume_carga;
    double peso_carga;
    bool refrigeracao;

public:

    VeiculoComercial(string marca, string modelo, int ano, int clientId, int VeiculoId, double volume_carga, double peso_carga, bool refrigeracao);

    double getVolumeCarga() const;

    void setVolumeCarga(double volumeCarga);

    double getPesoCarga() const;

    void setPesoCarga(double pesoCarga);

    bool hasRefrigeracao() const;

    void setRefrigeracao(bool &refrigeracao);

    void print()const;
};

#endif //UNTITLED_VEICULO_H
