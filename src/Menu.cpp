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
            empresa.printVeiculos();
        } else {
            cout << "Sorry, wrong input" << endl;
            checkRegister();
        }
    }
}

void Menu::login() const{
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
                empresa.printVeiculos();
            }
             else
                cout << "Better luck next time" << endl;

        }
     else{
        cout << "Sorry, that id doesn't match any client" << endl;
        login();
     }
}

