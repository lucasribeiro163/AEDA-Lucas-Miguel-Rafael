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
    saveReservations();
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


void Empresa::addClienteDono(ClienteDono &clienteDono) {
    ClienteDono *ptr;
    ptr = &clienteDono;
    clientesDono.push_back(ptr);
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
bool Empresa::hasClienteDono(int id) const {
    for(ClienteDono *cd : clientesDono)
    {
        if(cd->getId() == id){
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

    string buffer, nif, preferencias, nome, password, id;

    getline(readFile, buffer);//Nome da classe
    getline(readFile, nome);//nome do 1º Vr

    while(nome != "Cliente")//ler todos os visitantes registados
    {
        getline(readFile, nif);
        getline(readFile,id);
        getline(readFile, preferencias);
        getline(readFile, password);
        getline(readFile, buffer);//limpar lixo

        Preferencia *preferencia = new Preferencia(preferencias);
        VisitanteRegistado *vr = new VisitanteRegistado(nome, stoi(nif), stoi(id), (*preferencia), password);
        visitantesRegistados.push_back(vr);

        getline(readFile, nome);//limpar lixo
    }

    getline(readFile, nome);//limpar lixo

    while(nome != "ClienteDono")//ler todos os clientes
    {
        getline(readFile, nif);
        getline(readFile,id);
        getline(readFile, preferencias);
        getline(readFile, password);
        getline(readFile, buffer);//limpar tracejado entre clientes

        Preferencia *preferencia = new Preferencia(preferencias);
        Cliente *c = new Cliente(nome, stoi(nif),stoi(id), (*preferencia), password);
        clientes.push_back(c);

        getline(readFile, nome);//limpar lixo
    }

    while(!readFile.eof())//ler todos os clientesDono
    {
        getline(readFile, nome);
        getline(readFile, nif);
        getline(readFile,id);
        getline(readFile, preferencias);
        getline(readFile, password);

        Preferencia *preferencia = new Preferencia(preferencias);
        ClienteDono *cd = new ClienteDono(nome, stoi(nif), stoi(id), (*preferencia), password);
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
        line << visitantesRegistados.at(i)->getNif() << endl;
        line << visitantesRegistados.at(i)->getId() << endl;
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
        line << clientes.at(i)->getNif() << endl;
        line << clientes.at(i)->getId() << endl;
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
        line << clientesDono.at(i)->getNif() << endl;
        line << clientesDono.at(i)->getId() << endl;
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

    string buffer, marca, modelo, ano, clientId, veiculoId, nrPass, volume, peso, refrig, price;
    bool refrigeracao;


    getline(readFile, buffer);//Nome da classe
    getline(readFile, marca);//limpar lixo


    while(marca != "VeiculoComercial")//ler todos os veiculoPassageiro
    {
        getline(readFile, modelo);
        getline(readFile, ano);
        getline(readFile, clientId);
        getline(readFile, nrPass);
        getline(readFile, price);
        getline(readFile, buffer);//limpar tracejado entre veiculos



        VeiculoPassageiros *vp = new VeiculoPassageiros(marca, modelo, stoi(ano), stoi(clientId), stoi(nrPass), stod(price));


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
        getline(readFile, volume);
        getline(readFile, peso);
        getline(readFile, refrig);
        getline(readFile, price);
        refrigeracao = (refrig=="true");

        VeiculoComercial *vc = new VeiculoComercial(marca, modelo, stoi(ano), stoi(clientId),
                                                    stod(volume), stod(peso), refrigeracao, stod(price));
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

        Reserva *reserva = new Reserva(dataI, dataF, stoi(preco), completed, stoi(buffer));

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

void Empresa::removeByNrPassengers(vector<VeiculoPassageiros* >* veiculosPassageiros, int min_pass){

    for(int i =0; i < veiculosPassageiros->size(); i++){

        if(veiculosPassageiros->at(i)->getNrPassageiros() <= min_pass) {
            veiculosPassageiros->erase(veiculosPassageiros->begin() + i);
            i--;
        }

    }

}


void Empresa::removeByWeight(vector<VeiculoComercial *> *veiculosComerciais, int min_weight) {

    for(int i =0; i < veiculosComerciais->size(); i++){

        if(veiculosComerciais->at(i)->getPesoCarga() <= min_weight) {
            veiculosComerciais->erase(veiculosComerciais->begin() + i);
            i--;
        }
    }

}

void Empresa::removeByVolume(vector<VeiculoComercial *> *veiculosComerciais, int min_vol) {


    for(int i =0; i < veiculosComerciais->size(); i++){

        if(veiculosComerciais->at(i)->getVolumeCarga() <= min_vol) {
            veiculosComerciais->erase(veiculosComerciais->begin() + i);
            i--;
        }
    }
}

void Empresa::removeByRefri(vector<VeiculoComercial* >* veiculosComerciais, bool refri) {


    for(int i =0; i < veiculosComerciais->size(); i++){

        if(veiculosComerciais->at(i)->hasRefrigeracao() != refri) {
            veiculosComerciais->erase(veiculosComerciais->begin() + i);
            i--;
        }
    }
}

void Empresa::removeByPricePassengers(vector<VeiculoPassageiros *> *listaVeiculos, int maxPrice){
    for (int i = 0; i < listaVeiculos->size();i++)
    {
        if( listaVeiculos->at(i)->getPriceHour() > maxPrice)
        {
            listaVeiculos->erase(listaVeiculos->begin()+i);
            i--;
        }
    }
}



void Empresa::removeByReservaPassengers(vector<VeiculoPassageiros* >* veiculos, Data in, Data out){


    bool erase = false;


    for(int i =0; i < veiculos->size(); i++){


        for(int j=0; j < veiculos->at(i)->getReservas().size(); j++) {


            if( (veiculos->at(i)->getReservas().at(j)->getDataInicio() <= in && in <= veiculos->at(i)->getReservas().at(j)->getDataFim()) ||
                (veiculos->at(i)->getReservas().at(j)->getDataInicio() <= out && out <= veiculos->at(i)->getReservas().at(j)->getDataFim()) ) {

                erase = true;
            }

        }

        if(erase) {
            veiculos->erase(veiculos->begin() + i);
            erase = false;
            i--;
        }



    }
}



void Empresa::removeByReservaComerciais(vector<VeiculoComercial* >* veiculos, Data in, Data out){


    bool erase = false;


    for(int i =0; i < veiculos->size(); i++){


        for(int j=0; j < veiculos->at(i)->getReservas().size(); j++) {


            if( (veiculos->at(i)->getReservas().at(j)->getDataInicio() <= in && in <= veiculos->at(i)->getReservas().at(j)->getDataFim()) ||
                (veiculos->at(i)->getReservas().at(j)->getDataInicio() <= out && out <= veiculos->at(i)->getReservas().at(j)->getDataFim()) ) {

                erase = true;
            }

        }

        if(erase) {
            veiculos->erase(veiculos->begin() + i);
            erase = false;
            i--;
        }



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
        line << veiculosPassageiros.at(i)->getPriceHour() << endl;
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
        line << veiculosComerciais.at(i)->getPriceHour() << endl;
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

void Empresa::saveReservations() {
    ofstream file;
    stringstream line;
    file.open(reservasFile);
    Veiculo *v;
    for (size_t i = 0; i < veiculos.size();i++)
    {
        for (size_t j =0; j < veiculos.at(i)->getReservas().size(); j++)
        {

            if(j == 0 && i != 0 )
                line << endl;
            if(veiculos.at(i)->getReservas().at(j)->getDataInicio().getDia() < 10)
                line  << '0' << veiculos.at(i)->getReservas().at(j)->getDataInicio().getDia();
            else line  << veiculos.at(i)->getReservas().at(j)->getDataInicio().getDia();

            if(veiculos.at(i)->getReservas().at(j)->getDataInicio().getMes() < 10)
                line << '/' << '0' << veiculos.at(i)->getReservas().at(j)->getDataInicio().getMes();
            else line << '/' << veiculos.at(i)->getReservas().at(j)->getDataInicio().getMes();
            line << '/'<< veiculos.at(i)->getReservas().at(j)->getDataInicio().getAno() << endl;

            if(veiculos.at(i)->getReservas().at(j)->getDataInicio().getHora().getHora() < 10)
                line  << '0' << veiculos.at(i)->getReservas().at(j)->getDataInicio().getHora().getHora();
            else line << veiculos.at(i)->getReservas().at(j)->getDataInicio().getHora().getHora();

            if(veiculos.at(i)->getReservas().at(j)->getDataInicio().getHora().getMinuto() < 10)
                line << ':' << '0' << veiculos.at(i)->getReservas().at(j)->getDataInicio().getHora().getMinuto()<<endl;
            else line << ':' << veiculos.at(i)->getReservas().at(j)->getDataInicio().getHora().getMinuto() << endl;



            if(veiculos.at(i)->getReservas().at(j)->getDataInicio().getDia() < 10)
                line << '0' << veiculos.at(i)->getReservas().at(j)->getDataFim().getDia();
            else line  << veiculos.at(i)->getReservas().at(j)->getDataFim().getDia();

            if(veiculos.at(i)->getReservas().at(j)->getDataFim().getMes() < 10)
                line << '/' << '0' << veiculos.at(i)->getReservas().at(j)->getDataFim().getMes();
            else line << '/' << veiculos.at(i)->getReservas().at(j)->getDataFim().getMes();
            line << '/' << veiculos.at(i)->getReservas().at(j)->getDataFim().getAno() << endl;

            if(veiculos.at(i)->getReservas().at(j)->getDataFim().getHora().getHora() < 10)
                line << '0' << veiculos.at(i)->getReservas().at(j)->getDataFim().getHora().getHora();
            else line  << veiculos.at(i)->getReservas().at(j)->getDataFim().getHora().getHora();

            if(veiculos.at(i)->getReservas().at(j)->getDataFim().getHora().getMinuto() < 10)
                line << ':' << '0' << veiculos.at(i)->getReservas().at(j)->getDataFim().getHora().getMinuto()<<endl;
            else line << ':' << veiculos.at(i)->getReservas().at(j)->getDataFim().getHora().getMinuto()<<endl;

            line << veiculos.at(i)->getId() << endl;
            line << veiculos.at(i)->getReservas().at(j)->getPreco() << endl;
            if (veiculos.at(i)->getReservas().at(j)->isConcretizacao())
                line << "true" << endl;
            else line << "false" << endl;
            line << "----------";
            if (j != veiculos.at(i)->getReservas().size()-1)
                line << endl;

            file << line.str();
            line.str("");
        }
    }
    file.close();
}