//
// Created by migue on 11/7/2019.
//

#include "Empresa.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Empresa::Empresa(string empresaFile){
    this->empresaFile = empresaFile;
    parseClientInfo();
}

vector<VisitanteRegistado *> Empresa::getVisitantesRegistados() const{
    return visitantesRegistados;
}

vector<Cliente *> Empresa::getClientes()const{
    return clientes;
}

vector<ClienteDono *> Empresa::getClientesDono()const{
    return clientesDono;
}

VisitanteRegistado* Empresa::getVisitanteRegistado(int id) const{

    for(int i = 0; i < this->visitantesRegistados.size(); i++){
        if(this->visitantesRegistados.at(i)->getId() == id)
            return this->visitantesRegistados.at(i);
    }
    return NULL;

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
    cout << "Criou fstream" << endl;
    readFile.open(this->empresaFile);
    cout << "Abriu ficheiro" << endl;
    getline(readFile, this->clientesFile);//nome ficheiro clientes esta em empresa.txt
    getline(readFile, this->reservasFile);//nome ficheiro reservas esta em empresa.txt

    readFile.close();

    readFile.open(this->clientesFile);

    string buffer, id, nif, preferencias, nome, password;

    getline(readFile, buffer);//Nome da classe
    getline(readFile, nome);//nome do 1º Vr

    while(nome != "Cliente")//ler todos os visitantes registados
    {
        getline(readFile, id);
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, password);
        getline(readFile, buffer);//limpar lixo

        VisitanteRegistado *vr = new VisitanteRegistado(nome, stoi(id), stoi(nif), preferencias, password);
        visitantesRegistados.push_back(vr);

        getline(readFile, nome);//limpar lixo
    }

    getline(readFile, nome);//limpar lixo

    while(nome != "ClienteDono")//ler todos os clientes
    {
        getline(readFile, id);
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, password);
        getline(readFile, buffer);//limpar tracejado entre clientes

        Cliente *c = new Cliente(nome, stoi(id), stoi(nif), preferencias, password);
        visitantesRegistados.push_back(c);

        getline(readFile, nome);//limpar lixo
    }

    while(!readFile.eof())//ler todos os clientesDono
    {
        getline(readFile, nome);
        getline(readFile, id);
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, password);

        ClienteDono *cd = new ClienteDono(nome, stoi(id), stoi(nif), preferencias, password);
        visitantesRegistados.push_back(cd);

        getline(readFile, nome);//limpar lixo
    }
    //test

    //for(int i =0; i < this->visitantesRegistados.size(); i++){
      //  cout << this->visitantesRegistados.at(i)->getId() << endl;
    //}
}

void Empresa::printVeiculos() const{
    for(ClienteDono *cd : clientesDono){
        for(Veiculo *v : cd->getVeiculos())
        {
            v->print();
        }
    }
}