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

class Utilizador {

};

class Cliente : public Utilizador{

    string nif;
    int tipo;

public:

    const string &getNif() const;

    void setNif(const string &nif);

    const int &getTipo() const;

    void setTipo(const int &tipo);

};

class Visitant : public Utilizador{

    string id;

public:

    string getId() const;

    void setId(string id);

};


class ClienteDono : public Cliente{

    vector<Veiculo*> veiculos;

public:

    const vector<Veiculo *> &getVeiculos() const;

    void setVeiculos(const vector<Veiculo *> &veiculos);

};

class ClienteBasico : public Cliente{

    vector<Reserva*> reservas;
    vector<Reserva*> historico;

public:

    const vector<Reserva *> &getReservas() const;

    void setReservas(const vector<Reserva *> &reservas);

    const vector<Reserva *> &getHistorico() const;

    void setHistorico(const vector<Reserva *> &historico);

    void addVeiculo(const Reserva &reserva);

    void addToHistorico(const Reserva &element);


};


#endif //UNTITLED_UTILIZADOR_H
