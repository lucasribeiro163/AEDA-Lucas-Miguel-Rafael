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
    parseVehicleInfo();
    parseReservasInfo();
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

Cliente* Empresa::getCliente(int id) const {

    for(int i = 0; i < this->clientes.size(); i++){
        if(this->clientes.at(i)->getId() == id)
            return this->clientes.at(i);
    }
    return NULL;

}


void Empresa::addVisitanteRegistado(VisitanteRegistado &visitanteRegistado){
    VisitanteRegistado *visitanteRegistadoPtr;
    visitanteRegistadoPtr = &visitanteRegistado;
    visitantesRegistados.push_back(visitanteRegistadoPtr);
}

void Empresa::addCliente(Cliente &cliente) {
    Cliente *ptr;
    ptr = &cliente;
    clientes.push_back(ptr);
}

void Empresa::addClienteDono(ClienteDono &clienteDono) {
    ClienteDono *ptr;
    ptr = &clienteDono;
    clientesDono.push_back(ptr);
}

void Empresa::deleteVisitor(int id) {
    for ( int i = 0; i < clientes.size(); i++)
    {
        if(clientes.at(i)->getId() == id){
            delete clientes.at(i);
            clientes.erase(clientes.begin()+i);
            break;
        }

    }
    for ( int i = 0; i < clientesDono.size(); i++)
    {
        if(clientesDono.at(i)->getId() == id){
            delete clientesDono.at(i);
            clientesDono.erase(clientesDono.begin()+i);
            break;
        }

    }

    for ( int i = 0; i < visitantesRegistados.size(); i++)
    {
        if(visitantesRegistados.at(i)->getId() == id){
            delete visitantesRegistados.at(i);
            visitantesRegistados.erase(visitantesRegistados.begin()+i);
            break;
        }
    }
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

ClienteDono *Empresa::getClienteDono(int id){
    for(ClienteDono *cd : clientesDono)
    {
        if(cd->getId()==id)
        {
            return cd;
        }
    }
    return NULL;
}

void Empresa::parseClientInfo(){
    //clientes tem de estar na ordem: visitanteRegistado, Cliente, ClienteDono
    fstream readFile;
    readFile.open(this->empresaFile);
    getline(readFile, this->clientesFile);//nome ficheiro clientes esta em empresa.txt
    getline(readFile, this->veiculosFile);//nome ficheiro reservas esta em empresa.txt
    getline(readFile, this->reservasFile);//nome ficheiro reservas esta em empresa.txt

    readFile.close();

    readFile.open(this->clientesFile);

    string buffer, nif, preferencias, nome, password;

    getline(readFile, buffer);//Nome da classe
    getline(readFile, nome);//nome do 1º Vr

    while(nome != "Cliente")//ler todos os visitantes registados
    {
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, password);
        getline(readFile, buffer);//limpar lixo

        VisitanteRegistado *vr = new VisitanteRegistado(nome, stoi(nif), preferencias, password);
        visitantesRegistados.push_back(vr);

        getline(readFile, nome);//limpar lixo
    }

    getline(readFile, nome);//limpar lixo

    while(nome != "ClienteDono")//ler todos os clientes
    {
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, password);
        getline(readFile, buffer);//limpar tracejado entre clientes



        Cliente *c = new Cliente(nome, stoi(nif), preferencias, password);
        clientes.push_back(c);

        getline(readFile, nome);//limpar lixo
    }

    while(!readFile.eof())//ler todos os clientesDono
    {
        getline(readFile, nome);
        getline(readFile, nif);
        getline(readFile, preferencias);
        getline(readFile, password);

        ClienteDono *cd = new ClienteDono(nome, stoi(nif), preferencias, password);
        clientesDono.push_back(cd);

        getline(readFile, nome);//limpar lixo
    }
    readFile.close();

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

