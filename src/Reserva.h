//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_RESERVA_H
#define UNTITLED_RESERVA_H

#include "Data.h"
#include "Contract.h"
/** Class Reserva
 *
 * Formato da uma reserva, seus atributos e respectivas funções.
 *
 */
class Reserva {

    Data dataInicio, dataFim; /**Data de inicio e fim da reserva */
    bool concretizacao; /**Indicação se a reserva já foi concretizada */
    double preco; /**preço total reserva */
    int veiculoId; /**id do veiculo */
    Contract contrato;

public:

    /**
	 * Construtor de uma Reserva
     * @param dataInicio - Data de inicio do aluguer
     * @param dataFim - Data de fim do aluguer
     * @param preco - Preço total reserva
     * @param concretizacao - Indicação se a reserva já ocorreu
     * @param veiculoId - id do veiculo utilizado para a reserva
	 */
    Reserva(Data &dataInicio, Data &dataFim, double preco, bool concretizacao, int veiculoId,Contract contrato);

    /**
  * Função que retorna a data do inicio do aluguer.
  */
    Data &getDataInicio();
    /**
  * Função que retorna a data do fim do aluguer.
  */
    Data &getDataFim();

    /**
  * Função que retorna o preço por hora do aluguer.
  */
    const double getPreco();

    /**
  * Função que retorna se o aluguer já ocorreu.
  */
    bool isConcretizacao() const;

    /**
  * Função que retorna o id do veiculo utilizado para o aluguer
  */
    int getVeiculoId() const;

    /**
  * Função que imprime um aluguer
  */
    void print();

    /**
  * Overload do operador == para permitir discernir se duas reservas são iguais.
  */
    bool operator==(Reserva r);

    const Contract &getContrato() const;

};

#endif //UNTITLED_RESERVA_H
