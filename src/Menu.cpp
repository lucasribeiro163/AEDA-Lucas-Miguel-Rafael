//
// Created by migue on 11/7/2019.
//

#include <iostream>
#include "Menu.h"
using namespace std;

Menu::Menu(Empresa &empresa)
{
    this->empresa = empresa;
    cout << "Welcome to the agency" << endl;
    checkRegister();
}

void Menu::checkRegister() const{
    cout << "Are you registered? (Y/N)" << endl;
    string isRegistered;
    getline(cin, isRegistered);
    if ((isRegistered == "Y") || (isRegistered == "y")) {
        cout << "Welcome" << endl;
        login();
    }
    else {
        if ((isRegistered == "N") || (isRegistered == "n")) {
            cout << "Here are the company's offers: " << endl;
            //showOffers();
        } else {
            cout << "Sorry, wrong input" << endl;
            checkRegister();
        }
    }
}

void Menu::login() const{
    string inputId;
    cout << "What is your id?" << endl;
    getline(cin, inputId);
        //NOTA: Fazer try catch, para evitar erro em stoi(inputId)
        if(empresa.hasVisitanteRegistado(stoi(inputId))){
            cout <<"What would you like to do?" << endl;
            //showClientOptions();
        }
     else{
        cout << "Sorry, that id doesn't match any client" << endl;
        tryLoginAgain();
     }
}

void Menu::tryLoginAgain() const {
    cout << "Would you like to try again? (Y/N)" << endl;

    string tryAgain;
    getline(cin, tryAgain);

    if ((tryAgain == "Y") || (tryAgain == "y")) {
        login();
    }
    else {
        if ((tryAgain == "N") || (tryAgain == "n")) {
            //exit program
        } else {
            cout << "Sorry, wrong input" << endl;
            tryLoginAgain();
        }
    }
}