//
// Created by migue on 11/7/2019.
//

#ifndef PROJECT_EMPRESA_H
#define PROJECT_EMPRESA_H

#include <vector>
#include "Utilizador.h"

class Empresa {
    vector<Cliente *> clientes;

public:
    Empresa();
    vector<Cliente *> getClientes() const;
    void addCliente(Cliente *cliente);
};


#endif //PROJECT_EMPRESA_H
