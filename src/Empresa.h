//
// Created by migue on 11/7/2019.
//

#ifndef PROJECT_EMPRESA_H
#define PROJECT_EMPRESA_H

#include <vector>
#include "Utilizador.h"

using namespace std;

class Empresa {
    vector<VisitanteRegistado *> visitantesRegistados;

public:
    Empresa();
    vector<VisitanteRegistado *> getVisitantesRegistados() const;
    void addVisitanteRegistado(VisitanteRegistado &visitanteRegistado);
    bool hasVisitanteRegistado(int id) const;
};


#endif //PROJECT_EMPRESA_H