void Empresa::parseVehicleInfo() {
    //veiculos tem de estar na ordem: Veiculo, VeiculoPassageiros, VeiculoComercial
    fstream readFile;

    readFile.open(this->veiculosFile);

    string buffer, marca, modelo, ano, clientId, veiculoId, nrPass, volume, peso, refrig;
    bool refrigeracao;


    getline(readFile, buffer);//Nome da classe
    getline(readFile, marca);//limpar lixo


    while(marca != "VeiculoComercial")//ler todos os veiculoPassageiro
    {
        getline(readFile, modelo);
        getline(readFile, ano);
        getline(readFile, clientId);
        getline(readFile, veiculoId);
        getline(readFile, nrPass);
        getline(readFile, buffer);//limpar tracejado entre veiculos



        VeiculoPassageiros *vp = new VeiculoPassageiros(marca, modelo, stoi(ano), stoi(veiculoId), stoi(nrPass));


        getClienteDono(stoi(clientId))->addVeiculo(vp);
        getClienteDono(stoi(clientId))->addVeiculoPassageiros(vp);

        this->veiculosPassageiros.push_back(vp);

        this->addVeiculo(vp);


        getline(readFile, marca);//limpar lixo
    }

    while(!readFile.eof())//ler todos os VeiculoComercial
    {
        getline(readFile, marca);
        getline(readFile, modelo);
        getline(readFile, ano);
        getline(readFile, clientId);
        getline(readFile, veiculoId);
        getline(readFile, volume);
        getline(readFile, peso);
        getline(readFile, refrig);
        refrigeracao = (refrig=="true");

        VeiculoComercial *vc = new VeiculoComercial(marca, modelo, stoi(ano), stoi(veiculoId),
                                                    stod(volume), stod(peso), refrigeracao);
        getClienteDono(stoi(clientId))->addVeiculo(vc);
        getClienteDono(stoi(clientId))->addVeiculoComercial(vc);
        this->addVeiculo(vc);
        this->veiculosComerciais.push_back(vc);

        getline(readFile, marca);//limpar lixo
    }

}

void Empresa::printVeiculos() const{

    cout << "These are the available vehicles: "<< endl;

    for(Veiculo *v : getVeiculos())
    {
        cout << "----------" << endl;
        v->print();
    }
}

void Empresa::parseReservasInfo() {
    fstream readFile;

    readFile.open(this->reservasFile);

    string buffer, dataInicio, dataFim, horaInicio, horaFim, preco, completado;
    int veiculoId;
    bool completed;

    while(!readFile.eof())
    {
        getline(readFile, dataInicio);
        getline(readFile, horaInicio);
        getline(readFile, dataFim);
        getline(readFile, horaFim);
        getline(readFile, buffer);
        getline(readFile, preco);
        getline(readFile, completado);

        Data dataI = Data(dataInicio, horaInicio);
        Data dataF = Data(dataFim, horaFim);

        veiculoId = stoi(buffer);

        completed = (completado =="true");

        Reserva *reserva = new Reserva(dataI, dataF, stoi(preco), completed);

        Veiculo *veiculo = getVeiculo(veiculoId);

        veiculo->addReserva(reserva);

        getline(readFile, buffer);
    }

}

void Empresa::addVeiculo(Veiculo *v) {
    this->veiculos.push_back(v);
}

vector<Veiculo*> Empresa::getVeiculos() const{
    return veiculos;
}

vector<VeiculoComercial*> Empresa::getVeiculosComerciais() const{
    return veiculosComerciais;
}


vector<VeiculoPassageiros*> Empresa::getVeiculosPassageiros() const {
    return veiculosPassageiros;
}

void removeByNrPassengers(vector<VeiculoPassageiros* >* veiculosPassageiros, int min_pass){

    for(int i =0; i < veiculosPassageiros->size(); i++){

        if(veiculosPassageiros->at(i)->getNrPassageiros() <= min_pass)
            veiculosPassageiros->erase(veiculosPassageiros->begin() + i);

    }

}






void Empresa::saveVehicleInfo(){
    ofstream file;
    stringstream line;
    file.open(veiculosFile);
    Veiculo *v;
    line << "VeiculoPassageiros" << endl;
    for (size_t i = 0; i < veiculosPassageiros.size();i++)
    {
        line << veiculosPassageiros.at(i)->getMarca() << endl;
        line << veiculosPassageiros.at(i)->getModelo() << endl;
        line << veiculosPassageiros.at(i)->getAno() << endl;
        line << veiculosPassageiros.at(i)->getClientId() << endl;
        line << veiculosPassageiros.at(i)->getNrPassageiros() << endl;
        line << "----------" << endl;
        file << line.str();
        line.str("");
    }
    line << "VeiculoComercial" << endl;

    for (size_t i = 0; i < veiculosComerciais.size();i++)
    {
        line << veiculosComerciais.at(i)->getMarca() << endl;
        line << veiculosComerciais.at(i)->getModelo() << endl;
        line << veiculosComerciais.at(i)->getAno() << endl;
        line << veiculosComerciais.at(i)->getClientId() << endl;
        line << veiculosComerciais.at(i)->getVolumeCarga() << endl;
        line << veiculosComerciais.at(i)->getPesoCarga() << endl;
        if(veiculosComerciais.at(i)->hasRefrigeracao())
            line << "true" << endl;
        else line << "false" << endl;
        line << "----------";
        if (i != veiculosComerciais.size()-1)
            line << endl;
        file << line.str();
        line.str("");
    }
    file.close();
}

Veiculo *Empresa::getVeiculo(int &veiculoId){
    for(int i = 0; i < veiculos.size(); i++)
    {
        if(veiculos[i]->getId() == veiculoId)
            return veiculos[i];
    }
    return veiculos[0];//TODO
}