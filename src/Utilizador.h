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

    string nif;
    int preferencias, id;

public:

    const string &getNif() const;

    void setNif(const string &nif);

    const int &getPreferencias() const;

    void setPreferencias(const int &preferencias);

};

class Cliente : public VisitanteRegistado{

    vector<Reserva*> reservas;
    vector<Reserva*> historico;

public:

    string getId() const;

    void setId(string id);

    const vector<Reserva *> &getReservas() const;

    void setReservas(const vector<Reserva *> &reservas);

    const vector<Reserva *> &getHistorico() const;

    void setHistorico(const vector<Reserva *> &historico);


    void addToHistorico(const Reserva &element);
};


class ClienteDono : public VisitanteRegistado{

    vector<Veiculo*> veiculos;

public:

    const vector<Veiculo *> &getVeiculos() const;

    void setVeiculos(const vector<Veiculo *> &veiculos);

    void addVeiculo(const Veiculo &veiculo);

};


#endif //UNTITLED_UTILIZADOR_H
