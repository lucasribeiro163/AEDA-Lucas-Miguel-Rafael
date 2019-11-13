//
// Created by migue on 11/7/2019.
//

#include <iostream>
#include "Menu.h"
#include "Veiculo.h"

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
    cout << "What would you like to do?\n"
    << "1 - See all the company's cars\n"
    << "2 - Rent a vehicle" << endl
    << "3 - Advertise a vehicle" << endl;

    string option;
    cin.ignore();
    getline(cin, option);

    if(option != "1" && option != "2") {
        cout << "Invalid option" << endl;
        choose();
    }
    else{
        switch(stoi(option)){
            case(1):
                cin.clear();
                empresa.printVeiculos();
                choose();
                break;
            case(2):
                cin.clear();
                rentVehicle();
                break;
            case(3):
                cin.clear();
                advertiseVehicle();
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


    cout << "Is your vehicle a passenger vehicle or a cargo vehicle? (1 or 2)";
    int tipo;
    cin >> tipo;

    if(tipo != 1 && tipo != 2){
        cout << "You've entered an unkown vehicle type. Try again." << endl;
        advertiseVehicle();
        return;
    }

    cout << "Please fill the following fields: " << endl;

    cout << "Brand: ";
    string marca;
    cin >> marca;
    cout << "Model: ";
    string modelo;
    cin >> modelo;
    cout << "Year: ";
    int ano;
    cin >> ano;


    if(tipo == 1) {
        cout << "Number of passengers: ";
        int nr_pass;
        cin >> nr_pass;

        VeiculoPassageiros *v = new VeiculoPassageiros(marca, modelo, ano, this->visitanteAtual->getId(), nr_pass);
        
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

        VeiculoComercial *v = new VeiculoComercial(marca, modelo, ano, this->visitanteAtual->getId(), volume_carga, peso_carga, referigeracao);

    }

    cout << "You have advertised your car successfully!" << endl;

    choose();

}

void Menu::hourRentVehicle(){

    cout << "What day do you wanna rent the vehicle?" << endl << "Insert the day in the following format (dd-mm-aaaa): ";

    string option;
    cin >> option;





}
void Menu::dayRentVehicle() {
    cout << "dayRent" << endl;
}

