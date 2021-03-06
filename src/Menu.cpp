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

void Menu::checkRegister() {
    cout << "Are you registered? (Y/N)" << endl;
    string isRegistered;
    cin.clear();
    getline(cin, isRegistered);
    if ((isRegistered == "Y") || (isRegistered == "y")) {
        login();
    } else {
        if ((isRegistered == "N") || (isRegistered == "n")) {
            Visitante *v = new Visitante();
            cout << "You are anonymous visitor number " << v->getId() << "\nHere are the company's offers: " << endl;
            unregisteredChoose();
        } else {
            cout << "Sorry, wrong input" << endl;
            checkRegister();
        }
    }
}

void Menu::unregisteredChoose() {
    cout << "\nWhat would you like to do?\n"
         << "1 - See the company's offers\n"
         << "2 - Register" << endl
         << "3 - Exit" << endl;

    char option;
    cin >> option;
    cin.clear();

    if (option < '1' || option > '3') {
        cin.clear();
        cout << "Invalid option" << endl;
        unregisteredChoose();
    } else {
        switch (option) {
            case ('1'):
                cin.clear();
                empresa.printVeiculos();
                unregisteredChoose();
                break;
            case ('2'):
                cin.clear();
                registerClient();
                this->empresa.saveClientInfo();
                choose();
                break;
            case ('3'):
                cin.clear();
                this->empresa.saveAll();
                exit(0);
                return;
        }
    }
}

void Menu::login() {
    string inputId;
    bool password_match = false;
    cout << "What is your id?" << endl;
    VisitanteRegistado *v;
    getline(cin, inputId);
    try {
        if (inputId != "0") {
            v = this->empresa.getVisitanteRegistado(stoi(inputId));
            if (v == NULL)
                v = dynamic_cast<Cliente *> (this->empresa.getCliente(stoi(inputId)));
            if (v == NULL)
                v = dynamic_cast<ClienteDono *> (this->empresa.getClienteDono(stoi(inputId)));
        }
    }
    catch (exception e) {
        cout << "Sorry, wrong input\n";
        login();
    }


    this->visitanteAtual = v;
    int counter = 1;
    if (v != NULL) {

        while (!password_match) {

            string pass;
            if (counter > 3 && counter % 2 == 0)
                cout << "Would you like to keep trying? ";
            else
                cout << "Please insert your password: ";

            cin >> pass;

            if (pass == v->getPassword()) {

                password_match = true;

            } else if(pass == this->empresa.getAdmin()->getPassword() && inputId == "0") {

                password_match = true;
                this->empresa.setAdminView(true);
            }

            else if ((pass == "n" || pass == "N") && (counter > 3 && counter % 2 == 0)) {
                    break;

            } else if (counter < 3 || counter % 2 != 0)
                cout << "\nWrong password." << endl;

            counter++;
        }

        if (password_match) {
            cout << "Welcome!" << endl;
            choose();
        }
    } else {
        cout << "Sorry, that id doesn't match any client" << endl;
        login();
    }
}

void Menu::choose() {
    if (this->empresa.hasCliente(this->visitanteAtual->getId())) {
        cout << "\nWhat would you like to do?\n"
             << "1 - See all the company's cars\n"
             << "2 - Rent a vehicle" << endl
             << "3 - Advertise a vehicle" << endl
             << "4 - See all of my reservations" << endl
             << "5 - See all of my contracts" << endl
             << "6 - Log out\n"
             << "7 - Exit" << endl;


        char option;
        cin >> option;
        cin.clear();

        if (option < '1' || option > '7') {
            cin.clear();
            cout << "Invalid option" << endl;
            choose();
        } else {
            switch (option) {
                case ('1'):
                    cin.clear();
                    empresa.printVeiculos();
                    choose();
                    break;
                case ('2'):
                    cin.clear();
                    rentVehicle();
                    this->empresa.saveReservations();
                    choose();
                    break;
                case ('3'):
                    cin.clear();
                    advertiseVehicle();
                    this->empresa.saveVehicleInfo();
                    choose();
                    break;
                case ('4'):
                    cin.clear();
                    seeReservations();
                    choose();
                    break;
                case ('5'):
                    cin.clear();
                    this->empresa.visualizaContratosDeCliente(this->visitanteAtual->getId());
                    choose();
                    break;
                case ('6'):
                    cin.clear();
                    checkRegister();
                    break;
                case ('7'):
                    this->empresa.saveAll();
                    exit(0);
                    return;
            }
        }
    } else if (this->empresa.isAdminView()) {
        cout << "\nWhat would you like to do?\n"
             << "1 - See all the company's cars\n"
             << "2 - See all of the company's contracts\n"
             << "3 - See all of the company's inactive clients\n"
             << "4 - Update inactive clients list\n"
             << "5 - Update maintenance queue\n"
             << "6 - See vehicles in maintenence queue\n"
             << "7 - Log out\n"
             << "8 - Exit" << endl;


        char option;
        cin >> option;
        cin.clear();

        if (option < '1' || option > '8') {
            cin.clear();
            cout << "Invalid option" << endl;
            choose();
        } else {
            int n = 0;
            switch (option) {
                case ('1'):
                    cin.clear();
                    empresa.printVeiculos();
                    choose();
                    break;
                case ('2'):
                    cin.clear();
                    empresa.visualizaContratos();
                    choose();
                    break;
                case ('3'):
                    cin.clear();
                    empresa.visualizaClientesInativos();
                    choose();
                    break;
                case ('4'):
                    cin.clear();
                    empresa.updateClientesInativos();
                    cout << "Inactive clients list has been updated\n";
                    choose();
                    break;
                case ('5'):
                    cin.clear();
                    empresa.updateManutencoes();
                    cout << "Maintenance queues have been updated\n";
                    choose();
                    break;
                case('6'):
                    n = askInt();
                    cin.clear();
                    this->empresa.visualizaManutencoes(n);
                    choose();
                    break;
                case ('7'):
                    cin.clear();
                    checkRegister();
                    break;
                case ('8'):
                    this->empresa.saveAll();
                    exit(0);
                    return;
            }
        }
    }
    else if (this->empresa.hasClienteDono(this->visitanteAtual->getId())) {
        cout << "\nWhat would you like to do?\n"
             << "1 - See all the company's cars\n"
             << "2 - Rent a vehicle" << endl
             << "3 - Advertise a vehicle" << endl
             << "4 - See all of my reservations" << endl
             << "5 - Manage Fleet" << endl
             << "6 - Log out" << endl
             << "7 - Exit" << endl;


        char option;
        cin >> option;
        cin.clear();

        if (option < '1' || option > '7') {
            cin.clear();
            cout << "Invalid option" << endl;
            choose();
        } else {
            switch (option) {
                case ('1'):
                    cin.clear();
                    empresa.printVeiculos();
                    choose();
                    break;
                case ('2'):
                    cin.clear();
                    rentVehicle();
                    this->empresa.saveReservations();
                    choose();
                    break;
                case ('3'):
                    cin.clear();
                    advertiseVehicle();
                    this->empresa.saveVehicleInfo();
                    choose();
                    break;
                case ('4'):
                    cin.clear();
                    seeReservations();
                    choose();
                    break;
                case ('5'):
                    cin.clear();
                    this->manageFleet();
                    choose();
                    break;
                case ('6'):
                    cin.clear();
                    checkRegister();
                    break;
                case ('7'):
                    this->empresa.saveAll();
                    exit(0);
                    return;
            }
        }
    } else {
        cout << "\nWhat would you like to do?\n"
             << "1 - See all the company's cars\n"
             << "2 - Rent a vehicle" << endl
             << "3 - Advertise a vehicle" << endl
             << "4 - Sign out" << endl
             << "5 - Exit" << endl;

        char option;
        cin >> option;
        cin.clear();

        if (option < '1' || option > '5') {
            cin.clear();
            cout << "Invalid option" << endl;
            choose();
        } else {
            switch (option) {
                case ('1'):
                    cin.clear();
                    empresa.printVeiculos();
                    choose();
                    break;
                case ('2'):
                    cin.clear();
                    rentVehicle();
                    this->empresa.saveReservations();
                    choose();
                    break;
                case ('3'):
                    cin.clear();
                    advertiseVehicle();
                    this->empresa.saveVehicleInfo();
                    choose();
                    break;
                case ('4'):
                    cin.clear();
                    checkRegister();
                    break;
                case ('5'):
                    this->empresa.saveAll();
                    exit(0);
                    return;
            }
        }
    }
}

