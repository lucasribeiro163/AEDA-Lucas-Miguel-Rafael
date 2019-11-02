//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_RESERVA_H
#define UNTITLED_RESERVA_H



class Reserva {

    Data data;
    Veiculo veiculo;
    Transacao pagamento;
    bool concretização;

public:

    Data getData();

    void setData(Data data);

    Veiculo getVeiculo();

    void setVeiculo(Veiculo veiculo);

    Transacao getPagamento();

    void setPagamento(Transacao pagamento);

    bool isConcretização();

    void setConcretização(bool concretização);


};


#endif //UNTITLED_RESERVA_H
