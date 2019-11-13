//
// Created by migue on 11/7/2019.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include "Empresa.h"
#include "Utilizador.h"
#include "Veiculo.h"

class Menu {
    Empresa empresa;
    Visitante* visitanteAtual;

public:
    Menu(Empresa &empresa);
    void checkRegister();
    void login();
    void choose();
    void rentVehicle();
    void advertiseVehicle();
    void hourRentVehicle();
    void dayRentVehicle();
    void weekRentVehicle();
    void monthRentVehicle();
};


#endif //PROJECT_MENU_H
