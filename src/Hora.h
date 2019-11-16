//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_HORA_H
#define UNTITLED_HORA_H
#include <string>

using namespace std;

/** Class Hora
 *
 * Formato da Hora, atributos (hora, minuto) e respectivas funções.
 *
 */
class Hora {
    int hora;
    int minuto;
    /**< Hora e minutos de uma "hora" . */

public:

    /**
    * Construtor da data que recebe uma string representativa da hora.
    *
    * @param hora - string composta pela hora e pelos minutos, separados por ":".
    */
    Hora(string &horaRecebida);

    /**
   * Função que retorna a hora.
   */
    int getHora() const;
    /**
       * Função que retorna os minutos .
       */
    int getMinuto() const;
    /**
    * Overload do operados <= para permitir comparar duas horas.
    */
    bool operator<=(Hora hora);
        /**
       * Overload do operador == para permitir discernir a igualdade entre duas horas.
       */
    bool operator==(Hora hora);

    };


#endif //UNTITLED_HORA_H
