//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_UTILIZADOR_H
#define UNTITLED_UTILIZADOR_H

#include <string>
#include <vector>

using namespace std;

class Utilizador {

};

class Ciente : public Utilizador{

    string nif;
    int tipo;

public:

    const string &getNif() const;

    void setNif(const string &nif);

    int getTipo() const;

    void setTipo(int tipo);

};

class Visitant : public Utilizador{

    string id;

public:

    const string &getId() const;

    void setId(const string &id);

};


class CienteDono : public Cliente{

    vector<Veiculo*> veiculos;

public:

    const vector<Veiculo *> &getVeiculos() const;

    void setVeiculos(const vector<Veiculo *> &veiculos);

};

class CienteBasico : public Cliente{

    vector<Reserva*> reservas;
    vector<Reserva*> historico;

public:

    const vector<Reserva *> &getReservas() const;

    void setReservas(const vector<Reserva *> &reservas);

    const vector<Reserva *> &getHistorico() const;

    void setHistorico(const vector<Reserva *> &historico);

    void addVeiculo(Reserva reserva);

    void addToHistorico(Reserva element);


};


#endif //UNTITLED_UTILIZADOR_H
