//
// Created by migue on 11/7/2019.
//

#include "Empresa.h"

Empresa::Empresa(){
}

vector<VisitanteRegistado *> Empresa::getVisitantesRegistados() const{
    return visitantesRegistados;
}

void Empresa::addVisitanteRegistado(VisitanteRegistado &visitanteRegistado){
    VisitanteRegistado *visitanteRegistadoPtr;
    visitanteRegistadoPtr = &visitanteRegistado;
    visitantesRegistados.push_back(visitanteRegistadoPtr);
}

bool Empresa::hasVisitanteRegistado(int id) const {
    for(VisitanteRegistado *v : visitantesRegistados)
    {
        if(v->getId() == id){
            return true;
        }
    }
    return false;
}