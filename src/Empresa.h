//
// Created by migue on 11/7/2019.
//

#ifndef PROJECT_EMPRESA_H
#define PROJECT_EMPRESA_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "Utilizador.h"
#include "Contract.h"
#include "bst.h"

using namespace std;

/** Class Empresa
 * A classe Companhia é responsável por manter e atualizar
 * toda a informação necessaria para o correto funcionamento do programa
 * Contem os vetores de clientes, veiculos e reservas
 * Tem, portanto as funções que permitem ler e guardar em ficheiros,
 * visualizar reservas,
 */

class Empresa {

    Administrador* admin;

    bool adminView = false;
public:
    bool isAdminView() const;

    void setAdminView(bool adminView);

private:
    /**
	 * Vetor onde estao guardados os veiculos.
	 */
    vector<Veiculo* > veiculos;
    /**
	 * Vetor onde estao guardados os veiculos do tipo comercial.
	 */
    vector <VeiculoComercial* > veiculosComerciais;
    /**
	 * Vetor onde estao guardados os veiculos do tipo de passageiros.
	 */
    vector <VeiculoPassageiros* > veiculosPassageiros;
    /**
	 * Localização dos ficheiros de texto de apoio ao programa.
	 */
    string empresaFile, clientesFile, reservasFile, veiculosFile;

    BST<Contract> contratos; /**<.Árvore binária de pesquisa.  */
    vector<VisitanteRegistado*> allClients;/**<Vetor onde estão todos os clientes de todos os tipos.  */
    priority_queue<Veiculo*> filaVeiculos; /**<fila de prioridade de veiculos para manutenção.  */
    unordered_set<Cliente*, clientesHash, clientesHash> clientesInativos; /**<Tabela de dispersão dos clientes inativos.  */

    Data today = Data("01/01/2020", "10:00");

public:
    /**
	 * Construtor da empresa
     * @param empresaFile - ficheiro onde está guardada a localização dos restates ficheiros
	 */
    explicit Empresa(string empresaFile);

    /**
    * Função que devolve um vetor dos visitantes registados.
    */
    vector<VisitanteRegistado *> getVisitantesRegistados() const;

