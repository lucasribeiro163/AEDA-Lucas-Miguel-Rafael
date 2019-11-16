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
    int ano, clientId, id;
    vector<Reserva*> reservas;
    double priceHour;
public:

    static int nrVeiculos;

    Veiculo(string marca, string modelo, int ano, int clientId, double priceHour);

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

    virtual int getId() const;

    virtual void print()const;

    double getPriceHour() const;

    void setPriceHour(double priceHour);

};


class VeiculoPassageiros : public Veiculo{

    int nrPassageiros;

public:

    VeiculoPassageiros(string marca, string modelo, int ano, int clientId, int nrPassageiros, double price);
    int getNrPassageiros() const;
    void setNrPassageiros(int nrPassageiros);

    void print()const;
};


class VeiculoComercial : public Veiculo{

    double volume_carga;
    double peso_carga;
    bool refrigeracao;

public:

    VeiculoComercial(string marca, string modelo, int ano, int clientId, double volume_carga, double peso_carga, bool refrigeracao, double price);

    double getVolumeCarga() const;

    void setVolumeCarga(double volumeCarga);

    double getPesoCarga() const;

    void setPesoCarga(double pesoCarga);

    bool hasRefrigeracao() const;

    void setRefrigeracao(bool &refrigeracao);

    void print()const;



};

#endif //UNTITLED_VEICULO_H
