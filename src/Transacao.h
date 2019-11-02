//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_TRANSACAO_H
#define UNTITLED_TRANSACAO_H
#include "Veiculo.h"

class Transacao {

    double valor;
    Data data;
    Veiculo veiculo;


public:

    double getValor() const;

    void setValor(double valor);

    const Data &getData() const;

    void setData(const Data &data);

    const Veiculo &getVeiculo() const;

    void setVeiculo(const Veiculo &veiculo);

};


#endif //UNTITLED_TRANSACAO_H
