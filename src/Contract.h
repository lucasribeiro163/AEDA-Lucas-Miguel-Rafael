//
// Created by Rafael on 23-12-2019.
//

#ifndef AEDA_LUCAS_MIGUEL_RAFAEL_CONTRACT_H
#define AEDA_LUCAS_MIGUEL_RAFAEL_CONTRACT_H

#include "Data.h"

/**
 * A classe contract serve para criar contratos, tem portanto as funções que permitem gerir esses contratos.
 */
class Contract {
    Data contractDate; /**<Objeto do tipo data que corresponde à data de celebraçao do contrato. */
    //Data startDate;
    //Data endDate;
    int id; /**<id do veiculo associado ao contrato. */
    string clientName; /**<Nome do cliente associado ao contrato. */
    int typeContract; /**<Tipos de contrato. 1 para aluguer, 2 para cedência.  */
    // !


public:
    /**
     * Construtor de contrato "dummy"
     * @param name - nome
     * @param type - tipo dummy
     */
    Contract(string name, int type);
    /**
     * Construtor de Contratos
     * @param contractDate - Data de celebração do contrato.
     * @param clientName - Nome do Cliente.
     * @param carId - id do carro.
     * @param typeContract - tipo de contrato
     */
    Contract(Data contractDate, string clientName, int carId, int typeContract);

    /**
     * Função que devolve a data de celebração do contrato
     * @return - Data de celebração.
     */
    const Data &getContractDate() const;

    //const Data &getStartDate() const;

    //const Data &getEndDate() const;

    /**
     * Função que devolve o ID do carro.
     * @return - id do carro.
     */
    int getId() const;
    /**
     * Função que devolve o nome do cliente.
     * @return - nome do cliente.
     */
    const string &getClientName() const;
    /**
     * Funºão que devolve tipo de contrato.
     * @return tipo de contrato.
     */
    int getTypeContract() const;
    /**
     * Overload do operador < para permitir a comparação entre dois contratos.
     * @param contract1 - contrato com o qual se quer comparar
     * @return - booleano
     */
    bool operator <(const Contract &contract1) const;
    /**
     * Overload do operador == para permitir discernir a igualdade entre dois contratos.
     * @param contract1 - contrato com o qual se quer comparar.
     * @return - booleano
     */
    bool operator ==(const Contract &contract1) const;

};


#endif //AEDA_LUCAS_MIGUEL_RAFAEL_CONTRACT_H
