//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_UTILIZADOR_H
#define UNTITLED_UTILIZADOR_H

#include <string>
#include <vector>
#include "Veiculo.h"
#include "Reserva.h"
#include "Preferencia.h"

using namespace std;
/** Class Visitante
 *
 * Estrutura de um Visitante (não registado na empresa) seus atributos e respetivas funções.
 */
class Visitante {

    int id; /**id do visitante */

public:
    /**
	 * Construtor vazio do Visitante
     * Atribui um id ao Visitante.
	 */
    Visitante();

    static int nrVisitantes; /**Variavel que permite contar o numero de visitantes, e gerar ids para cada um*/

    /**
   * Função que retorna o id do visitante.
   */
    int getId();
    /**
   * Função que atribui um id a um utilizador.
     * @param id - id a atribuir.
   */
    void setId(int id);
    /**
   * Função auxiliar para garantir a geração de um id correto aquando do registo de um novo cliente.
   */
    void resetID(int id);

    virtual ~Visitante() {};


};
/** Class Visitante
 *
 * Estrutura de um Visitante Registado, os seus atributos herdados da classe mãe,
 * assim como novos atributos e respetivas funções.
 */
class VisitanteRegistado : public Visitante{

    int nif; /**nif do Visitante */
    string preferencias, nome, password; /**informação codificada das preferencias, nome e password do utilizador*/
    Preferencia preferencia; /**Objeto Preferencia do utilizador */

public:
/**
	 * Construtor  de um Visitante registado
     * @param nome - Nome do Utilizador
     * @param nif - Nif do utilizador
     * @param preferencias - Preferencias do utilizador
     * @param password - palavra-passa do utilizador
	 */
    VisitanteRegistado(string nome, int nif, Preferencia &preferencias, string password);
    /**
	 * Construtor  de um Visitante registado que já tem préviamente um id
     * @param nome - Nome do Utilizador
     * @param nif - Nif do utilizador
     * @param id - id do Utilizador
     * @param preferencias - Preferencias do utilizador
     * @param password - palavra-passa do utilizador
	 */
    VisitanteRegistado(string nome, int nif,int id, Preferencia &preferencias, string password);


/**
   * Função que devolve o nif do utilizador.
   */
    virtual const int &getNif() const;
    /**
   * Função que devolve a string codificada das preferencias do utilizador.
   */
    virtual const string getPreferencias() const;
    /**
   * Função que devolve o objeto Preferencia do utilizador.
   */
    virtual const Preferencia getPreferencia() const;

/**
   * Função que devolve o nome do utilizador.
   */
    virtual const string getNome() const;

/**
   * Função que devolve a palavra-chave do utilizador.
   */
    const string &getPassword() const;



};
/** Class Cliente
 *
 * Estrutura de um Cliente, os seus atributos herdados da classe mãe,
 * assim como novos atributos e respetivas funções.
 */
class Cliente : public VisitanteRegistado{

    vector<Reserva*> reservas;/**vetor com as reservas do utilizador */
    vector<Reserva*> historico; /**vetor com o historico de reservas do utilizador */

public:
/**
	 * Construtor  de um Cliente
     * @param nome - Nome do Utilizador
     * @param nif - Nif do utilizador
     * @param preferencias - Preferencias do utilizador
     * @param password - palavra-passa do utilizador
	 */
    Cliente(string nome, int nif, Preferencia &preferencias, string password);

    /**
	 * Construtor  de um Cliente que já tem préviamente um id
     * @param nome - Nome do Utilizador
     * @param nif - Nif do utilizador
     * @param preferencias - Preferencias do utilizador
     * @param password - palavra-passa do utilizador
	 */
    Cliente(string nome, int nif,int id, Preferencia  &preferencias, string password);

/**
   * Função que devolve o vetor de reservas do cliente.
   */
    virtual const vector<Reserva *> &getReservas() const;

    /**
   * Função que adiciona uma reserva ao vetor de reservas do cliente
     * @param r - reserva a inserir.
   */
    void addReservas(Reserva * r);

};

/** Class ClienteDono
 *
 * Estrutura de um Cliente Dono, os seus atributos herdados da classe mãe,
 * assim como novos atributos e respetivas funções.
 */
class ClienteDono : public Cliente{

    vector<Veiculo*> veiculos; /**vetor de veiculos do cliente*/
    vector<VeiculoPassageiros*> veiculosPassageiros;  /**vetor de veiculos de passageiros do cliente*/
    vector<VeiculoComercial*> veiculosComerciais; /**vetor de veiculos comerciais do cliente*/


public:
/**
	 * Construtor  de um Cliente Dono
     * @param nome - Nome do Utilizador
     * @param nif - Nif do utilizador
     * @param preferencias - Preferencias do utilizador
     * @param password - palavra-passa do utilizador
	 */
    ClienteDono(string nome, int nif, Preferencia  &preferencias, string password);
    /**
	 * Construtor  de um Cliente Dono que já tem préviamente um id
     * @param nome - Nome do Utilizador
     * @param nif - Nif do utilizador
     * @param preferencias - Preferencias do utilizador
     * @param password - palavra-passa do utilizador
	 */
    ClienteDono(string nome, int nif,int id, Preferencia  &preferencias, string password);

    /**
      * Função que devolve o vetor de veiculos do cliente.
      */
    vector<Veiculo *>* getVeiculos();
    /**
      * Função que devolve o vetor de veiculos Comerciais do cliente.
      */
    vector<VeiculoComercial *>* getVeiculosComerciais();
        /**
      * Função que devolve o vetor de veiculos de passageiros do cliente.
      */
    vector<VeiculoPassageiros *>* getVeiculosPassageiros();

    /**
      * Função que adiciona um veiculo ao vetor de veiculos do cliente
      */
    void addVeiculo(Veiculo* veiculo);

    /**
      * Função que adiciona um veiculo ao vetor de veiculos comerciais do cliente
      */
    void addVeiculoComercial(VeiculoComercial* veiculo);

    /**
      * Função que adiciona um veiculo ao vetor de veiculos de passageiros do cliente
      */
    void addVeiculoPassageiros(VeiculoPassageiros* veiculo);

    /**
      * Função que imprime os carros de um cliente Dono.
      */
    void printCars();
};


#endif //UNTITLED_UTILIZADOR_H
