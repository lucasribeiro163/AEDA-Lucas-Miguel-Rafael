//
// Created by migue on 11/7/2019.
//

#include "Empresa.h"

Empresa::Empresa(){
}

vector<Cliente *> Empresa::getClientes() const{
    return clientes;
}
void Empresa::addCliente(Cliente &cliente){
    Cliente *clientePtr;
    clientePtr = &cliente;
    clientes.push_back(clientePtr);
}