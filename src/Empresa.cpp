//
// Created by migue on 11/7/2019.
//

#include "Empresa.h"
#include <fstream>
#include <iostream>

Empresa::Empresa(string &empresaFile){
    this->empresaFile = empresaFile;
    parseClientInfo();
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

void Empresa::parseClientInfo(){
    //clientes tem de estar na ordem: visitanteRegistado, Cliente, ClienteDono
    fstream readFile;
    readFile.open(this->empresaFile);
    getline(readFile, this->clientesFile);//nome ficheiro clientes esta em empresa.txt
    getline(readFile, this->reservasFile);//nome ficheiro reservas esta em empresa.txt
    readFile.close();

    readFile.open(this->clientesFile);

    string buffer, id, nif, preferencias, nome;
    getline(readFile, buffer);//Nome da classe
    getline(readFile, nome);//nome do 1º Vr

    while(nome != "Cliente")//ler todos os visitantes registados
    {
        getline(readFile, id);
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, buffer);//limpar lixo

        VisitanteRegistado vr(nome, stoi(id), stoi(nif), preferencias);
        VisitanteRegistado *vrPointer;
        vrPointer = &vr;
        visitantesRegistados.push_back(vrPointer);

        getline(readFile, nome);//limpar lixo
    }

    getline(readFile, nome);//limpar lixo

    while(nome != "ClienteDono")//ler todos os clientes
    {
        getline(readFile, id);
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, buffer);//limpar tracejado entre clientes

        Cliente c(nome, stoi(id), stoi(nif), preferencias);
        Cliente *cPointer;
        cPointer = &c;
        visitantesRegistados.push_back(cPointer);

        getline(readFile, nome);//limpar lixo
    }


    while(!readFile.eof())//ler todos os clientesDono
    {
        getline(readFile, nome);
        getline(readFile, id);
        getline(readFile, nif);
        getline(readFile, preferencias);

        ClienteDono cd(nome, stoi(id), stoi(nif), preferencias);
        ClienteDono *cdPointer;
        cdPointer = &cd;
        visitantesRegistados.push_back(cdPointer);

        getline(readFile, nome);//limpar lixo
    }
}