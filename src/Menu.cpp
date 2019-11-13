//
// Created by migue on 11/7/2019.
//

#include <iostream>
#include "Menu.h"
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
            cout << "Here are the company's offers: " << endl;
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
    << "2 - Rent a vehicle" << endl;

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
        }
    }
}

void Menu::rentVehicle(){
    cout << "For how long would you like to rent?\n"
    << "1 - For one or more hours\n"
    << "2 - For one or more days\n"
    << "3 - For one or more weeks\n"
    << "4 - For one or more months\n"
    << "5 - Go back" << endl;

    string option;
    cin.ignore();
    getline(cin, option);
    if(option!="1" && option!="2" && option!="3" && option!="4" && option!="5")
    {
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
                weekRentVehicle();
                break;
            case(4):
                monthRentVehicle();
                break;
            case(5):
                choose();
                break;
        }
    }
}

void Menu::hourRentVehicle(){
    cout << "hourRent" << endl;
}
void Menu::dayRentVehicle(){
    cout << "dayRent" << endl;
}
void Menu::weekRentVehicle(){
    cout << "weekRent" << endl;
}
void Menu::monthRentVehicle(){
    cout << "monthRent" << endl;
}

