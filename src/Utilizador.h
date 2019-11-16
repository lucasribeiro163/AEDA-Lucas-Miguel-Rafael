//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_UTILIZADOR_H
#define UNTITLED_UTILIZADOR_H

#include <string>
#include <vector>
#include "Veiculo.h"
#include "Reserva.h"

using namespace std;

class Visitante {

    int id;

public:
    Visitante();

    static int nrVisitantes;

    int getId();
    void resetID(int id);
    virtual ~Visitante() {};


};

class VisitanteRegistado : public Visitante{

    int nif;
    string preferencias, nome, password;

public:

    VisitanteRegistado(string nome, int nif, string preferencias, string password);

    virtual const int &getNif() const;

    virtual void setNif(const int &nif);

    virtual const string getPreferencias() const;

    void setPreferencias(const string &preferencias);

    virtual const string getNome() const;

    void setNome(const string &nome);

    const string &getPassword() const;

    void setPassword(const string &password);


};

class Cliente : public VisitanteRegistado{

    vector<Reserva*> reservas;
    vector<Reserva*> historico;
    double balance;

public:

    Cliente(string nome, int nif, string preferencias, string password, double balance);

    virtual const vector<Reserva *> &getReservas() const;

    virtual void setReservas(const vector<Reserva *> &reservas);

    void addReservas(Reserva * r);

    virtual const vector<Reserva *> &getHistorico() const;

    virtual void setHistorico(const vector<Reserva *> &historico);

    virtual void addToHistorico(Reserva &reserva);

};


class ClienteDono : public Cliente{

    vector<Veiculo*> veiculos;
    vector<VeiculoPassageiros*> veiculosPassageiros;
    vector<VeiculoComercial*> veiculosComerciais;


public:

    ClienteDono(string nome, int nif, string preferencias, string password);

    vector<Veiculo *>* getVeiculos();

    vector<VeiculoComercial *>* getVeiculosComerciais();

    vector<VeiculoPassageiros *>* getVeiculosPassageiros();

    void setVeiculos(const vector<Veiculo *> &veiculos);

    void addVeiculo(Veiculo* veiculo);

    void addVeiculoComercial(VeiculoComercial* veiculo);

    void addVeiculoPassageiros(VeiculoPassageiros* veiculo);


    void printCars();
};


#endif //UNTITLED_UTILIZADOR_H