    /**
     * Função que devolve um vetor dos clientes.
     */
    vector<Cliente *> getClientes()const;
    /**
    * Função que devolve um vetor dos dos clientes donos de pelo menos um veiculo.
    */
    vector<ClienteDono *> getClientesDono()const;
    /**
    * Função que devolve um ClienteDono com um determinado id.
     * @param id - id do cliente a procurar.
    */
    ClienteDono *getClienteDono(int id);
    /**
    * Função que adiciona um veiculo a queue.
     * @param v - veiculo a adicionar.
    */
    void addToQueue(Veiculo *v);
    /**
    * Função que limpa queue.
    */
    void clearQueue();
    /**
    * Função que devolve um Visitante Registado com um determinado id.
     * @param id - id do visitante a procurar.
    */
    VisitanteRegistado* getVisitanteRegistado(int id) const;
    /**
    * Função que devolve um Cliente com um determinado id.
     * @param id - id do cliente a procurar.
    */
    Cliente* getCliente(int id) const;
    /**
    * Função que adiciona um visitante registado ao vetor de clientes registados.
     * @param visitanteRegistado - objeto a inserir no vetor de clientes registados.
    */
    void addVisitanteRegistado(VisitanteRegistado &visitanteRegistado);
    /**
    * Função que afere se existe um visitante registado com o id fornecido.
     * @param id - id do visitante a procurar.
    */
    bool hasVisitanteRegistado(int id) const;
    /**
   * Função que afere se existe um cliente dono  com o id fornecido.
    * @param id - id do Cliente Dono  a procurar.
   */
    bool hasClienteDono(int id) const;
    /**
    * Função que adiciona um cliente dono  ao vetor respetivo.
     * @param clienteDono - objeto a inserir no vetor respetivo.
    */
    void addClienteDono(ClienteDono &clienteDono);
    /**
    * Função que faz parse ao ficheiro dos clientes e popula o vetor respetivo.
    */
    void parseAll();
    /**
   * Função que chama parser de todos os ficheiros.
   */
    void parseAdministratorInfo();
    /**
   * Função que faz parse ao ficheiro da empresa de modo a obter a imformação do administrador.
   */
    void parseClientInfo();
    /**
   * Função que faz parse ao ficheiro dos veiculos e popula o vetor respetivo.
   */
    void parseVehicleInfo();
    /**
   * Função que faz parse ao ficheiro das reservas e popula o vetor respetivo.
   */
    void parseReservasInfo();
    /**
   * Função que escreve no ficheiro respetivo todos os clientes.
   */
    void saveClientInfo();
    /**
   * Função que escreve no ficheiro respetivo todos os veiculos.
   */
    void saveVehicleInfo();
    /**
   * Função que escreve no ficheiro respetivo todas as reservas.
   */
    void saveReservations();
    /**
   * Função que imprime todos os veiculos da empresa.
   */
    void printVeiculos() const;
    /**
   * Função que adiciona um veiculo ao respetivo vetor.
     * @param v - veiculo a inserir.
   */
    void addVeiculo(Veiculo* v);
    /**
     * Função que  devolve todos os veiculos.
     */
    vector<Veiculo*> getVeiculos() const;
    /**
      * Função que  devolve um veiculo com um certo ID.
      * @param veiculoId - id do veiculo a pesquisar.
      */
    Veiculo *getVeiculo(int &veiculoId);
    /**
      * Função que  devolve todos os veiculos do tipo Veiculo de passageiros.
      */
    vector<VeiculoPassageiros*> getVeiculosPassageiros() const;
    /**
      * Função que  devolve todos os veiculos do tipo Veiculo comercial.
      */
    vector<VeiculoComercial*> getVeiculosComerciais() const;
    /**
      * Função que filtra um vetor de veiculos de passageiros por um valor de numero mínimo de passageiros
      * @param veiculosPassageiros - vetor a processar.
      * @param min_pass - numero de passageiros que define a aceitação ou não de um veículo.
      */
    void removeByNrPassengers(vector<VeiculoPassageiros* >* veiculosPassageiros, int min_pass);
    /**
     * Função que filtra um vetor de veiculos comerciais por um valor mínimo de peso de carga.
      * @param veiculosComerciais - vetor a processar.
      * @param min_weight - valor de peso que define a aceitação ou não de um veículo.
     */
    void removeByWeight(vector<VeiculoComercial* >* veiculosComerciais, int min_weight);
    /**
    * Função que filtra um vetor de veiculos comerciais por um valor mínimo de volume de carga.
     * @param veiculosComerciais - vetor a processar.
      * @param min_vol - valor que define a aceitação ou não de um veículo.
      */
    void removeByVolume(vector<VeiculoComercial* >* veiculosComerciais, int min_vol);
    /**
 * Função que filtra um vetor de veiculos comerciais consoante possui ou não arca refrigerativa.
      * @param veiculosComerciais - vetor a processar.
      * @param refri -Possui ou não arca frigorifica.
 */
    void removeByRefri(vector<VeiculoComercial* >* veiculosComerciais, bool refri);
    /**
    * Função que filtra um vetor de veiculos de passageiros pelos parametros da data de inicio e fim da reserva.
     * @param veiculos - vetor a processar.
     * @param in - Data do inicio da reserva.
     * @param out - Data do fim da reserva.
     */
    void removeByReservaPassengers(vector<VeiculoPassageiros* >* veiculos, Data in, Data out);
    /**
 * Função que filtra um vetor de veiculos comerciais pelos parametros da data de inicio e fim da reserva.
     * * @param veiculos - vetor a processar.
     * @param in - Data do inicio da reserva.
     * @param out - Data do fim da reserva.
 */
    void removeByReservaComerciais(vector<VeiculoComercial* >* veiculos, Data in, Data out);
    /**
 * Função que filtra um vetor de veiculos de passageiros pelo parametro de preço maximo.
     * * @param listaVeiculos - vetor a processar.
     * @param maxPrice - preço maximo aceitavel.
 */
    void removeByPricePassengers(vector<VeiculoPassageiros* >* listaVeiculos, int maxPrice);
    /**
     *Função que insere um novo contrato na arvore binaria de pesquisa contratos
     * @param contract
     */
    void logContract(Contract contract);
    /**
     * Devolve um apontador para um objeto da classe base visitanteRegistado, o qual pode ser Cast de forma segura para o seu tipo original.
     * @param id - ID do cliente a pesquisar
     * @return - pointer para objeto da classe visitanteRegistado.
     */
    VisitanteRegistado* getTrueClient(int id);
    /**
     * Funaão que imprime todos os contratos disponiveis.
     */
    void visualizaContratos();
    /**
     * Função para visualizar todos os contratos de um cliente.
     * @param id - ID do cliente a pesquisar.
     */
    void visualizaContratosDeCliente(int id);
    /**
     *Função para visualizar todos os clientes inativos.
     */
    void visualizaClientesInativos();
    /**
     * Função que devolve um apontador para o administrador.
     * @return apontador para objeto do tipo Administrador.
     */
    Administrador *getAdmin() const;
    /**
     * Função que devolve a data atual.
     * @return Data atual.
     */
    Data getDateToday();
    /**
     * Função para alterar a data atual.
     * @param newDate
     */

