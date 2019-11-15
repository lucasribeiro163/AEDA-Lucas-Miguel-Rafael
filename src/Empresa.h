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
    vector <VeiculoComercial* > veiculosComerciais;
    vector <VeiculoPassageiros* > veiculosPassageiros;
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
    void saveVehicleInfo();
    void saveReservations();
    void printVeiculos() const;
    void addVeiculo(Veiculo* v);
    vector<Veiculo*> getVeiculos() const;
    Veiculo *getVeiculo(int &veiculoId);
    vector<VeiculoPassageiros*> getVeiculosPassageiros() const;
    vector<VeiculoComercial*> getVeiculosComerciais() const;
    void removeByNrPassengers(vector<VeiculoPassageiros* >* veiculosPassageiros, int min_pass);
    void removeByWeight(vector<VeiculoComercial* >* veiculosComerciais, int min_weight);
    void removeByVolume(vector<VeiculoComercial* >* veiculosComerciais, int min_vol);
    void removeByRefri(vector<VeiculoComercial* >* veiculosComerciais, bool refri);
    void removeByReservaPassengers(vector<VeiculoPassageiros* >* veiculos, string dataIn, string dataOut, string horaIn, string horaOut);
    void removeByReservaComerciais(vector<VeiculoComercial* >* veiculos, string dataIn, string dataOut, string horaIn, string horaOut);
    };


#endif //PROJECT_EMPRESA_H
