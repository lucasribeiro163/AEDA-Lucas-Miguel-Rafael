//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_RESERVA_H
#define UNTITLED_RESERVA_H

#include "Data.h"

class Reserva {

    Data dataInicio, dataFim;
    bool concretizacao;
    double preco;
    int veiculoId;

public:

    Reserva(Data &dataInicio, Data &dataFim, double preco, bool concretizacao, int veiculoId);

    Data &getDataInicio();

    void setDataInicio(const Data &dataInicio);

    Data &getDataFim();

    void setDataFim(const Data &dataFim);

    const double getPreco();

    const void setPreco(int &preco);

    bool isConcretizacao() const;

    void setConcretizacao(const bool concretizacao);

    int getVeiculoId() const;

    void setVeiculoId(int veiculoId);

    void print();

    bool operator==(Reserva r);

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