    void skipToDate(Data newDate);
    /**
     * Função para converter visitanteRegistado em Cliente aquando de alguma ação que o justifique.
     * @param vr - visitanteRegistado a ser atualizado
     */
    void turnVRToClient(VisitanteRegistado * vr);
    /**
     * Função para converter visitanteRegistado em ClienteDono aquando de alguma ação que o justifique.
     * @param vr - visitanteRegistado a ser atualizado
     */
    void turnVrToClientDono(VisitanteRegistado *vr);
    /**
     * Função para converter cliente em ClienteDono aquando de alguma ação que o justifique.
     * @param cl - cliente a ser atualizado
     */
    void turnClientToClientDono(Cliente *cl);
    /**
     * Função para verificar se um cliente existe.
     * @param id - Id do cliente a procurar.
     * @return booleano
     */
    bool hasCliente(int id) const;
    /**
     * Função para guardar toda a informação em memória nos ficheiros respetivos.
     */
    void saveAll();
    /**
     * Função que imprime as n primeiras manutenções ou todos os veículos caso n seja maior que o numero de veiculos disponiveis.
     * @param n
     */
    void visualizaManutencoes(int n );
    /**
     * Função que atualiza os clientes inativos.
     */
    void updateClientesInativos();
    /**
     * Função que atualiza os manutenções.
     */
    void updateManutencoes();
    /**
     * Função que permite alterar uma data de manutenção de um determinado veiculo.
     * @param carID - ID do veiculo a alterar.
     * @param manutencao - Nova data de manutenção.
     */
    void changeManutencao(int carID, Data manutencao);
    /**
     * Função que verifica a existencia de um Veiculo de passageiros com determinado ID
     * @param carID - id do carro a procurar.
     * @return - booleano.
     */
    bool hasPassengerVehicle(int carID) const;
    /**
     * Função que verifica a existencia de um Veiculo de mercadorias com determinado ID
     * @param carID - id do carro a procurar.
     * @return - booleano.
     */
    bool hasCargoVehicle(int carID) const;
};


/** Class UnknownInput
 * Excepção atirada quando se encontra
 * input desconhecido nos txt
 */
class UnknownInput{

    string line;
    string filename;

public:
     /**
	 * Construtor da UnkownInput
     * @param line - conteudo da linha que causou a excepção
     * @param filename - nome do ficheiro que causou a excepção
	 */
    UnknownInput(string line, string filename){
        this->line =line;
        this->filename = filename;
        cout << "Exception: Unkown Exception -> This line was not recognized: " << line << " in file " << filename << "." << endl;


    }


};


/** Class InvalidClientId
 * Excepção atirada quando se procura um
 * cliente de id não existente
 */
class InvalidClientId{

    int id;


public:
    /**
    * Construtor da InvalidClientId
    * @param id - id do veiculo que causou a excepção
    */
    InvalidClientId(int id){

        cout << "Exception: InvalidClientId: couldn't find a client with id =" << id << "." << endl;
    }

};




#endif //PROJECT_EMPRESA_H