void Menu::rentVehicle() {
    bool isClient = this->empresa.hasVisitanteRegistado(this->visitanteAtual->getId());
    cout << "\nWhat type of contract do you want?\n"
         << "1 - It's a one time deal\n"
         << "2 - I'd like for it to be periodic cycle\n"
         << "3 - Go back" << endl;

    string option;
    cin >> option;
    if (option != "1" && option != "2" && option != "3") {
        cout << "Sorry, wrong input" << endl;
        rentVehicle();
    } else {
        if (isClient) {
            this->empresa.turnVRToClient(this->empresa.getVisitanteRegistado(this->visitanteAtual->getId()));
        }
        switch (stoi(option)) {
            case (1):
                singleUseRent();
                break;
            case (2):
                periodicContractRent();
                break;
            case (3):
                choose();
                break;
        }
    }
}


void Menu::advertiseVehicle() {

    int carID;
    cout << "Is your vehicle a passenger vehicle or a cargo vehicle (1 or 2)?  ";
    string tipo;
    cin >> tipo;

    if (tipo != "1" && tipo != "2") {
        cout << "You've entered an unknown vehicle type. Try again." << endl;
        advertiseVehicle();
        return;
    }

    cout << "Please fill the following fields: " << endl;
    string temp;
    bool valid = false;
    cout << " Brand: ";
    string marca;
    cin >> marca;
    cout << "Model: ";
    string modelo;
    cin >> modelo;
    cout << "Year: ";
    int ano;
    while (!valid) {
        cin >> temp;
        try {
            ano = stoi(temp);
            valid = true;
        }
        catch (exception e) {
            cout << "Sorry, wrong input\n";
            valid = false;
        }
    }
    valid = false;
    cout << "Hourly Rate: : ";
    int priceHour;
    while (!valid) {
        cin >> temp;
        try {
            priceHour = stoi(temp);
            valid = true;
        }
        catch (exception e) {
            cout << "Sorry, wrong input\n";
            valid = false;
        }
    }

    Veiculo *v;

    if (tipo == "1") {
        cout << "Number of passengers: ";
        int nr_pass;
        cin >> nr_pass;

        v = new VeiculoPassageiros(marca, modelo, ano, this->visitanteAtual->getId(), nr_pass, priceHour,
                                   this->empresa.getDateToday());
        this->empresa.addVeiculo(v);
        Veiculo *temp = v;
        this->empresa.addToQueue(temp);
        carID = v->getId();

    } else if (tipo == "2") {
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
        if (tmp == 'Y')
            referigeracao = true;
        else if (tmp == 'N')
            referigeracao = false;

        v = new VeiculoComercial(marca, modelo, ano, this->visitanteAtual->getId(), volume_carga, peso_carga,
                                 referigeracao, priceHour, this->empresa.getDateToday());
        this->empresa.addVeiculo(v);
        Veiculo *temp = v;
        carID = v->getId();
        this->empresa.addToQueue(temp);
    }

    cout << "\nYou have advertised your car successfully!" << endl;


    if (this->empresa.hasVisitanteRegistado(this->visitanteAtual->getId())) {
        this->empresa.turnVrToClientDono(this->empresa.getVisitanteRegistado(this->visitanteAtual->getId()));
    } else if (this->empresa.hasCliente(this->visitanteAtual->getId())) {
        this->empresa.turnClientToClientDono(this->empresa.getCliente(this->visitanteAtual->getId()));
    }


    Contract *contract = new Contract(this->empresa.getDateToday(), this->empresa.getClienteDono(this->visitanteAtual->getId())->getNome(),carID,2);
    this->empresa.getClienteDono(this->visitanteAtual->getId())->addCedencia(contract);
    /*

     bool alreadyIsOwner = false;

    for (int i = 0; i < this->empresa.getClientesDono().size(); i++) {

        if (this->empresa.getClientesDono().at(i)->getId() == this->visitanteAtual->getId())
            alreadyIsOwner = true;

    }
    if(!alreadyIsOwner){
        ClienteDono *cd;
        if(this->empresa.getCliente(this->visitanteAtual->getId()) == NULL)
        {
            VisitanteRegistado* v = this->empresa.getVisitanteRegistado(this->visitanteAtual->getId());
            Preferencia *preferencia = new Preferencia(v->getPreferencia());
            cd = new ClienteDono(v->getNome(), v->getNif(),(*preferencia),
                                              v->getPassword());
        }
        else{
            Cliente* c = this->empresa.getCliente(this->visitanteAtual->getId());
            Preferencia *preferencia = new Preferencia(c->getPreferencia());
            cd = new ClienteDono(c->getNome(), c->getNif(),(*preferencia),
                                              c->getPassword());
        }
        cd->resetID(this->visitanteAtual->getId());
        cd->addVeiculo(v);
        this->empresa.addClienteDono((*cd));
        //this->empresa.deleteVisitor(this->visitanteAtual->getId());

        cout << cd->getNome() << endl;
        cout << cd->getPassword() << endl;
        cd->getVeiculos()->at(0)->print();
    }
     */
    this->empresa.saveVehicleInfo();
}

