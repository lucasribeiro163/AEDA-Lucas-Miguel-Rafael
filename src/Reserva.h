//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_RESERVA_H
#define UNTITLED_RESERVA_H

#include "Data.h"

class Reserva {

    Data dataInicio, dataFim;
    bool concretizacao;
    int preco;

public:

    Reserva(Data &dataInicio, Data &dataFim, int preco, bool concretizacao);

    const Data &getDataInicio() const;

    void setDataInicio(const Data &dataInicio);

    const Data &getDataFim() const;

    void setDataFim(const Data &dataFim);

    const int getPreco();

    const void setPreco(int &preco);

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
