//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_VEICULO_H
#define UNTITLED_VEICULO_H

#include <vector>
#include <string>
#include "Data.h"
#include "Reserva.h"

using namespace std;
/** Class Veiculo
 *
 * Estrutura de um Veiculo,  os seus atributos e respetivas funções.
 */
class Veiculo {

    string marca, modelo;  /**marca e modelo do veiculo*/
    int ano, clientId, id; /**Ano do veiculo, id do cliente dono do carro, e id do veiculo*/
    vector<Reserva*> reservas;/**vetor de reservas do veiculo */
    double priceHour; /**Preço por hora pelo aluger do veiculo */
    Data manutencao;
public:

    static int nrVeiculos;  /**Variavel que permite contar o numero de veiculos, e gerar ids para cada um*/

    /**
    * Construtor de um veiculo.
    * Atribui um id ao veiculo.
     * @param marca - Marca do veiculo.
     * @param modelo - Modelo do veiculo.
     * @param ano - Ano do veiculo.
     * @param clientId - Id do cliente dono do veiculo.
     * @param priceHour - Preço por hora do alguer.
    */
    Veiculo(string marca, string modelo, int ano, int clientId, double priceHour,Data manutencao);

    /**
    * Função que retorna o vetor de reservas do veiculo.
    */
    virtual const vector<Reserva*> &getReservas() const;

    /**
    * Função que adiciona uma reserva ao vetor de reservas do veiculo
     * @param reserva - Reserva a adicionar.
    */
    virtual void addReserva(Reserva *reserva);

    /**
    * Função que retorna a Marca do veiculo.
    */
    virtual string getMarca()const;

    /**
    * Função que atribui uma marca ao veiculo.
     * @param marca - marca a atribuir.
    */
    virtual void setMarca(string &marca);

    /**
    * Função que retorna o modelo do veiculo.
    */
    virtual string getModelo()const;
/**
    * Função que atribui um modelo ao veiculo.
     * @param modelo - modelo a atribuir.
    */
    virtual void setModelo(string &modelo);

    /**
    * Função que retorna o ano do veiculo.
    */
    virtual int getAno()const;
    /**
    * Função que atribui um ano ao veiculo.
     * @param ano - ano a atribuir.
    */
    virtual void setAno(int &ano);
    /**
    * Função que retorna o id do cliente dono do veiculo.
    */

    virtual int getClientId() const;

/**
    * Função que retorna o id do veiculo.
    */
    virtual int getId() const;
/**
    * Função que imprime o veiculo.
    */
    virtual void print()const;

    /**
    * Função que retorna o preço de aluguer por hora do veiculo.
    */
    double getPriceHour() const;

    /**
     * Função que devolve a data da próxima manutenção.
     * @return
     */
    Data getManutencao() const;

    /**
     * Função que atribui uma nova data de manutenção.
     * @param manutencao - nova manutenção.
     */
    void setManutencao(Data manutencao);
    /**
     * Função que atualiza a manutenção para o ano seguinte, aquando da execução da manutenção.
     */
    void updateManutencao();
    /**
     * Overload do operador < que permite comparar dois veiculos
     * @param v1 - Veiculo ao qual comparar.
     * @return - booleano
     */
    bool operator<(const Veiculo& v1) const;
};

/** Class VeiculoPassageiros
 *
 * Estrutura de um veiculo de passageiros, os seus atributos herdados da classe mãe,
 * assim como novos atributos e respetivas funções.
 */
class VeiculoPassageiros : public Veiculo{

    int nrPassageiros;  /**numero de passageiros do veiculo*/

public:

    /**
   * Construtor de um veiculo de passageiros.
   * Atribui um id ao veiculo.
    * @param marca - Marca do veiculo.
    * @param modelo - Modelo do veiculo.
    * @param ano - Ano do veiculo.
    * @param clientId - Id do cliente dono do veiculo.
     * @param nrPassageiros - Numero de passageiros que o veiculo suporta.
    * @param priceHour - Preço por hora do alguer.
   */
    VeiculoPassageiros(string marca, string modelo, int ano, int clientId, int nrPassageiros, double price, Data manutencao);
    /**
    * Função que devolve o numero de passageiros.
    */
    int getNrPassageiros() const;
    /**
    * Função que atribui um numero de passageiros ao veiculo.
     * @param nrPassageiros - numero de passageiros a atribuir.
    */
    void setNrPassageiros(int nrPassageiros);
/**
    * Função que imprime o veiculo.
    */
    void print()const;
};

/** Class VeiculoComercial
 *
 * Estrutura de um Veiculo comercial, os seus atributos herdados da classe mãe,
 * assim como novos atributos e respetivas funções.
 */
class VeiculoComercial : public Veiculo{

    double volume_carga; /**Volume máximo de carga*/
    double peso_carga;    /**Peso máximo de carga*/
    bool refrigeracao;  /**Possui ou não arca de refrigeração.*/

public:

    /**
   * Construtor de um veiculo comercial.
   * Atribui um id ao veiculo.
    * @param marca - Marca do veiculo.
    * @param modelo - Modelo do veiculo.
    * @param ano - Ano do veiculo.
    * @param clientId - Id do cliente dono do veiculo.
     * @param volume_carga - volume máximo de carga.
     * @param peso_carga - Peso máximo de carga.
     * @param refrigeracao - Possui arca de refrigeração ou não.
    * @param priceHour - Preço por hora do alguer.
   */
    VeiculoComercial(string marca, string modelo, int ano, int clientId, double volume_carga, double peso_carga, bool refrigeracao, double price, Data manutencao);

    /**
    * Função que devolve o volume máximo de carga.
    */
    double getVolumeCarga() const;

    /**
    * Função atribui um volume máximo de carga ao veiculo
     * @param volumeCarga  - Volume a atribuir.
    */
    void setVolumeCarga(double volumeCarga);

    /**
    * Função que devolve o peso máximo de carga.
    */
    double getPesoCarga() const;

    /**
    * Função que atribui um peso máximo de carga ao veiculo
     * @param pesoCarga - peso a atribuir.
    */
    void setPesoCarga(double pesoCarga);

    /**
    * Função que devolve a capacidade ou não de refrigeração
    */
    bool hasRefrigeracao() const;

    /**
    * Função que atribui um valor à existencia de arca de refrigeração
    * @param refrigeracao - booleano a atribuir
    */
    void setRefrigeracao(bool &refrigeracao);

    /**
    * Função que imprime o veiculo.
    */
    void print()const;



};

#endif //UNTITLED_VEICULO_H
