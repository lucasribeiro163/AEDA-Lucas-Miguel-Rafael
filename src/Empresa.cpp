//
// Created by migue on 11/7/2019.
//
#include "Empresa.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Empresa::Empresa(string empresaFile) :contratos(Contract("",-1)){
    this->empresaFile = empresaFile;
    parseClientInfo();
    parseVehicleInfo();
    parseReservasInfo();
    visualizaManutencoes(2);
    saveReservations();
    saveClientInfo();
    saveVehicleInfo();

}

vector<VisitanteRegistado *> Empresa::getVisitantesRegistados() const{
    vector<VisitanteRegistado*> visitantesRegistados;
    for(int i = 0; i < allClients.size(); i++)
    {
        if(allClients[i]->getType() == 0)
            visitantesRegistados.push_back(allClients[i]);
    }
    return visitantesRegistados;
}

vector<Cliente *> Empresa::getClientes() const{
    vector<Cliente *> clientes;
    for(int i = 0; i < allClients.size(); i++)
    {
        if(allClients[i]->getType() == 1)
            clientes.push_back(dynamic_cast<Cliente*> (allClients[i]));
    }
    return clientes;
}

vector<ClienteDono *> Empresa::getClientesDono()const{
    vector<ClienteDono*> clientesDono;
    for(int i = 0; i < allClients.size(); i++)
    {
        if(allClients[i]->getType() == 2)
            clientesDono.push_back(static_cast<ClienteDono*> (allClients[i]));
    }
    return clientesDono;
}

VisitanteRegistado* Empresa::getVisitanteRegistado(int id) const{

    for(int i = 0; i < this->allClients.size(); i++){
        if(this->allClients.at(i)->getId() == id)
            return this->allClients.at(i);
    }
    return NULL;

}

Cliente* Empresa::getCliente(int id) const {

    for(int i = 0; i < this->allClients.size(); i++){
        if(this->allClients.at(i)->getId() == id)
            return static_cast<Cliente*> (this->allClients.at(i));
    }
    throw InvalidClientId(id);

}


void Empresa::addVisitanteRegistado(VisitanteRegistado &visitanteRegistado){
    VisitanteRegistado *visitanteRegistadoPtr;
    visitanteRegistadoPtr = &visitanteRegistado;
    allClients.push_back(visitanteRegistadoPtr);
}


void Empresa::addClienteDono(ClienteDono &clienteDono) {
    VisitanteRegistado *ptr;
    ptr = &clienteDono;
    allClients.push_back(ptr);
}



bool Empresa::hasVisitanteRegistado(int id) const {
    for(VisitanteRegistado *v : allClients)
    {
        if(v->getId() == id && v->getType() == 0){
            return true;
        }
    }
    return false;
}
bool Empresa::hasClienteDono(int id) const {
    for(VisitanteRegistado *cd : allClients)
    {
        if(cd->getId() == id && cd->getType() == 2){
            return true;
        }
    }
    return false;
}

