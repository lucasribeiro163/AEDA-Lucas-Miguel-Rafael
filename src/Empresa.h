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
    string empresaFile, clientesFile, reservasFile;
public:
    explicit Empresa(string empresaFile);
    vector<VisitanteRegistado *> getVisitantesRegistados() const;
    vector<Cliente *> getClientes()const;
    vector<ClienteDono *> getClientesDono()const;
    VisitanteRegistado* getVisitanteRegistado(int id) const;
    void addVisitanteRegistado(VisitanteRegistado &visitanteRegistado);
    bool hasVisitanteRegistado(int id) const;
    void parseClientInfo();
    void printVeiculos() const;
};


#endif //PROJECT_EMPRESA_H
