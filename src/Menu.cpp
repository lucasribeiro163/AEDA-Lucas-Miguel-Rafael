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
            //registerClient();
            //empresa.saveClientInfo();
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
    << "4 - Manage your fleet" << endl
    << "5 - See all of my reservations" << endl;

    char option;
    cin >> option;
    cin.clear();

    if(option < '1' || option > '5') {
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
            case('5'):
                cin.clear();
                seeReservations();
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
                return false;
            }
        }
        else if(!isdigit(hora.at(i))) {
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
            if(data.at(i) != '/'){
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

    cout << "\nWhat day do you wanna rent the vehicle?" << endl << "Insert the day in the following format (dd/mm/aaaa): ";
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

    cout << "\nWhat type of vehicle do you need, Passenger or Cargo (1-2)? ";
    int type;
    cin >> type;

    if(type == 1) {

        cout << "\nWhat's the minimum number of passengers? ";
        int min_pass;
        cin >> min_pass;

        vector<VeiculoPassageiros *> res = this->empresa.getVeiculosPassageiros();
        this->empresa.removeByNrPassengers(&res, min_pass);
        this->empresa.removeByReservaPassengers(&res, data, data, horaIn, horaOut);


        if(res.empty())
            cout << "\n\nNo vehicles available with that criteria\n";
        else {
            for (VeiculoPassageiros *v : res) {

                v->print();
                cout << "--------" << endl;
            }
        }
    }
    else if(type == 2){

        cout << "\nWhat's the minimum weight capacity required? ";
        int min_weight;
        cin >> min_weight;

        cout << "\nWhat's the minimum volume capacity required? ";
        int min_vol;
        cin >> min_vol;

        cout << "\nIs referigeration required?(Y-N) ";
        char answer;
        cin >> answer;
        bool refri;
        if(answer == 'Y' || answer == 'y')
            refri = true;
        else if(answer == 'Y' || answer == 'y')
            refri = false;

        vector<VeiculoComercial *> res = this->empresa.getVeiculosComerciais();
        this->empresa.removeByWeight(&res, min_weight);
        this->empresa.removeByVolume(&res, min_vol);
        this->empresa.removeByRefri(&res, refri);
        this->empresa.removeByReservaComerciais(&res, data, data, horaIn, horaOut);


        for(VeiculoComercial *v : res){

            v->print();
            cout << "--------" << endl;
        }

    }

    cout << "Enter the id of the car you would like to rent: ";
    int id;
    cin >> id;

    Data in(data, horaIn);
    Data out(data, horaOut);

    //precos nao definidos para já
    Reserva *r = new Reserva(in,out, 100, false);


    for(int i =0; i < this->empresa.getClientes().size(); i++){

        if(this->empresa.getClientes().at(i)->getId() == this->visitanteAtual->getId())
            this->empresa.getClientes().at(i)->addReservas(r);

    }

    cout << "\n\nYour vehicle has been reservedd\n\n";
    choose();
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

        cout << "What do you wanna change? \n1-Brand\n2-Model\n3-Year\n4-Maximum Cargo volume\n5-Maximum cargo weight\n6-Referigeration ability\n";

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


        cout << "\nWhat do you wanna change? \n1-Brand\n2-Model\n3-Year\n4-Number of Passengers\n";

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

void Menu::seeReservations(){

    cout << "\n\nHere are your reservations: \n\n";

    Cliente *c;

    for(int i =0; i < this->empresa.getClientes().size(); i++){

        if(this->empresa.getClientes().at(i)->getId() == this->visitanteAtual->getId()) {
            c = this->empresa.getClientes().at(i);
        }

    }



    if(c->getReservas().empty())
        cout << "\nThere are no reservations.\n";
    else {

        for (int j = 0; j < c->getReservas().size(); j++) {

            cout << "\n\nReserva " << j << ": " << endl;

            for (Veiculo *v : this->empresa.getVeiculos()) {

                //Carro nao esta a imprimir
                for (Reserva *r : v->getReservas())
                    if (r == c->getReservas().at(j))
                        cout << "Carro: " << v->getMarca() << " " << v->getModelo() << " " << v->getAno() << endl;

            }

            c->getReservas().at(j)->print();

        }

    }

    choose();

}

int Menu::validCinInt()
{
    {
        int input = 0;
        bool valid = false;

        while (!valid)
        {
            cin >> input;
            if (!cin.good())
            {
                cin.clear();
                cout << "Invalid value. Please try again.\n";
            }
            valid = true;
            cin.ignore(10000, '\n');
        }
        return input;
    }
}
void Menu::registerClient() {
    string name, password, passConfirm;
    int nif, type, price, passengers, volume, weight, year;
    bool valid = false;
    bool fridge;
    cout << "Please insert your Name: ";
    getline(cin, name);
    cout << "Please enter your NIF: ";
    nif = validCinInt();
    while (!valid) {
        cout << "Please enter your password: ";
        getline(cin, password);
        cout << "Please enter your password again.";
        getline(cin, passConfirm);
        if (password == passConfirm) {
            valid = true;
        } else
            cout << "The passwords dont match, please try again." << endl;
    }
    valid = false;
    cout << "Do you want to rent passenger or commercial vehicles ?" << endl;
    cout << "Enter 1 for passenger vehicle" << endl;
    cout << "Enter 2 for comercial vehicle" << endl;
    while (!valid) {
        type = validCinInt();
        if (type == 1 || type == 2)
            valid = true;
        else {
            cout << "Invalid value. Please try again.\n";
        }
    }
    valid = false;

    cout << "In what range are you looking to spend? " << endl;
    cout << "Enter 1 for less than 20" << endl;
    cout << "Enter 2 for 20 to 40" << endl;
    cout << "Enter 3 over 40" << endl;
    while (!valid) {
        price = validCinInt();
        if (price == 1 || price == 2 || price == 3)
            valid = true;
        else {
            cout << "Invalid value. Please try again.\n";
        }
    }
    valid = false;
    cout << "from what range of years do you prefer your car" << endl;
    cout << "Enter 1 for older than 2000" << endl;
    cout << "Enter 2 for 2000 to 2010" << endl;
    cout << "Enter 3 newer than 2010" << endl;
    while (!valid) {
        year = validCinInt();
        if (price == 1 || price == 2 || price == 3)
            valid = true;
        else {
            cout << "Invalid value. Please try again.\n";
        }
    }
    valid = false;

    if (type == 1) {
        cout << "How many passengers do you usually travel with?" << endl;
        cout << "Enter 1 for Up to 1" << endl;
        cout << "Enter 2 for up to 4" << endl;
        cout << "Enter 3 for more than 5" << endl;
        while (!valid) {
            passengers = validCinInt();
            if (price == 1 || price == 2 || price == 3)
                valid = true;
            else {
                cout << "Invalid value. Please try again.\n";
            }
        }
        valid = false;
        string preferencias = to_string(type) + to_string(price) + to_string(year) + to_string(passengers);
        VisitanteRegistado *vr = new VisitanteRegistado(name, nif, preferencias, password);

        empresa.addVisitanteRegistado((*vr));
        cout << "Thank you for registering!" << endl;
        cout << "Your ID is: " << visitanteAtual->nrVisitantes - 1 << endl;
    } else {
        cout << "How much cargo weight do you usually travel with?" << endl;
        cout << "Enter 1 for Up to 50 " << endl;
        cout << "Enter 2 for between 50 and 150 " << endl;
        cout << "Enter 3 for more than 150" << endl;
        while (!valid) {
            weight = validCinInt();
            if (price == 1 || price == 2 || price == 3)
                valid = true;
            else {
                cout << "Invalid value. Please try again.\n";
            }
        }
        valid = false;

        cout << "How much cargo volume do you usually travel with?" << endl;
        cout << "Enter 1 for Up to 50 " << endl;
        cout << "Enter 2 for between 50 and 150 " << endl;
        cout << "Enter 3 for more than 150" << endl;
        while (!valid) {
            volume = validCinInt();
            if (price == 1 || price == 2 || price == 3)
                valid = true;
            else {
                cout << "Invalid value. Please try again.\n";
            }
        }
        valid = false;

        cout << "Do you need a refrigerated vehicle?" << endl;
        cout << "Enter 1 for yes " << endl;
        cout << "Enter 2 for no " << endl;
        while (!valid) {
            fridge = validCinInt();
            if (price == 1 || price == 2 || price == 3)
                valid = true;
            else {
                cout << "Invalid value. Please try again.\n";
            }
        }

        string preferencias =
                to_string(type) + to_string(price) + to_string(year) + to_string(weight) + to_string(volume) +
                to_string(fridge);
        VisitanteRegistado vr = VisitanteRegistado(name, nif, preferencias, password);
        empresa.addVisitanteRegistado(vr);
        cout << "Thank you for registering!" << endl;
        cout << "Your ID is: " << visitanteAtual->nrVisitantes - 1 << endl;
    }
    checkRegister();
}