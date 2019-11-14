//
// Created by migue on 11/7/2019.
//

#ifndef PROJECT_EMPRESA_H
#define PROJECT_EMPRESA_H

#include <vector>
#include <string>
#include "Utilizador.h"

using namespace std;

class Empresa {
    vector<VisitanteRegistado *> visitantesRegistados;
    vector<Cliente *> clientes;
    vector<ClienteDono *> clientesDono;
    vector<Veiculo* > veiculos;
    string empresaFile, clientesFile, reservasFile, veiculosFile;
public:
    explicit Empresa(string empresaFile);
    vector<VisitanteRegistado *> getVisitantesRegistados() const;
    vector<Cliente *> getClientes()const;
    vector<ClienteDono *> getClientesDono()const;
    ClienteDono *getClienteDono(int id);
    VisitanteRegistado* getVisitanteRegistado(int id) const;
    Cliente* getCliente(int id) const;
    void addVisitanteRegistado(VisitanteRegistado &visitanteRegistado);
    bool hasVisitanteRegistado(int id) const;
    void addCliente(Cliente &cliente);
    void deleteVisitor(int id);
    void addClienteDono(ClienteDono &clienteDono);
    void parseClientInfo();
    void parseVehicleInfo();
    void parseReservasInfo();
    void saveClientInfo();
    void printVeiculos() const;
    void addVeiculo(Veiculo* v);
    vector<Veiculo*> getVeiculos() const;

    };


#endif //PROJECT_EMPRESA_H
