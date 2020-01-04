//
// Created by migue on 11/7/2019.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include "Empresa.h"
#include "Utilizador.h"
#include "Veiculo.h"

/** Class Menu
 * A classe Menu é responsável por interagir com o utilizador.
 * Tem, portanto as funções que permitem ao utilizador gerir a sua conta
 * as suas reservas e os seus veiculos.
 */
class Menu {
    Empresa empresa; /**<Objeto Empresa que possui todos os vetores onde está guardada a informação. */
    Visitante* visitanteAtual; /**<Objeto do tipo visitante que permite qualquer usuario interagir com a nossa plataforma  */

public:
    /**
	 * Construtor do Menu
     * @param empresa - instancia da empresa.
	 */
    Menu(Empresa &empresa);

    /**
    * Função de boas vindas ao utilzidor e que verifica se ele está ou não registado na base de dados da empresa
    */
    void checkRegister();
    /**
    * Função que permite fazer login do utilizador introduzindo o seu id e a sua palavra-passe.
    */
    void login();
    /**
    * Função que imprime as opções que o utilizador tem ao seu dispor.
    */
    void choose();
    /**
    * Função que imprime os contratos disponiveis para alugar um veiculo
    */
    void rentVehicle();
    /**
    * Função que permite ao utilizador por o seu carro ao serviço da empresa.
    */
    void advertiseVehicle();
    /**
    * Função que faz um contratato de aluger unico de um veiculo.
    */
    void singleUseRent();
    /**
    * Função que permite efetuar um contrato regular com o usuario para o aluguer de um veiculo
    */
    void periodicContractRent();
    /**
    * Função que verifica a validade de uma data
     * @param data - data a verificar
    */
    bool checkDateFormat(string data);
    /**
  * Função que verifica a validade de uma hora
   * @param hora - hora a verificar
  */
    bool checkHourFormat(string hora);
    /**
  * Função que questiona o utilizador sobre a data manutencao.
  */
    string askDateMaintenance();
    /**
* Função que questiona o utilizador sobre a hora de manutencao.
*/
    string askHourMaintenance();
    /**
  * Função que questiona o utilizador sobre a data de inicio do aluguer.
  */
    string askDateIn();
    /**
 * Função que questiona o utilizador sobre a data de fim do aluguer.
 */
    string askDateOut();
    /**
 * Função que questiona o utilizador sobre a hora de inicio do aluguer.
 */
    string askHourIn();
    /**
 * Função que questiona o utilizador sobre a hora de fim do aluguer.
 */
    string askHourOut();
    /**
 * Função que imprime as opções disponíveis para gerir a frota de um utilizador
 */
    void manageFleet();
    /**
 * Função que permite ao utilizador indicar um carro seu que deixe de estar ao serviço da empresa.
 */
    void removeCar();
    /**
 * Função que imprime todos os carros da empresa.
 */
    void viewCars();
    /**
 * Função que informa e permite o utilizador escolher que tipo de atualização quer fazer.
 */
    void updateCar();
    /**
 * Função que permite ao utilizador alterar dados do seu veiculo Comercial.
 */
    void updateCargoVehicle();
    /**
 * Função que permite ao utilizador alterar dados do seu veiculo de passageiros.
 */
    void updatePassengerVehicle();
    /**
 * Função que permite ao utilizador visualizar as suas reservas.
 */
    void seeReservations();
    /**
 * Função que imprime para um utilizador não registado as opções de interação com a nossa plataforma.
 */
    void unregisteredChoose();
    /**
 * Função auxiliar para validar inputs de inteiros.
 */
    int validCinInt();
    /**
 * Função que permite ao utilizador criar um perfil na empresa.
 */
    void registerClient();
    /**
 * Função que faz uma oferta de aluguer ao utilizador consoante as suas preferencias.
     * @param in - Data do inicio do aluguer.
     * @param out - Data do fim do aluguer.
 */
    void makeOffer(Data in, Data out);
    /**
* Função que verifica se algum carro ja devia ter feito manutencao, e da opcao de fazer.
*/
    void checkMaintenance();
    /**
     * Função que obtem um inteiro do utilizador
     * @return - int
     */
    int askInt();
    };



#endif //PROJECT_MENU_H
