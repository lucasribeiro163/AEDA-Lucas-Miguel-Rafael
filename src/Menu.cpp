//
// Created by migue on 11/7/2019.
//

#include <iostream>
#include "Menu.h"
#include "Veiculo.h"
#include <ctype.h>

using namespace std;

Menu::Menu(Empresa &empresa) : empresa(empresa) {
    this->empresa = empresa;
    cout << "Welcome to the agency" << endl;
    checkRegister();

}

void Menu::checkRegister(){
    cout << "Are you registered? (Y/N)" << endl;
    string isRegistered;
    getline(cin, isRegistered);
    if ((isRegistered == "Y") || (isRegistered == "y")) {
        login();
    }
    else {
        if ((isRegistered == "N") || (isRegistered == "n")) {
            Visitante *v = new Visitante();
            cout << "You are anonymous visitor number " << v->getId() << "\nHere are the company's offers: " << endl;
            empresa.printVeiculos();
        } else {
            cout << "Sorry, wrong input" << endl;
            checkRegister();
        }
    }
}

void Menu::login(){
    string inputId;
    bool password_match = false;
    cout << "What is your id?" << endl;
    getline(cin, inputId);
        //NOTA: Fazer try catch, para evitar erro em stoi(inputId)
        VisitanteRegistado *v = this->empresa.getVisitanteRegistado(stoi(inputId));
        if (v == NULL)
            v = dynamic_cast<Cliente*> (this->empresa.getCliente(stoi(inputId)));
        if (v == NULL)
            v = dynamic_cast<ClienteDono*> (this->empresa.getClienteDono(stoi(inputId)));

        this->visitanteAtual = v;
        int counter = 1;
        if(v != NULL){

            while(!password_match) {

                string pass;
                if(counter > 3 && counter % 2 == 0)
                    cout << "Would you like to keep trying? ";
                else
                    cout << "Please insert your password: ";

                cin >> pass;

                if (pass == v->getPassword()) {

                    password_match = true;

                }
                else if((pass == "n" || pass == "N") && (counter > 3 && counter % 2 == 0)) {
                    break;
                }
                else if(counter < 3 || counter % 2 != 0)
                    cout << "\nWrong password." << endl;

                counter++;
            }

            if(password_match) {
                cout << "Welcome!" << endl;
                choose();
            }
        }
     else{
        cout << "Sorry, that id doesn't match any client" << endl;
        login();
     }
}

void Menu::choose() {
    cout << "\nWhat would you like to do?\n"
    << "1 - See all the company's cars\n"
    << "2 - Rent a vehicle" << endl
    << "3 - Advertise a vehicle" << endl
    << "4 - Manage your fleet" << endl;

    char option;
    cin >> option;
    cin.clear();

    if(option < '1' || option > '4') {
        cin.clear();
        cout << "Invalid option" << endl;
        choose();
    }
    else{
        switch(option){
            case('1'):
                cin.clear();
                empresa.printVeiculos();
                choose();
                break;
            case('2'):
                cin.clear();
                rentVehicle();
                break;
            case('3'):
                cin.clear();
                advertiseVehicle();
                break;
            case('4'):
                cin.clear();
                manageFleet();
                break;
        }
    }
}

void Menu::rentVehicle(){
    cout << "For how long would you like to rent?\n"
    << "1 - For one or more hours\n"
    << "2 - For one or more days\n"
    << "3 - Go back" << endl;

    string option;
    cin >> option;
    if(option!="1" && option!="2" && option!="3" && option!="4" && option!="5")
    {
        cout << "HERES the option:  " <<  option << endl;
        cout << "Sorry, wrong input" << endl;
        rentVehicle();
    }
    else{
        switch(stoi(option)){
            case(1):
                hourRentVehicle();
                break;
            case(2):
                dayRentVehicle();
                break;
            case(3):
                choose();
                break;
        }
    }
}


