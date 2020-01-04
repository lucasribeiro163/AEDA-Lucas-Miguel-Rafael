//
// Created by migue on 11/13/2019.
//

#ifndef PROJECT_PREFERENCIA_H
#define PROJECT_PREFERENCIA_H


#include "Data.h"

/** Class Preferencia
 * A classe Preferencia representa um conjunto de informações que definem o que um utilizador procura num carro.
 * Estas informações providenciadas pelo utilizador são guardadas em forma de código.
 *
 */
class Preferencia {
    unsigned int precoMax, anoMax, tipo, nrPass = 0;
    float peso_carga, volume = 0 ;
    bool refrigeracao;
    string preferencias; /**informação em formato codificado */
public:
    /**
	 * Construtor da preferencia para veiculos de passageiros
     * @param precoMax - gama na qual o cliente prefere pagar ( 0 - até 20, 1 - entre 20 e 40, 2 - acima de 40)
     * @param anoMax - altura de quando o cliente prefer o seu carro ( 0 - mais antigo que 2000, 1 - até 2010, 2 - mais recente que 2010)
     * @param nrPass - numero de passageiros preferidos pelo cliente ( 0 - até 2, 1 - até 5, 2 - mais de 5)
	 */
    Preferencia(int precoMax, int anoMax, int nrPass);
    /**
    * Construtor da preferencia para veiculos Comerciais
    * @param precoMax - gama na qual o cliente prefere pagar ( 0 - até 20, 1 - entre 20 e 40, 2 - acima de 40)
    * @param anoMax - altura de quando o cliente prefer o seu carro ( 0 - mais antigo que 2000, 1 - até 2010, 2 - mais recente que 2010)
    * @param peso_carga - peso que o cliente costuma pretender ( 0 - menos de 50, 1 - até 150, 2 - acima de 150)
     * @param volume - volume que o cliente costuma pretender ( 0 - menos de 50, 1 - até 150, 2 - acima de 150)
     * @param refrigeracao - Indicação se o cliente quer ou não arca redrigeradora.
    */
    Preferencia(int precoMax, int anoMax, float peso_carga, float volume, bool refrigeracao);

    /**
	 * Construtor da preferencia de forma codificada
     * @param preferencias - codigo na base de dados que codifica as preferencias.
	 */
    Preferencia(string preferencias);

    /**
    * Função que retorna o codigo relativo à gama de preço que o cliente prefer.
    */
    int getPrecoMax() const;

    /**
    * Função que retorna o codigo relativo à gama de idade de carros que o cliente prefer.
    */
    int getAnoMax() const;

    /**
   * Função que retorna o codigo relativo ao numero de passageiros que o cliente prefer.
   */
    int getNrPass() const;

    /**
   * Função que retorna o codigo relativo à gama de peso que o cliente costuma transportar.
   */
    float getPeso_carga() const;

    /**
   * Função que retorna o codigo relativo à gama de volume que o cliente costuma transportar
   */
    float getVolume() const;
    /**
       * Função que retorna o codigo relativo preferencia ou não por veiculo com arca refrigeradora.
       */
    bool getRefrigeracao() const;
    /**
   * Função que retorna o codigo relativo ao tipo de veiculo que o cliente prefer, comercial ou de passageiros.
   */
    int getTipo() const;

    /**
     * Função que devolve as  preferencias em formato string.
     * @return
     */
    const string getStringPreferencias() const ;
};


#endif //PROJECT_PREFERENCIA_H