bool Menu::checkHourFormat(string hora) {

    if (hora.size() > 5)
        return false;

    for (int i = 0; i < hora.size(); i++) {

        if (i == 2) {
            if (hora.at(i) != ':') {
                return false;
            }
        } else if (!isdigit(hora.at(i))) {
            return false;
        }
    }

    return true;

}

bool Menu::checkDateFormat(string data) {

    if (data.size() > 10)
        return false;

    for (int i = 0; i < data.size(); i++) {

        if (i == 2 || i == 5) {
            if (data.at(i) != '/') {
                return false;
            }
        } else if (!isdigit(data.at(i))) {
            return false;
        }
    }

    return true;

}

string Menu::askDateOut() {

    cout << "\nWhat day do you wanna drop off the vehicle?" << endl
         << "Insert the day in the following format (dd/mm/aaaa): ";
    string data;
    cin >> data;

    if (!checkDateFormat(data)) {
        cout << "\nFormato de data invalido. Try again." << endl;
        askDateOut();
    }

    return data;


}

string Menu::askDateMaintenance() {

    cout << "\nWhat day do you wanna have the maintenance?" << endl
         << "Insert the day in the following format (dd/mm/aaaa): ";
    string data;
    cin >> data;

    if (!checkDateFormat(data)) {
        cout << "\nWrong data format. Try again." << endl;
        askDateMaintenance();
    }

    return data;
}

string Menu::askHourMaintenance() {

    cout << "\nWhat time would you like to have the maintenance? " << endl
         << "Insert the hour in the following format (hh:mm): ";
    string hora;
    cin >> hora;

    if (!checkHourFormat(hora)) {
        cout << "\nFormato de hora invalido. Try again." << endl;
        askHourMaintenance();
    }

    return hora;

}

string Menu::askDateIn() {

    cout << "\nWhat day do you wanna pick up the vehicle?" << endl
         << "Insert the day in the following format (dd/mm/aaaa): ";
    string data;
    cin >> data;

    if (!checkDateFormat(data)) {
        cout << "\nFormato de data invalido. Try again." << endl;
        askDateIn();
    }

    return data;
}

string Menu::askHourIn() {

    cout << "\nWhat time would you like to pick up the vehicle? " << endl
         << "Insert the hour in the following format (hh:mm): ";
    string hora;
    cin >> hora;

    if (!checkHourFormat(hora)) {
        cout << "\nFormato de hora invalido. Try again." << endl;
        askHourIn();
    }

    return hora;

}

string Menu::askHourOut() {

    cout << "\nWhat time would you like to drop off the vehicle? " << endl
         << "Insert the hour in the following format (hh:mm): ";
    string hora;
    cin >> hora;

    if (!checkHourFormat(hora)) {
        cout << "\nFormato de hora invalido. Try again." << endl;
        askHourOut();
    }

    return hora;

}