void Menu::advertiseVehicle() {

    cout << "Is your vehicle a passenger vehicle or a cargo vehicle (1 or 2)?  ";
    int tipo;
    cin >> tipo;

    if(tipo != 1 && tipo != 2){
        cout << "You've entered an unkown vehicle type. Try again." << endl;
        advertiseVehicle();
        return;
    }

    cout << "Please fill the following fields: " << endl;

    cout << " Brand: ";
    string marca;
    cin >> marca;
    cout << "Model: ";
    string modelo;
    cin >> modelo;
    cout << "Year: ";
    int ano;
    cin >> ano;

    Veiculo *v;

    if(tipo == 1) {
        cout << "Number of passengers: ";
        int nr_pass;
        cin >> nr_pass;

        v = new VeiculoPassageiros(marca, modelo, ano, this->visitanteAtual->getId(), nr_pass);
        this->empresa.addVeiculo(v);
    }
    else if(tipo == 2){
        cout << "Maximum Cargo Volume: ";
        double volume_carga;
        cin >> volume_carga;

        cout << "Maximum Cargo Weight: ";
        double peso_carga;
        cin >> peso_carga;

        cout << "Does it have Referigeration (Y-N): ";
        char tmp;
        cin >> tmp;

        bool referigeracao;
        if(tmp == 'Y')
            referigeracao = true;
        else if(tmp == 'N')
            referigeracao = false;

        v = new VeiculoComercial(marca, modelo, ano, this->visitanteAtual->getId(), volume_carga, peso_carga, referigeracao);
        this->empresa.addVeiculo(v);
        this->empresa.addVeiculo(v);

    }

    cout << "\nYou have advertised your car successfully!" << endl;

    
    bool alreadyIsOwner = false;

    for(int i =0; i < this->empresa.getClientesDono().size(); i++){

        if(this->empresa.getClientesDono().at(i)->getId() == this->visitanteAtual->getId())
            alreadyIsOwner = true;

    }

    if(!alreadyIsOwner){
        ClienteDono *cd;
        if(this->empresa.getCliente(this->visitanteAtual->getId()) == NULL)
        {
            VisitanteRegistado* v = this->empresa.getVisitanteRegistado(this->visitanteAtual->getId());
            cd = new ClienteDono(v->getNome(), v->getNif(),v->getPreferencias(),
                                              v->getPassword());
        }
        else{
            Cliente* c = this->empresa.getCliente(this->visitanteAtual->getId());
            cd = new ClienteDono(c->getNome(), c->getNif(),c->getPreferencias(),
                                              c->getPassword());
        }
        cd->resetID(this->visitanteAtual->getId());
        cd->addVeiculo(v);
        this->empresa.addClienteDono((*cd));
        this->empresa.deleteVisitor(this->visitanteAtual->getId());

        cout << cd->getNome() << endl;
        cout << cd->getPassword() << endl;
        cd->getVeiculos()->at(0)->print();
    }
        choose();
}

bool Menu::checkHourFormat(string hora){

    if(hora.size() > 5)
        return false;

    for(int i=0; i < hora.size(); i++){

        if(i==2){
            if(hora.at(i) != ':') {
                cout << "ERRO1 " << i;
                return false;
            }
        }
        else if(!isdigit(hora.at(i))) {
            cout << "ERRO2 " << i;
            return false;
        }
    }

    return true;

}

bool Menu::checkDateFormat(string data){

    if(data.size() > 10)
        return false;

    for(int i=0; i < data.size(); i++) {

        if (i == 2 || i == 5){
            if(data.at(i) != '-'){
                return false;
            }
        }
        else if(!isdigit(data.at(i))) {
            return false;
        }
    }

    return true;

}

string Menu::askDate(){

    cout << "\nWhat day do you wanna rent the vehicle?" << endl << "Insert the day in the following format (dd-mm-aaaa): ";
    string data;
    cin >> data;

    if(!checkDateFormat(data)) {
        cout << "\nFormato de data invalido. Try again." << endl;
        askDate();
    }

    return data;


}

string Menu::askHourIn(){

    cout << "\nWhat time would you like to pick up the vehicle? "<< endl << "Insert the hour in the following format (hh:mm): ";
    string hora;
    cin >> hora;

    if(!checkHourFormat(hora)) {
        cout << "\nFormato de hora invalido. Try again." << endl;
        askHourIn();
    }

    return hora;

}

string Menu::askHourOut(){

    cout << "\nWhat time would you like to drop off the vehicle? "<< endl << "Insert the hour in the following format (hh:mm): ";
    string hora;
    cin >> hora;

    if(!checkHourFormat(hora)) {
        cout << "\nFormato de hora invalido. Try again." << endl;
        askHourOut();
    }

    return hora;

}


void Menu::hourRentVehicle(){

    string data = askDate();
    string horaIn = askHourIn();
    string horaOut = askHourOut();

    cout << endl << data << endl << horaIn << endl << horaOut << endl << endl;



    //verificar reservas e encontrar lista de carros disponiveis, dar display, pessoa escolhe id do carro que quer e pow


}


void Menu::dayRentVehicle() {
    cout << "dayRent" << endl;
}

void Menu::manageFleet(){

    cout << "\nWhat would you like to do?\n"
         << "1 - View all cars on your fleet\n"
         << "2 - Remove a car from fleet\n"
         << "3 - Update the info of a car from fleet\n";

    char option;
    cin >> option;

    if(option < '1' && option > '3') {
        cout << "Invalid option" << endl;
        choose();
    }
    else{
        switch(option){
            case('1'):
                cin.clear();
                viewCars();
                break;
            case('2'):
                cin.clear();
                removeCar();
                break;
            case('3'):
                cin.clear();
                updateCar();
                break;
        }

    }
}

