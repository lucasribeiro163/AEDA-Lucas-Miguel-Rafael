//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_RESERVA_H
#define UNTITLED_RESERVA_H


#include "Transacao.h"

class Reserva {

    Data data;
    Veiculo veiculo;
    Transacao pagamento;
    bool concretizacao;

public:

    const Data &getData() const;

    void setData(const Data &data);

    const Veiculo &getVeiculo() const;

    void setVeiculo(const Veiculo &veiculo);

    const Transacao &getPagamento() const;

    void setPagamento(const Transacao &pagamento);

    bool isConcretizacao() const;

    void setConcretizacao(const bool concretizacao);


};

class ReservaHoraria : public Reserva{

};

class ReservaDiaria : public Reserva{

};

class ReservaSemanal : public Reserva{

};

class ReservaMensal : public Reserva{

};


#endif //UNTITLED_RESERVA_H