ClienteDono *Empresa::getClienteDono(int id){
    for(VisitanteRegistado *cd  : allClients)
    {
        if(cd->getId()==id)
        {
            return static_cast<ClienteDono*>(cd);
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

        if(buffer != "----------")
            throw UnknownInput(buffer, this->clientesFile);


        Preferencia *preferencia = new Preferencia(preferencias);
        VisitanteRegistado *vr = new VisitanteRegistado(nome, stoi(nif), stoi(id), (*preferencia), password);
        //visitantesRegistados.push_back(vr);
        allClients.push_back(vr);

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


        if(buffer != "----------")
            throw UnknownInput(buffer, this->clientesFile);

        Preferencia *preferencia = new Preferencia(preferencias);
        Cliente *c = new Cliente(nome, stoi(nif),stoi(id), (*preferencia), password);
        VisitanteRegistado* temp = c;
        //clientes.push_back(c);
        allClients.push_back(temp);

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
        //clientesDono.push_back(cd);
        VisitanteRegistado* temp = cd;
        allClients.push_back(temp);
        getline(readFile, nome);//limpar lixo
    }
    readFile.close();

}
void Empresa::saveClientInfo(){
    ofstream file;
    stringstream line;
    file.open(clientesFile);
    vector<VisitanteRegistado*> visitantesRegistados = getVisitantesRegistados();
    vector<Cliente*> clientes = getClientes();
    vector<ClienteDono*> clientesDono = getClientesDono();
    line << "VisitanteRegistado" << endl;
    for (size_t i = 0; i < visitantesRegistados.size();i++)
    {
        line << visitantesRegistados.at(i)->getNome() << endl;
        line << visitantesRegistados.at(i)->getNif() << endl;
        line << visitantesRegistados.at(i)->getId() << endl;
        line << visitantesRegistados.at(i)->getPreferencia().getStringPreferencias() << endl;
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
        line << clientes.at(i)->getPreferencia().getStringPreferencias() << endl;
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
        line << clientesDono.at(i)->getPreferencia().getStringPreferencias() << endl;
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
    Data manutencao;
    string dia,hora;


    getline(readFile, buffer);//Nome da classe
    getline(readFile, marca);//limpar lixo


    while(marca != "VeiculoComercial")//ler todos os veiculoPassageiro
    {
        getline(readFile, modelo);
        getline(readFile, ano);
        getline(readFile, clientId);
        getline(readFile, nrPass);
        getline(readFile, price);
        getline(readFile,dia);
        getline(readFile,hora);
        getline(readFile, buffer);//limpar tracejado entre veiculos


        if(buffer != "----------")
            throw UnknownInput(buffer, this->veiculosFile);
        manutencao = Data(dia,hora);
        VeiculoPassageiros *vp = new VeiculoPassageiros(marca, modelo, stoi(ano), stoi(clientId), stoi(nrPass), stod(price),manutencao);


        getClienteDono(stoi(clientId))->addVeiculo(vp);
        getClienteDono(stoi(clientId))->addVeiculoPassageiros(vp);

        this->veiculosPassageiros.push_back(vp);
        Veiculo *temp = vp;
        //this->filaVeiculos.push(temp);
        this->addVeiculo(temp);


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
        getline(readFile,dia);
        getline(readFile,hora);

        refrigeracao = (refrig=="true");
        manutencao = Data(dia,hora);
        VeiculoComercial *vc = new VeiculoComercial(marca, modelo, stoi(ano), stoi(clientId),
                                                    stod(volume), stod(peso), refrigeracao, stod(price),manutencao);
        getClienteDono(stoi(clientId))->addVeiculo(vc);
        getClienteDono(stoi(clientId))->addVeiculoComercial(vc);
        this->veiculosComerciais.push_back(vc);
        Veiculo *temp = vc;
        this->addVeiculo(temp);
        //this->filaVeiculos.push(temp);


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
    string dataContrato, horaContrato, id, name;
    int veiculoId;
    bool completed;

    while(!readFile.eof())
    {
        getline(readFile, dataContrato);
        getline(readFile, horaContrato);
        getline(readFile, name);
        getline(readFile, dataInicio);
        getline(readFile, horaInicio);
        getline(readFile, dataFim);
        getline(readFile, horaFim);
        getline(readFile, buffer);
        getline(readFile, preco);
        getline(readFile, completado);

        Data dataI = Data(dataInicio, horaInicio);
        Data dataF = Data(dataFim, horaFim);
        Data contrato = Data(dataContrato,horaContrato);
        veiculoId = stoi(buffer);

        completed = (completado =="true");

        Contract *cntrc = new Contract(contrato, dataI, dataF, name, veiculoId, 1);
        Reserva *reserva = new Reserva(dataI, dataF, stoi(preco), completed, stoi(buffer), *cntrc);

        contratos.insert(*cntrc);

        Veiculo *veiculo = getVeiculo(veiculoId);
        veiculo->addReserva(reserva);

        getline(readFile, buffer);

        if(buffer != "----------")
            throw UnknownInput(buffer, this->reservasFile);
    }

}
void Empresa::addVeiculo(Veiculo *v) {
    this->veiculos.push_back(v);
    this->filaVeiculos.push(*v);
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

        if(veiculosPassageiros.at(i)->getManutencao().getDia() < 10)
            line  << '0' << veiculosPassageiros.at(i)->getManutencao().getDia();
        else line  << veiculosPassageiros.at(i)->getManutencao().getDia();

        if(veiculosPassageiros.at(i)->getManutencao().getMes() < 10)
            line << '/' << '0' << veiculosPassageiros.at(i)->getManutencao().getMes();
        else line << '/' << veiculosPassageiros.at(i)->getManutencao().getMes();
        line << '/'<< veiculosPassageiros.at(i)->getManutencao().getAno() << endl;

        if(veiculosPassageiros.at(i)->getManutencao().getHora().getHora() < 10)
            line  << '0' << veiculosPassageiros.at(i)->getManutencao().getHora().getHora() ;
        else line << veiculosPassageiros.at(i)->getManutencao().getHora().getHora() ;

        if(veiculosPassageiros.at(i)->getManutencao().getHora().getMinuto()  < 10)
            line << ':' << '0' << veiculosPassageiros.at(i)->getManutencao().getHora().getMinuto()<<endl;
        else line << ':' << veiculosPassageiros.at(i)->getManutencao().getHora().getMinuto() << endl;

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

        if(veiculosComerciais.at(i)->getManutencao().getDia() < 10)
            line  << '0' << veiculosComerciais.at(i)->getManutencao().getDia();
        else line  << veiculosComerciais.at(i)->getManutencao().getDia();

        if(veiculosComerciais.at(i)->getManutencao().getMes() < 10)
            line << '/' << '0' << veiculosComerciais.at(i)->getManutencao().getMes();
        else line << '/' << veiculosComerciais.at(i)->getManutencao().getMes();
        line << '/'<< veiculosComerciais.at(i)->getManutencao().getAno() << endl;

        if(veiculosComerciais.at(i)->getManutencao().getHora().getHora() < 10)
            line  << '0' << veiculosComerciais.at(i)->getManutencao().getHora().getHora() ;
        else line << veiculosComerciais.at(i)->getManutencao().getHora().getHora() ;

        if(veiculosComerciais.at(i)->getManutencao().getHora().getMinuto()  < 10)
            line << ':' << '0' << veiculosComerciais.at(i)->getManutencao().getHora().getMinuto()<<endl;
        else line << ':' << veiculosComerciais.at(i)->getManutencao().getHora().getMinuto() << endl;

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

            if(veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getDia() < 10)
                line  << '0' << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getDia();
            else line  << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getDia();

            if(veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getMes() < 10)
                line << '/' << '0' << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getMes();
            else line << '/' << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getMes();
            line << '/'<< veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getAno() << endl;

            if(veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getHora().getHora() < 10)
                line  << '0' << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getHora().getHora() ;
            else line << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getHora().getHora() ;

            if(veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getHora().getMinuto()  < 10)
                line << ':' << '0' << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getHora().getMinuto()<<endl;
            else line << ':' << veiculos.at(i)->getReservas().at(j)->getContrato().getContractDate().getHora().getMinuto() << endl;
            line << veiculos.at(i)->getReservas().at(j)->getContrato().getClientName() << endl;


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

void Empresa::logContract(Contract contract) {
    contratos.insert(contract);
}

VisitanteRegistado * Empresa::getTrueClient(int id) {
    for(int i = 0; i < allClients.size();i++)
    {
        if(allClients[i]->getId() == id)
        {
            return allClients[i];
        }
    }
    throw InvalidClientId(id);
}

void Empresa::visualizaContratos() {
    BSTItrIn<Contract> it(contratos);
    if (it.isAtEnd())
    {
        cout << "Não há contratos registados...\n";
        cin.get();
        return;
    }

    cout << setw(10) << "Data de celebracao" << setw(20) << "Inicio" << setw(23) << "Fim" << setw(23) << "Nome Cliente" << setw(20) << "ID do Carro" << setw(20) << "Tipo de Contrato"  << endl;

    while (!it.isAtEnd()){
        it.retrieve().getContractDate().printData();
        cout << " - ";
        it.retrieve().getContractDate().printHour();
        cout << setw(10);
        it.retrieve().getStartDate().printData();
        cout << " - ";
        it.retrieve().getStartDate().printHour();
        cout << setw(10);
        it.retrieve().getEndDate().printData();
        cout << " - ";
        it.retrieve().getEndDate().printHour();
        cout << "          " << it.retrieve().getClientName() << setw(10) << it.retrieve().getId();
        cout << setw(10);
        if(it.retrieve().getTypeContract() == 1)
            cout << "Aluguer" << endl;
        else cout << "Cedencia" << endl;

        it.advance();
    }

    cout << "Carregue no enter para continuar...\n";
    cin.get();
    return;
}

Data Empresa::getDateToday() {
    return today;
}

void Empresa::skipToDate(Data newDate) {
    this->today = newDate;
}

void Empresa::turnVRToClient(VisitanteRegistado *vr) {
    Cliente *c = new Cliente(vr->getNome(),vr->getNif(),vr->getId(),vr->getPreferencia(),vr->getPassword());
    VisitanteRegistado* temp = c;
    for(int i = 0; i < allClients.size(); i++)
    {
        if(allClients[i]->getId() == vr->getId())
        {
            allClients.erase(allClients.begin()+ i);
            allClients.push_back(temp);
        }
    }
}

void Empresa::turnVrToClientDono(VisitanteRegistado *vr){
    ClienteDono *cd = new ClienteDono(vr->getNome(),vr->getNif(),vr->getId(),vr->getPreferencia(),vr->getPassword());
    VisitanteRegistado* temp = cd;
    for(int i = 0; i < allClients.size(); i++)
    {
        if(allClients[i]->getId() == vr->getId())
        {
            allClients.erase(allClients.begin()+ i);
            allClients.push_back(temp);
        }
    }
}

void Empresa::turnClientToClientDono(Cliente *cl) {
    ClienteDono *cd = new ClienteDono(cl->getNome(),cl->getNif(),cl->getId(),cl->getPreferencia(),cl->getPassword());
    VisitanteRegistado* temp = cd;
    for(int i = 0; i < allClients.size(); i++)
    {
        if(allClients[i]->getId() == cl->getId())
        {
            allClients.erase(allClients.begin()+ i);
            allClients.push_back(temp);
        }
    }
}




bool Empresa::hasCliente(int id) const {
    for(VisitanteRegistado *cd : allClients)
    {
        if(cd->getId() == id && cd->getType() == 1){
            return true;
        }
    }
    return false;
}

void Empresa::saveAll() {
    saveClientInfo();
    saveReservations();
    saveVehicleInfo();
}

void Empresa::visualizaManutencoes(int n) {
    vector<Veiculo> aux;
    for(int i = 0; i < n && i < filaVeiculos.size(); i++)
    {
        aux.push_back(filaVeiculos.top());
        filaVeiculos.pop();
    }

    for(int i = 0; i < aux.size();i++)
    {
        filaVeiculos.push(aux[i]);
        aux[i].print();
        cout << endl;
    }


}