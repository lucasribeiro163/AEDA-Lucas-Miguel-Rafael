//
// Created by migue on 11/7/2019.
//

#include "Empresa.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

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
        clientes.push_back(c);

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
        clientesDono.push_back(cd);

        getline(readFile, nome);//limpar lixo
    }
    //test

    //for(int i =0; i < this->visitantesRegistados.size(); i++){
      //  cout << this->visitantesRegistados.at(i)->getId() << endl;
    //}
}
void Empresa::saveClientInfo(){
    ofstream file;
    stringstream line;

    file.open(clientesFile);
    line << "VisitanteRegistado" << endl;
    for (size_t i = 0; i < visitantesRegistados.size();i++)
    {
        line << visitantesRegistados.at(i)->getNome() << endl;
        line << visitantesRegistados.at(i)->getId() << endl;
        line << visitantesRegistados.at(i)->getNif() << endl;
        line << visitantesRegistados.at(i)->getPreferencias() << endl;
        line << visitantesRegistados.at(i)->getPassword() << endl;
        line << "----------" << endl;
        file << line.str();
        line.str("");

    }
    line << "Cliente" << endl;
    for (size_t i = 0; i < clientes.size();i++)
    {
        line << clientes.at(i)->getNome() << endl;
        line << clientes.at(i)->getId() << endl;
        line << clientes.at(i)->getNif() << endl;
        line << clientes.at(i)->getPreferencias() << endl;
        line << clientes.at(i)->getPassword() << endl;
        line << "----------" << endl;
        file << line.str();
        line.str("");
    }

    line << "ClienteDono" << endl;
    for (size_t i = 0; i < clientesDono.size();i++)
    {

        line << clientesDono.at(i)->getNome() << endl;
        line << clientesDono.at(i)->getId() << endl;
        line << clientesDono.at(i)->getNif() << endl;
        line << clientesDono.at(i)->getPreferencias() << endl;
        line << clientesDono.at(i)->getPassword() << endl;
        line << "----------";
        if (i != clientesDono.size()-1)
            line << endl;
        file << line.str();
        line.str("");
    }
    file.close();
}

void Empresa::printVeiculos() const{

    cout << "These are the available vehicles: "<< endl;

    for(ClienteDono *cd : clientesDono){
        for(Veiculo *v : cd->getVeiculos())
        {
            v->print();
        }
    }
}