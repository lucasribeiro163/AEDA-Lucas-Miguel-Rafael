//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include "Hora.h"
#include <string>

using namespace std;

/** Class Data
 *
 * Formato da Data, atributos (ano, mês, dia e Hora) e respectivas funções.
 *
 */
class Data {
    int ano;
    int mes;
    int dia;
    Hora hora;
    /**< dia, mes e ano e hora de uma data. */

public:
    Data();
    Data(string data);
    /**
	 * Construtor da data recebendo duas string: Data e hora.
	 *
	 * @param data - string composta pelo ano, mês e dia, separados por "/".
     * @param hora - string composta pela hora e pelos minutos, separados por ":".
	 */
    Data(string data, string hora);

    /**
	 * Construtor da data com os seguintes parametros.
	 * @param ano - ano da data.
	 * @param mes - mês da data.
     * @param dia - dia da data.
     * @param hora - Objeto do tipo hora.
	 */
    Data(int ano, int mes, int dia, Hora hora);


    /**
	 * Função que retorna o ano.
	 */
    int getAno() const;
    /**
    * Função atribui valor ano ao membro ano
    * @param ano - valor a atribuir
    */
    void setAno(int ano);
    /**
    * Função que retorna o mês.
    */
    int getMes() const;
    /**
    * Função atribui valor mes ao membro mes.
    * @param mes - valor a atribuir.
    */
    void setMes(int mes);
    /**
    * Função que retorna o dia.
    */
    int getDia() const;
    /**
    * Função atribui valor dia ao membro dia.
    * @param dia - valor a atribuir.
    */
    void setDia(int dia);

    /**
    * Função que retorna a Hora.
    */
    Hora getHora() const;
    /**
    * Função que atribui uma hora ao membro hora.
    */
    void setHora(Hora &hora);
    /**
    * Função que devolve a diferença temporal entre duas datas.
    * @param hora - valor a atribuir
    */
    Data getDifference(Data d);

    /**
    * Função que devolve o numero de horas de diferença entre duas datas.
    */
    int hoursBetween(Data d);

    /**
    * Overload do operados <= para permitir comparar duas datas.
    */
    bool operator<=(Data data) const;

    /**
    * Overload do operador == para permitir discernir a igualdade entre duas datas.
    */
    bool operator==(Data data) const;

    void printData() const;

    void printHour() const;
};


#endif //UNTITLED_DATA_H