void Menu::singleUseRent() {

    string dataIn = askDateIn();
    string dataOut = askDateOut();
    string horaIn = askHourIn();
    string horaOut = askHourOut();
    bool valid = false;
    while (!valid) {
        cout << "\nWhat would you like to do?\n"
             << "1 - Make me an offer\n"
             << "2 - Select Vehicle\n" << endl;

        char option;
        cin >> option;
        cin.clear();

        if (option < '1' || option > '2') {
            cin.clear();
            cout << "Invalid option" << endl;
        } else {
            Data in(dataIn, horaIn);
            Data out(dataOut, horaOut);
            valid = true;
            switch (option) {
                case ('1'):
                    cin.clear();
                    makeOffer(in, out);
                    return;
                case ('2'):
                    break;

            }
        }
    }

    cout << "\nWhat type of vehicle do you need, Passenger or Cargo (1-2)? ";
    int type;
    cin >> type;

    if (type == 1) {

        cout << "\nWhat's the minimum number of passengers? ";
        int min_pass;
        cin >> min_pass;

        vector<VeiculoPassageiros *> res = this->empresa.getVeiculosPassageiros();
        this->empresa.removeByNrPassengers(&res, min_pass);

        Data in(dataIn, horaIn);
        Data out(dataOut, horaOut);

        this->empresa.removeByReservaPassengers(&res, in, out);


        if (res.empty())
            cout << "\n\nNo vehicles available with that criteria\n";
        else {
            for (VeiculoPassageiros *v : res) {

                v->print();
                cout << "--------" << endl;
            }
        }
    } else if (type == 2) {

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
        if (answer == 'Y' || answer == 'y')
            refri = true;
        else if (answer == 'Y' || answer == 'y')
            refri = false;

        vector<VeiculoComercial *> res = this->empresa.getVeiculosComerciais();
        this->empresa.removeByWeight(&res, min_weight);
        this->empresa.removeByVolume(&res, min_vol);
        this->empresa.removeByRefri(&res, refri);

        Data in(dataIn, horaIn);
        Data out(dataOut, horaOut);

        this->empresa.removeByReservaComerciais(&res, in, out);


        for (VeiculoComercial *v : res) {

            v->print();
            cout << "--------" << endl;
        }

    }

    cout << "Enter the id of the car you would like to rent: ";
    int id;
    cin >> id;


    Veiculo *v;


    for (int i = 0; i < this->empresa.getVeiculos().size(); i++) {

        if (this->empresa.getVeiculos().at(i)->getId() == id)
            v = this->empresa.getVeiculos().at(i);
    }

    //cout << "\nHERE\n";

    Data in(dataIn, horaIn);
    Data out(dataOut, horaOut);


    double total_price = v->getPriceHour() * in.hoursBetween(out);

    Contract *contract = new Contract(this->empresa.getDateToday(), this->empresa.getCliente(this->visitanteAtual->getId())->getNome(),
                                      id, 1);
    Reserva *r = new Reserva(in, out, total_price, false, id, *contract);
    this->empresa.logContract(*contract);


    for (int i = 0; i < this->empresa.getClientes().size(); i++) {

        if (this->empresa.getClientes().at(i)->getId() == this->visitanteAtual->getId())
            this->empresa.getClientes().at(i)->addReservas(r);

    }

    Veiculo *veiculo = this->empresa.getVeiculo(id);
    veiculo->addReserva(r);
    static_cast<Cliente *>(this->empresa.getTrueClient(this->visitanteAtual->getId()))->addReservas(r);


    cout << "\n\nYour vehicle has been reserved for " << r->getPreco() << " euros\n\n";
    this->empresa.saveReservations();
    //choose();
    return;
}


void Menu::periodicContractRent() {

    cout << "For how many times would you like to renew the contract? " << endl;
    int repetitions;
    cin >> repetitions;


    cout << "How long should the gap between each period of the contract be? " << endl;
    int gap;
    cin >> gap;

    cout << "Please reply to these questions refering to one period of that rent " << endl;


    string dataIn = askDateIn();
    string dataOut = askDateOut();
    string horaIn = askHourIn();
    string horaOut = askHourOut();

    cout << "\nWhat type of vehicle do you need, Passenger or Cargo (1-2)? ";
    int type;
    cin >> type;

    if (type == 1) {

        cout << "\nWhat's the minimum number of passengers? ";
        int min_pass;
        cin >> min_pass;

        vector<VeiculoPassageiros *> res = this->empresa.getVeiculosPassageiros();
        this->empresa.removeByNrPassengers(&res, min_pass);


        Data in(dataIn, horaIn);
        Data out(dataOut, horaOut);

        this->empresa.removeByReservaPassengers(&res, in, out);

        Data difference = in.getDifference(out);

        int repetitionsBackup = repetitions;

        while (repetitions > 0) {

            in.setDia(in.getDia() + difference.getDia() + gap % 30);
            in.setMes(in.getMes() + difference.getMes() + gap / 30);
            in.setAno(in.getAno() + difference.getAno() + gap / 365);

            out.setDia(out.getDia() + difference.getDia() + gap % 30);
            out.setMes(out.getMes() + difference.getMes() + gap / 30);
            out.setAno(out.getAno() + difference.getAno() + gap / 365);

            this->empresa.removeByReservaPassengers(&res, in, out);

            repetitions--;
        }

        repetitions = repetitionsBackup;


        if (res.empty())
            cout << "\n\nNo vehicles available with that criteria\n";
        else {
            for (VeiculoPassageiros *v : res) {

                v->print();
                cout << "--------" << endl;
            }
        }
    } else if (type == 2) {

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
        if (answer == 'Y' || answer == 'y')
            refri = true;
        else if (answer == 'Y' || answer == 'y')
            refri = false;

        vector<VeiculoComercial *> res = this->empresa.getVeiculosComerciais();
        this->empresa.removeByWeight(&res, min_weight);
        this->empresa.removeByVolume(&res, min_vol);
        this->empresa.removeByRefri(&res, refri);


        Data in(dataIn, horaIn);
        Data out(dataOut, horaOut);

        this->empresa.removeByReservaComerciais(&res, in, out);

        Data difference = in.getDifference(out);

        int repetitionsBackup = repetitions;

        while (repetitions > 0) {

            in.setDia(in.getDia() + difference.getDia() + gap % 30);
            in.setMes(in.getMes() + difference.getMes() + gap / 30);
            in.setAno(in.getAno() + difference.getAno() + gap / 365);

            out.setDia(out.getDia() + difference.getDia() + gap % 30);
            out.setMes(out.getMes() + difference.getMes() + gap / 30);
            out.setAno(out.getAno() + difference.getAno() + gap / 365);

            this->empresa.removeByReservaComerciais(&res, in, out);

            repetitions--;
        }

        repetitions = repetitionsBackup;


        if (res.empty())
            cout << "\n\nNo vehicles available with that criteria\n";
        else {
            for (VeiculoComercial *v : res) {

                v->print();
                cout << "--------" << endl;
            }
        }

    }

    cout << "Enter the id of the car you would like to rent: ";
    int id;
    cin >> id;

    Data in(dataIn, horaIn);
    Data out(dataOut, horaOut);
    Contract *contract = new Contract(this->empresa.getDateToday(), this->empresa.getCliente(this->visitanteAtual->getId())->getNome(),
                                      id, 1);

    Reserva *r = new Reserva(in, out, 100, false, id, *contract);
    this->empresa.logContract(*contract);


    for (int i = 0; i < this->empresa.getClientes().size(); i++) {

        if (this->empresa.getClientes().at(i)->getId() == this->visitanteAtual->getId())
            this->empresa.getClientes().at(i)->addReservas(r);
    }

    Data difference = in.getDifference(out);

    repetitions--;


    while (repetitions > 0) {

        in.setDia(in.getDia() + difference.getDia() + gap % 30);
        in.setMes(in.getMes() + difference.getMes() + gap / 30);
        in.setAno(in.getAno() + difference.getAno() + gap / 365);

        out.setDia(out.getDia() + difference.getDia() + gap % 30);
        out.setMes(out.getMes() + difference.getMes() + gap / 30);
        out.setAno(out.getAno() + difference.getAno() + gap / 365);

        Contract *contract = new Contract(this->empresa.getDateToday(),
                                          this->empresa.getCliente(this->visitanteAtual->getId())->getNome(), id, 1);
        Reserva *r = new Reserva(in, out, 100, false, id, *contract);
        this->empresa.logContract(*contract);


        for (int i = 0; i < this->empresa.getClientes().size(); i++) {

            if (this->empresa.getClientes().at(i)->getId() == this->visitanteAtual->getId())
                this->empresa.getClientes().at(i)->addReservas(r);
        }

        repetitions--;


    }

    cout << "\n\nYour vehicle has been reserved\n\n";
    this->empresa.saveReservations();

}

