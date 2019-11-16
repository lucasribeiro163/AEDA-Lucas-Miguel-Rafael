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
    void singleUseRent();
    void periodicContractRent();
    bool checkDateFormat(string data);
    bool checkHourFormat(string hora);
    string askDateIn();
    string askDateOut();
    string askHourIn();
    string askHourOut();
    void manageFleet();
    void removeCar();
    void viewCars();
    void updateCar();
    void updateCargoVehicle();
    void updatePassengerVehicle();
    void seeReservations();
    void unregisteredChoose();
    int validCinInt();
    void registerClient();
    void makeOffer(Data in, Data out);

    };


#endif //PROJECT_MENU_H