void Menu::removeCar() {

    ClienteDono *cd = this->empresa.getClienteDono(this->visitanteAtual->getId());

    cout << "What's the id of the car you wanna remove from your fleet? ";
    int id;
    cin >> id;

    for (int i = 0; i < cd->getVeiculos()->size(); i++) {

        if (cd->getVeiculos()->at(i)->getId() == id)
            cd->getVeiculos()->erase(cd->getVeiculos()->begin() + i);

    }


    cout << "Do you want to see what cars you have left in your fleet? (Y-N)";
    char option;
    cin >> option;

    if (option == 'Y'){
        cd->printCars();
        cout << "\nPress any key to go back to your management options?";
        cin.get();
        manageFleet();
    }
    else
        choose();


}

void Menu::viewCars() {

    ClienteDono *cd = this->empresa.getClienteDono(this->visitanteAtual->getId());
    cd->printCars();

    cout << "\nPress any key to go back to your management options?";
    cin.get();
    manageFleet();

}


void Menu::updateCar() {


    ClienteDono *cd = this->empresa.getClienteDono(this->visitanteAtual->getId());

    cout << "What's the type of the car whose info you wanna edit? (1-2)";
    int option;
    cin >> option;

    if(option == 1)
        updatePassengerVehicle();
    else if(option == 2)
        updateCargoVehicle();

    cout << "Do you want to see what cars you have left in your fleet? (Y-N)";
    char option2;
    cin >> option2;

    if (option2 == 'Y'){
        cd->printCars();
        cout << "\nPress any key to go back to your management options?";
        cin.get();
        manageFleet();
    }
    else
        choose();
}

void Menu::updateCargoVehicle() {

    ClienteDono *cd = this->empresa.getClienteDono(this->visitanteAtual->getId());

    VeiculoComercial *v;

    cout << "What's the id of the car whose info you wanna edit? ";
    int id;
    cin >> id;


    for (int i = 0; i < cd->getVeiculosComerciais()->size(); i++) {

        if (cd->getVeiculosComerciais()->at(i)->getId() == id)
            v = cd->getVeiculosComerciais()->at(i);

    }

    bool done = false;

    while(!done) {

        cout << "What detail do you wanna change? \n"
                "1-Brand\n"
                "2-Model\n"
                "3-Year\n"
                "4-Maximum Cargo volume\n"
                "5-Maximum cargo weight\n"
                "6-Referigeration ability\n";

        char option;
        cin >> option;

        cout << "Insert new value: ";

        if (option == ('1')) {
            string marca;
            cin >> marca;
            v->setMarca(marca);
        } else if (option == ('2')) {
            string modelo;
            cin >> modelo;
            v->setModelo(modelo);
        } else if (option == ('3')) {
            int ano;
            cin >> ano;
            v->setAno(ano);
        } else if (option == ('4')) {
            int volume;
            cin >> volume;
            v->setVolumeCarga(volume);
        } else if (option == ('5')) {
            int peso;
            cin >> peso;
            v->setPesoCarga(peso);
        } else if (option == ('6')) {
            cout << "(0-1) ";
            bool refri;
            cin >> refri;
            v->setRefrigeracao(refri);
        }

        char option2;
        cout << "\nDo you wanna edit anything else? (Y-N) ";
        cin >> option2;

        if (option2 != 'Y')
            done = true;


    }


}

void Menu::updatePassengerVehicle() {


    ClienteDono *cd = this->empresa.getClienteDono(this->visitanteAtual->getId());


    VeiculoPassageiros *v;

    cout << "What's the id of the car whose info you wanna edit? ";
    int id;
    cin >> id;


    for (int i = 0; i < cd->getVeiculosPassageiros()->size(); i++) {

        if (cd->getVeiculosPassageiros()->at(i)->getId() == id)
            v = cd->getVeiculosPassageiros()->at(i);

    }

    bool done = false;

    while(!done) {

        cout << "What detail do you wanna change? \n"
                "1-Brand\n"
                "2-Model\n"
                "3-Year\n"
                "4-Number of Passengers\n";

        char option;
        cin >> option;

        cout << "Insert new value: ";

        if (option == ('1')) {
            string marca;
            cin >> marca;
            v->setMarca(marca);
        } else if (option == ('2')) {
            string modelo;
            cin >> modelo;
            v->setModelo(modelo);
        } else if (option == ('3')) {
            int ano;
            cin >> ano;
            v->setAno(ano);
        } else if (option == ('4')) {
            int nrpass;
            cin >> nrpass;
            v->setNrPassageiros(nrpass);
        }

        char option2;
        cout << "\nDo you wanna edit anything else? (Y-N) ";
        cin >> option2;

        if(option2 != 'Y')
            done = true;


    }

}