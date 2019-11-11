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

};

class VisitanteRegistado : public Visitante{

    int id, nif;
    string preferencias, nome;

public:

    VisitanteRegistado(string nome, int id, int nif, string preferencias);

    virtual const int &getNif() const;

    virtual void setNif(const int &nif);

    virtual int getId() const;

    virtual void setId(int id);

    virtual const string getPreferencias() const;

    void setPreferencias(const string &preferencias);

    virtual const string getNome() const;

    void setNome(const string &nome);

};

class Cliente : public VisitanteRegistado{

    vector<Reserva*> reservas;
    vector<Reserva*> historico;

public:

    Cliente(string nome, int id, int nif, string preferencias);

    virtual const vector<Reserva *> &getReservas() const;

    virtual void setReservas(const vector<Reserva *> &reservas);

    virtual const vector<Reserva *> &getHistorico() const;

    virtual void setHistorico(const vector<Reserva *> &historico);

    virtual void addToHistorico(Reserva &reserva);
};


class ClienteDono : public VisitanteRegistado{

    vector<Veiculo*> veiculos;

public:

    ClienteDono(string nome, int id, int nif, string preferencias);

    const vector<Veiculo *> &getVeiculos() const;

    void setVeiculos(const vector<Veiculo *> &veiculos);

    void addVeiculo(Veiculo &veiculo);

};


#endif //UNTITLED_UTILIZADOR_H
