//
// Created by Lucas on 11/2/2019.
//

#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include "Hora.h"
#include <string>

using namespace std;

class Data {
    int ano;
    int mes;
    int dia;
    Hora hora;

public:

    Data(string data, string hora);

    int getAno() const;

    void setAno(int ano);

    int getMes() const;

    void setMes(int mes);

    int getDia() const;

    void setDia(int dia);

    Hora &getHora();

    void setHora(Hora &hora);

    bool operator<=(Data data);
};


#endif //UNTITLED_DATA_H