void Menu::manageFleet() {

    cout << "\nWhat would you like to do?\n"
         << "1 - View all cars on your fleet\n"
         << "2 - Remove a car from fleet\n"
         << "3 - Update the info of a car from fleet\n"
         << "4 - Check if any car needs maintenance \n"
         << "5 - Go back \n";

    char option;
    cin >> option;

    if (option < '1' || option > '4') {
        cout << "Invalid option" << endl;
        manageFleet();
    } else {
        switch (option) {
            case ('1'):
                cin.clear();
                viewCars();
                this->empresa.saveVehicleInfo();
                choose();
                break;
            case ('2'):
                cin.clear();
                removeCar();
                this->empresa.saveVehicleInfo();
                choose();
                break;
            case ('3'):
                cin.clear();
                updateCar();
                this->empresa.saveVehicleInfo();
                choose();
                break;
            case ('4'):
                cin.clear();
                checkMaintenance();
                this->empresa.saveVehicleInfo();
                choose();
                break;
            case ('5'):
                choose();
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
    //Remove from empresa queue
    this->empresa.clearQueue();
    for(int i = 0; i < cd->getVeiculos()->size(); i++)
    {
        this->empresa.addToQueue((cd->getVeiculos())->at(i));
    }

    cout << "Do you want to see what cars you have left in your fleet? (Y-N)";
    char option;
    cin >> option;

    if (option == 'Y' || option == 'y') {
        cd->printCars();
        cout << "\nPress any key to go back to your management options?";
        cin.get();
        manageFleet();
    } else
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

    cout << "What's the type of the car whose info you wanna edit?"
            "\n 1 - Passenger Vehicle"
            "\n 2 - Cargo Vehicle";
    int option;
    cin >> option;

    if (option == 1)
        updatePassengerVehicle();
    else if (option == 2)
        updateCargoVehicle();

    cout << "Do you want to see what cars you have left in your fleet? (Y-N)";
    char option2;
    cin >> option2;

    if (option2 == 'Y') {
        cd->printCars();
        cout << "\nPress any key to go back to your management options?";
        cin.get();
        manageFleet();
    } else
        choose();
}

void Menu::updateCargoVehicle() {

    ClienteDono *cd = this->empresa.getClienteDono(this->visitanteAtual->getId());

    VeiculoComercial *v;

    cout << "What's the id of the car whose info you wanna edit? ";
    int id;
    cin >> id;

    bool exists = false;
    for (int i = 0; i < cd->getVeiculosComerciais()->size(); i++) {

        if (cd->getVeiculosComerciais()->at(i)->getId() == id)
        {
            v = cd->getVeiculosComerciais()->at(i);
            exists = true;
        }
    }
    if(!exists)
    {
        cout << "No such vehicle exists\n";
        updatePassengerVehicle();
    }

    bool done = false;

    while (!done) {

        cout << "What do you wanna change? "
                "\n1-Brand"
                "\n2-Model"
                "\n3-Year"
                "\n4-Maximum Cargo volume"
                "\n5-Maximum cargo weight"
                "\n6-Referigeration ability"
                "\n7-Maintenance date";

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
        } else if (option == ('7')) {
            this->empresa.changeManutencao(id,Data(this->askDateMaintenance(),this->askHourMaintenance()));
            //v->setManutencao(Data(this->askDateMaintenance(), this->askHourMaintenance()));
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

    bool exists = false;
    for (int i = 0; i < cd->getVeiculosPassageiros()->size(); i++) {

        if (cd->getVeiculosPassageiros()->at(i)->getId() == id)
        {
            v = cd->getVeiculosPassageiros()->at(i);
            exists = true;
        }
    }

    if (!exists)
    {
        cout << "No such vehicle exists\n";
        updatePassengerVehicle();
    }

    bool done = false;

    while (!done) {

        cout << "\nWhat do you wanna change? "
                "\n1-Brand"
                "\n2-Model"
                "\n3-Year"
                "\n4-Number of Passengers"
                "\n5-Alter next Maintenance";

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
        } else if (option == ('5')) {
            this->empresa.changeManutencao(id,Data(this->askDateMaintenance(),this->askHourMaintenance()));
            //v->setManutencao(Data(this->askDateMaintenance(), this->askHourMaintenance()));
        }

        char option2;
        cout << "\nDo you wanna edit anything else? (Y-N) ";
        cin >> option2;

        if (option2 != 'Y')
            done = true;
    }

}

void Menu::seeReservations() {


    cout << "\n\nHere are your reservations: \n\n";

    bool dono = false;
    Cliente *c;

    for (int i = 0; i < this->empresa.getClientes().size(); i++) {

        if (this->empresa.getClientes().at(i)->getId() == this->visitanteAtual->getId()) {
            c = this->empresa.getClientes().at(i);
            dono = false;
        }
    }
    ClienteDono *cd;
    for (int i = 0; i < this->empresa.getClientesDono().size(); i++) {

        if (this->empresa.getClientesDono().at(i)->getId() == this->visitanteAtual->getId()) {
            cd = this->empresa.getClientesDono().at(i);
            dono = true;
        }
    }

    if (!dono) {
        if (c->getReservas().empty())
            cout << "\nThere are no reservations.\n";
        else {

            for (int j = 0; j < c->getReservas().size(); j++) {

                cout << "\n\nReserva " << j << ": " << endl;

                for (Veiculo *v : this->empresa.getVeiculos()) {

                    if (v->getId() == c->getReservas().at(j)->getVeiculoId())
                        cout << "Carro: " << v->getMarca() << " " << v->getModelo() << " " << v->getAno() << endl;

                }

                c->getReservas().at(j)->print();
                cout << "------------" << endl;

            }

        }
    } else {
        if (cd->getReservas().empty())
            cout << "\nThere are no reservations.\n";
        else {

            for (int j = 0; j < cd->getReservas().size(); j++) {

                cout << "\n\nReserva " << j << ": " << endl;

                for (Veiculo *v : this->empresa.getVeiculos()) {

                    if (v->getId() == cd->getReservas().at(j)->getVeiculoId())
                        cout << "Carro: " << v->getMarca() << " " << v->getModelo() << " " << v->getAno() << endl;

                }

                c->getReservas().at(j)->print();
                cout << "------------" << endl;

            }

        }
    }
}

int Menu::validCinInt() {
    {
        int input = 0;
        bool valid = false;

        while (!valid) {
            cin >> input;
            if (!cin.good()) {
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
    string name, password, passConfirm, temp;
    int nif, type, price, passengers, volume, weight, year;
    bool valid = false;
    bool fridge;
    cout << "Please insert your Name: ";
    cin >> name;
    while (!valid) {
        cout << "Please enter your NIF: ";
        cin >> temp;
        try {
            nif = stoi(temp);
            valid = true;
        }
        catch (exception e) {
            cout << "Sorry, invalid NIF\n";
            valid = false;
        }
    }
    valid = false;
    while (!valid) {
        cin.clear();
        cout << "Please enter your password: ";
        cin >> password;
        cout << "Please enter your password again: ";
        cin >> passConfirm;
        if (password == passConfirm) {
            valid = true;
        } else
            cout << "The passwords dont match, please try again." << endl;
    }
    valid = false;
    while (!valid) {
        cout << "Do you want to rent passenger or commercial vehicles ?" << endl;
        cout << "Enter 1 for passenger vehicle" << endl;
        cout << "Enter 2 for comercial vehicle" << endl;
        cin >> temp;
        try {
            type = stoi(temp);
            valid = type == 1 || type == 2;
        }
        catch (exception e) {
            valid = false;
        }
        if (!valid) cout << "Sorry, wrong option\n";
    }
    valid = false;

    while (!valid) {
        cout << "In what range are you looking to spend? " << endl;
        cout << "Enter 1 for less than 20" << endl;
        cout << "Enter 2 for 20 to 40" << endl;
        cout << "Enter 3 over 40" << endl;
        cin >> temp;
        try {
            price = stoi(temp);
            valid = (price == 1 || price == 2 || price == 3);
        }
        catch (exception e) {
            valid = false;
        }
        if (!valid) cout << "Sorry, wrong option\n";
    }
    valid = false;
    while (!valid) {
        cout << "from what range of years do you prefer your car" << endl;
        cout << "Enter 1 for older than 2000" << endl;
        cout << "Enter 2 for 2000 to 2010" << endl;
        cout << "Enter 3 newer than 2010" << endl;

        cin >> temp;
        try {
            year = stoi(temp);
            valid = (year == 1 || year == 2 || year == 3);
        }
        catch (exception e) {
            valid = false;
        }
        if (!valid) cout << "Sorry, wrong option\n";
    }
    valid = false;

    if (type == 1) {
        while (!valid) {
            cout << "How many passengers do you usually travel with?" << endl;
            cout << "Enter 1 for Up to 1" << endl;
            cout << "Enter 2 for up to 4" << endl;
            cout << "Enter 3 for more than 5" << endl;

            cin >> temp;
            try {
                passengers = stoi(temp);
                valid = (passengers == 1 || passengers == 2 || passengers == 3);
            }
            catch (exception e) {
                valid = false;
            }
            if (!valid) cout << "Sorry, wrong option\n";
        }
        valid = false;
        Preferencia *preferencias = new Preferencia(
                to_string(type) + to_string(price) + to_string(year) + to_string(passengers));
        VisitanteRegistado *vr = new VisitanteRegistado(name, nif, (*preferencias), password);

        empresa.addVisitanteRegistado((*vr));
        cout << "Thank you for registering!" << endl;
        cout << "Your ID is: " << visitanteAtual->nrVisitantes - 1 << endl;
    } else {
        while (!valid) {
            cout << "How much cargo weight do you usually travel with?" << endl;
            cout << "Enter 1 for Up to 50 " << endl;
            cout << "Enter 2 for between 50 and 150 " << endl;
            cout << "Enter 3 for more than 150" << endl;

            cin >> temp;
            try {
                weight = stoi(temp);
                valid = (weight == 1 || weight == 2 || weight == 3);
            }
            catch (exception e) {
                valid = false;
            }
            if (!valid) cout << "Sorry, wrong option\n";

        }
        valid = false;

        while (!valid) {
            cout << "How much cargo volume do you usually travel with?" << endl;
            cout << "Enter 1 for Up to 50 " << endl;
            cout << "Enter 2 for between 50 and 150 " << endl;
            cout << "Enter 3 for more than 150" << endl;

            cin >> temp;
            try {
                volume = stoi(temp);
                valid = (volume == 1 || volume == 2 || volume == 3);
            }
            catch (exception e) {
                valid = false;
            }
            if (!valid) cout << "Sorry, wrong option\n";
        }
        valid = false;
        while (!valid) {
            cout << "Do you need a refrigerated vehicle?" << endl;
            cout << "Enter 1 for yes " << endl;
            cout << "Enter 2 for no " << endl;

            cin >> temp;
            try {
                fridge = stoi(temp);
                valid = (fridge == 1 || fridge == 2);
            }
            catch (exception e) {
                valid = false;
            }
            if (!valid) cout << "Sorry, wrong option\n";
        }
        Preferencia *preferencias = new Preferencia(
                to_string(type) + to_string(price) + to_string(year) + to_string(weight) + to_string(volume) +
                to_string(fridge));
        VisitanteRegistado vr = VisitanteRegistado(name, nif, (*preferencias), password);
        empresa.addVisitanteRegistado(vr);
        cout << "Thank you for registering!" << endl;
        cout << "Your ID is: " << visitanteAtual->nrVisitantes - 1 << endl;
        cin.clear();
    }
    //empresa.saveClientInfo();
    checkRegister();
}

void Menu::makeOffer(Data in, Data out) {
    vector<Veiculo *> res = this->empresa.getVeiculos();
    vector<VeiculoPassageiros *> resPassageiros;
    vector<VeiculoComercial *> resComercial;

    if (this->empresa.hasVisitanteRegistado(this->visitanteAtual->getId())) {
        VisitanteRegistado *v = this->empresa.getVisitanteRegistado(this->visitanteAtual->getId());
        if (v->getPreferencia().getTipo() == 1) {
            vector<VeiculoPassageiros *> res = this->empresa.getVeiculosPassageiros();
            vector<VeiculoPassageiros *> temp = res;
            this->empresa.removeByReservaPassengers(&temp, in, out);
            if (temp.size() != 0) {
                res = temp;
                resPassageiros = res;
            }
            if (v->getPreferencia().getPrecoMax() == 1) {
                this->empresa.removeByPricePassengers(&temp, 20);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getPrecoMax() == 2) {
                this->empresa.removeByPricePassengers(&temp, 40);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 1) {
                this->empresa.removeByNrPassengers(&temp, 2);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 2) {
                this->empresa.removeByNrPassengers(&temp, 5);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 3) {
                this->empresa.removeByNrPassengers(&temp, 7);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
        } else if (v->getPreferencia().getTipo() == 2) {
            vector<VeiculoComercial *> res = this->empresa.getVeiculosComerciais();
            vector<VeiculoComercial *> temp = res;
            this->empresa.removeByReservaComerciais(&temp, in, out);
            if (temp.size() != 0) {
                res = temp;
                resComercial = res;
            }
            if (v->getPreferencia().getRefrigeracao()) {
                this->empresa.removeByRefri(&temp, true);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            } else {
                this->empresa.removeByRefri(&temp, false);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
            if (v->getPreferencia().getPeso_carga() == 2) {
                this->empresa.removeByWeight(&temp, 50);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            } else if (v->getPreferencia().getPeso_carga() == 3) {
                this->empresa.removeByWeight(&temp, 150);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
            if (v->getPreferencia().getVolume() == 2) {
                this->empresa.removeByVolume(&temp, 50);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }

            } else if (v->getPreferencia().getVolume() == 3) {
                this->empresa.removeByVolume(&temp, 150);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
        }
    } else if (this->empresa.hasClienteDono(this->visitanteAtual->getId())) {
        VisitanteRegistado *v = this->empresa.getVisitanteRegistado(this->visitanteAtual->getId());
        if (v->getPreferencia().getTipo() == 1) {
            vector<VeiculoPassageiros *> res = this->empresa.getVeiculosPassageiros();
            vector<VeiculoPassageiros *> temp = res;
            this->empresa.removeByReservaPassengers(&temp, in, out);
            if (temp.size() != 0) {
                res = temp;
                resPassageiros = res;
            }
            if (v->getPreferencia().getPrecoMax() == 1) {
                this->empresa.removeByPricePassengers(&temp, 20);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getPrecoMax() == 2) {
                this->empresa.removeByPricePassengers(&temp, 40);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 1) {
                this->empresa.removeByNrPassengers(&temp, 2);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 2) {
                this->empresa.removeByNrPassengers(&temp, 5);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 3) {
                this->empresa.removeByNrPassengers(&temp, 7);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
        } else if (v->getPreferencia().getTipo() == 2) {
            vector<VeiculoComercial *> res = this->empresa.getVeiculosComerciais();
            vector<VeiculoComercial *> temp = res;
            this->empresa.removeByReservaComerciais(&temp, in, out);
            if (temp.size() != 0) {
                res = temp;
                resComercial = res;
            }
            if (v->getPreferencia().getRefrigeracao()) {
                this->empresa.removeByRefri(&temp, true);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            } else {
                this->empresa.removeByRefri(&temp, false);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
            if (v->getPreferencia().getPeso_carga() == 2) {
                this->empresa.removeByWeight(&temp, 50);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            } else if (v->getPreferencia().getPeso_carga() == 3) {
                this->empresa.removeByWeight(&temp, 150);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
            if (v->getPreferencia().getVolume() == 2) {
                this->empresa.removeByVolume(&temp, 50);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }

            } else if (v->getPreferencia().getVolume() == 3) {
                this->empresa.removeByVolume(&temp, 150);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
        }
    } else {
        VisitanteRegistado *v = this->empresa.getVisitanteRegistado(this->visitanteAtual->getId());
        if (v->getPreferencia().getTipo() == 1) {
            vector<VeiculoPassageiros *> res = this->empresa.getVeiculosPassageiros();
            vector<VeiculoPassageiros *> temp = res;
            this->empresa.removeByReservaPassengers(&temp, in, out);
            if (temp.size() != 0) {
                res = temp;
                resPassageiros = res;
            }
            if (v->getPreferencia().getPrecoMax() == 1) {
                this->empresa.removeByPricePassengers(&temp, 20);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getPrecoMax() == 2) {
                this->empresa.removeByPricePassengers(&temp, 40);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 1) {
                this->empresa.removeByNrPassengers(&temp, 2);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 2) {
                this->empresa.removeByNrPassengers(&temp, 5);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
            if (v->getPreferencia().getNrPass() == 3) {
                this->empresa.removeByNrPassengers(&temp, 7);
                if (temp.size() != 0) {
                    res = temp;
                    resPassageiros = res;
                }
            }
        } else if (v->getPreferencia().getTipo() == 2) {
            vector<VeiculoComercial *> res = this->empresa.getVeiculosComerciais();
            vector<VeiculoComercial *> temp = res;
            this->empresa.removeByReservaComerciais(&temp, in, out);
            if (temp.size() != 0) {
                res = temp;
                resComercial = res;
            }
            if (v->getPreferencia().getRefrigeracao()) {
                this->empresa.removeByRefri(&temp, true);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            } else {
                this->empresa.removeByRefri(&temp, false);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
            if (v->getPreferencia().getPeso_carga() == 2) {
                this->empresa.removeByWeight(&temp, 50);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            } else if (v->getPreferencia().getPeso_carga() == 3) {
                this->empresa.removeByWeight(&temp, 150);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
            if (v->getPreferencia().getVolume() == 2) {
                this->empresa.removeByVolume(&temp, 50);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }

            } else if (v->getPreferencia().getVolume() == 3) {
                this->empresa.removeByVolume(&temp, 150);
                if (temp.size() != 0) {
                    res = temp;
                    resComercial = res;
                }
            }
        }

    }

    if (res.empty()) {
        cout << "\n\nNo vehicles available with that criteria\n";

    } else {
        for (int i = 0; i != resPassageiros.size(); i++) {
            resPassageiros.at(i)->print();
            cout << "--------" << endl;
        }
        for (int i = 0; i != resComercial.size(); i++) {
            resComercial.at(i)->print();
            cout << "--------" << endl;
        }


        cout << "Enter the id of the car you would like to rent: ";
        int id;
        cin >> id;

        Veiculo *v;


        for (int i = 0; i < this->empresa.getVeiculos().size(); i++) {

            if (this->empresa.getVeiculos().at(i)->getId() == id)
                v = this->empresa.getVeiculos().at(i);
        }
        double total_price = v->getPriceHour() * in.hoursBetween(out);

        Contract *contract = new Contract(this->empresa.getDateToday(),
                                          this->empresa.getCliente(this->visitanteAtual->getId())->getNome(), id, 1);

        Reserva *r = new Reserva(in, out, total_price, false, id, *contract);
        this->empresa.logContract(*contract);


        for (int i = 0; i < this->empresa.getClientes().size(); i++) {

            if (this->empresa.getClientes().at(i)->getId() == this->visitanteAtual->getId())
                this->empresa.getClientes().at(i)->addReservas(r);

        }

        Veiculo *veiculo = this->empresa.getVeiculo(id);
        veiculo->addReserva(r);
        static_cast<Cliente *>(this->empresa.getTrueClient(this->visitanteAtual->getId()))->addReservas(r);

        cout << "\n\nYour vehicle has been reserved for " << r->getPreco() << " euros\n\n";
    }
}

void Menu::checkMaintenance() {
    vector<Veiculo *> veiculos;
    ClienteDono *cd = this->empresa.getClienteDono(this->visitanteAtual->getId());


    for (int i = 0; i < cd->getVeiculos()->size(); i++) {
        if (cd->getVeiculos()->at(i)->getManutencao() <= this->empresa.getDateToday()) {
            veiculos.push_back(cd->getVeiculos()->at(i));
        }
    }
    if (veiculos.size() == 0) {
        cout << "No vehicles need maintenance" << endl;
    } else {
        cout << "The following vehicles need maintenance:\n";
        for (int i = 0; i < veiculos.size(); i++) {
            cout << endl;
            veiculos[i]->print();
        }
    }
    cout << "To what car do you want to perform maintenance? Press 0 for none\n";
    string option;
    cin >> option;
    if (option != "0") {
        Veiculo *v;
        for (int i = 0; i < cd->getVeiculos()->size(); i++) {
            if (cd->getVeiculos()->at(i)->getId() == stoi(option))
                v = cd->getVeiculos()->at(i);
        }
        //adiar proxima manutencao para um ano a seguir
        this->empresa.changeManutencao(stoi(option),Data(v->getManutencao().getAno() + 1, v->getManutencao().getMes(), v->getManutencao().getDia(),
                                                         v->getManutencao().getHora()));

        //v->setManutencao(Data(v->getManutencao().getAno() + 1, v->getManutencao().getMes(), v->getManutencao().getDia(),
         //                     v->getManutencao().getHora()));
        Contract c("dummy", 1);
        Data inicio = this->empresa.getDateToday();
        Data fim = inicio;
        fim.setDia(fim.getDia() + 5);
        //reserva dummy para veiculo ficar indisponivel nos proximos 5 dias
        Reserva r(inicio, fim, 0, false, v->getId(), c);
        v->addReserva(&r);
    }
}


int Menu::askInt() {
    int n;
    string temp;

    cout << "\nHow many vehicles do you wish to see?";
    cin >> temp;

    try {
        n = stoi(temp);
    }
    catch (exception e) {
        cout << "Sorry, wrong input\n";
        askInt();
    }
    return n;


}
