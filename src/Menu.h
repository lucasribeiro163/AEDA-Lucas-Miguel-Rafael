//
// Created by migue on 11/7/2019.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include "Empresa.h"
#include "Utilizador.h"

class Menu {
    Empresa empresa;
public:
    Menu(Empresa &empresa);
    void checkRegister() const;
    void login() const;
    void showOffers() const;
};


#endif //PROJECT_MENU_H
